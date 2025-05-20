//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

typedef struct HashNode {
    Student data;
    struct HashNode *next;
} HashNode;

unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(HashNode **table, Student student) {
    unsigned int index = hash(student.id);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->data = student;
    newNode->next = table[index];
    table[index] = newNode;
}

Student *search(HashNode **table, int key) {
    unsigned int index = hash(key);
    HashNode *current = table[index];

    while (current != NULL) {
        if (current->data.id == key) {
            return &current->data;
        }
        current = current->next;
    }

    return NULL;
}

void printStudent(Student student) {
    printf("ID: %d, Name: %s, Age: %d\n", student.id, student.name, student.age);
}

int main() {
    HashNode *studentsTable[TABLE_SIZE] = {NULL};

    Student students[5] = {
        {1, "John Doe", 20},
        {2, "Jane Doe", 22},
        {3, "Bob Smith", 25},
        {4, "Alice Johnson", 23},
        {5, "Mike Brown", 21}
    };

    for (int i = 0; i < 5; i++) {
        insert(studentsTable, students[i]);
    }

    Student *student;

    student = search(studentsTable, 3);
    if (student != NULL) {
        printStudent(*student);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}