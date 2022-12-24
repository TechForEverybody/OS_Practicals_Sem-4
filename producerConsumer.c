#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int mutex = 1, full = 0, empty = 5, x = 0;

void producer()
{
    mutex = mutex - 1;
    full = full + 1;
    empty = empty - 1;
    x = x + 1;
    printf("\nmutex= %d", mutex);
    printf("\nfull= %d", full);
    printf("\nempty= %d", empty);
    printf("\nProducer produces item %d", x);
    mutex = mutex + 1;
}

void consumer()
{
    mutex = mutex - 1;
    full = full - 1;
    empty = empty + 1;
    printf("\nmutex= %d", mutex);
    printf("\nfull= %d", full);
    printf("\nempty= %d", empty);
    printf("\nConsumer consumes item %d", x);
    x = x - 1;
    mutex = mutex + 1;
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n1.for Producer\n2. for Consumer\n3.for Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
            {
                producer();
            }
            else
            {
                printf("Buffer is full!");
            }
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else
            {
                printf("Buffer is empty!");
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\ninvalid choice\n");
        }
    }
}
