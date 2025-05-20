//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 30
#define DROPS 200

struct Cell {
    int x, y;
    int precipitation;
    struct Cell *next;
};

void init_cells(struct Cell **head) {
    srand(time(NULL));
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            (*head) = (struct Cell*) malloc(sizeof(struct Cell));
            (*head)->x = j;
            (*head)->y = i;
            (*head)->precipitation = rand() % 101; // 0-100
            (*head)->next = NULL;
            head = &((*head)->next);
        }
    }
}

void print_cells(struct Cell *head) {
    while(head!= NULL) {
        printf("(%d,%d): %d\n", head->x, head->y, head->precipitation);
        head = head->next;
    }
}

void move_drops(struct Cell **head) {
    struct Cell *curr = *head;
    while(curr!= NULL) {
        if(curr->precipitation > 0) {
            curr->precipitation--;
        }
        curr = curr->next;
    }
}

void add_drops(struct Cell **head) {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(rand() % 101 <= 50) { // 50% chance
                (*head)->precipitation++;
            }
        }
    }
}

int main() {
    struct Cell *head = NULL;
    init_cells(&head);
    printf("Initial precipitation:\n");
    print_cells(head);

    int k;
    for(k = 0; k < DROPS; k++) {
        move_drops(&head);
        add_drops(&head);
        printf("\nAfter %d drops:\n", k+1);
        print_cells(head);
        sleep(1);
    }

    return 0;
}