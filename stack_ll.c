#include <stdio.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* head;
int pop();
void push(int);
int deleteend();
void insertend(int);
int main(){
    
    return 0;
}

void push(int val){
    insertend(val);
}
int pop(){
    return deleteend();
}
void insertend(int val){
    node* temp = malloc(sizeof(node));
    node* p = head;
    
   temp->data = val;
    temp->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}

int deleteend(){
    node*temp = head;
    node* q;
    while(temp->next!= NULL){
        q = temp;
        temp = temp->next;
    }
    q->next = NULL;
    int val = temp->data;
    free(temp);
    return val;
}