//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a summary of a given text
void summarizeText(char* text) {
    // Get the length of the input text
    int length = strlen(text);

    // Initialize the output summary string
    char* summary = (char*)malloc(length * sizeof(char));
    summary[0] = '\0';

    // Loop through the input text and generate the summary
    int index = 0;
    int maxIndex = 0;
    while (index < length) {
        // Find the next word in the text
        char* word = strtok(text + index, " \n\t");
        while (word!= NULL) {
            // Check if the word is already in the summary
            int found = 0;
            for (int i = 0; i < maxIndex; i++) {
                if (strcmp(summary + i * length, word) == 0) {
                    found = 1;
                    break;
                }
            }

            // If the word is not in the summary, add it
            if (!found) {
                strcat(summary, word);
                maxIndex++;
            }

            // Get the next word
            word = strtok(NULL, " \n\t");
        }

        // Increment the index
        index++;
    }

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the allocated memory
    free(summary);
}

int main() {
    // Read the input text from a file
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the text from the file
    char text[1024];
    fgets(text, sizeof(text), file);

    // Close the file
    fclose(file);

    // Call the summarizeText function
    summarizeText(text);

    return 0;
}