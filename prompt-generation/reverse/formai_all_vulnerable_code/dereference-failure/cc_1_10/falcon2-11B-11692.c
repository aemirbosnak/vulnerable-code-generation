//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_character_name() {
    char name[100];
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);
    return strdup(name);
}

int main() {
    char* name = get_character_name();
    printf("Welcome, %s!\n", name);

    printf("You find yourself in a dark forest. There are two paths ahead of you.\n");

    char* choice = get_character_name();
    if (strcmp(choice, "left") == 0) {
        printf("You decide to take the left path. After walking for a while, you find yourself at a clearing. There is a cottage in the middle of the clearing. What do you do?\n");
        char* choice2 = get_character_name();
        if (strcmp(choice2, "go to the cottage") == 0) {
            printf("As you approach the cottage, the door opens and a friendly old woman greets you. She invites you inside for tea. You accept her invitation.\n");
            printf("After tea, the old woman reveals that she is a witch and offers to grant you a wish. What do you wish for?\n");
            char* choice3 = get_character_name();
            if (strcmp(choice3, "wish for something") == 0) {
                printf("You think for a moment and decide to wish for wisdom. The old woman grants your wish and disappears. You feel a sudden surge of knowledge and understanding.\n");
            } else {
                printf("You decline her offer and leave the cottage.\n");
            }
        } else {
            printf("You decide to continue exploring the forest. After some time, you stumble upon a group of bandits. What do you do?\n");
            char* choice4 = get_character_name();
            if (strcmp(choice4, "fight the bandits") == 0) {
                printf("You engage the bandits in battle. After a fierce fight, you emerge victorious. The bandits flee and you continue on your journey.\n");
            } else {
                printf("You decide to flee from the bandits. You escape into the forest and continue exploring.\n");
            }
        }
    } else {
        printf("You decide to take the right path. After walking for a while, you find yourself at the edge of a cliff. What do you do?\n");
        char* choice5 = get_character_name();
        if (strcmp(choice5, "jump off the cliff") == 0) {
            printf("You jump off the cliff and plummet to your death.\n");
        } else {
            printf("You decide to climb down the cliff. After some time, you reach the bottom and continue exploring the forest.\n");
        }
    }

    return 0;
}