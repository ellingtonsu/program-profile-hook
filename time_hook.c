#include<stdio.h>
#include<time.h>
#include<sys/time.h>
#include "time_hook.h"

double getMicroSecond(struct timeval tv){
    double time = (double)tv.tv_sec*1000000 + (double)tv.tv_usec;
    return time;    
}

double cpu_diff(t_hook *hook) {
    double elapsed = (double)((hook->stop_cpu - hook->start_cpu) * 1000000 / CLOCKS_PER_SEC);
    return elapsed;
}

double time_diff(t_hook *hook) {
    double elapsed = getMicroSecond(hook->stop_time) - getMicroSecond(hook->start_time);
    return elapsed;
}

void time_start(t_hook *hook) {
    hook->start_cpu = clock();
    gettimeofday(&(hook->start_time), NULL);
}

void time_stop(t_hook *hook) {
    hook->stop_cpu = clock();
    gettimeofday(&(hook->stop_time), NULL);
}
