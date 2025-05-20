//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* email;
    char* name;
} Contact;

void add_contact(Contact** list, int* size, int* capacity, char* email, char* name) {
    if (*size >= *capacity) {
        int new_capacity = (*capacity == 0) ? 1 : *capacity * 2;
        Contact* new_list = (Contact*)realloc(*list, new_capacity * sizeof(Contact));
        if (new_list != NULL) {
            *list = new_list;
            *capacity = new_capacity;
        } else {
            printf("Error: failed to realloc\n");
            return;
        }
    }

    (*list)[*size].email = (char*)malloc(strlen(email) + 1);
    if ((*list)[*size].email != NULL) {
        strcpy((*list)[*size].email, email);
    } else {
        printf("Error: failed to malloc email\n");
        return;
    }

    (*list)[*size].name = (char*)malloc(strlen(name) + 1);
    if ((*list)[*size].name != NULL) {
        strcpy((*list)[*size].name, name);
    } else {
        printf("Error: failed to malloc name\n");
        free((*list)[*size].email);
        return;
    }

    (*size)++;
}

void remove_contact(Contact** list, int* size, char* email) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp((*list)[i].email, email) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: %s is not found\n", email);
        return;
    }

    free((*list)[index].email);
    free((*list)[index].name);

    for (int i = index; i < *size - 1; i++) {
        (*list)[i] = (*list)[i + 1];
    }

    (*size)--;
}

void print_list(Contact* list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", list[i].email, list[i].name);
    }
}

int main() {
    int capacity = 0;
    int size = 0;
    Contact* list = NULL;

    add_contact(&list, &size, &capacity, "alice@example.com", "Alice");
    add_contact(&list, &size, &capacity, "bob@example.com", "Bob");
    add_contact(&list, &size, &capacity, "charlie@example.com", "Charlie");
    print_list(list, size);

    remove_contact(&list, &size, "bob@example.com");
    print_list(list, size);

    return 0;
}