//Falcon-180B DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    char *name;
    int age;
    float salary;
} Record;

typedef struct node {
    Record data;
    struct node *next;
} Node;

Node *create_node(Record record) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = record;
    node->next = NULL;
    return node;
}

void add_record(Node **head, Record record) {
    Node *node = create_node(record);
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

int main() {
    FILE *file;
    char line[100];
    char *token;
    Record record;
    Node *head = NULL;
    int count = 0;
    file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, ",");
        strcpy(record.name, token);
        token = strtok(NULL, ",");
        record.age = atoi(token);
        token = strtok(NULL, ",");
        record.salary = atof(token);
        add_record(&head, record);
        count++;
    }
    fclose(file);
    printf("Total records: %d\n", count);
    return 0;
}