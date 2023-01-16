#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
} node;


void insert_beg(int);
void insert_end(int);
void insert_bw(int,int);
void delete_beg();
void delete_end();
void delete_bw(int);
void display();

node* head = NULL;

int main(){
    int choice=0;
    int val=0;
    printf("choose an option\n");
    printf("1.Insert beg\n2.Insert end\n3.Insert between\n4.Delete beg\n5.Delete end\n6.Delete between\n7.Display\n8.EXIT\n");
    
    while(choice !=8){
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enter the value to be inserted\n");
                scanf("%d",&val);
                insert_beg(val);
                break;
            case 2:printf("enter the value to be inserted\n");
                scanf("%d",&val);
                insert_end(val);
                break;
            case 3:printf("enter the value to be inserted and the position to be inserted after\n");
                int pos;
                scanf("%d %d",&val, &pos);
                insert_bw(pos,val);
                break;
            case 4:printf("deleting at the beginning\n");
                delete_beg();
                break;
            case 5:printf("deleting at the end\n");
                delete_end();
                break;
            case 6:printf("enter the value to be deleted\n");
                scanf("%d",&val);
                delete_bw(val);
                break;
            case 7:display();
                printf("\n");
                break;
            case 8:printf("Exitting the program\n");
                break;
            default:
                printf("Enter a valid choice\n");
                break;
        }
    }
    return 0;
}

void insert_beg(int val){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->prev = NULL;
    if(head == NULL){
        head= newNode;
        newNode->next = NULL;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    newNode->data = val;
}

void insert_end(int val){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->next = NULL;
    if(head==NULL){
        head= newNode;
        newNode->prev = NULL;
    }
    else{
        node* temp = head;
        while(temp->next != NULL)
        temp = temp->next;

        newNode->prev = temp;
        temp->next = newNode;
    }
    newNode->data = val;
}

void insert_bw(int pos, int val){
    node* newNode = (node*) malloc(sizeof(node));
    if(head == NULL){
        head= newNode;
        newNode->prev = NULL;
    }
    else{
        node* temp = head;
        while(temp->data != pos &&temp->next != NULL)
        temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp->next->prev;
        temp->next->prev = newNode;
        temp->next = newNode;

    }
    newNode->data = val;
}

void delete_end(){
    node* temp = head;
    if(head== NULL){
        printf("List is empty cannot delete\n");
        return;
    }
    else if(temp->next == NULL){
        head = NULL;
        free(temp);
    }
    else{
        while(temp->next != NULL)
        temp = temp->next;

        temp->prev->next = NULL;
        free(temp);
    }
}

void delete_beg(){
    node* temp = head;
    if(head==NULL){
           printf("List is empty cannot delete\n");
        return;
    }
    else if(temp->next == NULL){
        head = NULL;
        free(temp);
    }
    else{
        head = temp->next;
        free(temp);
    }
    
}

void delete_bw(int pos){
     node* temp = head;
    if(head==NULL){
           printf("List is empty cannot delete\n");
        return;
    }
    else if(temp->next == NULL){
        head = NULL;
        free(temp);
    }
    else{
        while(temp->data != pos &&temp->next != NULL)
        temp = temp->next;

        if(temp->data == pos){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
        
    }
}

void display(){
    node* temp = head;
    while(temp != NULL){
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}