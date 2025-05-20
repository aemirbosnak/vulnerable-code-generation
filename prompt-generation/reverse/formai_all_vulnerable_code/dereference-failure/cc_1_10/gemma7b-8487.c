//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int baggage_count;
    struct Node* baggage_list;
} Player;

typedef struct Node {
    struct Node* next;
    char item_name[20];
    int item_weight;
} Node;

void initialize_players(Player** players) {
    for (int i = 0; i < MAX_Players; i++) {
        players[i] = malloc(sizeof(Player));
        players[i]->baggage_count = 0;
        players[i]->baggage_list = NULL;
        strcpy(players[i]->name, "Player");
    }
}

void add_item_to_baggage(Player* player, char* item_name, int item_weight) {
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->item_name, item_name);
    new_node->item_weight = item_weight;

    if (player->baggage_list == NULL) {
        player->baggage_list = new_node;
    } else {
        player->baggage_list->next = new_node;
        player->baggage_count++;
    }
}

void print_baggage(Player* player) {
    Node* current_node = player->baggage_list;
    printf("%s's baggage:\n", player->name);
    while (current_node) {
        printf("%s (%d)  ", current_node->item_name, current_node->item_weight);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    Player** players = malloc(MAX_Players * sizeof(Player*));
    initialize_players(players);

    add_item_to_baggage(players[0], "Laptop", 10);
    add_item_to_baggage(players[0], "Phone", 2);
    add_item_to_baggage(players[1], "Trolley", 5);
    add_item_to_baggage(players[1], "Clothes", 12);

    print_baggage(players[0]);
    print_baggage(players[1]);

    return 0;
}