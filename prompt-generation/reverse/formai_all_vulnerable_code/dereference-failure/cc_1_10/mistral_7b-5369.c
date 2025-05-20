//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    int id;
    char name[50];
} Record;

typedef struct Node {
    Record data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* current = NULL;

void createDB() {
    head = NULL;
}

void insertRecord(int id, char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.id = id;
    strcpy(newNode->data.name, name);
    newNode->next = head;
    head = newNode;
}

void deleteRecord(int id) {
    if (head == NULL) {
        printf("Database is empty.\n");
        return;
    }

    if (head->data.id == id) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    current = head;
    while (current->next != NULL && current->next->data.id != id) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Record not found.\n");
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void searchRecord(int id) {
    if (head == NULL) {
        printf("Database is empty.\n");
        return;
    }

    current = head;
    while (current != NULL && current->data.id != id) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Record not found.\n");
        return;
    }

    printf("ID: %d, Name: %s\n", current->data.id, current->data.name);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <create|insert|delete|search> [args]\n", argv[0]);
        return 1;
    }

    switch (*argv[1]) {
        case 'c':
            createDB();
            break;
        case 'i':
            if (argc < 4) {
                printf("Usage: %s insert <id> <name>\n", argv[0]);
                return 1;
            }
            insertRecord(atoi(argv[2]), argv[3]);
            break;
        case 'd':
            if (argc < 3) {
                printf("Usage: %s delete <id>\n", argv[0]);
                return 1;
            }
            deleteRecord(atoi(argv[2]));
            break;
        case 's':
            if (argc < 3) {
                printf("Usage: %s search <id>\n", argv[0]);
                return 1;
            }
            searchRecord(atoi(argv[2]));
            break;
        default:
            printf("Invalid command.\n");
            printf("Usage: %s <create|insert|delete|search> [args]\n", argv[0]);
            return 1;
    }

    return 0;
}