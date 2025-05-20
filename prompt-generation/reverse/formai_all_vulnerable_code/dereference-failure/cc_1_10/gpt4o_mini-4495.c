//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define NAME_LENGTH 30

typedef struct Node {
    char name[NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int size;
} List;

// Function prototypes
List* createList();
void addNode(List* list, const char* name);
void visualizeList(List* list, int shapeType);
void freeList(List* list);
void printShape(int shapeType);

int main() {
    List* list = createList();
    char name[NAME_LENGTH];
    int choice, shapeType;

    // Adding nodes to the list
    while (1) {
        printf("Enter a name to add to the list (or type 'q' to quit): ");
        scanf("%s", name);
        if (strcmp(name, "q") == 0) break;
        addNode(list, name);
    }

    while (1) {
        printf("Select shape to visualize:\n1. Circle\n2. Square\n3. Triangle\n4. Exit\nChoice: ");
        scanf("%d", &shapeType);
        if (shapeType < 1 || shapeType > 3) break;

        visualizeList(list, shapeType);
    }

    freeList(list);
    return 0;
}

List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addNode(List* list, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, NAME_LENGTH);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void visualizeList(List* list, int shapeType) {
    int i = 0;
    Node* current = list->head;

    printShape(shapeType);

    while (current != NULL) {
        printf("%s ", current->name);
        current = current->next;
        if (shapeType == 1) {
            // Circle shape: adding some circular representation
            if (i < list->size - 1) {
                printf(" -> ");
            }
            i++;
        } else if (shapeType == 2) {
            // Square shape: linear representation top-to-bottom
            printf("\n");
        } else if (shapeType == 3) {
            // Triangle shape: increasing spaces for each level
            for (int j = 0; j < i; j++) {
                printf(" ");
            }
            printf("%s\n", current->name);
            i++;
        }
    }

    printf("\n");
}

void printShape(int shapeType) {
    if (shapeType == 1) {
        printf("Visualizing as a Circle:\n");
    } else if (shapeType == 2) {
        printf("Visualizing as a Square:\n");
    } else if (shapeType == 3) {
        printf("Visualizing as a Triangle:\n");
    }
}

void freeList(List* list) {
    Node* current = list->head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}