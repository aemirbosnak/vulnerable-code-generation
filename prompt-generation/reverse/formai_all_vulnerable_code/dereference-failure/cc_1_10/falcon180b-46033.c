//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of words to be typed
#define NUM_WORDS 50

// Function to generate a random word
char *generate_word(int length) {
    char *word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        word[i] = rand() % 26 + 'a';
    }
    word[length] = '\0';
    return word;
}

// Function to print the words to be typed
void print_words(char **words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to measure typing speed
double measure_speed(int num_correct, int num_incorrect, double time_taken) {
    double speed = 0;
    if (time_taken > 0) {
        speed = (double)num_correct / time_taken;
    }
    return speed;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the words to be typed
    char **words = malloc(NUM_WORDS * sizeof(char *));
    for (int i = 0; i < NUM_WORDS; i++) {
        words[i] = generate_word(rand() % 10 + 5);
    }

    // Print the words to be typed
    printf("Words to be typed:\n");
    print_words(words, NUM_WORDS);

    // Get user input
    char input[100];
    scanf("%s", input);

    // Convert input to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Initialize variables
    int num_correct = 0;
    int num_incorrect = 0;
    double time_taken = 0;

    // Measure typing speed
    clock_t start_time = clock();
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcmp(input, words[i]) == 0) {
            num_correct++;
        } else if (strcmp(input, words[i])!= 0 && strcmp(input, "")!= 0) {
            num_incorrect++;
        }
        free(words[i]);
    }
    time_taken = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    // Print results
    printf("You typed %d words correctly and %d words incorrectly.\n", num_correct, num_incorrect);
    printf("Your typing speed is %.2f words per minute.\n", measure_speed(num_correct, num_incorrect, time_taken));

    return 0;
}