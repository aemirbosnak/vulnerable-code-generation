//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Struct for linked list node
typedef struct node {
    void* data;
    size_t size;
    struct node* next;
} node_t;

// Linked list for memory management
node_t* head = NULL;

// Function to allocate memory and add to linked list
void* my_malloc(size_t size) {
    void* result = malloc(size);
    if (result == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = result;
    new_node->size = size;
    new_node->next = head;
    head = new_node;
    return result;
}

// Function to free memory and remove from linked list
void my_free(void* ptr) {
    node_t* curr_node = head;
    while (curr_node!= NULL) {
        if (curr_node->data == ptr) {
            free(curr_node->data);
            if (curr_node->next!= NULL) {
                curr_node->next = curr_node->next->next;
            } else {
                head = NULL;
            }
            free(curr_node);
            return;
        }
        curr_node = curr_node->next;
    }
    printf("Invalid pointer!\n");
}

int main() {
    char* str1 = my_malloc(20);
    char* str2 = my_malloc(30);
    char* str3 = my_malloc(40);

    strcpy(str1, "Hello, world!");
    strcpy(str2, "This is a test.");
    strcpy(str3, "The quick brown fox jumps over the lazy dog.");

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);

    my_free(str1);
    my_free(str2);
    my_free(str3);

    return 0;
}