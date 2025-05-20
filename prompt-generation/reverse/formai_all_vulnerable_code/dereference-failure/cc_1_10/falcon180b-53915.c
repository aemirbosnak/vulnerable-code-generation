//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 100

struct node{
    char name[MAX];
    int num;
    struct node *next;
};

struct node *top = NULL;

void push(char str[], int n){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name, str);
    newnode->num = n;
    newnode->next = NULL;
    if(top == NULL){
        top = newnode;
    }
    else{
        newnode->next = top;
        top = newnode;
    }
}

int pop(){
    char str[MAX];
    int n;
    struct node *temp = top;
    top = top->next;
    strcpy(str, temp->name);
    n = temp->num;
    free(temp);
    return n;
}

int isempty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(){
    int count = 0;
    struct node *temp = top;
    while(temp!= NULL){
        count++;
        temp = temp->next;
    }
    if(count == MAX){
        return 1;
    }
    else{
        return 0;
    }
}

void display(){
    struct node *temp = top;
    while(temp!= NULL){
        printf("%s %d\n", temp->name, temp->num);
        temp = temp->next;
    }
}

int main(){
    char str[MAX];
    int n, choice;
    do{
        printf("Enter the name of the component: ");
        scanf("%s", str);
        printf("Enter the number of components: ");
        scanf("%d", &n);
        push(str, n);
        printf("Do you want to add more components? (y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y' || choice == 'Y');
    printf("The components added are:\n");
    display();
    return 0;
}