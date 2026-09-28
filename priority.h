#ifndef PRIORITY_H
#define PRIORITY_H

double calculateImportanceScore(int importance);
double calculateUrgencyScore(double daysRemaining);
double calculateLeadTimeRisk(double duration, double hoursRemaining);
double calculatePriorityScore(int importance, double daysRemaining,
                              double duration, double hoursRemaining);

void updateAllPriorities();

#endif
