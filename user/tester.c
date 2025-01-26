#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void tr(void){
    printf("I AM ALIVE");
}
void tr2(void){
    printf("I AM ALIVE");
}
void tr3(void){
    printf("I AM ALIVE");
}
void tr4(void){
    sleep(50);
    printf("I AM ALIVE");
}
void tr5(void){
    printf("I AM ALIVE");
}


int
main(int argc, char *argv[])
{
  // int i=0;
//   getpid();
  printf("Inside tester\n");
  printf("the func:%ld\n",(uint64)tr);
  printf("the func:%ld\n",(uint64)tr2);
  printf("the func:%ld\n",(uint64)tr3);
  printf("the func:%ld\n",(uint64)tr4);
  printf("the func:%ld\n",(uint64)tr5);

  void * stack = malloc(4096);
  int tid=thread_create(tr4,stack);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  printf("I have a thread %d\n",tid);
  

  exit(0);
}
