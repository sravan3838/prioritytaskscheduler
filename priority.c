#include <stdio.h>
#include "priority.h"

double calculateImportanceScore(int importance)
{
    return importance * 20.0;
}

double calculateUrgencyScore(double daysRemaining)
{
    if(daysRemaining < 0)
    {
        daysRemaining = 0;
    }

    return 100.0 / (1.0 + daysRemaining);
}

double calculateLeadTimeRisk(double duration, double hoursRemaining)
{
    double ratio;

    if(hoursRemaining <= 0)
    {
        return 100.0;
    }

    ratio = duration / hoursRemaining;

    if(ratio > 2.0)
    {
        ratio = 2.0;
    }

    return ratio * 50.0;
}

double calculatePriority(struct Task *task)
{
    double importanceScore;
    double urgencyScore;
    double leadTimeRisk;

    /*
       Deadline and remaining-time calculation
       will be connected later.
    */

    importanceScore = calculateImportanceScore(task->importance);

    urgencyScore = 0.0;
    leadTimeRisk = 0.0;

    return importanceScore + urgencyScore + leadTimeRisk;
}

void calculateAllPriorities()
{
    int i;

    for(i = 0; i < taskcount; i++)
    {
        tasks[i].priority = calculatePriority(&tasks[i]);
    }
}
