//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

/* defining a structure to hold each element of the data structure */
struct element{
    int value; /* Value */
    struct element* next; /* Pointer to the next element in the list */
};

/* defining the data structure */
struct list{
    struct element* head; /* Pointer to the head element of the list */
    int length; /* Length of the list */
};

/* Function to create a new element with given value */
struct element* create_element(int value){
    struct element* new_element = (struct element*) malloc(sizeof(struct element)); /* Allocating memory to the new element */
    new_element->value = value; /* Setting the value of the new element */
    new_element->next = NULL; /* Setting the next pointer of the new element to NULL */
    
    return new_element; /* Returning the new element */
}

/* Function to create a new list */
struct list* create_list(){
    struct list* new_list = (struct list*) malloc(sizeof(struct list)); /* Allocating memory to the new list */
    new_list->head = NULL;
    new_list->length = 0;
    
    return new_list;
}

/* Function to add an element to the list */
void add_element(struct list* list, int value){
    struct element* new_element = create_element(value); /* Creating a new element with the given value */
    
    if(list->length == 0){ /* If the list is empty, new element becomes the head */
        list->head = new_element;
    }
    else{
        struct element* current = list->head; /* Starting from the head */
        
        /* Traversing the list until we reach the end */
        while(current->next != NULL){
            current = current->next;
        }
        
        current->next = new_element; /* Adding the new element to the end of the list */
    }
    
    list->length++; /* Incrementing the length of the list */
}

/* Function to display the elements of the list */
void display_list(struct list* list){
    struct element* current = list->head; /* Starting from the head */
    
    printf("\n-------------Linked List-------------\n");
    
    /* Traversing the list and printing each element */
    while(current != NULL){
        printf("%d -> ", current->value);
        current = current->next;
    }
    
    printf("NULL\n------------------------------------");
}

/* Main function */
int main(){
    struct list* my_list = create_list(); /* Creating a new list */
    
    add_element(my_list, 5); /* Adding some elements to the list */
    add_element(my_list, 3);
    add_element(my_list, 7);
    add_element(my_list, 4);
    
    display_list(my_list); /* Displaying the list */
    
    return 0;
}