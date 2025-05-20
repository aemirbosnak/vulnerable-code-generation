//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    char name[50];
    int age;
} Student;

typedef struct {
    char name[50];
    int age;
    int grade;
} Teacher;

typedef struct {
    char name[50];
    int age;
    int grade;
    int num_classes;
} School;

typedef struct {
    char name[50];
    int age;
    int grade;
    struct Node *next;
} Node;

struct Node {
    char name[50];
    int age;
    int grade;
    struct Node *next;
} *graph[MAX_NODES];

void add_node(struct Node **head, char name[], int age, int grade) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    strcpy(temp->name, name);
    temp->age = age;
    temp->grade = grade;
    temp->next = *head;
    *head = temp;
}

void print_nodes(struct Node *head) {
    struct Node *temp = head;
    while (temp!= NULL) {
        printf("%s (%d) (%d)\n", temp->name, temp->age, temp->grade);
        temp = temp->next;
    }
}

void add_edge(struct Node *head1, struct Node *head2) {
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;
    while (temp1!= NULL && temp2!= NULL) {
        if (strcmp(temp1->name, temp2->name) == 0) {
            temp1->next = temp2->next;
            temp2->next = head1;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

int main() {
    char name[50];
    int age, grade;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter grade: ");
    scanf("%d", &grade);

    add_node(&graph[0], name, age, grade);
    graph[0]->next = graph[1];
    graph[1]->age = 30;
    graph[1]->grade = 8;
    graph[1]->name[0] = 'T';

    printf("Student: %s (%d) (%d)\n", graph[0]->name, graph[0]->age, graph[0]->grade);
    printf("Teacher: %s (%d) (%d)\n", graph[1]->name, graph[1]->age, graph[1]->grade);

    return 0;
}