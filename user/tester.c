#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(fork()==0){
    sleep(5);
    printf("tid: %d\n",gettid());
  }else{
    printf("tid: %d\n",gettid());
  }

  

  exit(0);
}
