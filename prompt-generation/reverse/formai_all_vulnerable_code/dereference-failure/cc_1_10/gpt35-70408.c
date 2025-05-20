//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
/* A unique C Database Indexing System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char email[50];
} Person;

typedef struct {
    Person* data;
    int size;
    int capacity;
} DataArray;

typedef struct {
    Person* data;
    int index;
} IndexEntry;

typedef struct {
    IndexEntry* data;
    int size;
    int capacity;
} IndexArray;

IndexArray* create_index(DataArray* arr) {
    // create an index array and initialize its capacity
    IndexArray* index = malloc(sizeof(IndexArray));
    index->size = 0;
    index->capacity = arr->capacity;
    index->data = malloc(sizeof(IndexEntry) * index->capacity);

    // add each person from the data array to the index array
    for (int i = 0; i < arr->size; i++) {
        IndexEntry entry = {&arr->data[i], i};
        index->data[i] = entry;
        index->size++;
    }

    return index;
}

void print_person(Person* person) {
    printf("ID: %d | Name: %s | Email: %s\n", person->id, person->name, person->email);
}

void print_data(DataArray* arr) {
    printf("Data Array:\n");
    for (int i = 0; i < arr->size; i++) {
        print_person(&arr->data[i]);
    }
}

void print_index(IndexArray* index) {
    printf("Index Array:\n");
    for (int i = 0; i < index->size; i++) {
        printf("Index: %d | ", index->data[i].index);
        print_person(index->data[i].data);
    }
}

void add_person(DataArray* arr, IndexArray* index, Person person) {
    // add person to data array
    arr->data[arr->size] = person;
    arr->size++;

    // update index array
    IndexEntry entry = {&arr->data[arr->size - 1], arr->size - 1};
    index->data[index->size] = entry;
    index->size++;
}

void search_person_by_id(IndexArray* index, int id) {
    for (int i = 0; i < index->size; i++) {
        if (index->data[i].data->id == id) {
            printf("Person Found:\n");
            print_person(index->data[i].data);
            return;
        }
    }

    printf("Person with ID %d not found.\n", id);
}

int main() {
    // initialize data array
    DataArray data = {malloc(sizeof(Person) * 10), 0, 10};

    // add some people to the data array
    Person person1 = {1, "John Doe", "johndoe@gmail.com"};
    Person person2 = {2, "Jane Smith", "janesmith@gmail.com"};
    Person person3 = {3, "Bob Johnson", "bobjohnson@gmail.com"};
    add_person(&data, NULL, person1);
    add_person(&data, NULL, person2);
    add_person(&data, NULL, person3);

    // create index array
    IndexArray* index = create_index(&data);

    // print data and index arrays
    print_data(&data);
    printf("\n");
    print_index(index);
    printf("\n");

    // search for person by ID
    search_person_by_id(index, 2);

    // free memory
    free(data.data);
    free(index->data);
    free(index);
    return 0;
}