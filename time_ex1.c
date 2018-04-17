#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include "time_hook.h"

int main(void) {
    int i = 0;
    int sum = 0;
    t_hook hook;

    time_start(&hook);

    for(i=0;i<100000000;i++);
    sleep(1);
    printf("\nExecution time for code\n");
    printf("for(i=0;i<100000000;i++);\n");
    printf("sleep(1)\n\n");;

    time_stop(&hook);

    printf("cpu diff\t %lf us\n", cpu_diff(&hook));
    printf("time diff\t %lf us\n\n", time_diff(&hook));


}
