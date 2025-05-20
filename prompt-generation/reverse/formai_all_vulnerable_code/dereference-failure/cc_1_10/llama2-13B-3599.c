//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LEN 256
#define MAX_PHONE_LEN 64
#define MAX_ADDRESS_LEN 256

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char address[MAX_ADDRESS_LEN];
} person_t;

#define LIST_INITIAL_SIZE 10
#define LIST_GROW_FACTOR 2

struct list_t {
    person_t* data;
    size_t size;
    size_t capacity;
};

void list_init(struct list_t* list) {
    list->data = NULL;
    list->size = 0;
    list->capacity = LIST_INITIAL_SIZE;
}

void list_add(struct list_t* list, const char* name, const char* phone, const char* address) {
    if (list->size == list->capacity) {
        list->capacity *= LIST_GROW_FACTOR;
        list->data = realloc(list->data, sizeof(person_t) * list->capacity);
    }
    list->data[list->size] = (person_t) {
        .name = name,
        .phone = phone,
        .address = address
    };
    list->size++;
}

void list_print(struct list_t* list) {
    for (size_t i = 0; i < list->size; i++) {
        printf("%s %s %s\n", list->data[i].name, list->data[i].phone, list->data[i].address);
    }
}

int main() {
    struct list_t list;
    list_init(&list);

    list_add(&list, "Alice", "555-1234", "123 Main St");
    list_add(&list, "Bob", "555-5678", "456 Elm St");
    list_add(&list, "Charlie", "555-9012", "789 Oak St");

    list_print(&list);

    return 0;
}