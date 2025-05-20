//Gemma-7B DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Student {
    char name[MAX_SIZE];
    int roll_no;
    float marks[MAX_SIZE];
    struct Student* next;
} Student;

Student* insert_at_tail(Student* head, char* name, int roll_no, float marks[]) {
    Student* new_node = (Student*)malloc(sizeof(Student));
    strcpy(new_node->name, name);
    new_node->roll_no = roll_no;
    memcpy(new_node->marks, marks, MAX_SIZE * sizeof(float));
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

void print_students(Student* head) {
    Student* current = head;
    while (current) {
        printf("Name: %s, Roll No: %d, Marks: ", current->name, current->roll_no);
        for (int i = 0; i < MAX_SIZE; i++) {
            printf("%f ", current->marks[i]);
        }
        printf("\n");
        current = current->next;
    }
}

int main() {
    Student* head = NULL;

    insert_at_tail(head, "John Doe", 123, (float[]){90.5, 85.2, 92.1});
    insert_at_tail(head, "Jane Doe", 456, (float[]){80.3, 82.4, 88.6});
    insert_at_tail(head, "Peter Pan", 789, (float[]){95.0, 92.2, 94.3});

    print_students(head);

    return 0;
}