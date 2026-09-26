#include <stdio.h>
#include "priority.h"

int main()
{
    printf("Importance Score Tests\n");

    printf("Importance 1 = %.2f\n", calculateImportanceScore(1));
    printf("Importance 3 = %.2f\n", calculateImportanceScore(3));
    printf("Importance 5 = %.2f\n", calculateImportanceScore(5));

    printf("\nUrgency Score Tests\n");

    printf("2 days remaining = %.2f\n", calculateUrgencyScore(2));
    printf("1 day remaining = %.2f\n", calculateUrgencyScore(1));
    printf("0 days remaining = %.2f\n", calculateUrgencyScore(0));

    printf("\nLead-Time Risk Tests\n");

    printf("30 min / 48 hours = %.2f\n",
           calculateLeadTimeRisk(0.5, 48));

    printf("6 hours / 12 hours = %.2f\n",
           calculateLeadTimeRisk(6, 12));

    printf("6 hours / 4 hours = %.2f\n",
           calculateLeadTimeRisk(6, 4));

    return 0;
}
