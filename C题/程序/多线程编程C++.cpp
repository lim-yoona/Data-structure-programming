/*线程的基本操作 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<windows.h>


/* 子线程1 */
void *thread_routine1(void *arg)
{
    fprintf(stdout, "thread1: Hello world!\n");
    Sleep(1);
    return NULL;
}

/* 子线程2 */
void *thread_routine2(void *arg)
{
    fprintf(stdout, "thraed2: I'm running...\n");
    pthread_t main_thread = (pthread_t)arg;

    /* 分离自我 */
    pthread_detach(pthread_self());
    /* 判断线程1 与线程2 是否相等 */
    if(!pthread_equal(main_thread, pthread_self())){
        fprintf(stdout, "thread2: main thread id is not equal thread2\n");
    }

    /* 等待线程终止 */
    pthread_join(main_thread, NULL);
    fprintf(stdout, "thread2: main thread exit!\n");
    fprintf(stdout, "thread2: exit!\n");
    fprintf(stdout, "thread2: process exit!\n");

    /* 子线程2 终止，进程退出 */
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{

    /* 创建子线程1 */
    pthread_t t1;
    if(pthread_create(&t1, NULL, thread_routine1, NULL)!=0)
    {
        fprintf(stderr, "create thread fail.\n");
        exit(-1);
    }

    /*等待子线程1终止*/
    pthread_join(t1, NULL);
    fprintf(stdout, "main thread: thread1 terminated!\n\n");

    /* 创建子线程2， 并将主线程id 传给子线程2 */
    pthread_t t2;
    if(pthread_create(&t2, NULL, thread_routine2, (void *)pthread_self())!=0)
    {
        fprintf(stderr, "create thread fail.\n");
        exit(-1);
    }

    fprintf(stdout, "main thread: sleeping...\n");
    Sleep(3);

    /* 主线程使用 pthread_exit 函数终止，进程继续存在 */
    fprintf(stdout,"main thread: exit!\n");
    pthread_exit(NULL);

    fprintf(stdout, "main thread: never reach here!\n");
    return 0;

}
