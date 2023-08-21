#include <stdio.h>
#define s 50

int main()
{
    int n, t[s], bt[s], st[s], wt[s], tat[s], p[s];
    float awt = 0.0, atat = 0.0;
    printf("Enter the number of Process : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Burst Time P%d : ", i + 1);
        scanf("%d", &bt[i]);
        printf("Priority Time P%d : ", i + 1);
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                int tempbt = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = tempbt;

                int tempP = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempP;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d\t", bt[i]);

    wt[0] = 0;
    tat[0] = bt[0];
    atat += bt[0];
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += wt[i] + bt[i];
    }
    printf("\nP\tAT\tBT\tPT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t0\t%d\t%d\t%d\t%d\n", i + 1, bt[i], p[i], wt[i], tat[i]);
    printf("\nAvg Waiting Time : %f\n", awt / n);
    printf("Avg TurnAround Time : %f", atat / n);
    return 0;
}