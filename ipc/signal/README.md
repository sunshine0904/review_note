    信号
信号是异步的，是进程间通信机制中唯一的异步通信机制。信号是在软件层次上对中断的一种模拟。
信号的来源：硬件来源（按下键盘或硬件故障）；
            软件来源（系统函数kill、raise、alarm、setitimer、sigqueue函数或非法操作）

信号的种类：可靠信号和不可靠信号
1、不可靠信号
  信号值小于SIGRTMIN的信号都是不可靠信号；
  不可靠原因L：信号可能丢失；
2、可靠信号
  信号值位于SIGRTMIN和SIGRTMAX之间的信号都是可靠信号。可靠信号克服了信号可能丢失的问题。
  信号安装函数：signal()、sigaction()
  这两个函数区别：sigaction安装的信号都能传递信息给信号处理函数；signal安装的信号不能向信号处理函数传递信息；

进程对信号的响应：
    1）、忽略信号。不对信号做任何处理。sigkill及sigstop信号不可忽略；
    2）、捕捉信号。定义信号处理函数，当信号发生时，执行相应的处理函数；
    3）、执行缺省操作。linux对每一种信号都规定了默认操作。

信号的发送：
    发送信号的主要函数有：kill() 、raise()、sigqueue()、alarm()、setitimer()、abort()
信号的安装（设置信号关联函数）：
    signal()、sigaction()


参考资料：
https://www.ibm.com/developerworks/cn/linux/l-ipc/part2/index1.html
https://www.ibm.com/developerworks/cn/linux/l-ipc/part2/index2.html
