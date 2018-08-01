/*************************************************************************
	> File Name: mesque.c
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Aug 2018 06:52:17 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include"msgque.h"

int main(int argc, char **argv)
{
    key_t key = 0;
    uint32_t msgid = 0;
    int ret = 0;
    struct msg_buf smbuf;
    struct msg_buf rmbuf;
    struct msqid_ds qbuf;

    memset(&smbuf, 0, sizeof(struct msg_buf));
    memset(&rmbuf, 0, sizeof(struct msg_buf));
    memset(&qbuf, 0, sizeof(struct msqid_ds));
    
    key = ftok(MPATH, 'a');
    if (key < 0)
    {
        perror("fail to ftok\n");
        return ERRNO_FAIL;
    }
    
    msgid = msgget(key, IPC_CREAT|0666);
    if (msgid < 0)
    {
        perror("msgget error!\n");
        return ERRNO_FAIL;
    }


    printf("key:0x%x msgid:%d\n", key, msgid);

    ret = msgctl(msgid, IPC_STAT, &qbuf);
    if (ret < 0)
    {
        perror("msgctl error!\n");
        return ERRNO_FAIL;
    }

    qbuf.msg_qnum = 20;
    qbuf.msg_qbytes = 20 * sizeof(struct msg_buf);

    ret = msgctl(msgid, IPC_SET, &qbuf);
    if (ret < 0)
    {
        perror("msgctl error!\n");
        return ERRNO_FAIL;
    }

    smbuf.mtype = 1;
    strcpy(smbuf.buf, "hello msg queue!"); 

    ret = msgsnd(msgid, &smbuf, sizeof(struct msg_buf), IPC_NOWAIT);
    if (ret < 0)
    {
        perror("msgsnd error!\n");
        return ERRNO_FAIL;
    }

    printf("msgsnd send %d bytes content!\n", ret);

    system("ipcs -q");
    sleep(5);

    ret = msgrcv(msgid, &rmbuf, sizeof(struct msg_buf), 0, IPC_NOWAIT);
    if (ret < 0)
    {
        perror("msgrcv error!\n");
    }
    else
    {
        printf("msgrcv recv %d bytes content! content:%s\n", ret, rmbuf.buf);
    }


    ret = msgctl(msgid, IPC_RMID, NULL);
    if (ret < 0)
    {
        perror("Del msg queue error!\n");
        return ERRNO_FAIL;
    }

    system("ipcs -q");
    return ERRNO_SUCCESS;

}
