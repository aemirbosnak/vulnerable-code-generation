//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FORTUNES 10

// Structure to store fortunes
typedef struct {
    char *fortune;
} Fortune;

// Function to generate random number between min and max
int rand_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize array of fortunes
    Fortune fortunes[MAX_FORTUNES];
    for (int i = 0; i < MAX_FORTUNES; i++) {
        fortunes[i].fortune = malloc(50 * sizeof(char));
        strcpy(fortunes[i].fortune, "Fortune ");
        switch (i) {
            case 0:
                strcat(fortunes[i].fortune, "1: The future is bright, like the sun.");
                break;
            case 1:
                strcat(fortunes[i].fortune, "2: Prepare for a journey, it's time to explore.");
                break;
            case 2:
                strcat(fortunes[i].fortune, "3: Good things are coming your way, stay positive.");
                break;
            case 3:
                strcat(fortunes[i].fortune, "4: You will find happiness in unexpected places.");
                break;
            case 4:
                strcat(fortunes[i].fortune, "5: Your hard work will pay off, keep going.");
                break;
            case 5:
                strcat(fortunes[i].fortune, "6: Trust your intuition, it will lead you right.");
                break;
            case 6:
                strcat(fortunes[i].fortune, "7: Love is in the air, open your heart.");
                break;
            case 7:
                strcat(fortunes[i].fortune, "8: Stay focused, success is just around the corner.");
                break;
            case 8:
                strcat(fortunes[i].fortune, "9: The universe has your back, have faith.");
                break;
            case 9:
                strcat(fortunes[i].fortune, "10: Be patient, good things come to those who wait.");
                break;
        }
    }

    // Welcome message
    printf("Welcome to the Automated Fortune Teller!\n");

    // Loop to generate and display fortune
    int fortune_number = rand_range(0, MAX_FORTUNES - 1);
    printf("Your fortune for today is: %s\n", fortunes[fortune_number].fortune);

    // Free memory allocated for fortunes
    for (int i = 0; i < MAX_FORTUNES; i++) {
        free(fortunes[i].fortune);
    }

    return 0;
}