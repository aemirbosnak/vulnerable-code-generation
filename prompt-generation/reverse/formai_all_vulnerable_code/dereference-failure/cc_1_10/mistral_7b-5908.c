//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101

typedef struct Student {
    int id;
    char name[50];
    int age;
    char gender[10];
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
    HashNode *new_node = (HashNode *) malloc(sizeof(HashNode));
    new_node->data = student;
    new_node->next = NULL;

    if (*table == NULL) {
        *table = new_node;
    } else {
        HashNode *current = *table;
        while (current != NULL && current->data.id < student.id) {
            current = current->next;
        }
        new_node->next = current;
        if (current != NULL && current->data.id == student.id) {
            free(new_node);
            return;
        }
        if (index == current->data.id) {
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

Student *search(HashNode **table, int id) {
    unsigned int index = hash(id);
    HashNode *current = *table;

    while (current != NULL && current->data.id != id) {
        current = current->next;
    }

    if (current == NULL) {
        return NULL;
    }

    return &current->data;
}

void print_student(Student student) {
    printf("ID: %d, Name: %s, Age: %d, Gender: %s\n", student.id, student.name, student.age, student.gender);
}

int main() {
    HashNode *students_table = NULL;

    Student student1 = {1, "John Doe", 20, "Male"};
    Student student2 = {2, "Jane Doe", 22, "Female"};
    Student student3 = {1, "John Doe", 21, "Male"}; // Duplicate entry

    insert(&students_table, student1);
    insert(&students_table, student2);
    insert(&students_table, student3);

    Student *found_student = search(&students_table, 1);
    if (found_student != NULL) {
        print_student(*found_student);
    }

    return 0;
}