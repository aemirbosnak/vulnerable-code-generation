//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data[MAX_BUFFER_SIZE];
    struct Node* next;
} Node;

typedef struct IntrusionDetectionSystem {
    Node* head;
    int threshold;
    int numTriggers;
} IntrusionDetectionSystem;

IntrusionDetectionSystem* initializeIntrusionDetectionSystem(int threshold) {
    IntrusionDetectionSystem* system = (IntrusionDetectionSystem*)malloc(sizeof(IntrusionDetectionSystem));
    system->head = NULL;
    system->threshold = threshold;
    system->numTriggers = 0;
    return system;
}

void insertNode(IntrusionDetectionSystem* system, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = system->head;
    system->head = newNode;
    strcpy(newNode->data, data);
}

void checkForIntrusion(IntrusionDetectionSystem* system) {
    if (system->numTriggers >= system->threshold) {
        return;
    }

    for (Node* node = system->head; node; node = node->next) {
        if (strlen(node->data) > MAX_BUFFER_SIZE) {
            system->numTriggers++;
            printf("Intrusion detected: Data length exceeded threshold.\n");
            return;
        }
    }

    system->numTriggers++;
    printf("No intrusion detected.\n");
}

int main() {
    IntrusionDetectionSystem* system = initializeIntrusionDetectionSystem(5);

    insertNode(system, "This is a normal message.");
    insertNode(system, "This message is too long. It exceeds the threshold.");
    insertNode(system, "This is another normal message.");

    checkForIntrusion(system);

    return 0;
}