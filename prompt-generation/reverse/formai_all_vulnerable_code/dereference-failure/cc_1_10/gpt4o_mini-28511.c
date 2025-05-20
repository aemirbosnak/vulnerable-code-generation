//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_LINES 10

// Function to encode a string: for demonstration, we will just reverse it
char* encode_string(const char* input) {
    size_t len = strlen(input);
    char* encoded = (char*)malloc(len + 1);
    if (encoded == NULL) {
        perror("Unable to allocate memory for encoded string");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < len; i++) {
        encoded[i] = input[len - 1 - i];
    }
    encoded[len] = '\0'; // Null terminate the string
    return encoded;
}

// Function to free the dynamically allocated strings
void free_encoded_strings(char** encoded_strings, int count) {
    for (int i = 0; i < count; i++) {
        free(encoded_strings[i]); // Free each encoded string
    }
    free(encoded_strings); // Free the array of pointers
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char** encoded_strings = (char**)malloc(MAX_LINES * sizeof(char*));
    if (encoded_strings == NULL) {
        perror("Unable to allocate memory for encoded strings");
        return EXIT_FAILURE;
    }

    int line_count = 0;

    printf("Enter up to %d lines of text (type 'exit' to quit):\n", MAX_LINES);
    
    while (line_count < MAX_LINES) {
        printf("Line %d: ", line_count + 1);
        fgets(input, MAX_INPUT_LENGTH, stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break; // Exit the loop if user types "exit"
        }

        // Encode the input string
        encoded_strings[line_count] = encode_string(input);
        line_count++;
    }

    // Displaying the encoded strings
    printf("\nEncoded Strings:\n");
    for (int i = 0; i < line_count; i++) {
        printf("Encoded Line %d: %s\n", i + 1, encoded_strings[i]);
    }

    // Free the allocated memory
    free_encoded_strings(encoded_strings, line_count);

    printf("Memory freed successfully. Exiting the program.\n");
    return EXIT_SUCCESS;
}