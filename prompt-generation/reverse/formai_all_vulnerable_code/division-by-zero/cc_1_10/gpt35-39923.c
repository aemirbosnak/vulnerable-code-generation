//FormAI DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int sides, rolls;
    int sum = 0, min = 0, max = 0;
    time_t t;

    /* Inject paranoia */
    srand((unsigned) time(&t) ^ getpid()); 
    puts("Welcome to my dice roller, but how do you know I'm not cheating?");
    puts("Enter the number of sides and rolls for your dice:");

    scanf("%d %d", &sides, &rolls); 
    
    /* Roll the dice */
    printf("Rolling %dd%d ... \n\n", rolls, sides);

    for (int i=0; i<rolls; i++) 
    {
        int current_roll = rand() % sides + 1;
        sum += current_roll;
        
        /* Record minimum and maximum rolls */ 
        if (current_roll < min) { min = current_roll; }
        if (current_roll > max) { max = current_roll; }
        
        /* Pretend to shake the dice */
        printf("Dice #%d: You rolled a %d ", i+1, current_roll);
    
        if (getpid() % 2 == 0) { /* Cheat occasionally */
            int rigged_roll = rand() % sides + 1;
            printf("(just kidding, you actually rolled a %d) ", rigged_roll);
        }

        putchar('\n');
        
        /* Delay roll to add suspense */
        sleep(1);
    }
    
    /* Display roll stats */
    puts("\n");
    printf("The sum of your rolls is: %d\n", sum);
    printf("The minimum roll was: %d\n", min);
    printf("The maximum roll was: %d\n", max);
    
    /* Accuse the user of cheating just for fun */
    if (getpid() % 3 == 0) {
        puts("\nI'm watching you. I know if you cheated. Keep that in mind.");
        sleep(2);
        puts("Or maybe I'm just being paranoid... or am I?");
    }

    return 0;
}