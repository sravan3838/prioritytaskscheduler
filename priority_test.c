#include <stdio.h>
#include "priority.h"

int main()
{
    double score;

    score = calculatePriorityScore(5, 0, 2, 4);

    printf("Priority Score: %.2f\n", score);

    return 0;
}
printf("%.2f\n",
       calculatePriorityScore(5, 0, 2, 4));

printf("%.2f\n",
       calculatePriorityScore(3, 2, 6, 12));

printf("%.2f\n",
       calculatePriorityScore(2, 7, 1, 48));

printf("%.2f\n",
       calculatePriorityScore(4, 0, 10, 4));
