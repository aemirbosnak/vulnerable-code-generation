//FormAI DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>

/* Struct to keep track of allocated memory blocks */
typedef struct Node {
    void *ptr;
    struct Node *next;
} Node;

Node *head = NULL;  // Head of the list

/* Allocates memory and adds to the list */
void *myAlloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    Node *node = malloc(sizeof(Node));
    node->ptr = ptr;
    node->next = head;
    head = node;
    printf("Allocated %zu bytes at %p\n", size, ptr);
    return ptr;
}

/* Frees memory and removes from the list */
void myFree(void *ptr) {
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL) {
        if (curr->ptr == ptr) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr->ptr);
            free(curr);
            printf("Freed memory at %p\n", ptr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Error: Invalid pointer\n");
    exit(1);
}

int main() {
    int *ptr1 = myAlloc(sizeof(int));  // Allocate memory for an integer
    int *ptr2 = myAlloc(sizeof(int));  // Allocate memory for an integer
    float *ptr3 = myAlloc(sizeof(float));  // Allocate memory for a float
    char *ptr4 = myAlloc(10 * sizeof(char));  // Allocate memory for an array of characters
    
    *ptr1 = 42;  // Write to allocated memory
    *ptr2 = *ptr1 + 1;  // Write to allocated memory
    *ptr3 = 3.14;  // Write to allocated memory
    sprintf(ptr4, "Hello");  // Write to allocated memory
    
    printf("%d\n%d\n%f\n%s\n", *ptr1, *ptr2, *ptr3, ptr4);  // Read from allocated memory
    
    myFree(ptr1);  // Free allocated memory
    myFree(ptr2);  // Free allocated memory
    myFree(ptr3);  // Free allocated memory
    myFree(ptr4);  // Free allocated memory
    
    return 0;
}