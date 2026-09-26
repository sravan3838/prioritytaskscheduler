#ifndef TASK_H
#define TASK_H
#define maxtasks 100
struct Task
{
    int id;
    char name[100];
    char deadline[20];
    int importance;
    int duration;
    double priority;
    int completed;
};
extern struct Task tasks[maxtasks];
extern int taskcount;
void addtask();
void displaytasks();
void searchtask(int id);
void updatetask(int id);
void deletetask(int id);
void completetask(int id);
#endif // TASK_H
