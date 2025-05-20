//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    size_t size;
    struct node* next;
} Node;

Node* head = NULL;

void addToList(char* name, size_t size) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->size = size;
    newNode->next = head;
    head = newNode;
}

void printMemoryUsage() {
    Node* current = head;
    printf("\n============== MEMORY USAGE REPORT ==============\n");
    printf("| Name             | Size (bytes) |\n");
    printf("-----------------------------------------------|\n");

    while (current != NULL) {
        printf("| %-20s | %10ld |\n", current->name, current->size);
        current = current->next;
    }
    printf("-----------------------------------------------|\n");
}

int main() {
    char* knightName = "Sir Ramblesalot";
    int* knightHealth = (int*) malloc(sizeof(int));
    *knightHealth = 100;

    addToList(knightName, sizeof(int) + strlen(knightName) + 1);

    char* dragonName = "Dragonzilla";
    size_t dragonSize = 1000 * 1024; // 1 MB
    char* dragonDescription = (char*) malloc(dragonSize);

    strcpy(dragonDescription, "A mighty dragon with scales of emerald and eyes of ruby.");

    addToList(dragonName, dragonSize + strlen(dragonName) + strlen(dragonDescription) + 1);

    printMemoryUsage();

    free(dragonDescription);
    free(knightHealth);

    printMemoryUsage();

    return 0;
}