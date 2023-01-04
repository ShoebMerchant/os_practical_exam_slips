#include <stdio.h>
#define MAX 30
int main()
{
    int i, j, n, t, p[MAX], bt[MAX], wt[MAX], tat[MAX];
    float awt = 0, atat = 0, swt = 0, stat = 0;

    printf("Enter the number of processes : ");
    scanf("%d", &n);

    printf("Enter the Process : ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter the Burst Time : ");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    // Sort Processes on burst time - bubble sort
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }

    printf("process \t burst time \t waiting time \t turn around time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        swt = swt + wt[i];
        stat = stat + tat[i];
        printf("%d\t %d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }
    awt = swt / n;
    atat = stat / n;
    printf("Average waiting time %f\n", awt);
    printf("Average Turn arounf time %f\n", atat);
}