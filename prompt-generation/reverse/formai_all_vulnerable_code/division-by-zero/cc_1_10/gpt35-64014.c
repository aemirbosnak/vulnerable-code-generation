//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int human_strength, alien_strength, distance, days_until_arrival, invasion_probability, random;
    
    // Request user input
    printf("Enter the strength of the humans (0-100): ");
    scanf("%d", &human_strength);
    
    printf("Enter the strength of the aliens (0-100): ");
    scanf("%d", &alien_strength);
    
    printf("Enter the distance between Earth and the aliens (in millions of miles): ");
    scanf("%d", &distance);
    
    printf("Enter the number of days until the aliens arrive: ");
    scanf("%d", &days_until_arrival);
    
    // Seed the random number generator for determining random events
    srand(time(NULL));
    random = rand() % 100;
    
    // Calculate invasion probability
    invasion_probability = ((100 - human_strength) + alien_strength) - (distance / days_until_arrival);
    
    // Determine if unexpected events occur
    if (random < 20) {
        invasion_probability += 10;
        printf("Unexpected event: The humans have discovered a new weapon, adding 10 to the invasion probability!\n");
    }
    
    if (random < 40) {
        invasion_probability -= 10;
        printf("Unexpected event: The aliens' technology has malfunctioned, decreasing the invasion probability by 10!\n");
    }
    
    if (random < 60) {
        invasion_probability += 5;
        printf("Unexpected event: The humans have developed a powerful alliance, adding 5 to the invasion probability!\n");
    }
    
    if (random < 80) {
        invasion_probability -= 5;
        printf("Unexpected event: The aliens' communication system has been compromised, decreasing the invasion probability by 5!\n");
    }
    
    // Display final probability
    if (invasion_probability > 75) {
        printf("The aliens have a high chance of successfully invading Earth. Prepare for the worst!\n");
    } else if (invasion_probability > 50) {
        printf("The chance of alien invasion is moderate. Be cautious and prepare for defense.\n");
    } else if (invasion_probability > 25) {
        printf("The chance of an alien invasion is low, but not impossible. Keep a watchful eye and make sure defenses are in place.\n");
    } else {
        printf("The chance of an alien invasion is very low. Relax and enjoy life on Earth!\n");
    }
    
    return 0;
}