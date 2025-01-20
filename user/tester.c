#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
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
