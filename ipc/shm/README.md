    共享内存
共享内存指两个或多个进程共享一个给定的存储区。
特点：
    1、共享内存是最快的一种ipc，因为进程是直接对内存进行存取；
    2、多个进程可以同时操作，所以需要进行同步；
    3、信号量和共享内存通常结合在一起使用，信号量用来同步对共享内存的访问。