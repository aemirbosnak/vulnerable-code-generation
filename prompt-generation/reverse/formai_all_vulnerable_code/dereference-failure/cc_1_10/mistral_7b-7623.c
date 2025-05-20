//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    int key;
    char name[50];
    float grade;
} Record;

typedef struct Node {
    Record data;
    struct Node* next;
} Node;

typedef struct Database {
    Node* head;
    int size;
} Database;

Database* createDatabase() {
    Database* db = (Database*) malloc(sizeof(Database));
    db->head = NULL;
    db->size = 0;
    return db;
}

void insertRecord(Database* db, int key, char name[], float grade) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data.key = key;
    strcpy(newNode->data.name, name);
    newNode->data.grade = grade;
    newNode->next = db->head;
    db->head = newNode;
    db->size++;
}

Record searchRecord(Database* db, int key) {
    Node* current = db->head;
    while (current != NULL) {
        if (current->data.key == key)
            return current->data;
        current = current->next;
    }
    Record notFound = {-1, "", 0.0};
    return notFound;
}

void deleteRecord(Database* db, int key) {
    if (db->head == NULL)
        return;
    if (db->head->data.key == key) {
        Node* temp = db->head;
        db->head = db->head->next;
        free(temp);
        db->size--;
        return;
    }
    Node* current = db->head;
    while (current->next != NULL && current->next->data.key != key) {
        current = current->next;
    }
    if (current->next == NULL)
        return;
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    db->size--;
}

void printDatabase(Database* db) {
    Node* current = db->head;
    while (current != NULL) {
        printf("| %d | %s | %.2f |\n", current->data.key, current->data.name, current->data.grade);
        current = current->next;
    }
}

int main() {
    Database* myDatabase = createDatabase();
    insertRecord(myDatabase, 1, "Alan Turing", 4.0);
    insertRecord(myDatabase, 2, "Grace Hopper", 3.5);
    insertRecord(myDatabase, 3, "Ada Lovelace", 4.5);
    printDatabase(myDatabase);
    Record found = searchRecord(myDatabase, 2);
    if (found.key != -1)
        printf("Found: %s %f\n", found.name, found.grade);
    else
        printf("Not Found\n");
    deleteRecord(myDatabase, 2);
    printDatabase(myDatabase);
    return 0;
}