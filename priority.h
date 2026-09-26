#ifndef PRIORITY_H
#define PRIORITY_H

struct Task {
    int importance;
    double daysRemaining;
    double duration;
    double hoursRemaining;
    double priority;
};

double calculateImportanceScore(int importance);
double calculateUrgencyScore(double daysRemaining);
double calculateLeadTimeRisk(double duration, double hoursRemaining);
double calculatePriority(struct Task *task);
void calculateAllPriorities(void);

#endif
