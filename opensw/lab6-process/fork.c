#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t a = fork();

    if(a==0){
        printf("child porcess' pid is %d, ppid is %d\n", getpid(), getppid());
        for(int i = 0;i<100;i++){
            printf("%d\n", i);
        }
        exit(123);
    }
    else{
        int status;

        wait(&status);
        
        printf("parent process' pid is %d, ppid is %d\n", getpid(), getppid());
        for(int i = 100;i<200;i++){
            printf("%d\n", i);
        }
        // so busy...
        // while(1){} //zombie process
        if(WIFEXITED(status)){
            printf("child exit code : %d\n", WEXITSTATUS(status));
        };
    }

    return 0;
}