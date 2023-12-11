#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t a = fork();

    char *new_argv[] = {"ls", "-l", NULL};
    if(a==0){
        execve("/usr/bin/ls", new_argv, NULL);
        exit(123);
    }
    else{
        int status;
        printf("hello world\n");
        wait(&status);
        printf("goodbye world\n");
        
        // so busy...
        // while(1){} //zombie process
        if(WIFEXITED(status)){
            printf("child exit code : %d\n", WEXITSTATUS(status));
        };
    }

    return 0;
}