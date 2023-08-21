#include <stdio.h>
int rc = 0, r = 0, w = 0, mutex = 1;

void read()
{
    mutex--;
    rc++;
    r = 1;
    printf("Reading (%d) reading ....", rc);
    mutex++;
}
void write()
{
    mutex--;
    w = 1;
    printf("Writing (%d) writing ....", w);
    mutex++;
}
int main()
{
    int choice;
    do
    {
        printf("\n\n SELECT OPERATION\n-----------------------------\n1) Read\n2) Write\n3) delete last reader\n4) delete last writer\n5) Exit");
        printf("\n-----------------------------\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (mutex == 1 && w == 0)
                read();
            else
                printf("Cannot read, Already process is writing");
            break;
        case 2:
            if (mutex == 1 && r == 0 && w == 0)
                write();
            else
                printf("Cannot write, Already process is reading");
            break;
        case 3:
            if (rc > 1)
            {
                rc--;
                printf("Readers(%d)", rc);
            }
            else
            {
                r = 0;
                rc = 0;
                printf("Reader removed");
            }
            break;
        case 4:
            w = 0;
            printf("Writer removed");
            break;
        }

    } while (choice != 5);

    return 0;
}