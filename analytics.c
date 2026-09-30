#include <stdio.h>
#include "task.h"
#include "scheduler.h"
#include "analytics.h"

void showreport()
{
    int done = 0, open = 0, late = 0, i;
    double workhrsleft = 0, hrsdone = 0, impsum = 0;

    if(taskcount == 0)
    {
        printf("no tasks yet\n");
        return;
    }

    for(i = 0; i < taskcount; i++)
    {
        impsum+= tasks[i].importance;


        if(tasks[i].completed)
        {
            done++;
            hrsdone += tasks[i].duration;
        }
        else
        {
            open++;
            workhrsleft += tasks[i].duration;
            if(isOverdue(tasks[i]))
                late++;
        }
    }

    printf("\n==Productivity Report ==\n");
    printf("total tasks    : %d\n", taskcount);
    printf("completed      : %d\n", done);
    printf("open           : %d\n", open);
    printf("late           : %d\n", late);
    printf("Completion rate: %.1f%%\n", 100.0 * done / taskcount);
    printf("Hours done     : %.1f\n", hrsdone);
    printf("Work hours left: %.1f\n",workhrsleft);
    printf("average lvl : %.2f\n", impsum / taskcount);
}
