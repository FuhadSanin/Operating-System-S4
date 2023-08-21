#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sort(int a[20], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    // printf("Request are : ");
    // // for (int i = 0; i < n; i++)
    // //     printf("%d\t", a[i]);
}

void scan(int a[20], int n, int head)
{
    int pos, diff, seek, curr, i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == head)
        {
            pos = i;
            break;
        }
    }
    printf("\nTraversal order is :- \n");
    for (i = pos; i < n - 1; i++)
    {
        diff = abs(a[i + 1] - a[i]);
        seek += diff;
        printf("%d -> %d\n", a[i], a[i + 1]);
    }
    curr = i;
    for (i = pos - 1; i >= 0; i--)
    {
        diff = abs(a[curr] - a[i]);
        seek += diff;
        printf("%d -> %d\n", a[curr], a[i]);
        curr = i;
    }
    printf("\nSeek time is : %d\n", seek);
}

int main()
{
    int a[20], n, head;
    printf("Enter the no. of request : ");
    scanf("%d", &n);
    printf("Enter the head : ");
    scanf("%d", &head);
    a[0] = head;
    printf("Enter the request : ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[n + 1] = 199;
    n = n + 2;
    // for (int i = 0; i < n; i++)
    //     printf("%d\t", a[i]);
    sort(a, n);
    scan(a, n, head);
    return 0;
}