//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256

// Function to initialize the frequency counter array
void init_freq(int *freq) {
    int i;
    for (i = 0; i < MAX_CHAR; i++) {
        freq[i] = 0;
    }
}

// Function to increment the frequency count of a character
void inc_freq(int *freq, char ch) {
    freq[(int)ch]++;
}

// Function to print the frequency count of each character
void print_freq(int *freq) {
    int i, freq_val;
    for (i = 0; i < MAX_CHAR; i++) {
        if ((int)i >= 32 && (int)i <= 126) { // Print only printable ASCII characters
            freq_val = freq[i];
            printf("%c : %d\n", (char)i, freq_val);
        }
    }
}

int main(int argc, char *argv[]) {
    int freq[MAX_CHAR];
    int str_len, i;
    char *input_str;

    // Check if input string is provided
    if (argc != 2) {
        printf("Usage : %s <string>\n", argv[0]);
        return 1;
    }

    // Allocate memory for the input string
    input_str = (char *)calloc(strlen(argv[1]) + 1, sizeof(char));
    if (input_str == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Copy the input string to the allocated memory
    strncpy(input_str, argv[1], strlen(argv[1]) + 1);

    // Initialize the frequency counter array
    init_freq(freq);

    // Calculate the length of the input string
    str_len = strlen(input_str);

    // Increment the frequency count of each character in the input string
    for (i = 0; i < str_len; i++) {
        inc_freq(freq, input_str[i]);
    }

    // Print the frequency count of each character
    print_freq(freq);

    // Free the allocated memory
    free(input_str);

    return 0;
}