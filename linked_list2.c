#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;
void insertbeg();
void insertend();
void insertbw();
void deleteend();
void deletebeg();
void deletebw();
void reverse();
void createLinkedList(int n);
void display();

node *head;
int main()
{
    
    int choice = 0;
    int n;
    
    printf("choice 1 : create queue\n");
    printf("choice 2 : Insert at the beginning\n");
    printf("choice 3 : Insert in between\n");
    printf("choice 4 : Insert in the end\n");
    printf("choice 5 : Delete at the beginning\n");
    printf("choice 6 : Delete in between\n");
    printf("choice 7 : Delete at the end\n");
    printf("choice 8 : Display elements in the linked list\n");
    printf("chocie 9: exit program\n");

    while (choice != 9)
    {   printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of elements required in the linked list\n");
            scanf("%d", &n);
            createLinkedList(n);
            break;
        case 2:
            insertbeg();
            break;
        case 3:
        insertbw();
            break;
        case 4:
        insertend();
            break;
        case 5:
            deletebeg();
            break;
        case 6:
            deletebw();
            break;
        case 7:
            reverse();
            break;
        case 8:
            display();
            break;
        case 9:
            printf("Exitting the program.......\n");
            break;
        default:
            printf("Enter valid choice\n");
            break;
        }
    }
}

void createLinkedList(int n){
    node* temp;
    for (int i = 0; i < n; i++){
        if(i == 0){
            temp = malloc(sizeof(node));
            head = temp;
        }
        else{
            temp->next = malloc(sizeof(node));
            temp = temp->next;
        }
        printf("Enter the data\n");
        scanf("%d", &temp->data);
    }
    temp->next = NULL;
   
}

void insertbeg(){
    node* p = malloc(sizeof(node));
    
    printf("Enter the value you want to insert:\n");
    scanf("%d", &p->data);
    p->next = head;
    head = p;
}

void insertend(){
    node* temp = malloc(sizeof(node));
    node* p = head;
    // node* q;
    printf("Enter the value you want to insert:\n");
    scanf("%d", &temp->data);
    temp->next = NULL;
    while (p->next != NULL)
    {
        // q = p;
        p = p->next;
    }
    p->next = temp;
}

void insertbw(){
    node* temp = malloc(sizeof(node));
    node* p = head;
    node* q;
    int n, count = 1;
    printf("Enter the position and the value you want to insert:\n");
    scanf("%d%d", &n, &temp->data);
    while(count != n && p != NULL){
        q = p;
        p = p->next;
        count++;
    }
    q->next = temp;
    temp->next = p;
    return;
}

void deletebeg(){
    node* temp = head;
    head = head->next;
    free(temp);
    printf("Success\n");
}

void deleteend(){
    node*temp = head;
    node* q;
    while(temp->next!= NULL){
        q = temp;
        temp = temp->next;
    }
    q->next = NULL;
    free(temp);
    printf("Success\n");
}
void deletebw(){
    node* temp = head;
    node* q;
    int n, count = 1;
    printf("Enter the position you want to delete:\n");
    scanf("%d", &n);
    while(count != n && temp != NULL){
        q = temp;
        temp = temp->next;
        count++;
    }
    q->next = temp-> next;
    free(temp);
    printf("Success\n");
}

void display(){
    node* temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

