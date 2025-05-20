//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 200

// Function to get random words from the wordlist file
char* get_random_word() {
    FILE* fp;
    char* filename = "wordlist.txt";
    int count = 0, random_index;
    char temp_word[MAX_STRING_LENGTH];
    char* random_word = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));

    // Open the file
    fp = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening the file %s\n", filename);
        exit(1);
    }

    // Count the number of words in the file
    while (fgets(temp_word, MAX_STRING_LENGTH, fp)) {
        count++;
    }

    // Generate a random index to pick a word from the file
    srand(time(NULL));
    random_index = rand() % count;

    // Move the file pointer to the random index word
    rewind(fp);
    while (random_index-- >= 0) {
        fgets(random_word, MAX_STRING_LENGTH, fp);
    }

    // Remove the newline character at the end of the word
    random_word[strcspn(random_word, "\n")] = 0;

    // Close the file and return the random word
    fclose(fp);
    return random_word;
}

// Function to calculate and print the result
void print_result(float time_taken, int words_typed, int errors) {
    int wpm = (int)((float)words_typed / (time_taken / 60.0));
    float accuracy = 100.0 - ((float)errors / (float)words_typed) * 100.0;
    printf("\nTyping Speed Test Results:\n");
    printf("------------------------\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Words typed: %d\n", words_typed);
    printf("Errors: %d\n", errors);
    printf("Words per minute (WPM): %d\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);
}

int main() {
    int i, j, current_word_index, words_typed = 0, errors = 0;
    char c, current_word[MAX_STRING_LENGTH];
    clock_t start_time, end_time, total_time;
    float time_taken;

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the words displayed and press Enter to proceed to the next word.\n");
    printf("Press Ctrl+C to exit the test at any time.\n\n");

    // Loop through 10 random words
    for (i = 0; i < 10; i++) {
        char* random_word = get_random_word();
        current_word_index = 0;
        printf("Word %d: %s\n", i + 1, random_word);
        start_time = clock();
        // Loop through the current word
        while ((c = getchar()) != '\n') {
            if (c == random_word[current_word_index]) {
                current_word_index++;
                if (current_word_index == strlen(random_word)) {
                    // Word completed successfully
                    words_typed++;
                    break;
                }
            }
            else {
                errors++;
            }
        }
        // Timing and results
        end_time = clock();
        total_time = end_time - start_time;
        time_taken = ((float)total_time) / CLOCKS_PER_SEC;
        printf("Time taken: %.2f seconds\n", time_taken);
        if (current_word_index != strlen(random_word)) {
            printf("Word %d: %s (Error: incomplete word)\n", i + 1, random_word);
        }
        free(random_word);
    }

    // Print final results
    print_result(time_taken, words_typed, errors);
    return 0;
}