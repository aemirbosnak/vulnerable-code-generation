//FormAI DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int id;
    char name[20];
    float grade;
} Student;

Student* createStudent(int id, char* name, float grade) {
    Student* student = (Student*) malloc(sizeof(Student));
    student->id = id;
    strcpy(student->name, name);
    student->grade = grade;
    return student;
}

typedef struct node {
    Student* data;
    struct node* next;
} Node;

Node* createNode(Student* data, Node* next) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

typedef struct list {
    Node* head;
    Node* tail;
} List;

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addStudent(List* list, Student* student) {
    Node* node = createNode(student, NULL);
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void printList(List* list) {
    Node* node = list->head;
    while(node != NULL) {
        printf("ID: %d - Name: %s - Grade: %.2f\n", node->data->id, node->data->name, node->data->grade);
        node = node->next;
    }
}

int main() {
    List* list = createList();
    Student* student1 = createStudent(1, "John", 7.5);
    Student* student2 = createStudent(2, "Mary", 8.0);
    Student* student3 = createStudent(3, "Peter", 9.5);
    addStudent(list, student1);
    addStudent(list, student2);
    addStudent(list, student3);
    printList(list);
    return 0;
}