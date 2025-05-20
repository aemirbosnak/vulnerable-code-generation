//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX_SIZE 100

typedef struct Knight {
    char name[50];
    int strength;
    int agility;
    int wisdom;
    struct Knight* next;
} Knight;

Knight* insertKnight(Knight* head, char* name, int strength, int agility, int wisdom) {
    Knight* newKnight = (Knight*)malloc(sizeof(Knight));
    strcpy(newKnight->name, name);
    newKnight->strength = strength;
    newKnight->agility = agility;
    newKnight->wisdom = wisdom;
    newKnight->next = NULL;

    if (head == NULL) {
        head = newKnight;
    } else {
        Knight* tempKnight = head;
        while (tempKnight->next) {
            tempKnight = tempKnight->next;
        }
        tempKnight->next = newKnight;
    }

    return head;
}

int searchKnight(Knight* head, char* name) {
    Knight* tempKnight = head;
    while (tempKnight) {
        if (strcmp(tempKnight->name, name) == 0) {
            return 1;
        }
        tempKnight = tempKnight->next;
    }

    return 0;
}

int main() {
    Knight* head = NULL;
    head = insertKnight(head, "Sir Robin", 15, 12, 10);
    head = insertKnight(head, "Sir Lucan", 12, 14, 8);
    head = insertKnight(head, "Sir Gareth", 13, 13, 9);

    if (searchKnight(head, "Sir Robin") == 1) {
        printf("Sir Robin has been found.\n");
    } else {
        printf("Sir Robin has not been found.\n");
    }

    return 0;
}