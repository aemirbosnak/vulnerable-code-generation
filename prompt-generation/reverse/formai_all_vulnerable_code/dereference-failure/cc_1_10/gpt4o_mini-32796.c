//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_title() {
    printf("**********************************\n");
    printf("      Welcome to Mystic Quest     \n");
    printf("**********************************\n\n");
}

void print_intro() {
    printf("In a realm shrouded by darkness, a forgotten hero awakens.\n");
    printf("Your journey begins in the Village of Eldergrove, where whispers of a cursed castle beckon...\n");
    printf("Will you dare to uncover the secrets that lie within?\n\n");
}

char* get_input() {
    char *input = malloc(100);
    printf("> ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove trailing newline character
    return input;
}

void explore_village() {
    printf("You are in the Village of Eldergrove.\n");
    printf("You can go to the 'forest', check the 'market', or head to the 'inn'.\n");
}

void explore_forest() {
    printf("You step into the dark forest, where shadows linger and woeful sounds echo.\n");
    printf("You encounter a wild beast! You can 'fight' or 'run'.\n");
}

void check_market() {
    printf("You arrive at the bustling market.\n");
    printf("You can buy 'potion', 'sword', or 'exit'.\n");
}

void visit_inn() {
    printf("You enter the inn, where the atmosphere is warm and inviting.\n");
    printf("You can rest or gather information about the cursed castle.\n");
}

void battle() {
    printf("You bravely battle the wild beast...\n");
    printf("With courage and skill, you defeat the beast!\n");
}

void encounter() {
    printf("You discover hidden treasures in a forsaken clearing!\n");
    printf("You gain a magical amulet!\n");
}

int main() {
    char *choice;

    print_title();
    print_intro();

    while (1) {
        explore_village();
        choice = get_input();

        if (strcmp(choice, "forest") == 0) {
            explore_forest();
            choice = get_input();
            if (strcmp(choice, "fight") == 0) {
                battle();
                encounter();
            } else if (strcmp(choice, "run") == 0) {
                printf("You run back to the village safely.\n");
            } else {
                printf("Invalid command! You stand still in confusion.\n");
            }
        } else if (strcmp(choice, "market") == 0) {
            check_market();
            choice = get_input();
            if (strcmp(choice, "potion") == 0) {
                printf("You buy a healing potion and feel rejuvenated!\n");
            } else if (strcmp(choice, "sword") == 0) {
                printf("You purchase a shiny new sword, sharp and glistening in the sun!\n");
            } else if (strcmp(choice, "exit") == 0) {
                printf("You leave the market with your purchases.\n");
            } else {
                printf("Invalid command! You leave the market empty-handed.\n");
            }
        } else if (strcmp(choice, "inn") == 0) {
            visit_inn();
            choice = get_input();
            if (strcmp(choice, "rest") == 0) {
                printf("You take a restful nap and feel refreshed!\n");
            } else if (strcmp(choice, "information") == 0) {
                printf("The innkeeper shares tales about the cursed castle...\n");
            } else {
                printf("You leave the inn without taking any action.\n");
            }
        } else if (strcmp(choice, "quit") == 0) {
            printf("Thank you for playing Mystic Quest! Until next time!\n");
            free(choice);
            return 0;
        } else {
            printf("Invalid command! Please choose again.\n");
        }
        free(choice);
    }

    return 0;
}