//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Employee structure
struct Employee {
    char name[100];
    int id;
    char department[100];
    double salary;
};

// Linked list node
struct Node {
    struct Employee employee;
    struct Node* next;
};

// Function to insert a new employee into the linked list
struct Node* insert(struct Node* head, struct Employee emp) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->employee = emp;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

// Function to print the employee information in the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%s - %d - %s - %f\n", temp->employee.name, temp->employee.id, temp->employee.department, temp->employee.salary);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;

    struct Employee emp1 = {"John Doe", 1, "IT", 50000};
    struct Employee emp2 = {"Jane Smith", 2, "HR", 60000};
    struct Employee emp3 = {"Mike Johnson", 3, "Finance", 55000};

    head = insert(head, emp1);
    head = insert(head, emp2);
    head = insert(head, emp3);

    printList(head);

    return 0;
}