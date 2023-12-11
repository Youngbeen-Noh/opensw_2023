#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_system(char * command){
    if(fork()==0){
        execl("/bin/sh", "sh", "-c", command, (char *) NULL);
    }
    else{
        int status;
        wait(&status);
    }
}
int main(){

    int status;
    // status = system("ls -l | wc");
    status = my_system("ls -l | wc");
    printf("exit code %d\n", WEXITSTATUS(status));

    return 0;
}