#include<stdio.h>
#include<ctype.h>
#include<string.h>

int priority_checker(char);
void infix_to_postfix(char start[], char target[]);
void push(char stack[],char data);
char pop();

int size;

    char stack[100];
    int top=-1;

int main(){
    char infix[100], postfix[100];
    size = 100;
    printf("Enter the infix expression\n");
    gets(infix);
    infix_to_postfix(infix, postfix);
    return 0;
}

int priority_checker(char val){
    if(val == '*'||'/'||'%')
        return 1;
    else if(val == '+'|| '-')
        return 0;
}

void infix_to_postfix(char start[], char target[]){
    int temp;
    // strcpy(target, "0");
    int i=0, j=0;
    while(start[i]!= '\0'){
        if(isalpha(start[i]) ||isdigit(start[i])){
                target[j] = start[i];
                i++;
                j++;

                printf("%d %d %d\t", i, j, top);
        }
        else if(start[i] == '('){
            push(stack, start[i]);
            i++;
            printf("%d %d %d\t", i, j, top);
        }
        else if(start[i] == ')'){
            while(stack[i] != '('&& top != -1){
                target[j] = pop();
                j++;
            }
            top--;
            i++;
            printf("%d %d %d\t", i, j, top);
        }
        else if(start[i] == '+'||'-'||'*'||'/'||'%'){
            while(priority_checker(stack[top]) >= priority_checker(start[i]) && top!=-1){
            //    if(stack[top] == '('){
            //         temp =pop();
            //    }
                // else{
                    target[j] = pop();
                    j++;
                // }
                
            }
            push(stack, start[i]);
            // printf(" %c ", stack[top]);
            i++;
            // printf("%d %d %d\t", i, j, top);
        }
        else
            printf("Enter correct expression\n");
    }
    
    while(top>-1 ){
        target[j] = pop(stack);
        printf(" %d  ", top);
        j++;
    }
    target[j] = '\0';
    printf("%d %d %d\t", i, j, top);
    puts(target);
}


void push(char stack[], char val){
    if(top> size-1)
        printf("Overlfow\n");
    else{
        top++;
        stack[top] = val;
    }
}

char pop(){
    if(top <=-1)
        printf("Underflow\n");
    else{
        top--;
        return stack[top+1];
    }
}