//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

int compare_entries(const void *a, const void *b) {
    const Entry *entry_a = a;
    const Entry *entry_b = b;
    return strcmp(entry_a->name, entry_b->name);
}

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char line[100];

    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ",");
        char *number = strtok(NULL, ",");

        if (name == NULL || number == NULL) {
            printf("Error: invalid entry in file.\n");
            exit(2);
        }

        strcpy(entries[num_entries].name, name);
        strcpy(entries[num_entries].number, number);
        num_entries++;
    }

    fclose(file);

    qsort(entries, num_entries, sizeof(Entry), compare_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s, %s\n", entries[i].name, entries[i].number);
    }

    return 0;
}