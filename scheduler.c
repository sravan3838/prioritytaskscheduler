#include <stdio.h>
#include <time.h>

#include "task.h"
#include "heap.h"
#include "scheduler.h"


double calculateHoursRemaining(struct Task task)
{
    struct tm deadline = {0};
    time_t currentTime;
    time_t deadlineTime;

    int day, month, year;
    int hour, minute;

    if (sscanf(task.deadline, "%d-%d-%d %d:%d",
               &day, &month, &year, &hour, &minute) != 5)
    {
        return 0.0;
    }

    deadline.tm_mday = day;
    deadline.tm_mon = month - 1;
    deadline.tm_year = year - 1900;
    deadline.tm_hour = hour;
    deadline.tm_min = minute;
    deadline.tm_sec = 0;
    deadline.tm_isdst = -1;

    deadlineTime = mktime(&deadline);
    currentTime = time(NULL);

    if (deadlineTime == (time_t)-1)
    {
        return 0.0;
    }

    return difftime(deadlineTime, currentTime) / 3600.0;
}


double calculateDaysRemaining(struct Task task)
{
    double hoursRemaining;

    hoursRemaining = calculateHoursRemaining(task);

    return hoursRemaining / 24.0;
}


int isOverdue(struct Task task)
{
    double hoursRemaining;

    hoursRemaining = calculateHoursRemaining(task);

    if (hoursRemaining <= 0)
    {
        return 1;
    }

    return 0;
}


struct Task getNextTask()
{
    return peek();
}


void merge(struct Task arr[], int left, int middle, int right)
{
    struct Task temp[maxtasks];

    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right)
    {
        if (arr[i].priority >= arr[j].priority)
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= middle)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}


void mergeSort(struct Task arr[], int left, int right)
{
    int middle;

    if (left < right)
    {
        middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}


void sortTasksByPriority()
{
    if (taskcount > 1)
    {
        mergeSort(tasks, 0, taskcount - 1);
    }

    printf("Tasks sorted by priority.\n");
}
