//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char* name;
    int type;
    bool is_array;
    int size;
    struct metadata* next;
} metadata;

void add_metadata(metadata** head, char* name, int type, bool is_array, int size) {
    metadata* new_metadata = (metadata*)malloc(sizeof(metadata));
    new_metadata->name = strdup(name);
    new_metadata->type = type;
    new_metadata->is_array = is_array;
    new_metadata->size = size;
    new_metadata->next = *head;
    *head = new_metadata;
}

void print_metadata(metadata* metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Type: ");
    switch(metadata->type) {
        case 1: printf("int\n"); break;
        case 2: printf("double\n"); break;
        case 3: printf("char*\n"); break;
        default: printf("unknown\n"); break;
    }
    printf("Is Array: %s\n", metadata->is_array? "Yes" : "No");
    printf("Size: %d\n", metadata->size);
    printf("\n");
}

int main() {
    metadata* head = NULL;

    add_metadata(&head, "age", 1, false, 0);
    add_metadata(&head, "name", 3, false, 0);
    add_metadata(&head, "grades", 1, true, 5);
    add_metadata(&head, "address", 3, false, 0);

    printf("Printing Metadata:\n");
    metadata* current = head;
    while(current!= NULL) {
        print_metadata(current);
        current = current->next;
    }

    return 0;
}