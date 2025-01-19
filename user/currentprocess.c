#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{

    printf("Current process's ID is: %d\n",getpid());
    printf("---The ID of current running thread of this process: %d\n",gettid());

  
  exit(0);
}
