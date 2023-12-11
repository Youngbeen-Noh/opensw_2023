#include <unistd.h>
#include <stdio.h>

int main(){

    char *new_argv[] = {"ls", "-l", NULL};

    printf("hello world\n");
    execve("/usr/bin/ls", new_argv, NULL);
    printf("goodbye world\n");

    return 0;
}