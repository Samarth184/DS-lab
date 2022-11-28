#include <stdio.h>

int queue[10];
int rear = -1;
int front = -1;
int max = 10;

void insert(int);
int delete ();
void display();

int main()
{
    printf("choice 1 : Insert element to  queue\n");
    printf("choice 2 : Delete element from  queue\n");
    printf("choice 3 : Display element to  queue\n");
    printf("choice 4 : Exit program\n");

    int val;
    int opt;
    while (opt != 4)
    {
        printf("Enter your choice\n");

        scanf("%d", &opt);
        {
            switch (opt)
            {
            case 1:
                printf("Enter the value you want to  insert\n");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("The element deleted was %d\n", delete ());
                break;
            case 3:
                printf("The elements present are:\n");
                display();
                break;
            case 4:
                printf("Exiting the queue program.....\n");
                break;
            default:
                printf("Enter valid choice\n");
                break;
            }
        }
    }

    return 0;
}

void insert(int val)
{
    if (rear == max - 1)
        printf("Overlfow\n");
    else if (rear == -1 && front == -1)
    {
        front++;
        queue[++rear] = val;
    }
    else
        queue[++rear] = val;
}

int delete ()
{
    if (front == rear)
        printf("Underflow\n");
    else
    {
        front++;
        return queue[front];
    }
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d\n", queue[i]);
    }
}