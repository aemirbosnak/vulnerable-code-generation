//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void meowify(char *input, char *output) {
    char *meowDict[] = {"meow", "purr", "hiss", "mew", "yowl"};
    int len = strlen(input);
    
    for (int i = 0; i < len; i++) {
        char ch = input[i];
        if (ch >= 'a' && ch <= 'z') {
            int randomWordIndex = rand() % 5; // Randomly pick a meow word
            strcat(output, meowDict[randomWordIndex]);
            strcat(output, " "); // Space between meows
        } else {
            char temp[2] = {ch, '\0'};
            strcat(output, temp); // For any non-lowercase letter
            strcat(output, " "); // Space after non-lowercase
        }
    }
}

void cryptic_display(const char *translated) {
    for (int i = 0; translated[i] != '\0'; i++) {
        printf("%c", translated[i]);
        if (i % 5 == 4) { // Introduce a delay on every 5 characters
            usleep(250000); // Sleep for 250 milliseconds
        }
    }
    printf("\n");
}

char* capture_input() {
    char *buffer = (char *)malloc(MAX_LEN);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    printf("Whisper your message to the feline realm: ");
    fgets(buffer, MAX_LEN, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    return buffer;
}

int main() {
    srand(time(NULL)); // Seed for randomization
    char input[MAX_LEN];
    char output[MAX_LEN] = ""; // Initialize output buffer

    // Step 1: Capture Input
    strcpy(input, capture_input());

    // Step 2: Meowification
    meowify(input, output);

    // Step 3: Cryptic Display
    printf("Your message in Cat Language: \n");
    cryptic_display(output);

    // Step 4: Clean up
    return 0;
}