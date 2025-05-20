//FormAI DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void add_value_at_start(struct node **header, int value){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->value = value;
    temp->next = *header;
    *header = temp;
}

void delete_node(struct node **header, int value){
    struct node *temp = *header, *prev;
    if(temp != NULL && temp->value == value){
        *header = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->value != value){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void print_list(struct node *header){
    while(header != NULL){
        printf("%d ", header->value);
        header = header->next;
    }
    printf("\n");
}

int main(){
    struct node *header = NULL;
    
    add_value_at_start(&header, 5);
    add_value_at_start(&header, 4);
    add_value_at_start(&header, 3);
    add_value_at_start(&header, 2);
    add_value_at_start(&header, 1);
    
    printf("List before deletion:\n");
    print_list(header);
    
    delete_node(&header, 3);
    delete_node(&header, 1);
    
    printf("List after deletion:\n");
    print_list(header);
    
    return 0;
}