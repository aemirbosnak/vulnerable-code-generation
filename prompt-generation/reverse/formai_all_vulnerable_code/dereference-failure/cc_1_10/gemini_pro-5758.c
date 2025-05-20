//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main(int argc, char *argv[])
{
    // Parse command line arguments
    int delay = 5;
    if (argc > 1) {
        delay = atoi(argv[1]);
    }

    // Initialize traffic light state
    enum { RED_LIGHT, YELLOW_LIGHT, GREEN_LIGHT } light_state = RED_LIGHT;

    // Main loop
    while (1) {
        // Display traffic light state
        switch (light_state) {
            case RED_LIGHT:
                printf("%s[RED]%s\n", RED, RESET);
                break;
            case YELLOW_LIGHT:
                printf("%s[YELLOW]%s\n", YELLOW, RESET);
                break;
            case GREEN_LIGHT:
                printf("%s[GREEN]%s\n", GREEN, RESET);
                break;
        }

        // Sleep for specified delay
        sleep(delay);

        // Advance traffic light state
        switch (light_state) {
            case RED_LIGHT:
                light_state = GREEN_LIGHT;
                break;
            case YELLOW_LIGHT:
                light_state = RED_LIGHT;
                break;
            case GREEN_LIGHT:
                light_state = YELLOW_LIGHT;
                break;
        }
    }

    return 0;
}