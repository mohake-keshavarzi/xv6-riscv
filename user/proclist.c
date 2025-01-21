#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/process_data.h"

int
main(int argc, char *argv[]){
    struct process_data process_info;

    int next_pid=0;
    int process_count=0;
    while(next_process(next_pid,&process_info)!=0){
        next_pid=process_info.pid;
        printf("next ---> PID:%d  Parent PID:%d   Heap Size:%d   State:%d   Name:%s\n"
        ,process_info.pid,process_info.parent_pid,process_info.heap_size,process_info.state,process_info.name);
        printf("\tThread IDs: ");
        for (int i = 0; i < MAXTHREADPERPROC; i++)
        {
            if(process_info.active_tids[i]!=-1)
                printf("%d, ",process_info.active_tids[i]);
        }
        printf("\n");
        
        process_count++;
    }
}
