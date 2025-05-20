//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int operand;
    char operator;
    struct node *next;
};

struct node *createNode(int operand, char operator)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->operand = operand;
    node->operator = operator;
    node->next = NULL;
    return node;
}

struct node *insertOperator(struct node *head, char operator)
{
    struct node *temp = head;
    while(temp->next!= NULL && temp->next->operator!= '(')
    {
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        temp->next = createNode(0, operator);
    }
    else if(temp->next->operator == '(')
    {
        temp->next = createNode(0, operator);
        temp = temp->next;
    }
    return head;
}

void calculate(struct node *head, int operand)
{
    int carry = 0;
    struct node *temp = head;
    while(temp!= NULL)
    {
        int result = (temp->operand + carry);
        carry = 0;
        if(result >= 10)
        {
            carry = 1;
            result -= 10;
        }
        temp->operand = result;
        temp = temp->next;
    }
    if(carry > 0)
    {
        struct node *newNode = createNode(carry, '*');
        temp = newNode;
        while(temp->next!= NULL && temp->next->operator!= '(')
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printResult(struct node *head)
{
    while(head!= NULL)
    {
        if(head->operator == '*')
        {
            printf("%d", head->operand);
        }
        else
        {
            printf("%d", head->operand);
            if(head->next!= NULL && head->next->operator == '*')
            {
                printf(" * ");
                printResult(head->next->next);
            }
        }
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    head = insertOperator(head, '+');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '/');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '+');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '/');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '+');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '+');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '/');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '+');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '+');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '+');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '^');
    head = insertOperator(head, '*');
    head = insertOperator(head, '+');
    calculate(head, 9);
    printResult(head);
    return 0;
}