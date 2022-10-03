#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void ParentProcess(void);
void ChildProcess(void);
void WaitForChildrenProcess(void);

void  main(void){
     pid_t  pid;
     pid = fork();
     if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess();
}

void ParentProcess(void){
	pid_t pid = fork();
	if (pid == 0) 
      ChildProcess();
  else 
      WaitForChildrenProcess();
}

void ChildProcess(void){
	int i;
     for (i = 1; i <= rand() % 30 + 1; i++){
			 pid_t pid = getpid();
			 printf("Child Pid: %d is going to sleep!\n", pid);
			 sleep(rand()% 10 + 1);
			 printf("Child Pid: % d is awake!\nWhere is my Parent: %d\n", pid, getppid());
		 }
}
void WaitForChildrenProcess(void){
	int status;
	pid_t pid;
	int processNum = 2;
	while (processNum > 0){
		pid = wait(& status);
		printf("Child Pid: %d has completed\n", pid);
		processNum --;
	}
}