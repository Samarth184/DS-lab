bool isMatching(char a, char b){
    return a == '{' && b == '}' ||
        a == '(' && b == ')'||
        a == '[' && b == ']';
}

bool isValid(char * s){
    char stack[10000];
    int top =-1;
    
    for(int i =0; s[i] != '\0'; i++){
        if(s[i] == '('|| s[i] =='{'|| s[i] =='['){
            stack[++top] = s[i];
        }
        else {
            if(top == -1)
                return false;
            else if( isMatching(stack[top],s[i]))
                top --;
            else 
                return false;
        }
    }
    if(top == -1)
    return true;
    else
    return false;
}
