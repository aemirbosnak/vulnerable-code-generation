//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Knight {
    char name[MAX_NAME_LENGTH];
    int strength, agility, wisdom;
    struct Knight* next;
} Knight;

Knight* insertKnight(Knight* head, char* name, int strength, int agility, int wisdom) {
    Knight* newKnight = malloc(sizeof(Knight));
    newKnight->strength = strength;
    newKnight->agility = agility;
    newKnight->wisdom = wisdom;
    strcpy(newKnight->name, name);
    newKnight->next = NULL;

    if (head == NULL) {
        head = newKnight;
    } else {
        Knight* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newKnight;
    }

    return head;
}

Knight* searchKnight(Knight* head, char* name) {
    Knight* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

int main() {
    Knight* head = NULL;

    insertKnight(head, "Sir Robin", 15, 12, 10);
    insertKnight(head, "Sir Lancelot", 12, 14, 8);
    insertKnight(head, "Sir Arthur", 13, 13, 9);
    insertKnight(head, "Sir Gareth", 14, 11, 7);

    Knight* knight = searchKnight(head, "Sir Robin");

    if (knight) {
        printf("Name: %s\n", knight->name);
        printf("Strength: %d\n", knight->strength);
        printf("Agility: %d\n", knight->agility);
        printf("Wisdom: %d\n", knight->wisdom);
    } else {
        printf("Knight not found.\n");
    }

    return 0;
}