//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
#define _CRYPTIC_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _CRYPTIC_
typedef struct crypt_cell crypt_cell_t;

struct crypt_cell {
    char data;
    crypt_cell_t *next;
};

typedef struct crypt_list crypt_list_t;

struct crypt_list {
    crypt_cell_t *head;
    crypt_cell_t *tail;
};

void push(crypt_list_t *list, char data) {
    crypt_cell_t *new_cell = (crypt_cell_t *) malloc(sizeof(crypt_cell_t));
    new_cell->data = data;
    new_cell->next = NULL;

    if (list->head == NULL) {
        list->head = new_cell;
        list->tail = new_cell;
    } else {
        list->tail->next = new_cell;
        list->tail = new_cell;
    }
}

int find(crypt_list_t *list, char target) {
    crypt_cell_t *cell = list->head;
    int index = 0;

    while (cell != NULL) {
        if (cell->data == target) {
            return index;
        }
        cell = cell->next;
        index++;
    }

    return -1;
}

int main() {
    crypt_list_t search_list;
    search_list.head = NULL;
    search_list.tail = NULL;

    push(&search_list, 'A');
    push(&search_list, 'B');
    push(&search_list, 'C');
    push(&search_list, 'D');
    push(&search_list, 'E');

    char target = 'C';
    int result = find(&search_list, target);

    if (result >= 0) {
        printf("Found target '%c' at index %d\n", target, result);
    } else {
        printf("Target '%c' not found\n", target);
    }

    free(search_list.head);
    return 0;
}
#else
#error "This code requires the _CRYPTIC_ definition to be set."
#endif