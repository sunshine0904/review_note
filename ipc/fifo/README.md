    有名管道
有名管道创建的管道以文件形式存在与文件系统中，因此只要能访问该管道文件的进程都可以与创建进程通信。
有名管道及匿名管道都严格遵循先进先出的规则，读总是从管道开始处返回数据，写总是把数据写在末尾。不支持lseek定位操作。
有名管道的名字存在于文件系统中，内容存放在内存中。


参考资料：
https://www.ibm.com/developerworks/cn/linux/l-ipc/part1/index.html