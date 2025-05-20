//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

typedef struct {
    Student* record;
    struct hash_table_node* next;
} StudentRecord;

typedef struct {
    StudentRecord* entries[MAX_RECORDS];
    int size;
} HashTable;

typedef struct {
    int hash_value;
    int index;
} HashTableNode;

typedef struct {
    HashTable* hash_table;
    StudentRecord* current_entry;
    StudentRecord* free_entry;
    bool is_empty;
} Database;

void initialize_database(Database* db) {
    db->hash_table = (HashTable*) malloc(sizeof(HashTable));
    db->current_entry = NULL;
    db->free_entry = NULL;
    db->is_empty = true;
    memset(db->hash_table->entries, 0, sizeof(StudentRecord*) * MAX_RECORDS);
}

void add_student(Database* db, const char* name, int age, float gpa) {
    StudentRecord* new_entry = (StudentRecord*) malloc(sizeof(StudentRecord));
    new_entry->record = (Student*) malloc(sizeof(Student));
    strncpy(new_entry->record->name, name, sizeof(new_entry->record->name));
    new_entry->record->age = age;
    new_entry->record->gpa = gpa;

    StudentRecord* entry = db->current_entry;
    for (int i = 0; i < db->hash_table->size; i++) {
        if (db->hash_table->entries[i] == NULL) {
            entry = db->free_entry;
            db->free_entry = entry->next;
            entry->next = new_entry;
            db->hash_table->entries[i] = new_entry;
            db->is_empty = false;
            return;
        } else {
            entry = entry->next;
        }
    }
    entry->next = new_entry;
}

Student* get_student(Database* db, const char* name) {
    StudentRecord* entry = db->current_entry;
    for (int i = 0; i < db->hash_table->size; i++) {
        if (db->hash_table->entries[i] == NULL) {
            return NULL;
        } else {
            if (strcmp(db->hash_table->entries[i]->record->name, name) == 0) {
                return db->hash_table->entries[i]->record;
            }
            entry = entry->next;
        }
    }
    return NULL;
}

void update_student(Database* db, const char* name, int age, float gpa) {
    Student* student = get_student(db, name);
    if (student!= NULL) {
        student->age = age;
        student->gpa = gpa;
    }
}

void delete_student(Database* db, const char* name) {
    Student* student = get_student(db, name);
    if (student!= NULL) {
        StudentRecord* entry = db->current_entry;
        for (int i = 0; i < db->hash_table->size; i++) {
            if (db->hash_table->entries[i] == NULL) {
                return;
            } else {
                if (strcmp(db->hash_table->entries[i]->record->name, name) == 0) {
                    StudentRecord* next = db->hash_table->entries[i]->next;
                    free(db->hash_table->entries[i]);
                    db->hash_table->entries[i] = next;
                    db->is_empty = false;
                    return;
                }
                entry = entry->next;
            }
        }
    }
}

void print_students(Database* db) {
    StudentRecord* entry = db->current_entry;
    for (int i = 0; i < db->hash_table->size; i++) {
        if (db->hash_table->entries[i] == NULL) {
            continue;
        }
        printf("Name: %s, Age: %d, GPA: %f\n", db->hash_table->entries[i]->record->name, db->hash_table->entries[i]->record->age, db->hash_table->entries[i]->record->gpa);
        entry = entry->next;
    }
}

int main() {
    Database db;
    initialize_database(&db);

    add_student(&db, "John Doe", 20, 3.5);
    add_student(&db, "Jane Smith", 22, 3.8);
    add_student(&db, "Mike Johnson", 21, 3.9);
    print_students(&db);

    Student* student = get_student(&db, "John Doe");
    if (student!= NULL) {
        student->age = 21;
        student->gpa = 3.9;
        update_student(&db, "John Doe", 21, 3.9);
    }

    student = get_student(&db, "Jane Smith");
    if (student!= NULL) {
        student->age = 23;
        student->gpa = 3.7;
        update_student(&db, "Jane Smith", 23, 3.7);
    }

    delete_student(&db, "John Doe");
    print_students(&db);

    return 0;
}