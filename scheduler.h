#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"

double calculateHoursRemaining(struct Task task);
double calculateDaysRemaining(struct Task task);
int isOverdue(struct Task task);

struct Task getNextTask();

void sortTasksByPriority();

#endif
