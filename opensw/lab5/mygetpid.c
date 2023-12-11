// header files
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

    printf("my pid is %lu\n", (unsigned long) getpid());

    printf("my ppid is %lu\n", (unsigned long) getppid());

    return 0;
}