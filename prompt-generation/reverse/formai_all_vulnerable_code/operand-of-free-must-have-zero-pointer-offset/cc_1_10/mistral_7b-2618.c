//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char type[50];
} Ruin;

typedef struct Survivor {
    char name[30];
    int age;
} Survivor;

typedef struct Node {
    Survivor survivor;
    struct Node* next;
} Node;

typedef struct RuinList {
    Ruin ruin;
    Node* head;
} RuinList;

void printRuin(RuinList* ruinList) {
    printf("%s (%s):\n", ruinList->ruin.name, ruinList->ruin.type);
    Node* current = ruinList->head;
    while (current != NULL) {
        printf("- %s (age %d)\n", current->survivor.name, current->survivor.age);
        current = current->next;
    }
}

void addSurvivor(RuinList* ruinList, Survivor survivor) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->survivor = survivor;
    newNode->next = ruinList->head;
    ruinList->head = newNode;
}

int main() {
    RuinList cityRuins = {"City Ruins", ""};
    RuinList templeRuins = {"Temple Ruins", ""};

    Survivor survivor1 = {"John Doe", 35};
    Survivor survivor2 = {"Jane Doe", 28};

    addSurvivor(&cityRuins, survivor1);
    addSurvivor(&cityRuins, survivor2);

    addSurvivor(&templeRuins, survivor1);

    printRuin(&cityRuins);
    printRuin(&templeRuins);

    free(cityRuins.head);
    free(templeRuins.head);
    free(cityRuins.ruin.name);
    free(cityRuins.ruin.type);
    free(templeRuins.ruin.name);
    free(templeRuins.ruin.type);

    return 0;
}