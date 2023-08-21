#include <stdio.h>
#define s 10

int main()
{
    int bt[s], at[s], rt[s], n, remain, i, q, time, flag = 0;
    float awt = 0.0, atat = 0.0;
    printf("Enter the number of Process : ");
    scanf("%d", &n);
    remain = n;
    printf("Burst Time  : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter the Time Quantum : ");
    scanf("%d", &q);
    time = 0;
    for (i = 0; remain != 0;)
    {
        if (rt[i] <= q && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if (rt[i] > 0)
        {
            time += q;
            rt[i] -= q;
        }
        if (flag == 1 && rt[i] == 0)
        {
            remain--;
            awt += time - at[i] - bt[i];
            atat += time - at[i];
            flag = 0;
        }
        if (i == n - 1)
            i = 0;
        else if (at[i + 1] <= time)
            i++;
        else
            i=0;
    }
    printf("\nAvg Waiting time : %f", awt / n);
    printf("\nAvg TurnAround time : %f", atat / n);

    return 0;
}