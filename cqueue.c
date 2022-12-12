#include<stdio.h>
#define MAX 3

int cqueue[MAX];
int rear=-1;
int front=-1;

int delete();
void insert(int val);
void display();
int main(){
    int choice = 0;
    int val;

    printf("choice 1 : Insert element to  queue\n");
    printf("choice 2 : Delete element from  queue\n");
    printf("choice 3 : Display elements in the  queue\n");
    printf("choice 4 : Exit program\n");
    

    while(choice != 4){
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number you want to insert into the circular queue\n");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            printf("The number deleted was %d\n", delete());
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Enter valid choice \n");
            break;
        }
    }
        
    return 0;
}

void insert(int val){
    if(front == (rear+1)%MAX){
    printf("overflow\n");
    }
    else if(front == MAX -1 && front!=0 ){
        rear = 0;
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
    }
    else
    rear++;

    cqueue[rear] = val;
}

int delete(){
    if(front == rear)
    printf("Queue is empty");
    else
    return cqueue[front--];
}

void display()
{
    for (int i = front; i != rear; i= (i + 1) % MAX)
    {
        printf("%d\n", cqueue[i]);
    }
}