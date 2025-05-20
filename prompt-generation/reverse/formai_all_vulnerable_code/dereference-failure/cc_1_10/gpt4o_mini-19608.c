//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A joyful function to convert natural language date to a standard format
void joyfulDateConversion(const char* input, char* output) {
    struct tm tm;
    
    // Clear the output buffer
    memset(output, 0, 50);
    
    // Prepare the happy messages
    const char *happyMessages[] = {
        "Yay! You're living in the present!",
        "What a wonderful day to reflect!",
        "Let's make today unforgettable!",
        "Time is flying, let's dance along!",
        "Another bright day in life!",
    };

    // Example of natural language date parsing
    if (strstr(input, "today")) {
        time_t now = time(NULL);
        tm = *localtime(&now);
        strftime(output, 50, "%Y-%m-%d", &tm);
        printf("%s - It's today! %s\n", output, happyMessages[rand() % 5]);
    } else if (strstr(input, "tomorrow")) {
        time_t now = time(NULL) + 86400; // Add one day in seconds
        tm = *localtime(&now);
        strftime(output, 50, "%Y-%m-%d", &tm);
        printf("%s - Tomorrow is a new adventure! %s\n", output, happyMessages[rand() % 5]);
    } else if (strstr(input, "yesterday")) {
        time_t now = time(NULL) - 86400; // Subtract one day in seconds
        tm = *localtime(&now);
        strftime(output, 50, "%Y-%m-%d", &tm);
        printf("%s - Ah, the fun of yesterday! %s\n", output, happyMessages[rand() % 5]);
    } else {
        printf("Oops! I couldn't understand your request. But let's stay positive!\n");
        sprintf(output, "Unknown");
    }
}

// Main function to test our joyful date converter
int main() {
    char input[100];
    char output[50];

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Joyful Natural Language Date Converter!\n");
    printf("You can ask for 'today', 'tomorrow', or 'yesterday'.\n");
    printf("What date would you like to know? Type here: ");
    
    // Getting user input
    fgets(input, sizeof(input), stdin);
    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    // Call the joyful date conversion function
    joyfulDateConversion(input, output);

    return 0;
}