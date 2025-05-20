//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *number;
} entry;

entry *phonebook = NULL;
int size = 0;

void add(char *name, char *number) {
    phonebook = realloc(phonebook, sizeof(entry) * (size + 1));
    phonebook[size].name = strdup(name);
    phonebook[size].number = strdup(number);
    size++;
}

void find(char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("Not found\n");
}

void list() {
    for (int i = 0; i < size; i++) {
        printf("%s %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    char buffer[1024];
    while (1) {
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);
        char *command = strtok(buffer, " ");
        if (strcmp(command, "add") == 0) {
            char *name = strtok(NULL, " ");
            char *number = strtok(NULL, " ");
            add(name, number);
        } else if (strcmp(command, "find") == 0) {
            char *name = strtok(NULL, " ");
            find(name);
        } else if (strcmp(command, "list") == 0) {
            list();
        } else if (strcmp(command, "quit") == 0) {
            break;
        }
    }
    for (int i = 0; i < size; i++) {
        free(phonebook[i].name);
        free(phonebook[i].number);
    }
    free(phonebook);
    return 0;
}