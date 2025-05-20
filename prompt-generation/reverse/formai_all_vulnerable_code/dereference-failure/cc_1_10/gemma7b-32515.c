//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: multiplayer
#include <stdio.h>
#include <time.h>

#define MAX_PLAYERS 4

struct Player {
    char name[20];
    int score;
    int speed;
    struct Player* next;
};

void initializePlayers(struct Player** head) {
    *head = malloc(sizeof(struct Player));
    (*head)->name[0] = '\0';
    (*head)->score = 0;
    (*head)->speed = 0;
    (*head)->next = NULL;
}

void joinPlayers(struct Player** head, char* name) {
    struct Player* newPlayer = malloc(sizeof(struct Player));
    newPlayer->name[0] = '\0';
    newPlayer->score = 0;
    newPlayer->speed = 0;
    newPlayer->next = NULL;

    if((*head) == NULL) {
        *head = newPlayer;
    } else {
        struct Player* current = *head;
        while(current->next) {
            current = current->next;
        }
        current->next = newPlayer;
    }
}

void startRace(struct Player* head) {
    time_t start = time(NULL);
    for(int i = 0; i < MAX_PLAYERS; i++) {
        struct Player* current = head;
        while(current) {
            printf("%s is typing...", current->name);
            sleep(1);
            printf(".");
            current = current->next;
        }
    }
    time_t end = time(NULL);
    for(struct Player* current = head; current; current++) {
        current->score = end - start;
    }
}

int main() {
    struct Player* head = NULL;

    // Initialize players
    initializePlayers(&head);

    // Join players
    joinPlayers(&head, "John");
    joinPlayers(&head, "Jane");
    joinPlayers(&head, "Alice");
    joinPlayers(&head, "Bob");

    // Start the race
    startRace(head);

    // Show the results
    for(struct Player* current = head; current; current++) {
        printf("%s's score is %d.", current->name, current->score);
    }

    return 0;
}