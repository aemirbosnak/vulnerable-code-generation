//Falcon-180B DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    int length;
} Text;

int main(int argc, char *argv[]) {
    FILE *file;
    Text input_text;
    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    // Open the input file for reading
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Initialize the input text
    input_text.text = NULL;
    input_text.length = 0;

    // Read the input file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;

        // Allocate memory for the input text
        if (input_text.text == NULL) {
            input_text.text = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
            input_text.length = 0;
        }

        // Append the current line to the input text
        strcat(input_text.text, line);
        input_text.length += strlen(line);

        // Check if the input text exceeds the maximum length
        if (input_text.length >= MAX_LINE_LENGTH) {
            printf("Error: input text exceeds maximum length.\n");
            free(input_text.text);
            return 1;
        }
    }

    // Close the input file
    fclose(file);

    // Reverse the input text
    char *start = input_text.text;
    char *end = start + input_text.length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    // Print the reversed input text
    printf("Reversed input text:\n");
    printf("%s", input_text.text);

    // Free the input text memory
    free(input_text.text);

    return 0;
}