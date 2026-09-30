#include<stdio.h>
#include "task.h"
#include "priority.h"
#include "heap.h"
#include "scheduler.h"
#include "file.h"
#include "analytics.h"
void refreshtasksystem()
{
    updateallpriorities();
    buildHeap();
}
void displaynexttask()
{
    struct Task nexttask;
    if(heapsize==0)
    {
        printf("\nNo tasks available\n");
        return;
    }
    nexttask=getNextTask();
    printf("\n===== NEXT TASK =====\n");
    printf("Task ID     :%d\n",nexttask.id);
    printf("Task Name   :%s\n",nexttask.name);
    printf("Deadline    :%s\n",nexttask.deadline);
    printf("Importance  :%d\n",nexttask.importance);
    printf("Duration    :%d\n",nexttask.duration);
    printf("Priority    :%.2f\n",nexttask.priority);
    if(nexttask.completed==1)
    {
        printf("Status:Completed\n");
    }
    else
    {
        printf("Status:Pending\n");
    }
}
int main()
{
    int choice;
    int result;
    int loadedtasks;
    loadedtasks=loadtasks(datafile);
    if(loadedtasks>0)
    {
        buildHeap();
        printf("%d tasks loaded successfully\n",loadedtasks);
    }
    else if(loadedtasks==0)
    {
        printf("No valid saved tasks found\n");
    }
    do
    {
        printf("\n===============================\n");
        printf("      PRIORITY TASK SCHEDULER\n");
        printf("\n===============================\n");
        printf("1.Add Task\n");
        printf("2.Display All tasks\n");
        printf("3.Search task\n");
        printf("4.Update task\n");
        printf("5.Complete task\n");
        printf("6.Delete task\n");
        printf("7.Sort tasks by priority\n");
        printf("8.Show next task\n");
        printf("9.Save tasks\n");
        printf("10.Load tasks\n");
        printf("11.Productivity report\n");
        printf("0.Exit\n");
        printf("Enter your choice:");
        if(scanf("%d",&choice)!=1)
        {
            printf("Invalid input..Enter a number\n");
            while(getchar()!='\n')
                  {
                   /*clear invalid input*/
                  }
        choice=-1;
        continue;
        }
        switch(choice)
        {
        case 1:
            addtask();
            refreshtasksystem();
            break;
        case 2:
            displaytasks();
            break;
        case 3:
            {
                int id;
                printf("Enter taks ID to search:");
                scanf("%d",&id);
                searchtask(id);
                break;
            }
        case 4:
            {
                int id;
                printf("Enter task ID to update:");
                scanf("%d",&id);
                updatetask(id);
                refreshtasksystem();
                break;
            }
        case 5:
            {
                int id;
                printf("Enter task ID to complete:");
                scanf("%d",&id);
                completetask(id);
                refreshtasksystem();
                break;
            }
        case 6:
            {
                int id;
                printf("Enter task ID to delete:");
                scanf("%d",&id);
                deletetask(id);
                refreshtasksystem();
                break;

            }
        case 7:
            refreshtasksystem();
            sortTasksByPriority();
            buildHeap();
            break;
        case 8:
            refreshtasksystem();
            displaynexttask();
            break;
        case 9:
            result=savetasks(datafile);
            if(result==0)
            {
                printf("Tasks saved successfully\n");

            }
            else
            {
                printf("Failed to save tasks\n");

            }
            break;
        case 10:
            result=loadtasks(datafile);
            if(result==-1)
            {
                printf("Failed to load tasks\n");
                break;
            }
            buildHeap();
            printf("%d tasks loaded successfully\n",result);
            break;
        case 11:
            refreshtasksystem();
            showreport();
            break;
        case 0:
            result=savetasks(datafile);
            if(result==0)
            {
                printf("Tasks saved successfully\n");
            }
            else
            {
                printf("Warning:Could not save tasks\n");
            }
            printf("Exiting Priority task scheduler\n");
            break;
        default:
            printf("Invalid choice.Please try again\n");
        }
    }while(choice!=0);
    return 0;
}
