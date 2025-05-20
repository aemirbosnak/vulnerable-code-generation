//FormAI DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int key;
    char name[20];
    struct node *next;
};

struct index_node {
    int key;
    struct node *data;
};

int hash(int key) {
    return key % 10;
}

void add_to_index(struct index_node *index, struct node *data) {
    int key = hash(data->key);
    if(index[key].data == NULL) {
        index[key].key = key;
        index[key].data = data;
    } else {
        struct node *current = index[key].data;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = data;
    }
}

void display(struct index_node *index) {
    for(int i = 0; i < 10; i++) {
        printf("Index %d: ", index[i].key);
        if(index[i].data == NULL) {
            printf("NULL\n");
        } else {
            struct node *current = index[i].data;
            while(current != NULL) {
                printf("(%d, %s) -> ", current->key, current->name);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    struct index_node *index = (struct index_node *) malloc(sizeof(struct index_node) * 10);

    struct node *node1 = (struct node *) malloc(sizeof(struct node));
    node1->key = 5;
    strcpy(node1->name, "John");
    node1->next = NULL;

    struct node *node2 = (struct node *) malloc(sizeof(struct node));
    node2->key = 10;
    strcpy(node2->name, "Jane");
    node2->next = NULL;

    struct node *node3 = (struct node *) malloc(sizeof(struct node));
    node3->key = 22;
    strcpy(node3->name, "Tim");
    node3->next = NULL;

    add_to_index(index, node1);
    add_to_index(index, node2);
    add_to_index(index, node3);

    display(index);

    return 0;
}