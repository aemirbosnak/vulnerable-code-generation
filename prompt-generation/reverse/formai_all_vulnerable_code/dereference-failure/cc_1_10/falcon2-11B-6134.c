//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* name;
    int age;
} Player;

int main() {
    srand(time(NULL));
    int choice, num, roll, score;
    Player players[100];
    int count = 0;

    // Initialize players
    for (int i = 0; i < 100; i++) {
        players[i].name = (char*) malloc(100);
        players[i].age = rand() % 100 + 1;
        strcpy(players[i].name, "Player ");
        sprintf(players[i].name + 8, "%d", i + 1);
    }

    do {
        printf("\nWelcome to the Dice Game!\n");
        printf("1. Roll the dice\n");
        printf("2. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                roll = rand() % 6 + 1;
                printf("\nYou rolled a %d!\n", roll);
                score += roll;
                break;
            case 2:
                printf("\nThanks for playing!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        for (int i = 0; i < 100; i++) {
            if (players[i].age == 0) {
                num = rand() % 6 + 1;
                players[i].age = num;
                roll = num;
                printf("\n%s rolled a %d!\n", players[i].name, roll);
                score += roll;
                break;
            }
        }
    } while (choice!= 2);

    printf("\nFinal Score: %d\n", score);

    for (int i = 0; i < 100; i++) {
        if (players[i].age!= 0) {
            printf("\n%s's age is %d\n", players[i].name, players[i].age);
        }
    }

    return 0;
}