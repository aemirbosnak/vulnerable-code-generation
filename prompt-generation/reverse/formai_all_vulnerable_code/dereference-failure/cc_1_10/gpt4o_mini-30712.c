//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define NAME_LENGTH 50
#define HASH_SIZE 19
#define LOAD_FACTOR 0.7

typedef struct {
    char name[NAME_LENGTH];
    int age;
} Person;

typedef struct {
    Person* people[MAX_SIZE];
    int count;
} HashTable;

// Hash function to compute the hash index
int hash(const char* name) {
    int index = 0;
    while (*name) {
        index = (index + *name) % HASH_SIZE;
        name++;
    }
    return index;
}

// Create a new person
Person* create_person(const char* name, int age) {
    Person* person = (Person*)malloc(sizeof(Person));
    strncpy(person->name, name, NAME_LENGTH);
    person->age = age;
    return person;
}

// Initialize the hash table
HashTable* init_table() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < MAX_SIZE; i++) {
        table->people[i] = NULL;
    }
    table->count = 0;
    return table;
}

// Insert a person into the hash table
void insert_person(HashTable* table, const char* name, int age) {
    if (table->count >= MAX_SIZE * LOAD_FACTOR) {
        printf("HashTable is full!\n");
        return;
    }

    Person* person = create_person(name, age);
    int index = hash(name);

    while (table->people[index] != NULL) {
        index = (index + 1) % MAX_SIZE;
    }

    table->people[index] = person;
    table->count++;
}

// Search for a person by name in the hash table
Person* search_person(HashTable* table, const char* name) {
    int index = hash(name);

    while (table->people[index] != NULL) {
        if (strcmp(table->people[index]->name, name) == 0) {
            return table->people[index];
        }
        index = (index + 1) % MAX_SIZE;
    }
    return NULL;
}

// Display the hash table
void display_table(HashTable* table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (table->people[i] != NULL) {
            printf("Index %d: Name: %s, Age: %d\n", i, table->people[i]->name, table->people[i]->age);
        }
    }
}

// Free the allocated memory for the hash table
void free_table(HashTable* table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (table->people[i] != NULL) {
            free(table->people[i]);
        }
    }
    free(table);
}

// Main function to drive the program
int main() {
    HashTable* table = init_table();
    int option;
    char name[NAME_LENGTH];
    int age;

    do {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert Person\n");
        printf("2. Search Person\n");
        printf("3. Display Table\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                insert_person(table, name, age);
                break;
            case 2:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                Person* found = search_person(table, name);
                if (found) {
                    printf("Person found - Name: %s, Age: %d\n", found->name, found->age);
                } else {
                    printf("Person not found!\n");
                }
                break;
            case 3:
                display_table(table);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 4);

    free_table(table);
    return 0;
}