//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct Entry {
    char name[50];
    int phone_number;
} Entry;

unsigned int hash(char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

Entry *create_entry(char *name, int phone_number) {
    Entry *new_entry = (Entry *) malloc(sizeof(Entry));

    strcpy(new_entry->name, name);
    new_entry->phone_number = phone_number;

    return new_entry;
}

void insert(Entry **table, char *name, int phone_number) {
    unsigned int index = hash(name);

    if (table[index] != NULL) {
        printf("Error: Name already exists!\n");
        free(create_entry(name, phone_number));
        return;
    }

    table[index] = create_entry(name, phone_number);
}

Entry *search(Entry **table, char *name) {
    unsigned int index = hash(name);

    if (table[index] == NULL)
        return NULL;

    if (strcmp(table[index]->name, name) == 0)
        return table[index];

    return search(table, name + 1);
}

void delete(Entry **table, char *name) {
    unsigned int index = hash(name);

    if (table[index] == NULL)
        return;

    if (strcmp(table[index]->name, name) != 0)
        delete(table, name + 1);
    else {
        Entry *temp = table[index];
        table[index] = NULL;
        free(temp);
    }
}

void display(Entry **table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            printf("%s: %d\n", table[i]->name, table[i]->phone_number);
        }
    }
}

int main() {
    Entry *phone_book[TABLE_SIZE];

    char command[20];
    char name[50], phone_str[20];
    int phone_number;

    while (1) {
        printf("\nPhone Book\n1. Add\n2. Delete\n3. Search\n4. Display\n5. Quit\n");
        scanf("%s", command);

        switch (*command) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone_str);
                sscanf(phone_str, "%d", &phone_number);
                insert(phone_book, name, phone_number);
                break;
            case '2':
                printf("Enter name: ");
                scanf("%s", name);
                delete(phone_book, name);
                break;
            case '3':
                printf("Enter name: ");
                scanf("%s", name);
                if (search(phone_book, name) != NULL)
                    printf("Phone number: %d\n", search(phone_book, name)->phone_number);
                else
                    printf("Error: Name not found!\n");
                break;
            case '4':
                display(phone_book);
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid command!\n");
        }
    }

    return 0;
}