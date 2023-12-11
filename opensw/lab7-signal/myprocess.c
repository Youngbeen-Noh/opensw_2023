#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void hoo(){
    while(1){
        printf("pid: %lu\n", (unsigned long)getpid());
        sleep(1);
    }
}

void goo(){
    hoo();
}

void foo(){
    goo();
}

int main(){

    foo();

    return 0;
}