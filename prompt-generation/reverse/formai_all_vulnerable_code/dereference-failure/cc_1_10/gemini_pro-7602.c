//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A curious data structure to store indexed elements
typedef struct IndexedElement {
    char *key;
    void *value;
    struct IndexedElement *next;
} IndexedElement;

// A curious data structure to store the index
typedef struct Index {
    char *key;
    IndexedElement *element;
} Index;

// Create a new index
Index *create_index(char *key) {
    Index *index = malloc(sizeof(Index));
    index->key = strdup(key);
    index->element = NULL;
    return index;
}

// Add an element to the index
void add_element_to_index(Index *index, char *key, void *value) {
    IndexedElement *element = malloc(sizeof(IndexedElement));
    element->key = strdup(key);
    element->value = value;
    element->next = index->element;
    index->element = element;
}

// Get an element from the index
void *get_element_from_index(Index *index, char *key) {
    IndexedElement *element = index->element;
    while (element != NULL) {
        if (strcmp(element->key, key) == 0) {
            return element->value;
        }
        element = element->next;
    }
    return NULL;
}

// Print the index
void print_index(Index *index) {
    IndexedElement *element = index->element;
    while (element != NULL) {
        printf("%s: %p\n", element->key, element->value);
        element = element->next;
    }
}

// Free the index
void free_index(Index *index) {
    IndexedElement *element = index->element;
    while (element != NULL) {
        IndexedElement *next = element->next;
        free(element->key);
        free(element);
        element = next;
    }
    free(index->key);
    free(index);
}

// A curious function to test the index
int main() {
    Index *index = create_index("name");
    add_element_to_index(index, "John", "Doe");
    add_element_to_index(index, "Jane", "Doe");
    add_element_to_index(index, "Bill", "Smith");
    add_element_to_index(index, "Alice", "Jones");

    printf("Index:\n");
    print_index(index);

    printf("Get element with key \"John\": %s\n", get_element_from_index(index, "John"));

    free_index(index);

    return 0;
}