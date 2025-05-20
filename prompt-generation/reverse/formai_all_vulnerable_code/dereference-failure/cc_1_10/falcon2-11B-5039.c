//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // Check if the user has provided the input string and the dictionary file
    if (argc!= 3) {
        printf("Usage: %s <input_string> <dictionary_file>\n", argv[0]);
        return 1;
    }

    // Read the input string from the user
    char input_string[100];
    fgets(input_string, sizeof(input_string), stdin);

    // Convert the input string to lowercase for case-insensitive checking
    char *lower_input = strdup(input_string);
    for (int i = 0; lower_input[i]; i++)
        lower_input[i] = tolower(lower_input[i]);

    // Read the dictionary file and store its contents in an array
    char dictionary_file[100];
    strcpy(dictionary_file, argv[2]);
    FILE *dictionary = fopen(dictionary_file, "r");
    char *word = NULL;
    char dictionary_array[100][100];
    while (fscanf(dictionary, "%s", word)!= EOF) {
        strcpy(dictionary_array[strlen(dictionary_array)], word);
    }

    // Check for spelling errors in the input string
    int error_count = 0;
    for (int i = 0; i < strlen(input_string); i++) {
        for (int j = 0; j < strlen(dictionary_array); j++) {
            if (strcmp(lower_input + i, dictionary_array[j]) == 0) {
                error_count++;
                break;
            }
        }
    }

    // Print the error count and the input string if there are errors
    if (error_count > 0) {
        printf("Spelling errors found: %d\n", error_count);
        printf("Input string: %s\n", input_string);
    } else {
        printf("No spelling errors found.\n");
    }

    // Clean up memory
    free(lower_input);
    fclose(dictionary);

    return 0;
}