#include <stdio.h>
#include <math.h>
#include "task.h"
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
    double executionRatio;

    if(hoursRemaining <= 0)
    {
        return 100.0;
    }

    executionRatio = duration / hoursRemaining;

    if(executionRatio >= 2.0)
    {
        return 100.0;
    }

    return executionRatio * 50.0;
}
double calculatePriorityScore(int importance, double daysRemaining,
                              double duration, double hoursRemaining)
{
    double importanceScore;
    double urgencyScore;
    double leadTimeRisk;

    importanceScore = calculateImportanceScore(importance);
    urgencyScore = calculateUrgencyScore(daysRemaining);
    leadTimeRisk = calculateLeadTimeRisk(duration, hoursRemaining);

    return importanceScore + urgencyScore + leadTimeRisk;
}
char deadline[20];
