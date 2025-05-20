//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node{
    char name[20];
    struct node *next;
};

struct node *head = NULL;

void add_to_list(struct node *node){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(temp->name, "name");
    temp->next = NULL;
    node->next = temp;
}

void print_list(){
    struct node *temp = head;
    if(temp == NULL){
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while(temp!= NULL){
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

void search_list(char *name){
    struct node *temp = head;
    if(temp == NULL){
        printf("List is empty.\n");
        return;
    }
    while(temp!= NULL){
        if(strcmp(temp->name, name) == 0){
            printf("Found '%s' in list.\n", name);
            return;
        }
        temp = temp->next;
    }
    printf("'%s' not found in list.\n", name);
}

void delete_from_list(char *name){
    struct node *temp = head;
    if(temp == NULL){
        printf("List is empty.\n");
        return;
    }
    while(temp!= NULL){
        if(strcmp(temp->name, name) == 0){
            struct node *prev = temp->next;
            free(temp);
            temp = prev;
            return;
        }
        temp = temp->next;
    }
    printf("'%s' not found in list.\n", name);
}

int main(){
    srand(time(NULL));
    struct node *node = (struct node*)malloc(sizeof(struct node));
    if(node == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }
    for(int i = 0; i < 10; i++){
        strcpy(node->name, "name");
        add_to_list(node);
        node = node->next;
    }
    print_list();
    sleep(1);
    printf("\n");
    search_list("name");
    sleep(1);
    printf("\n");
    delete_from_list("name");
    print_list();
    return 0;
}