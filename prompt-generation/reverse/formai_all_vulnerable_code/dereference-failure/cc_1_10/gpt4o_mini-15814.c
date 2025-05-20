//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "funny_event_log.txt"

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Oops! Could not open the log file. Is it secretly plotting against me?");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);

    // Remove the newline character from ctime
    timestamp[strlen(timestamp) - 1] = '\0';

    fprintf(file, "[%s] - %s \n", timestamp, event);
    fclose(file);
}

void eat_pasta(int num_pieces) {
    for (int i = 0; i < num_pieces; i++) {
        log_event("Someone just ate a piece of pasta. Al Dente or Al Elephant?");
        printf("Nom nom nom! Pasta piece %d down the hatch!\n", i + 1);
    }
}

int play_game() {
    log_event("Someone started playing a game of hide and seek with the code!");
    
    int score = rand() % 100;
    printf("Yikes! Scored %d points in hide and seek! Did the code hide well?\n", score);
    
    return score;
}

int order_pizza() {
    log_event("Ordering pizza because, you know, coding isn't complete without pizza!");
    
    printf("Pizza ordered! The cheese will melt like my focus when I code!\n");
    return rand() % 8; // Random number representing pizza slices.
}

void celebrate_pizza(int slices) {
    log_event("Pizza has arrived! Prepare for slice warfare!");
    
    for (int i = 0; i < slices; i++) {
        printf("Pizza slice %d is being devoured! Calories? What's that?\n", i + 1);
    }
}

void check_code() {
    log_event("Checking code for potential existential crises!");
    
    if (rand() % 2) {
        printf("All good! The code is not crying!\n");
    } else {
        printf("Code has found a bug! Might need a hug!\n");
        log_event("ERROR: Code found a bug! Call the insect exterminator!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the randomness to make things unpredictable!
    
    log_event("Program started! Grab your snack and hold onto your keyboards!");
    
    printf("Initializing the most fun C event logger ever!\n");

    // Do some playful activities
    eat_pasta(3);
    int gameScore = play_game();
    int pizzaSlices = order_pizza();
    
    printf("Game score: %d. Wow, I bet I could have coded instead!\n", gameScore);
    
    celebrate_pizza(pizzaSlices);
    
    check_code();
    
    log_event("Program is about to end. Empathy levels are at 0.0!");
    printf("All events logged! Time to hit the coding party!\n");

    return 0;
}