//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

// Fortune cookies contain fortunes
typedef struct {
    char *fortune;
} FortuneCookie;

// Function to generate random numbers
int randint(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    FortuneCookie *fortune_cookies = malloc(NUM_FORTUNES * sizeof(FortuneCookie));

    // Fill fortune cookies with fortunes
    for (int i = 0; i < NUM_FORTUNES; i++) {
        fortune_cookies[i].fortune = malloc(256 * sizeof(char));

        switch (randint(0, 2)) {
            case 0:
                strcpy(fortune_cookies[i].fortune, "Your future is bright.\n");
                break;
            case 1:
                strcpy(fortune_cookies[i].fortune, "Good things are coming your way.\n");
                break;
            case 2:
                strcpy(fortune_cookies[i].fortune, "Your hard work will pay off.\n");
                break;
            default:
                fprintf(stderr, "Unexpected error: invalid random number.\n");
                exit(1);
        }
    }

    // Present user with a random fortune cookie
    int fortune_index = randint(0, NUM_FORTUNES - 1);
    printf("Here's your fortune:\n");
    printf("%s", fortune_cookies[fortune_index].fortune);

    // Free memory allocated for fortune cookies
    for (int i = 0; i < NUM_FORTUNES; i++) {
        free(fortune_cookies[i].fortune);
    }
    free(fortune_cookies);

    return 0;
}