//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

Player* head = NULL;

void addPlayer(char* name) {
    Player* newPlayer = malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = 0;
    newPlayer->next = NULL;

    if (head == NULL) {
        head = newPlayer;
    } else {
        head->next = newPlayer;
        head = newPlayer;
    }
}

void extractMetadata(char* data) {
    char* token = strtok(data, ",");
    while (token) {
        char* name = strtok(token, ":");
        char* value = strtok(NULL, ":");

        for (Player* player = head; player; player = player->next) {
            if (strcmp(player->name, name) == 0) {
                player->score = atoi(value);
            }
        }
        token = strtok(NULL, ",");
    }
}

int main() {
    addPlayer("John");
    addPlayer("Mary");
    addPlayer("Bob");
    addPlayer("Alice");

    char data[] = "John:100,Mary:200,Bob:300,Alice:400";

    extractMetadata(data);

    for (Player* player = head; player; player = player->next) {
        printf("%s: %d\n", player->name, player->score);
    }

    return 0;
}