//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    float gpa;
} Student;

typedef struct {
    Student *data;
    int size;
} Table;

typedef struct {
    Student **index;
    int size;
} Index;

void insert(Table *table, Index *index, Student student) {
    table->data = (Student *) realloc(table->data, (table->size + 1) * sizeof(Student));
    table->data[table->size] = student;
    index->index[student.id] = &(table->data[table->size]);
    table->size++;
}

void initIndex(Index *index, int size) {
    index->size = size;
    index->index = (Student **) calloc(size, sizeof(Student *));
}

void printTable(Table table) {
    printf("ID\tName\tGPA\n");
    for (int i = 0; i < table.size; i++) {
        printf("%d\t%s\t%.2f\n", table.data[i].id, table.data[i].name, table.data[i].gpa);
    }
}

int main() {
    Table table;
    table.data = NULL;
    table.size = 0;

    Index index;
    initIndex(&index, 100);

    Student student1 = {0, "John", 3.8};
    insert(&table, &index, student1);

    Student student2 = {1, "Jane", 3.9};
    insert(&table, &index, student2);

    Student student3 = {2, "Bob", 3.5};
    insert(&table, &index, student3);

    printf("Initial Table:\n");
    printTable(table);

    printf("Retrieving student with ID %d:\n", student2.id);
    printf("%s\n", index.index[student2.id]->name);

    return 0;
}