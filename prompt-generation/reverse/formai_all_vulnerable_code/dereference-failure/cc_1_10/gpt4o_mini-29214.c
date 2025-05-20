//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_GRADES 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int grades[MAX_GRADES];
    float average;
} Student;

typedef struct Node {
    Student student;
    struct Node* next;
} Node;

Node* head = NULL;

void insertStudent(const char* name, int grades[], int count) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->student.name, name, MAX_NAME_LENGTH);
    newNode->student.average = 0.0;
    for (int i = 0; i < count && i < MAX_GRADES; i++) {
        newNode->student.grades[i] = grades[i];
        newNode->student.average += grades[i];
    }
    newNode->student.average /= (float)count;
    newNode->next = head;
    head = newNode;
}

void printStudentList() {
    Node* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->student.name);
        printf("Grades: ");
        for (int i = 0; i < MAX_GRADES; i++) {
            printf("%d ", current->student.grades[i]);
        }
        printf("\nAverage: %.2f\n", current->student.average);
        printf("----------------------\n");
        current = current->next;
    }
}

void freeStudentList() {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = NULL;
}

float getClassAverage() {
    Node* current = head;
    float totalAverage = 0.0;
    int count = 0;

    while (current != NULL) {
        totalAverage += current->student.average;
        count++;
        current = current->next;
    }
    
    return (count > 0) ? totalAverage / count : 0.0;
}

void searchStudent(const char* name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->student.name, name) == 0) {
            printf("Student found:\n");
            printf("Name: %s\n", current->student.name);
            printf("Grades: ");
            for (int i = 0; i < MAX_GRADES; i++) {
                printf("%d ", current->student.grades[i]);
            }
            printf("\nAverage: %.2f\n", current->student.average);
            return;
        }
        current = current->next;
    }
    printf("Student with name '%s' not found.\n", name);
}

int main() {
    int grades1[MAX_GRADES] = {85, 90, 78, 92, 88};
    insertStudent("Alice", grades1, 5);

    int grades2[MAX_GRADES] = {76, 85, 90, 82, 80};
    insertStudent("Bob", grades2, 5);

    int grades3[MAX_GRADES] = {90, 92, 85, 88, 91};
    insertStudent("Charlie", grades3, 5);

    printf("Student List:\n");
    printStudentList();

    printf("Class Average: %.2f\n", getClassAverage());

    printf("Searching for 'Bob':\n");
    searchStudent("Bob");

    printf("Searching for 'Dan':\n");
    searchStudent("Dan");

    freeStudentList();

    return 0;
}