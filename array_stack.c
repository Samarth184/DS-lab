#include <stdio.h>
#include <string.h>

int stack[20];
int top = -1, size = 20;

void push(int data);
int pop(void);
void display();

int main()
{
    int choice = 0;
    int data;

    do
    {   printf("Enter a choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number you want to push\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printf("The element popped is\n");
            printf("%d\n", pop());
            break;
        case 3:
            printf("The stack is\n");
            display();
            break;
        case 4:
            printf("exitting ......");
            break;
        }
        
    }while(choice != 4);

    return 0;
}

void push(int data)
{
    if (top >= size)
        printf("overflow");
    else
    {
        top++;
        stack[top] = data;
    }
}

int pop(void)
{
    if (top <= -1)
    {
        printf("underflow\n");
    }
    else
    {
        top--;
        return stack[top + 1];
    }
}

void display(void){
    int i=top;
    while(i>=-1){
        printf("%d \t", stack[i]);
        i--;
    }
}