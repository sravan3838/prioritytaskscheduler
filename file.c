#include <stdio.h>
#include "priority.h"
#include "task.h"
#include "file.h"

int savetasks(const char *fname)
{
    FILE *fp = fopen(fname, "w");
    int i;
    if(!fp)
    {
        printf("Unable to open file for writing\n");
        return -1;
    }

    for(i = 0; i < taskcount; i++)
    {
        fprintf(fp, "%d|%s|%s|%d|%d|%d\n", tasks[i].id, tasks[i].name,tasks[i].deadline, tasks[i].importance,tasks[i].duration, tasks[i].completed);
    }
    fclose(fp);
    return 0;
}

int loadtasks(const char *fname)
{
    FILE *fp = fopen(fname, "r");
    char buf[300];
    int got = 0,i;
    struct Task t;

    if(!fp)
    {
        printf("no task file found\n");
        return -1;
    }
    taskcount = 0;
    while(taskcount < maxtasks && fgets(buf, sizeof(buf), fp))
    {
        if(sscanf(buf, "%d|%99[^|]|%19[^|]|%d|%d|%d", &t.id, t.name,t.deadline, &t.importance, &t.duration, &t.completed) != 6)
            continue;

        if(t.importance < 1 || t.importance > 5 || t.duration <= 0)
            continue;
        for(i=0;i<taskcount;i++)
        {
            if(tasks[i].id==t.id)
            {
                break;
            }
        }
        if(i<taskcount)
        {
            continue;
        }
        t.priority = 0.0;
        tasks[taskcount++] = t;
        got++;
    }

    fclose(fp);
    updateallpriorities();
    return got;
}
