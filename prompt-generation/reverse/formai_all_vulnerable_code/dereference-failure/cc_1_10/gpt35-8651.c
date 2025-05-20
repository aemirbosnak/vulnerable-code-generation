//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include<stdio.h>
#include<stdlib.h>

char* playerName;

void gameTitle(){
    printf("*****A HAPPY ADVENTURE GAME*****\n\n");
    printf("Welcome, %s! Get ready for a joyful adventure!\n", playerName);
    printf("You are currently standing near a lush green forest. Ahead of you is a pathway that seems to lead to a bright meadow.\n");
    printf("What would you like to do?\n");
}

void gameIntro(){
    printf("You start walking through the forest, and after a few minutes,\n");
    printf("you spot something glistening on the ground. You go closer to investigate and\n");
    printf("find a gold ring lying on the ground. You put it on and continue walking steps into the meadow.\n");
    printf("After walking a few steps, you see a rabbit, and you follow it.\n");
    printf("As you follow it, you come across a friendly unicorn who wants to show you\n");
    printf("the way to a magical kingdom. Suddenly, the world around you begins to sparkle and shimmer.\n\n");
    printf("Congratulations %s, you have found the magical kingdom!\n", playerName);
}

void forest(){
    printf("\nYou walk towards the forest. As you enter, the trees begin to rustle,\n");
    printf("and you see squirrels running around gathering nuts, birds chirping and singing\n");
    printf("alongside a creek. After walking for a while, you find an apple tree with\n");
    printf("crisp and red apples hanging from its branches. You decide to eat one. It tastes delicious.\n");
    printf("What would you like to do next?\n");
}

void meadow(){
    printf("\nAs you walk through the meadow, you see a group of happy butterflies fluttering around, creating beautiful patterns in the\n");
    printf("air. The meadow is filled with colorful flowers, and the sun is shining bright. Suddenly, you come across a group of rabbits\n");
    printf("who are having fun playing. They invite you to be a part of their game, and you happily agree. After a while, you say goodbye to\n");
    printf("the rabbits and continue your journey. What would you like to do next?\n");
}

void magicKingdom(){
    printf("\nAs you enter the magical kingdom, you see unicorns, fairies, and magical creatures all around you.\n");
    printf("One of the fairies approaches you and asks if you want to go on a magical treasure hunt.\n");
    printf("You eagerly say yes, and she gives you a map and offers you her help on the journey. You go on a treasure hunt and find a chest filled\n");
    printf("with gold and silver. Congratulations, %s! You have successfully completed the game!\n", playerName);
}

void gamePlay(){
    int choice;
    printf("\nChoices: \n1 - Walk through the lush green forest.\n2 - Walk on the pathway toward the meadow.\n3 - Enter the magical kingdom.\n4 - Quit.\n\n");
    printf("What would you like to do?\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            forest();
            gamePlay();
            break;
        case 2:
            meadow();
            gamePlay();
            break;
        case 3:
            magicKingdom();
            break;
        case 4:
            printf("\nThank you for playing, %s! I hope you had fun.\n", playerName);
            exit(0);
        default:
            printf("\nInvalid choice, try again.\n");
            gamePlay();
            break;
    }
}

int main(){
    printf("Enter your name: ");
    playerName = malloc(sizeof(char)*50);
    scanf("%s", playerName);
    gameTitle();
    gamePlay();
    return 0;
}