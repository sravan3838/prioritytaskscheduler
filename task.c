#include<stdio.h>
#include<string.h>
#include "task.h"
#include "scheduler.h"
struct Task tasks[maxtasks];
int taskcount=0;
void addtask()
{
    int valid;
    if(taskcount>=maxtasks)
    {
        printf("Task limit reached.Cannot add more tasks.\n");
        return;
    }
    printf("Enter Task ID:");
    scanf("%d",&tasks[taskcount].id);
    int i;
    for(i=0;i<taskcount;i++)
    {
        if(tasks[i].id==tasks[taskcount].id)
        {
            printf("Task ID already exists.\n");
            return;
        }
    }
    printf("Enter task name:");
    scanf(" %99[^\n]",tasks[taskcount].name);
    do{
    printf("Enter Deadline (DD-MM-YYYY HH:MM):");
    scanf(" %19[^\n]",tasks[taskcount].deadline);
    valid=isvaliddeadline(tasks[taskcount].deadline);
    if(valid==0)
    {
        printf("Invalid deadline.Use DD-MM-YYYY HH:MM\n");
    }
    }while(valid==0);
    printf("Enter Importance (1-5):");
    scanf("%d",&tasks[taskcount].importance);
    while(tasks[taskcount].importance<1||tasks[taskcount].importance>5)
    {
        printf("Invalid Importance..Enter a value between 1-5");
        scanf("%d",&tasks[taskcount].importance);
    }
    printf("Enter Estimated Duration(hours):");
    scanf("%d",&tasks[taskcount].duration);
    while(tasks[taskcount].duration<=0)
    {
        printf("Invalid duration. enter value greater than 0:");
        scanf("%d",&tasks[taskcount].duration);
    }
    tasks[taskcount].completed=0;
    tasks[taskcount].priority=0.0;
    taskcount++;
    printf("Task added successfully\n");
}
void displaytasks()
{
    if(taskcount==0)
    {
        printf("No tasks available\n");
        return;
    }
    int i;
    for(i=0;i<taskcount;i++)
    {
        printf("\n-----------------------------\n");
        printf("Task ID    :%d\n",tasks[i].id);
        printf("Task Name  :%s\n",tasks[i].name);
        printf("Deadline   :%s\n",tasks[i].deadline);
        printf("Importance :%d\n",tasks[i].importance);
        printf("Duration   :%d hours\n",tasks[i].duration);
        printf("Priority   :%.2f\n",tasks[i].priority);
          if(tasks[i].completed==1)
          {
              printf("Status:Completed\n");
          }
          else
          {
              printf("Status:Pending\n");
          }
         printf("-----------------------------\n");
    }
}
void searchtask(int id)
{
    int i;
    if(taskcount==0)
    {
        printf("No available tasks\n");
        return;
    }

    for(i=0;i<taskcount;i++)
    {
        if(tasks[i].id==id)
        {
            printf("\nTask Found\n");
            printf("-----------------------------\n");
            printf("Task ID    :%d\n",tasks[i].id);
            printf("Task Name  :%s\n",tasks[i].name);
            printf("Deadline   :%s\n",tasks[i].deadline);
            printf("Importance :%d\n",tasks[i].importance);
            printf("Duration   :%d hours\n",tasks[i].duration);
            printf("Priority   :%.2f\n",tasks[i].priority);
         if(tasks[i].completed==1)
        {
            printf("Status:Completed\n");
        }
        else
        {
            printf("Status:Pending\n");
        }
        printf("-----------------------------\n");
        return;
        }

    }
    printf("Task with %d ID not found\n",id);
}
void updatetask(int id)
{
    int i,valid;
    for(i=0;i<taskcount;i++)
    {
        if(tasks[i].id==id)
        {
            printf("\nTask Found\n");
            printf("1.Update Task Name:\n");
            printf("2.Update Deadline:\n");
            printf("3.Update Importance:\n");
            printf("4.Update Duration:\n");
            printf("0.Finish Update\n");
            int ch;
            do
            {
                printf("Enter your choice:");
                scanf("%d",&ch);
                switch(ch)
                {
                case 1:
                    printf("Enter new task name:");
                    scanf(" %99[^\n]",tasks[i].name);
                    printf("New task name updated\n");
                    break;
                case 2:
                    do{
                        printf("Enter Deadline (DD-MM-YYYY HH:MM):");
                        scanf(" %19[^\n]",tasks[taskcount].deadline);
                        valid=isvaliddeadline(tasks[taskcount].deadline);
                        if(valid==0)
                        {
                            printf("Invalid deadline.Use DD-MM-YYYY HH:MM\n");
                        }
                        }while(valid==0);
                    printf("Deadline updated\n");
                    break;
                case 3:
                    printf("Enter new importance value:");
                    scanf("%d",&tasks[i].importance);
                    while(tasks[i].importance<1 || tasks[i].importance>5)
                    {
                        printf("Invalid importance.Enter value between 1-5");
                        scanf("%d",&tasks[i].importance);
                    }
                    printf("Importance updated successfully\n");
                    break;
                case 4:
                    printf("Enter new duration(hours):");
                    scanf("%d",&tasks[i].duration);
                    while(tasks[i].duration<=0)
                    {
                        printf("Invalid duration.Enter value greater than 0:");
                        scanf("%d",&tasks[i].duration);

                    }
                    printf("Duration updated\n");
                    break;
                case 0:
                    printf("Update finished\n");
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }while(ch!=0);
            return;
    }
}
printf("Task with %d ID not found\n",id);
}
void deletetask(int id)
{
    int i,j;
    for(i=0;i<taskcount;i++)
    {
        if(tasks[i].id==id)
        {
            for(j=i;j<taskcount-1;j++)
            {
                tasks[j]=tasks[j+1];
            }
            taskcount--;
            printf("Task deleted successfully\n");
            return;
        }
    }
    printf("Task with ID %d not found.Failed to delete\n",id);
}
void completetask(int id)
{
    int i;
    for(i=0;i<taskcount;i++)
    {
        if(tasks[i].id==id)
        {
            if(tasks[i].completed==1)
            {
                printf("Task is already completed\n");
                return;
            }
            tasks[i].completed=1;
            printf("Task completed succesfully\n");
            return;
        }
    }
    printf("Task with ID %d not found\n",id);
}







