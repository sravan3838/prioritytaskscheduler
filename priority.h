#ifndef PRIORITY_H
#define PRIORITY_H
#include "task.h"
double calculateimportancescore(struct Task task);
double calculateurgencyscore(struct Task task);
double calculateleadtimerisk(struct Task task);
double calculatepriority(struct Task task);
void updateallpriorities();
#endif

