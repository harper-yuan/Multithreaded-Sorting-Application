#include<bits/stdc++.h>
#include<pthread.h>
using namespace std;

#define MAX 100

typedef struct
{
    int list[MAX];
}p_argv;

p_argv *p = (p_argv*)malloc(sizeof(p_argv));
int n  = 10;

void print(int *a,int n)
{
    for(int i= 0 ;i<n;i++) cout<<a[i]<<' ';
    cout<<endl;
}

void *thread1(void *p)
{
    p_argv *g = (p_argv*)p;
    sort(g->list,g->list+n/2);
    cout<<"thread1:"<<endl;
    print(g->list,n/2);
    return NULL;
}

void *thread2(void *p)
{
    p_argv *g = (p_argv*)p;
    sort(g->list+n/2,g->list+n);
    cout<<"thread2:"<<endl;
    print(g->list+n/2,n/2);
    return NULL;
}

int main()
{
    int a[n] = {7,12,19,3,18,4,2,6,15,8};
    p->list;
    memcpy(p->list,a,MAX*sizeof(int));
    print(p->list,n);
    pthread_t tid1,tid2;
    int ret1,ret2;
    ret1 = pthread_create(&tid1,NULL,thread1,(void*)p);
    if(ret1!=0)//Return 0 on successful creation
    {
        fprintf(stdout,"reason:%s",strerror(ret1));
        exit(1);
    }
    ret2 = pthread_create(&tid2,NULL,thread2,(void*)p);
    if(ret2!=0)//Return 0 on successful creation
    {
        fprintf(stdout,"reason:%s",strerror(ret2));
        exit(1);
    }
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    
    cout<<"result:";
    print(p->list,10);
    free(p);
    return 0;
}