#include <stdio.h>
#include <unistd.h>

int main()
{
    int i, n, odd = 0, pid, even = 0;
    printf("Enter the limit : ");
    scanf("%d", &n);
    int val = fork();
    if (val == 0)
    {
        pid = getppid();
        for (i = 0; i < n; i = i + 2)
            even += i;
        printf("Sum of even : %d\n", even);
        printf("Child Parent id: %d\n", pid);
    }
    else
    {
        pid = getpid();
        for (i = 1; i < n; i = i + 2)
            odd += i;
        printf("Sum of odd : %d\n", odd);
        printf("Parent id: %d\n", pid);
    }
    return 0;
}
