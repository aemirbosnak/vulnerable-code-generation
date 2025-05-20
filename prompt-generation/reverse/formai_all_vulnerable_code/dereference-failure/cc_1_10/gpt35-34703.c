//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

typedef struct {
    Node* head;
    int size;
} Linked_list;

void add_element(Linked_list* list_ptr, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if(list_ptr->head == NULL){
        list_ptr->head = new_node;
    }
    else{
        Node* current_node = list_ptr->head;
        while(current_node->next != NULL){
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    list_ptr->size++;
}

void remove_element(Linked_list* list_ptr, int remove_data){
    if(list_ptr->head == NULL){
        return;
    }
    else if(list_ptr->head->data == remove_data){
        Node* temp = list_ptr->head;
        list_ptr->head = list_ptr->head->next;
        free(temp);
        list_ptr->size--;
    }
    else{
        Node* current_node = list_ptr->head;
        while(current_node->next != NULL && current_node->next->data != remove_data){
            current_node = current_node->next;
        }
        if(current_node->next != NULL){
            Node* temp = current_node->next;
            current_node->next = temp->next;
            free(temp);
            list_ptr->size--;
        }
    }
}

void print_list(Linked_list* list_ptr){
    Node* current_node = list_ptr->head;
    while(current_node != NULL){
        printf("%d->", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

int main(){
    Linked_list my_list = {NULL, 0};
    add_element(&my_list, 5);
    add_element(&my_list, 10);
    add_element(&my_list, 15);
    add_element(&my_list, 20);
    printf("Original List: ");
    print_list(&my_list);
    remove_element(&my_list, 10);
    printf("List after Removing 10: ");
    print_list(&my_list);
    remove_element(&my_list, 5);
    printf("List after Removing 5: ");
    print_list(&my_list);
    printf("Size of List: %d\n", my_list.size);
    return 0;
}