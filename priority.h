#ifndef PRIORITY_H
#define PRIORITY_H

#include "task.h"

double calculateImportanceScore(int importance);
double calculateUrgencyScore(double daysRemaining);
double calculateLeadTimeRisk(double duration, double hoursRemaining);
double calculatePriority(struct Task *task);

void calculateAllPriorities();

#endif
