#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void thr(void){
    sleep(1);
    printf("I AM ALIVE\n");
    return;
}

int
main(int argc, char *argv[])
{
    int tid=thread_create(thr);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);
    printf("thread created %d\n",tid);

    char *args[2]={"proclist", 0};
    if(fork()==0){
        printf("tid: %d\n",gettid());
        int ret=exec("/proclist",args);
        printf("returned: %d",ret);
    }else{
        sleep(5);
        printf("tid: %d\n",gettid());
    }

  

  exit(0);
}
