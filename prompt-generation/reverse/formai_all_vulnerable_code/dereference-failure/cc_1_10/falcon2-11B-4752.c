//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct game {
    int size;
    node *head;
} game;

void create_game(game *game) {
    game->size = 0;
    game->head = NULL;
}

void add_node(game *game, int value) {
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    if (game->head == NULL) {
        game->head = new_node;
    } else {
        node *current = game->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    game->size++;
}

bool is_empty(game *game) {
    return game->size == 0;
}

int main() {
    game my_game;
    create_game(&my_game);
    add_node(&my_game, 1);
    add_node(&my_game, 2);
    add_node(&my_game, 3);
    add_node(&my_game, 4);
    add_node(&my_game, 5);
    printf("Game size: %d\n", my_game.size);
    printf("Game head value: %d\n", my_game.head->value);
    return 0;
}