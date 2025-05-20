//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Knight {
    char name[MAX_NAME_LENGTH];
    int level;
    struct Knight *next;
} Knight;

Knight *insertKnight(Knight *head, char *name, int level) {
    Knight *newKnight = malloc(sizeof(Knight));
    strcpy(newKnight->name, name);
    newKnight->level = level;
    newKnight->next = NULL;

    if (head == NULL) {
        head = newKnight;
    } else {
        Knight *tempKnight = head;
        while (tempKnight->next) {
            tempKnight = tempKnight->next;
        }
        tempKnight->next = newKnight;
    }

    return head;
}

Knight *findKnight(Knight *head, char *name) {
    Knight *tempKnight = head;
    while (tempKnight) {
        if (strcmp(tempKnight->name, name) == 0) {
            return tempKnight;
        }
        tempKnight = tempKnight->next;
    }

    return NULL;
}

int main() {
    Knight *head = NULL;

    insertKnight(head, "Sir Robin", 10);
    insertKnight(head, "The White Knight", 5);
    insertKnight(head, "Sir Gary", 15);
    insertKnight(head, "The Red Knight", 20);

    Knight *knight = findKnight(head, "Sir Robin");

    if (knight) {
        printf("Name: %s, Level: %d\n", knight->name, knight->level);
    } else {
        printf("Knight not found.\n");
    }

    return 0;
}