#include <stdio.h>
#define s 50
int main()
{
    int n, b[s], sb[s], c[s][s], t[s], f;
    printf("Enter the number of files : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("No. of blocks %d: ", i + 1);
        scanf("%d", &b[i]);
        printf("Enter Starting block %d: ", i + 1);
        scanf("%d", &sb[i]);
        t[i] = sb[i];
        for (int j = 0; j < b[i]; j++)
            c[i][j] = sb[i]++;
    }
    printf("\nFileName\tStarting Block\tLength\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\n", i + 1, t[i], b[i]);

    printf("\n\nEnter the FileName : ");
    scanf("%d", &f);
    printf("\nFile Length : %d", b[f - 1]);
    printf("\nBlock allocated : ");
    for (int i = 0; i < b[f - 1]; i++)
        printf("%d\t", c[f - 1][i]);

    return 0;
}