//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 256

typedef struct {
    int id;
    char name[STR_SIZE];
    int age;
} Person;

typedef struct {
    int size;
    Person* data;
} PersonList;

/**
 * Compare function for binary search.
 */
int compare(int a, int b) {
    return a - b; // assume id is unique
}

/**
 * Insert a new Person into a sorted PersonList.
 */
void insert(PersonList* list, Person person) {
    int mid, left = 0, right = list->size - 1;

    if (list->data == NULL) {
        list->size = 1;
        list->data = malloc(sizeof(Person));
        *(list->data) = person;
        return;
    }

    // binary search for the correct position
    while (left <= right) {
        mid = (left + right) / 2;
        if (compare(list->data[mid].id, person.id) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // move data to make room for the new element
    list->size++;
    list->data = realloc(list->data, list->size * sizeof(Person));
    memmove(list->data + left + 1, list->data + left, (list->size - left - 1) * sizeof(Person));
    list->data[left] = person;
}

/**
 * Find a Person by id using binary search.
 * Returns NULL if not found.
 */
Person* find(PersonList* list, int id) {
    int mid, left = 0, right = list->size - 1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (compare(list->data[mid].id, id) == 0) {
            return &list->data[mid];
        } else if (compare(list->data[mid].id, id) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return NULL;
}

int main() {
    PersonList list = { .size = 0, .data = NULL };
    Person p1 = { .id = 1, .name = "Alice", .age = 20 };
    Person p2 = { .id = 3, .name = "Bob", .age = 30 };
    Person p3 = { .id = 2, .name = "Charlie", .age = 25 };

    insert(&list, p1);
    insert(&list, p2);
    insert(&list, p3);

    Person* found = find(&list, 2);
    if (found) {
        printf("Found person %s (%d)\n", found->name, found->age);
    } else {
        printf("Person not found\n");
    }

    free(list.data);
    return 0;
}