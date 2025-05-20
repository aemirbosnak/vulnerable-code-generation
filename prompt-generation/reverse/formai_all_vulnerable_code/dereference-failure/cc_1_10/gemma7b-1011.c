//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDLES 100

typedef struct Candle {
    int burning_time;
    struct Candle* next;
} Candle;

Candle* insert_candle(Candle* head, int burning_time) {
    Candle* new_candle = malloc(sizeof(Candle));
    new_candle->burning_time = burning_time;
    new_candle->next = NULL;

    if (head) {
        head->next = new_candle;
    } else {
        head = new_candle;
    }

    return head;
}

void burn_candles(Candle* head) {
    while (head) {
        head->burning_time--;
        if (head->burning_time == 0) {
            printf("Candle %p has burned out.\n", head);
            free(head);
            head = head->next;
        }
    }
}

int main() {
    Candle* head = NULL;

    // Insert a bunch of candles
    insert_candle(head, 5);
    insert_candle(head, 3);
    insert_candle(head, 2);
    insert_candle(head, 4);
    insert_candle(head, 6);

    // Burn the candles
    burn_candles(head);

    return 0;
}