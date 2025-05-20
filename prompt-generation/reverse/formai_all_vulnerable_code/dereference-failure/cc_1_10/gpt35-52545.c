//FormAI DATASET v1.0 Category: Memory management ; Style: Cryptic
// Initializing the program for Memory Management
#include <stdio.h>
#include <stdlib.h>

// Defining the basic structure for the memory pointer
typedef struct node {
    void* ptr;
    int size;
    struct node* next;
} Memory_Node;

// Defining the global variables to start managing the memory
Memory_Node* head = NULL;
Memory_Node* tail = NULL;

// Function to allocate memory for the program
void* cryptic_malloc(int bytes) {
    Memory_Node* temp = (Memory_Node*)malloc(sizeof(Memory_Node));
    if (temp == NULL) {
        return NULL;
    }
    temp->ptr = malloc(bytes);
    if (temp->ptr == NULL) {
        free(temp);
        return NULL;
    }
    temp->size = bytes;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    return temp->ptr;
}

// Function to free the memory allocated previously
void cryptic_free(void* ptr) {
    Memory_Node *current = head, *previous = NULL;
    while (current) {
        if (current->ptr == ptr) {
            if (previous) {
                previous->next = current->next;
            }
            else {
                head = current->next;
            }
            if (current == tail) {
                tail = previous;
            }
            free(current->ptr);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to reallocation memory space 
void* cryptic_realloc(void* ptr, int bytes) {
    Memory_Node *current = head;
    while (current) {
        if (current->ptr == ptr) {
            void* new_ptr = malloc(bytes);
            if (new_ptr == NULL) {
                return NULL;
            }
            int copy_bytes = bytes > current->size ? current->size : bytes;
            memcpy(new_ptr, current->ptr, copy_bytes);
            cryptic_free(current->ptr);
            current->ptr = new_ptr;
            current->size = bytes;
            return current->ptr;
        }
        current = current->next;
    }
    return NULL;
}

// Main function to test the memory management of this program
int main() {
    char* str = cryptic_malloc(10 * sizeof(char));
    if (str == NULL) {
        printf("Error: Unable to allocate memory\n");
        return 0;
    }
    strcpy(str, "Cryptic");

    printf("The string is %s\n", str);
    cryptic_realloc(str, 20 * sizeof(char));
    strcat(str, " Memory Management");
    printf("The string now is %s\n", str);
    cryptic_free(str);

    return 0;
}