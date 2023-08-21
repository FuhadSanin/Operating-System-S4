#include <stdio.h>
#define s 50
int main()
{
    int n, m, alloc[s][s], max[s][s], avail[s], need[s][s], finish[s], i, j, k, x, flag, ind = 0, safe[s];
    printf("Enter the no. process : ");
    scanf("%d", &n);
    printf("Enter the no. resources : ");
    scanf("%d", &m);
    // allocation matrix
    printf("Allocation matrix : ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }
    // max matrix
    printf("Max matrix : ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }
    // need matrix
    printf("Need Matrix : ");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d\t", need[i][j]);
        }
    }
    // available matrix
    printf("\nAvailable Matrix : ");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);
    for (i = 0; i < n; i++)
        finish[i] = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {

            if (finish[i] == 0)
            {
                flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    safe[ind++] = i;
                    for (x = 0; x < m; x++)
                        avail[x] += alloc[i][x];
                    finish[i] = 1;
                }
            }
        }
    }
    printf("Safe Sequence : ");
    for (i = 0; i < n; i++)
        printf("P%d\t", safe[i]);

    return 0;
}