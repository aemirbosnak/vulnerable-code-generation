//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node{
    char* key;
    char* value;
    struct node* next;
};

struct node* newNode(char* key, char* value){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

void addNode(struct node** head, char* key, char* value){
    struct node* node = *head;
    while(node!= NULL){
        if(strcmp(node->key, key) == 0){
            free(node->value);
            node->value = strdup(value);
            return;
        }
        node = node->next;
    }
    node = newNode(key, value);
    node->next = *head;
    *head = node;
}

void printList(struct node* node){
    while(node!= NULL){
        printf("%s: %s\n", node->key, node->value);
        node = node->next;
    }
}

int main(){
    FILE* fp;
    char line[1024];
    char* token;
    char* key;
    char* value;
    struct node* head = NULL;

    fp = fopen("metadata.txt", "r");
    if(fp == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    while(fgets(line, sizeof(line), fp)!= NULL){
        token = strtok(line, ":");
        key = strdup(token);
        value = strdup(strtok(NULL, "\n"));
        addNode(&head, key, value);
    }

    fclose(fp);
    printList(head);

    return 0;
}