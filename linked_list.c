#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node* next;
} node;
void insert();
// node* createLinkedList(int n);
void display();
node *head;
int main()
{
    
    int choice = 0;
    int n;

    printf("choice 1 : create queue\n");
    printf("choice 2 : Display elements in the linked list\n");
    printf("chocie 3: exit program\n");

    while (choice != 3)
    {   printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:insert();
            // printf("Enter the number of elements required in the linked list\n");
            // scanf("%d", &n);
            // head = createLinkedList(n);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Exitting the program.......\n");
            break;
        default:
            printf("Enter valid choice\n");
            break;
        }
    }
    return 0;
}


void insert(){
    node* temp;
    temp = malloc(sizeof(node));
    printf("enter the value\n");
    scanf("%d", &temp-> number);
    temp-> next = head;
    head = temp;
}


// node* createLinkedList(int n)
// {
//     node* head1;
//     node* temp;
//     int count = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0)
//         {
//             temp = (node*) malloc(sizeof(node));
//             head = temp;
//         }
//         else
//         {
//             temp->next = (node*)malloc(sizeof(node));
            
//         }
//         printf("Enter the data for element %d\n", count++);
//         scanf("%d", & temp->number);
//     }

//     temp->next = NULL;

//     return head1;
// }

void display()
{
    node* temp = head;
    int count = 1;
    printf(".");
    while (temp->next != NULL)
    {
        printf("Node %d: Number = %d\n", count++, temp->number);
        temp = temp-> next;
    }
}