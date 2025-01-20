#include "process_data.h"
#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_gettid(void)
{
  return mythread()->t_id;
}

uint64
sys_next_process(void)
{
  int before_pid;
  struct process_data result;
  uint64 result_addr;
  argint(0,&before_pid);
  argaddr(1, &result_addr);
  struct proc* my_proc=nextProcess(before_pid);
  if(my_proc==0) return 0;
  result.pid=my_proc->pid;
  switch (my_proc->state)
  {
    case SLEEPING:result.state=MY_SLEEPING; break;
    case RUNNABLE:result.state=MY_RUNNABLE; break;
    case RUNNING:result.state=MY_RUNNING; break;
    case ZOMBIE:result.state=MY_ZOMBIE; break;
    default: break;
  }
  if(my_proc->parent==0) result.parent_pid=-1;
  else result.parent_pid=my_proc->parent->pid;
  result.heap_size=my_proc->sz;
  strncpy(result.name,my_proc->name,16);
  for (int i = 0; i < MAXTHREADNUM; i++)
  {
    if(my_proc->threads[i].state==ACTIVE)
      result.active_tids[i]=my_proc->threads[i].t_id;
    else
      result.active_tids[i]=-1;

  }
  
  struct proc *p = myproc();
  return copyout(p->pagetable, result_addr, (char*)&result, sizeof(result))+1;

}


uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  if(n < 0)
    n = 0;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
