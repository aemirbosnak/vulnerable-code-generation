//FormAI DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 1000

typedef struct {
    int id;
    char name[256];
    char address[256];
} Person;

typedef struct {
    int index[MAX_INDEX];
    int size;
} IndexList;

IndexList indexByName[MAX_INDEX];
IndexList indexByAddress[MAX_INDEX];

Person people[MAX_INDEX];
int count = 0;

void addPerson(int id, char* name, char* address) {
    Person* person = malloc(sizeof(Person));
    person->id = id;
    strcpy(person->name, name);
    strcpy(person->address, address);
    people[count++] = *person;

    int nameHash = hash(name);
    indexByName[nameHash].index[indexByName[nameHash].size++] = count - 1;

    int addressHash = hash(address);
    indexByAddress[addressHash].index[indexByAddress[addressHash].size++] = count - 1;
}

int hash(char* str) {
    int hash = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        hash += str[i];
    }
    return hash % MAX_INDEX;
}

IndexList* getByName(char* name) {
    int nameHash = hash(name);
    return &indexByName[nameHash];
}

IndexList* getByAddress(char* address) {
    int addressHash = hash(address);
    return &indexByAddress[addressHash];
}

int main() {
    addPerson(1, "John", "123 Main St.");
    addPerson(2, "Jane", "456 Fifth St.");
    addPerson(3, "Joe", "789 Elm St.");

    IndexList* johnList = getByName("John");
    int i;
    for (i = 0; i < johnList->size; i++) {
        int id = people[johnList->index[i]].id;
        char* name = people[johnList->index[i]].name;
        char* address = people[johnList->index[i]].address;
        printf("id=%d, name=%s, address=%s\n", id, name, address);
    }

    IndexList* mainStList = getByAddress("123 Main St.");
    for (i = 0; i < mainStList->size; i++) {
        int id = people[mainStList->index[i]].id;
        char* name = people[mainStList->index[i]].name;
        char* address = people[mainStList->index[i]].address;
        printf("id=%d, name=%s, address=%s\n", id, name, address);
    }

    return 0;
}