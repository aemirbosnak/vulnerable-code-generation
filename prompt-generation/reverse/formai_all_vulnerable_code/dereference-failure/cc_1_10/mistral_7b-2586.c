//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Student {
    char name[50];
    int roll_number;
    float percentage;
    struct Student* next;
} Student;

Student* head = NULL;
Student* current = NULL;
Student* temp = NULL;

bool isEmpty() {
    return head == NULL;
}

int count() {
    Student* count_ptr = head;
    int count = 0;

    while (count_ptr != NULL) {
        count++;
        count_ptr = count_ptr->next;
    }

    return count;
}

void display() {
    Student* display_ptr = head;

    printf("Name\tRoll Number\tPercentage\n");

    while (display_ptr != NULL) {
        printf("%s\t%d\t%.2f\n", display_ptr->name, display_ptr->roll_number, display_ptr->percentage);
        display_ptr = display_ptr->next;
    }
}

Student* createNode(char* name, int roll_number, float percentage) {
    Student* new_node = (Student*) malloc(sizeof(Student));

    strcpy(new_node->name, name);
    new_node->roll_number = roll_number;
    new_node->percentage = percentage;
    new_node->next = NULL;

    return new_node;
}

void addAtBeginning(Student* new_node) {
    new_node->next = head;
    head = new_node;
}

void addAtEnd(Student* new_node) {
    if (isEmpty()) {
        head = new_node;
    } else {
        current = head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
    }
}

void deleteNode(int roll_number) {
    if (isEmpty()) {
        printf("List is empty!\n");
        return;
    }

    if (head->roll_number == roll_number) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    current = head;

    while (current->next != NULL && current->next->roll_number != roll_number) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Roll number not found!\n");
        return;
    }

    temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int main() {
    Student* student1 = createNode("John Doe", 1, 90.5);
    Student* student2 = createNode("Jane Doe", 2, 92.5);
    Student* student3 = createNode("Bob Smith", 3, 85.5);

    addAtBeginning(student1);
    addAtEnd(student2);
    addAtEnd(student3);

    display();

    deleteNode(1);

    display();

    return 0;
}