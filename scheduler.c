#include <stdio.h>
#include <time.h>

#include "task.h"
#include "heap.h"
#include "scheduler.h"
static int parseDeadline(const char *deadlineText,time_t*result)
{
    struct tm deadline={0};
    int day,month,year,hour,minute;
    if(sscanf(deadlineText,"%d-%d-%d %d:%d",&day,&month,&year,&hour,&minute)!=5)
    {
        return 0;
    }
    if(month<1 || month>12|| day<1 ||day>31 ||hour<0||hour>23 ||minute<0 ||minute>59)
    {
        return 0;
    }
    deadline.tm_mday=day;
    deadline.tm_mon=month-1;
    deadline.tm_year=year-1900;
    deadline.tm_hour=hour;
    deadline.tm_min=minute;
    deadline.tm_sec=0;
    deadline.tm_isdst=-1;
    *result=mktime(&deadline);
    if(*result==(time_t)-1)
    {
        return 0;
    }
    if(deadline.tm_mday!=day || deadline.tm_mon!=month-1 || deadline.tm_year!=year-1900 || deadline.tm_hour!=hour || deadline.tm_min!=minute)
    {
        return 0;
    }
    return 1;
}
int isvaliddeadline(const char *deadlineText)
{
    time_t deadlineTime;
    return parseDeadline(deadlineText,&deadlineTime);
}
double calculateHoursRemaining(struct Task task)
{
    time_t currentTime;
    time_t deadlineTime;
    if (parseDeadline(task.deadline,&deadlineTime)==0)
    {
        return 0.0;
    }
    currentTime=time(NULL);
    return difftime(deadlineTime,currentTime)/3600.0;
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

    if (hoursRemaining < 0)
    {
        return 1;
    }

    return 0;
}


struct Task getNextTask()
{
    return peek();
}


static void merge(struct Task arr[], int left, int middle, int right)
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
static void mergeSort(struct Task arr[], int left, int right)
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
    if(taskcount==0)
    {
        printf("No tasks available to sort.\n");
        return;
    }
    if (taskcount > 1)
    {
        mergeSort(tasks, 0, taskcount - 1);
    }
    printf("Tasks sorted by priority.\n");
}
