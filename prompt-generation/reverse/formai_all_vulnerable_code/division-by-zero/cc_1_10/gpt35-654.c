//FormAI DATASET v1.0 Category: Dice Roller ; Style: Romeo and Juliet
/* A Dice Roller Program in Romeo and Juliet Style */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_rolls, num_sides, i, total = 0;
    char answer;

    /* Introduction */
    printf("Oh gentle dice, how fair thou art,\n");
    printf("To tumble us like lovers' hearts;\n\n");

    /* Prompt user for number of rolls */
    printf("How many rolls, my sweetest friend?\n");
    scanf("%d", &num_rolls);

    /* Prompt user for number of sides */
    printf("\nAnd how many sides must thee attend?\n");
    scanf("%d", &num_sides);

    /* Roll the dice */
    srand(time(0));
    for(i = 1; i <= num_rolls; i++) {
        int roll = rand() % num_sides + 1;
        printf("\nAlas, thou hast rolled a %d\n\n", roll);
        total += roll;
    }

    /* Display total */
    printf("So now, dear friend, what is the sum?\n");
    printf("Speak freely, and do not succumb.\n");
    printf("(Answer in Yea or Nay, kind sir/madam)\n");

    /* Prompt for total */
    while(answer != 'Y' && answer != 'N') {
        scanf(" %c", &answer);
        if(answer == 'Y') {
            printf("\nAh, then the total doth equate to %d\n", total);
        } else if(answer == 'N') {
            printf("\nThen what could the total be, pray?\n");
            printf("Speak true, and do not stray.\n");
            printf("(Answer in digits, my love)\n");
            scanf("%d", &total);
        } else {
            printf("\nOh woe is me, thou hast not answered in Yea or Nay!\n");
            printf("Try again, and do not dismay.\n\n");
        }
    }

    /* Farewell */
    printf("\nFarewell, sweet dice, until we meet again,\n");
    printf("May thy rolls bring us joy, not pain.\n");

    return 0;
}