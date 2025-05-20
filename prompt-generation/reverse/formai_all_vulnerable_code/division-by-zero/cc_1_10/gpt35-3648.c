//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // initialise random number generator
    
    int humanity = 100; // set initial humanity level
    int aliens = 0; // set initial alien presence
    
    printf("Welcome to the Alien Invasion Probability Calculator, post-apocalyptic edition!\n");
    printf("Humanity: %d, Aliens: %d\n\n", humanity, aliens);
    
    while(humanity > 0) { // repeat until humanity is extinct
        int invasion_roll = rand() % 101; // generate random number between 0-100 for invasion chance
        
        printf("Chance of Invasion: %d%%\n", invasion_roll);
        
        if(invasion_roll >= 50) { // alien invasion successful
            aliens += rand() % (humanity/2); // generate random number of aliens between 0.5 to 100% of current humanity
            humanity /= 2; // reduce humanity by 50%
            printf("Oh no! An alien invasion was successful!\n");
            printf("Humanity: %d, Aliens: %d\n", humanity, aliens);
        } else { // alien invasion unsuccessful
            printf("Phew! No alien invasion this time...\n");
            printf("Humanity: %d, Aliens: %d\n", humanity, aliens);
        }
        
        int resistance_roll = rand() % 101; // generate random number between 0-100 for human resistance chance
        
        printf("Chance of Resistance: %d%%\n", resistance_roll);
        
        if(resistance_roll >= 75) { // human resistance successful
            humanity += rand() % aliens; // generate random number of humans between 0-100% of current alien presence
            aliens = 0; // eliminate alien presence
            printf("Hooray! Human resistance was successful!\n");
            printf("Humanity: %d, Aliens: %d\n", humanity, aliens);
        } else { // human resistance unsuccessful
            aliens *= 2; // double alien presence
            printf("Oh no! Human resistance was unsuccessful...\n");
            printf("Humanity: %d, Aliens: %d\n", humanity, aliens);
        }
        
        printf("\n");
    }
    
    printf("Game over! Humanity is extinct.\n");
    
    return 0;
}