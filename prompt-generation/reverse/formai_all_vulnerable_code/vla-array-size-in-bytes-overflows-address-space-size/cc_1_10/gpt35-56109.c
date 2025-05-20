//FormAI DATASET v1.0 Category: Weather simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate weather condition for a given day
char* generateWeatherCondition() {
    int num = rand() % 3;
    switch(num) {
        case 0:
            return "Sunny";
        case 1:
            return "Cloudy";
        case 2:
            return "Rainy";
    }
}

// structure for a player
struct Player {
    char name[20];
    int points;
    char weatherCondition[10];
};

int main() {
    srand(time(NULL));
    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);
    struct Player players[numPlayers];
    for(int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].points = 0;
    }
    int numRounds;
    printf("Enter the number of rounds: ");
    scanf("%d", &numRounds);
    for(int i = 0; i < numRounds; i++) {
        char* weather = generateWeatherCondition();
        printf("\n\nDay %d (%s):\n\n", i+1, weather);
        for(int j = 0; j < numPlayers; j++) {
            printf("%s, it's your turn.\n", players[j].name);
            int points = rand() % 11;
            if(points < 5) {
                printf("Unfortunately, you scored 0 points on this round.\n");
            }
            else {
                printf("Congrats! You scored %d points on this round.\n", points);
                players[j].points += points;
            }
        }
    }
    printf("\n\nGame over!\n\nResults:\n");
    for(int i = 0; i < numPlayers; i++) {
        printf("%s - %d points\n", players[i].name, players[i].points);
    }
    return 0;
}