//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_GRADE 100

typedef struct student {
    char name[50];
    int grade;
} Student;

typedef struct hash_table {
    int capacity;
    int size;
    Student *students;
} HashTable;

int hash_func(const char *name) {
    int hash_value = 0;
    int len = strlen(name);

    for (int i = 0; i < len; i++) {
        hash_value += name[i];
    }

    return hash_value % MAX_STUDENTS;
}

HashTable *create_hash_table(int capacity) {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->capacity = capacity;
    ht->size = 0;
    ht->students = (Student *)malloc(capacity * sizeof(Student));
    return ht;
}

void insert_student(HashTable *ht, const char *name, int grade) {
    int index = hash_func(name);
    Student *student = &ht->students[index];

    if (ht->size >= ht->capacity) {
        ht->capacity *= 2;
        ht->students = (Student *)realloc(ht->students, ht->capacity * sizeof(Student));
    }

    student->name[0] = '\0';
    strcpy(student->name, name);
    student->grade = grade;
    ht->size++;
}

int find_student(HashTable *ht, const char *name) {
    int index = hash_func(name);
    Student *student = &ht->students[index];

    if (ht->size == 0) {
        return -1;
    }

    for (int i = 0; i < ht->size; i++) {
        if (strcmp(student->name, name) == 0) {
            return student->grade;
        }
        student++;
    }

    return -1;
}

void print_grades(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        printf("%s: %d\n", ht->students[i].name, ht->students[i].grade);
    }
}

int main() {
    HashTable *ht = create_hash_table(MAX_STUDENTS);

    insert_student(ht, "Alice", 90);
    insert_student(ht, "Bob", 85);
    insert_student(ht, "Charlie", 75);

    printf("Grades for students:\n");
    print_grades(ht);

    int alice_grade = find_student(ht, "Alice");
    if (alice_grade!= -1) {
        printf("Alice's grade: %d\n", alice_grade);
    } else {
        printf("Alice's grade not found\n");
    }

    return 0;
}