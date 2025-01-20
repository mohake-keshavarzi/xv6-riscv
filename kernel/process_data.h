#include "param.h"
enum proccess_state { MY_SLEEPING , MY_RUNNABLE , MY_RUNNING , MY_ZOMBIE };
struct process_data {
    int pid;
    int parent_pid;
    int heap_size;
    enum proccess_state state;
    char name[16];
    int active_tids[MAXTHREADNUM];
};