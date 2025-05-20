//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 10
#define BUFFER_SIZE 256

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int size;
} List;

char* surrealistPhrase() {
    const char* phrases[] = {
        "a dream within a dream",
        "echoes of forgotten whispers",
        "a mirror reflecting the void",
        "colors melting into sounds",
        "a labyrinth of shadows",
        "the dance of lost time",
        "the whispers of the cosmos",
        "a raindrop's melodic sigh",
        "the heartbeat of the universe",
        "a canvas painted with thoughts"
    };
    return (char*)phrases[rand() % 10];
}

void printVisual(List* list) {
    Node* current = list->head;
    printf("A surrealist visualization of the List:\n");
    
    while(current != NULL) {
        char description[BUFFER_SIZE];
        snprintf(description, BUFFER_SIZE, 
                  "Node %d: \"%s\"\n", 
                  current->value, surrealistPhrase());
        printf("%s", description);
        current = current->next;
    }

    printf("End of the mesmerizing tale...\n");
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void append(List* list, int value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

void freeList(List* list) {
    Node* current = list->head;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    list->head = NULL;
    list->size = 0;
}

int main() {
    srand(time(NULL));

    List surrealList = {NULL, 0};

    printf("Creating a surrealist list of %d nodes:\n", MAX_NODES);
    for (int i = 1; i <= MAX_NODES; i++) {
        append(&surrealList, i);
        printf("Added node with value: %d\n", i);
    }

    printVisual(&surrealList);
    freeList(&surrealList);

    return 0;
}