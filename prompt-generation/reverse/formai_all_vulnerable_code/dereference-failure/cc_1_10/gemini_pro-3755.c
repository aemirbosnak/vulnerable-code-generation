//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* number;
} pb_entry;

pb_entry* pb;
int pb_size = 0;

void pb_add(char* name, char* number) {
    pb_size++;
    pb = realloc(pb, pb_size * sizeof(pb_entry));
    pb[pb_size - 1].name = name;
    pb[pb_size - 1].number = number;
}

void pb_print() {
    for (int i = 0; i < pb_size; i++) {
        printf("%s: %s\n", pb[i].name, pb[i].number);
    }
}

void pb_search(char* name) {
    for (int i = 0; i < pb_size; i++) {
        if (strcmp(pb[i].name, name) == 0) {
            printf("%s: %s\n", pb[i].name, pb[i].number);
            return;
        }
    }
    printf("Not found\n");
}

int main() {
    pb_add("John Doe", "555-1212");
    pb_add("Jane Doe", "555-1213");
    pb_add("John Smith", "555-1214");
    pb_add("Jane Smith", "555-1215");

    pb_print();

    pb_search("John Doe");
    pb_search("Jane Doe");
    pb_search("John Smith");
    pb_search("Jane Smith");
    pb_search("Not found");

    return 0;
}