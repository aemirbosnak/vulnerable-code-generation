//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: intelligent
#include<stdio.h>
#include<ctype.h>
#define MAX_LEN 1000

void printOpeningScene();
void printIntro();
void playGame();
void printMap();
void printCharStats();
void getUserInput(char* input);

int health = 100; // Player's health
int coins = 0; // Player's coins
int position = 0; // Current position

int main() {
    printOpeningScene();
    printIntro();
    playGame();
    return 0;
}

// Prints the opening scene of the game
void printOpeningScene() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("In this game, you will embark on a journey to defeat the evil dragon\n");
    printf("and become the hero of the kingdom. Are you ready? Let's begin!\n\n");
}

// Prints the introduction of the game and its instructions
void printIntro() {
    printf("You are a brave knight who has been tasked with defeating the evil dragon\n");
    printf("that has been terrorizing the kingdom of Camelot. You start your journey\n");
    printf("at the gates of your castle and you must travel through different lands and\n");
    printf("defeat various enemies to reach the dragon's lair. Good luck!\n\n");

    printf("INSTRUCTIONS:\n\n");
    printf("1. You can move north, south, east or west.\n2. You may be attacked by enemies as you move around.\n");
    printf("3. You will come across different objects which can help you.\n4. You can use the coins you earn to buy items.\n\n");

    char input[MAX_LEN];
    printf("Press any key to start the game\n");
    fgets(input, MAX_LEN, stdin);
}

// Plays the game
void playGame() {
    printf("You are at the gates of your castle.\n");
    printMap();
    printCharStats();
    char input[MAX_LEN];

    while(health > 0 && position != 3) { // Position 3 is the dragon's lair
        printf("What would you like to do? ");
        getUserInput(input);

        if(strcmp(input, "north") == 0) {
            printf("You move north\n");
            position++;
        }
        else if(strcmp(input, "south") == 0) {
            printf("You move south\n");
            position--;
        }
        else if(strcmp(input, "east") == 0) {
            printf("You move east\n");
            position += 2;
        }
        else if(strcmp(input, "west") == 0) {
            printf("You move west\n");
            position -= 2;
        }
        else {
            printf("Invalid command\n");
        }

        if(position == 1) { // Forest
            printf("You are in the forest\n");
            printf("An enemy appears!\n");
            int enemyHealth = 50;

            while(enemyHealth > 0 && health > 0) {
                printf("What would you like to do? ");
                getUserInput(input);

                if(strcmp(input, "fight") == 0) {
                    printf("You attack the enemy and deal 20 damage\n");
                    enemyHealth -= 20;
                }
                else if(strcmp(input, "run") == 0) {
                    printf("You run away from the enemy\n");
                    break;
                }
                else {
                    printf("Invalid command\n");
                }

                if(enemyHealth > 0) {
                    printf("The enemy attacks you and deals 10 damage\n");
                    health -= 10;
                    printCharStats();
                }
            }

            if(health <= 0) {
                printf("You have been defeated\n");
                break;
            }
            else {
                printf("You defeated the enemy and earned 50 coins!\n");
                coins += 50;
            }
        }
        else if(position == 2) { // Town
            printf("You are in the town\n");
            printf("You have %d coins\n", coins);

            while(1) {
                printf("What would you like to buy? ");
                getUserInput(input);

                if(strcmp(input, "axe") == 0) {
                    if(coins >= 100) {
                        printf("You bought the axe!\n");
                        coins -= 100;
                        break;
                    }
                    else {
                        printf("You do not have enough coins to buy the axe\n");
                    }
                }
                else if(strcmp(input, "shield") == 0) {
                    if(coins >= 50) {
                        printf("You bought the shield!\n");
                        coins -= 50;
                        break;
                    }
                    else {
                        printf("You do not have enough coins to buy the shield\n");
                    }
                }
                else {
                    printf("Invalid item\n");
                }
            }
        }

        printMap();
        printCharStats();
    }

    if(health > 0) {
        printf("Congratulations! You have defeated the dragon and saved the kingdom\n");
    }
}

// Prints the map of the game
void printMap() {
    printf(" ------------\n");
    printf("|     |      |\n");
    printf("|  T  |      |\n");
    printf("|-----| CASTLE\n");
    printf("|     |      |\n");
    printf("|  F  | D LAIR\n");
    printf("|_____|______|\n");
}

// Prints the character's stats
void printCharStats() {
    printf("HEALTH: %d\n", health);
    printf("COINS: %d\n", coins);
}

// Gets user input, ignoring leading and trailing white spaces
void getUserInput(char* input) {
    fgets(input, MAX_LEN, stdin);

    int len = strlen(input);

    if(input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    while(isspace(*input)) {
        input++;
    }

    len = strlen(input);
    input += len - 1;

    while(isspace(*input)) {
        input--;
    }

    input++;
    *input = '\0';
}