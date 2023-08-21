#include <stdio.h>
#define s 50

int main()
{
    int n, at[s], bt[s], st[s], wt[s], tat[s];
    float awt = 0.0, atat = 0.0;
    printf("Enter the number of Process : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Burst Time P%d : ", i + 1);
        scanf("%d", &bt[i]);
        printf("Arrival Time P%d : ", i + 1);
        scanf("%d", &at[i]);
    }
    st[0] = 0;
    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        st[i + 1] = st[i] + bt[i];
        wt[i] = st[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time : %f\n", awt / n);
    printf("Average TurnAround Time : %f\n", atat / n);
    return 0;
}