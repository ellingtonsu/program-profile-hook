#include<time.h>
#include<sys/time.h>

typedef struct time_hook {
    clock_t start_cpu;
    clock_t stop_cpu;
    struct timeval start_time;
    struct timeval stop_time;
} t_hook;

double time_diff(t_hook*);
double cpu_diff(t_hook*);
double getMicroSecond(struct timeval);
