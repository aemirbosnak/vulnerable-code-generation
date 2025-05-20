//Gemma-7B DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESULTS 10

typedef struct Knight {
    char name[20];
    int strength;
    int wisdom;
    struct Knight* next;
} Knight;

Knight* insertKnight(Knight* head, char* name, int strength, int wisdom) {
    Knight* newKnight = malloc(sizeof(Knight));
    strcpy(newKnight->name, name);
    newKnight->strength = strength;
    newKnight->wisdom = wisdom;
    newKnight->next = NULL;

    if (head == NULL) {
        head = newKnight;
    } else {
        head->next = newKnight;
    }

    return head;
}

Knight* findKnight(Knight* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

void queryKnights(Knight* head) {
    Knight* currentKnight = head;

    printf("Behold, the list of valiant knights:\n");

    while (currentKnight) {
        printf("Name: %s, Strength: %d, Wisdom: %d\n", currentKnight->name, currentKnight->strength, currentKnight->wisdom);
        currentKnight = currentKnight->next;
    }
}

int main() {
    Knight* head = NULL;

    insertKnight(head, "Sir Robin", 15, 12);
    insertKnight(head, "Sir Ivan", 12, 10);
    insertKnight(head, "Sir Gareth", 13, 11);
    insertKnight(head, "Sir Arthur", 14, 13);

    queryKnights(head);

    Knight* foundKnight = findKnight(head, "Sir Ivan");

    if (foundKnight) {
        printf("Found Knight: %s\n", foundKnight->name);
    } else {
        printf("Knight not found.\n");
    }

    return 0;
}