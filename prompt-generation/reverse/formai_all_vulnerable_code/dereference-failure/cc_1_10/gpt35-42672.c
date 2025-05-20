//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_INDEX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_NAME_LENGTH];
} Person;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int index[MAX_INDEX_ENTRIES];
    int size;
} Index;

Index* create_index(char* name) {
    Index* index = (Index*)malloc(sizeof(Index));
    strcpy(index->name, name);
    index->size = 0;
    return index;
}

void insert_into_index(Index* index, int position) {
    if (index->size < MAX_INDEX_ENTRIES - 1) {
        index->index[index->size++] = position;
    }
}

void sort_index(Index* index, Person* people, int n) {
    int i, j, temp;
    Person key;
    for (i = 1; i < n; i++) {
        key = people[i];
        j = i - 1;
        while (j >= 0 && strcmp(people[j].name, key.name) > 0) {
            people[j + 1] = people[j];
            j--;
        }
        people[j + 1] = key;
    }
    for (i = 0; i < n; i++) {
        temp = i;
        while (temp < n && strcmp(people[temp].name, people[i].name) == 0) {
            insert_into_index(index, temp);
            temp++;
        }
        i = temp - 1;
    }
}

int main() {
    Person people[] = {
        {"Alice", 20, "123 Main St."},
        {"Bob", 25, "456 Second St."},
        {"Charlie", 30, "789 Third St."},
        {"David", 35, "101 Fourth St."},
        {"Emily", 40, "1111 Fifth St."}
    };
    int n = sizeof(people) / sizeof(Person);
    Index* index = create_index("name");
    sort_index(index, people, n);
    int i, j;
    for (i = 0; i < index->size; i++) {
        j = index->index[i];
        printf("%-10s %-5d %-20s\n", people[j].name, people[j].age, people[j].address);
    }
    return 0;
}