//Falcon-180B DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

int top=-1;

char stack[MAX];

void push(char c)
{
    if(top==MAX-1)
        printf("\nStack Overflow");
    else
    {
        top++;
        stack[top]=c;
    }
}

char pop()
{
    char c;
    if(top==-1)
        printf("\nStack Underflow");
    else
    {
        top--;
        c=stack[top+1];
    }
    return c;
}

void display()
{
    if(top==-1)
        printf("\nStack is empty");
    else
    {
        printf("\nStack elements are: ");
        for(int i=top;i>=0;i--)
            printf("%c ",stack[i]);
    }
}

int main()
{
    char postfix[MAX],operand1,operand2,result;
    int i,j;
    printf("\nEnter a postfix expression: ");
    scanf("%s",postfix);

    for(i=0;postfix[i]!='\0';i++)
    {
        if(isalnum(postfix[i]))
        {
            push(postfix[i]);
        }
        else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
        {
            operand1=pop();
            operand2=pop();

            switch(postfix[i])
            {
                case '+':
                    result=operand1+operand2;
                    break;

                case '-':
                    result=operand1-operand2;
                    break;

                case '*':
                    result=operand1*operand2;
                    break;

                case '/':
                    result=operand1/operand2;
                    break;
            }

            push(result);
        }
    }

    result=pop();

    printf("\nThe result of the postfix expression is: %c",result);

    return 0;
}