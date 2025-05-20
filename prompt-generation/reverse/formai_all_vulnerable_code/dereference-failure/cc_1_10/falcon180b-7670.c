//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 10000

struct node{
    int data;
    int size;
    struct node **table;
};

typedef struct node Node;

Node *create_node(int data, int size){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->size = size;
    new_node->table = (Node **)malloc(size * sizeof(Node *));
    for(int i=0; i<size; i++)
        new_node->table[i] = NULL;
    return new_node;
}

void insert_data(Node *root, int data){
    Node *curr_node = root;
    while(curr_node->size > 1){
        int index = data % curr_node->size;
        curr_node = curr_node->table[index];
    }
    curr_node->data = data;
}

void search_data(Node *root, int data){
    Node *curr_node = root;
    int index;
    while(curr_node->size > 1){
        index = data % curr_node->size;
        curr_node = curr_node->table[index];
    }
    if(curr_node->data == data)
        printf("%d found\n", data);
    else
        printf("%d not found\n", data);
}

int main(){
    Node *root = create_node(1, MAX_SIZE);
    int choice, data;
    while(1){
        printf("1.Insert\n2.Search\n3.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_data(root, data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search_data(root, data);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}