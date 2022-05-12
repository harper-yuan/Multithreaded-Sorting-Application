# 用多线程实现一个排序APP 

## 预备知识
- [pthread.h库的使用](https://blog.csdn.net/lileiyuyanqin/article/details/78212305
)

## 线程的优点
- 及时响应——部分线程被阻塞，其他可继续执行(对用户界面尤其重要)
- 资源共享——线程共享进程资源，比共享内存或消息传递更容易
- 经济——比进程创建便宜，线程切换开销比上下文切换低
- 可扩展性——线程可在多处理器上并行运行

## 一些小错误
1. 结构体p_argv定义了整型数组list[3]：

        typedef struct
        {
            int list[3];
        }p_argv;
        p_argv *p;
        int main()
        {
            p->list = {1,2,3};
            return 0;
        }

&emsp; &emsp; 这会产生报错：
&emsp; &emsp;“assigning to an array from an initializer list”

&emsp; &emsp;解决方案：
&emsp; &emsp;将int list[3]定义为int *list,把初始值传给一个临时数组，把数组指针在赋给q->list即可



