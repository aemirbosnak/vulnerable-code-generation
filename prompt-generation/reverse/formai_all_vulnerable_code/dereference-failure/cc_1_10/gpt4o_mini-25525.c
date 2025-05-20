//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Student* next;
} Student;

typedef struct {
    Student* head;
} StudentList;

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->next = NULL;
    return newNode;
}

Student* createStudent(int id, const char* name) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = id;
    strncpy(newStudent->name, name, MAX_NAME_LENGTH);
    newStudent->next = NULL;
    return newStudent;
}

void appendStudent(StudentList* list, int id, const char* name) {
    Student* newStudent = createStudent(id, name);
    if (!list->head) {
        list->head = newStudent;
    } else {
        Student* temp = list->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void printStudentList(const StudentList* list) {
    printf("Student List:\n");
    Student* temp = list->head;
    while (temp) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

void deleteStudentById(StudentList* list, int id) {
    if (!list->head) return;
    
    Student* temp = list->head;
    Student* prev = NULL;

    if (temp->id == id) {
        list->head = temp->next;
        free(temp);
        return;
    }

    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return;

    prev->next = temp->next;
    free(temp);
}

void freeStudentList(StudentList* list) {
    Student* temp = list->head;
    while (temp) {
        Student* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
}

void visualizeStudentReferences(const StudentList* list) {
    printf("\nVisualizing Student References:\n");
    Student* temp = list->head;
    while (temp) {
        printf("Student ID: %d -> Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
    printf("End of List -> NULL\n");
}

int main() {
    StudentList list;
    list.head = NULL;

    appendStudent(&list, 1, "Alice");
    appendStudent(&list, 2, "Bob");
    appendStudent(&list, 3, "Charlie");
    
    printStudentList(&list);
    
    visualizeStudentReferences(&list);
    
    printf("\nDeleting student with ID 2...\n");
    deleteStudentById(&list, 2);
    
    printStudentList(&list);

    printf("Visualizing after deletion:\n");
    visualizeStudentReferences(&list);

    freeStudentList(&list);
    return 0;
}