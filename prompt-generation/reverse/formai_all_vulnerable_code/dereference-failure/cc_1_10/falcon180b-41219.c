//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

//Node structure for the surrealist database
struct surrealist_node{
    int data;
    int index;
    struct surrealist_node* next;
};

struct surrealist_node* head = NULL;
int size = 0;

void surrealist_insert(int data){
    struct surrealist_node* new_node = (struct surrealist_node*)malloc(sizeof(struct surrealist_node));
    new_node->data = data;
    new_node->index = size;
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
    }else{
        struct surrealist_node* temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    size++;
}

void surrealist_delete(int data){
    struct surrealist_node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            struct surrealist_node* next_node = temp->next;
            free(temp);
            temp = next_node;
        }else{
            temp = temp->next;
        }
    }
}

void surrealist_search(int data){
    struct surrealist_node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            printf("%d is found at index %d\n", data, temp->index);
        }
        temp = temp->next;
    }
}

int surrealist_index(int data){
    struct surrealist_node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            return temp->index;
        }
        temp = temp->next;
    }
    return -1;
}

int surrealist_size(){
    return size;
}

int main(){
    surrealist_insert(5);
    surrealist_insert(10);
    surrealist_insert(15);

    surrealist_search(5);
    surrealist_search(20);

    surrealist_delete(10);

    printf("Size of surrealist database is %d\n", surrealist_size());

    return 0;
}