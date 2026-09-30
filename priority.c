
#include "task.h"
#include "scheduler.h"
#include "priority.h"
double calculateimportancescore(struct Task task)
{
    return task.importance * 20.0;
}
double calculateurgencyscore(struct Task task)
{
    double daysRemaining;
    daysRemaining=calculateDaysRemaining(task);
    if(daysRemaining <=0)
    {
       return 100.0;
    }

    return 100.0 / (1.0 + daysRemaining);
}
double calculateleadtimerisk(struct Task task)
{
    double executionratio;
    double hoursRemaining;
    hoursRemaining=calculateHoursRemaining(task);
    if(hoursRemaining <= 0)
    {
        return 100.0;
    }
    executionratio = task.duration / hoursRemaining;
    if(executionratio >= 2.0)
    {
        return 100.0;
    }
    return executionratio * 50.0;
}
double calculatepriority(struct Task task)
{
    double importancescore;
    double urgencyscore;
    double leadtimerisk;
    importancescore = calculateimportancescore(task);
    urgencyscore = calculateurgencyscore(task);
    leadtimerisk = calculateleadtimerisk(task);
    return importancescore + urgencyscore + leadtimerisk;
}
void updateallpriorities()
{
    int i;
    for(i=0;i<taskcount;i++)
    {
        if(tasks[i].completed==1)
        {
            tasks[i].priority=0.0;
        }
        else
        {
            tasks[i].priority=calculatepriority(tasks[i]);
        }
    }
}
