//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Knight {
    int x, y;
    struct Knight *next;
} Knight;

Knight *insertKnight(Knight *head, int x, int y) {
    Knight *newKnight = (Knight *)malloc(sizeof(Knight));
    newKnight->x = x;
    newKnight->y = y;
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

Knight *searchKnight(Knight *head, int x, int y) {
    Knight *tempKnight = head;

    while (tempKnight) {
        if (tempKnight->x == x && tempKnight->y == y) {
            return tempKnight;
        }
        tempKnight = tempKnight->next;
    }

    return NULL;
}

int main() {
    Knight *head = NULL;

    insertKnight(head, 1, 2);
    insertKnight(head, 3, 4);
    insertKnight(head, 5, 6);

    Knight *knight = searchKnight(head, 3, 4);

    if (knight) {
        printf("Knight found at (%d, %d)\n", knight->x, knight->y);
    } else {
        printf("Knight not found\n");
    }

    return 0;
}