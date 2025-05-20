//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int age;
    float salary;
    struct Node *next;
} Node;

typedef enum {
    SHAPE_PERSON,
    SHAPE_VIP,
} ShapeType;

typedef struct Shape {
    ShapeType shapeType;
    Node *node;
} Shape;

Node *createNode(char *name, int age, float salary) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->salary = salary;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, char *name, int age, float salary) {
    Node *newNode = createNode(name, age, salary);
    newNode->next = *head;
    *head = newNode;
}

void displayNodes(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", temp->name, temp->age, temp->salary);
        temp = temp->next;
    }
}

Shape *shapeShift(Node *node, ShapeType shapeType) {
    Shape *shape = (Shape *)malloc(sizeof(Shape));
    shape->shapeType = shapeType;
    shape->node = node;
    return shape;
}

void displayShape(Shape *shape) {
    if (shape->shapeType == SHAPE_PERSON) {
        printf("Person Shape -> Name: %s, Age: %d, Salary: %.2f\n", 
            shape->node->name, shape->node->age, shape->node->salary);
    } else if (shape->shapeType == SHAPE_VIP) {
        printf("VIP Shape -> Name: %s, Age: %d, Salary: %.2f (Exclusive Benefits)\n", 
            shape->node->name, shape->node->age, shape->node->salary * 1.5); // Different salary representation
    }
}

void freeList(Node *head) {
    Node *current = head;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    Node *head = NULL;
    insertNode(&head, "Alice", 30, 60000.50);
    insertNode(&head, "Bob", 25, 50000.00);
    insertNode(&head, "Charlie", 35, 70000.00);
    
    printf("Database Records:\n");
    displayNodes(head);
    
    printf("\nShape Shifting Demonstrations:\n");
    Node *temp = head;    
    while (temp) {
        Shape *shape = shapeShift(temp, SHAPE_PERSON);
        displayShape(shape);
        free(shape);      
        temp = temp->next;
    }

    // Shift to VIP
    temp = head;    
    while (temp) {
        Shape *shape = shapeShift(temp, SHAPE_VIP);
        displayShape(shape);
        free(shape);      
        temp = temp->next;
    }    

    freeList(head);
    return 0;
}