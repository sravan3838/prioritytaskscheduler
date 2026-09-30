#include "heap.h"
#include "task.h"
#include "priority.h"
#include<stdio.h>
struct Task heap[maxtasks];
int heapsize=0;
void heapifyUp(int index)
{
    int parent;
    while(index>0)
    {
        parent =(index-1)/2;
        if(heap[index].priority>heap[parent].priority)
        {
            struct Task temp;
            temp=heap[index];
            heap[index]=heap[parent];
            heap[parent]=temp;
            index=parent;
        }
        else
        {
            break;
        }
    }
}
void insertTask(struct Task task)
{
    if(task.completed==1)
    {
        return;
    }
    if(heapsize>=maxtasks)
    {
        printf("Heap is full..cannot insert task\n");
        return;

    }
    heap[heapsize]=task;
    heapsize++;
    heapifyUp(heapsize-1);
}
struct Task peek()
{
    struct Task emptytask={0};
    if(heapsize==0)
    {
        printf("Heap is empty.No tasks available\n");
        emptytask.id=-1;
        return emptytask;
    }
    return heap[0];
};
struct Task extractMax()
{
    struct Task emptytask={0};
    if(heapsize==0)
    {
        printf("Heap is empty.no task to extract\n");
        emptytask.id=-1;
        return emptytask;
    }
    struct Task maxTask=heap[0];
    heap[0]=heap[heapsize-1];
    heapsize--;
    heapifyDown(0);
    return maxTask;
};
void heapifyDown(int index)
{
    int largest;
    int left;
    int right;
    while(1)
    {
        left=2*index+1;
        right=2*index+2;
        largest=index;
        if(left<heapsize && heap[left].priority>heap [largest].priority)
        {
            largest=left;
        }
        if(right<heapsize &&heap[right].priority>heap[largest].priority)
        {
            largest=right;
        }
        if(largest==index)
        {
            break;
        }
        struct Task temp;
        temp=heap[index];
        heap[index]=heap[largest];
        heap[largest]=temp;
        index=largest;
    }
}
void buildHeap()
{

    int i;
    heapsize=taskcount;
    for(i=0;i<taskcount;i++)
    {
       if(tasks[i].completed==0)
       {
           heap[heapsize]=tasks[i];
           heapsize++;
       }
    }
    for(i=(heapsize/2)-1;i>=0;i--)
    {
        heapifyDown(i);
    }
}
