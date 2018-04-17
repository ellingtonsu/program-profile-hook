#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include "time_hook.h"

int main(void) {
    int i = 0;
    unsigned long sum1 = 0, sum2 = 0;
    t_hook hook1, hook2;

    time_start(&hook1);
    for(i=1;i<=1000000;i++){
        sum1 = sum1 + i;
    }
    time_stop(&hook1);

    time_start(&hook2);
    sum2 = ((1 + 1000000L) * 1000000L)/2;
    time_stop(&hook2);

    printf("sum1 = %d\tcpu diff %.2lf us\ttime diff %.2lf us\n", sum1, cpu_diff(&hook1), time_diff(&hook1));
    printf("sum2 = %d\tcpu diff %.2lf us\ttime diff %.2lf us\n", sum2, cpu_diff(&hook2), time_diff(&hook2));

    return 0;
}
