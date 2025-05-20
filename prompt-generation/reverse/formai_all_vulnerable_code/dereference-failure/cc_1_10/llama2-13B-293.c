//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024
#define MAX_OBJS 10

// Structure to represent a object
struct obj {
    void *data;
    size_t size;
    struct obj *next;
};

// Function to allocate memory for an object
void *obj_alloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return ptr;
}

// Function to deallocate memory for an object
void obj_free(void *ptr) {
    free(ptr);
}

// Function to create a linked list of objects
struct obj *obj_list_create() {
    struct obj *head = NULL;
    head = (struct obj *)obj_alloc(sizeof(struct obj));
    head->data = NULL;
    head->size = 0;
    head->next = NULL;
    return head;
}

// Function to add an object to the linked list
void obj_list_add(struct obj **list, void *data, size_t size) {
    struct obj *new = (struct obj *)obj_alloc(sizeof(struct obj));
    new->data = data;
    new->size = size;
    new->next = *list;
    *list = new;
}

// Function to remove the first object from the linked list
void obj_list_remove(struct obj **list) {
    if (*list != NULL) {
        struct obj *temp = *list;
        *list = temp->next;
        obj_free(temp);
    }
}

int main() {
    struct obj *list = obj_list_create();

    // Add some objects to the list
    void *data1 = "Hello, world!";
    size_t size1 = strlen(data1) + 1;
    obj_list_add(&list, data1, size1);

    void *data2 = "This is a test.";
    size_t size2 = strlen(data2) + 1;
    obj_list_add(&list, data2, size2);

    void *data3 = "Another test.";
    size_t size3 = strlen(data3) + 1;
    obj_list_add(&list, data3, size3);

    // Remove the first object from the list
    obj_list_remove(&list);

    // Print the remaining objects in the list
    struct obj *current = list;
    while (current != NULL) {
        printf("Object at address: %p\n", current);
        printf("Data: %s\n", current->data);
        printf("Size: %zu\n", current->size);
        current = current->next;
    }

    return 0;
}