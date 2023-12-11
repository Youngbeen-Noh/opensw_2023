#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct two_double{
    double a;
    double b;
} data;
void sigalarm_handler(int signo){
    printf("%f\t%f\t\n", data.a, data.b);
    alarm(1);
}

int main(){
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};

    struct sigaction sa_alarm;

    sigemptyset(&sa_alarm.sa_mask);
    sa_alarm.sa_flags = 0;
    sa_alarm.sa_handler = sigalarm_handler;
    sigaction(SIGALRM, &sa_alarm, NULL);
    alarm(1);

    while(1){
        // block SIGALRM
        sigprocmask(SIG_BLOCK, &sa_alarm.sa_mask, NULL);
        data = ones;
        // unblock SIGALRM
        sigprocmask(SIG_SETMASK, NULL , NULL);

        // block SIGALRM
        sigprocmask(SIG_BLOCK, &sa_alarm.sa_mask, NULL);
        data = zeros;
        // unblock SIGALRM
        sigprocmask(SIG_SETMASK, NULL, NULL);
    }

    return 0;
}