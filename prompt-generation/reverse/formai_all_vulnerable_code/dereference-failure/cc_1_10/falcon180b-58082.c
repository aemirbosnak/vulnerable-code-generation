//Falcon-180B DATASET v1.0 Category: Recursive ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

struct node {
    char *str;
    struct node *next;
};

struct node *head = NULL;

void push(char *str) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->str = str;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    }
    else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

char* pop() {
    if (head == NULL) {
        return NULL;
    }
    else {
        char *str = head->str;
        struct node *temp = head;
        head = head->next;
        free(temp);
        return str;
    }
}

void display() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->str);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    char str[MAX_SIZE];
    printf("Enter strings to push onto the stack:\n");
    while (scanf("%s", str)!= EOF) {
        push(strdup(str));
    }
    printf("Stack:\n");
    display();
    printf("Popped string: %s\n", pop());
    printf("Stack after popping:\n");
    display();
    return 0;
}