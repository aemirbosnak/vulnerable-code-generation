//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: active
#include <stdlib.h>
#include <stdio.h>

// A custom memory allocator that tracks allocations and warns of leaks.
typedef struct {
    void* ptr;
    size_t size;
} Allocation;

static Allocation* allocations = NULL;
static size_t allocation_count = 0;

void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Out of memory!\n");
        return NULL;
    }

    Allocation* allocation = realloc(allocations, sizeof(Allocation) * (allocation_count + 1));
    if (allocation == NULL) {
        fprintf(stderr, "Failed to allocate memory for allocation tracking!\n");
        free(ptr);
        return NULL;
    }

    allocations = allocation;
    allocations[allocation_count].ptr = ptr;
    allocations[allocation_count].size = size;
    allocation_count++;

    return ptr;
}

void my_free(void* ptr) {
    int found = 0;
    for (size_t i = 0; i < allocation_count; i++) {
        if (allocations[i].ptr == ptr) {
            free(ptr);
            allocations[i] = allocations[allocation_count - 1];
            allocation_count--;
            found = 1;
            break;
        }
    }

    if (!found) {
        fprintf(stderr, "Attempted to free unallocated memory!\n");
    }
}

// A simple linked list implementation.
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node with the given data.
Node* create_node(int data) {
    Node* node = (Node*)my_malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert a new node with the given data at the end of the linked list.
void insert_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

// Print the linked list.
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Free the linked list.
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        my_free(current);
        current = next;
    }
}

// The main function.
int main() {
    // Create a linked list of numbers from 1 to 10.
    Node* head = NULL;
    for (int i = 1; i <= 10; i++) {
        insert_node(&head, i);
    }

    // Print the linked list.
    print_list(head);

    // Free the linked list.
    free_list(head);

    // Check for memory leaks.
    if (allocation_count > 0) {
        fprintf(stderr, "Memory leak detected! %zu allocations not freed.\n", allocation_count);
        for (size_t i = 0; i < allocation_count; i++) {
            fprintf(stderr, "   - %p (%zu bytes)\n", allocations[i].ptr, allocations[i].size);
        }
    }

    // Free the memory tracking data.
    my_free(allocations);

    return 0;
}