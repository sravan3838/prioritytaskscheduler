#include <stdio.h>
#include "task.h"
#include "scheduler.h"
#include "analytics.h"

void showreport()
{
    int done = 0, open = 0, late = 0, i, lv;
    double hrsleft = 0, hrsdone = 0, impsum = 0;

    if(taskcount == 0) { printf("no tasks yet\n"); return; }

    for(i = 0; i < taskcount; i++)
    {
        lv = tasks[i].importance;
        impsum += lv;

        if(tasks[i].completed) { done++; hrsdone += tasks[i].duration; }
        else
        {
            open++;
            hrsleft += tasks[i].duration;
            if(isOverdue(tasks[i])) late++;
        }
    }

    printf("\n== report ==\n");
    printf("total   : %d\n", taskcount);
    printf("done    : %d\n", done);
    printf("open    : %d\n", open);
    printf("late    : %d\n", late);
    printf("rate    : %.1f%%\n", 100.0 * done / taskcount);
    printf("hrs done: %.1f\n", hrsdone);
    printf("hrs left: %.1f\n", hrsleft);
    printf("avg lvl : %.2f\n", impsum / taskcount);
}
