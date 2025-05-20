//FormAI DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Welcome the user
    printf("Welcome to the Mind-bending Text Processor!\n");

    // Ask for input
    printf("Please enter your text: ");
    char* input = malloc(256); // allocate memory for input string
    scanf("%[^\n]", input); // read input until newline character

    // Initialize variables
    int length = strlen(input);
    char* output = malloc((length * 2) + 1); // allocate memory for output string
    
    // Loop through input string
    int i = 0, j = 0;
    while (i < length) {
        // Mind-bending transformation
        if (input[i] == ' ') {
            output[j] = 'M';
            output[j+1] = 'i';
            output[j+2] = 'n';
            output[j+3] = 'd';
            output[j+4] = '-';
            output[j+5] = 'b';
            output[j+6] = 'e';
            output[j+7] = 'n';
            output[j+8] = 'd';
            output[j+9] = 'i';
            output[j+10] = 'n';
            output[j+11] = 'g';
            output[j+12] = ' ';
            j += 13;
        } else if (input[i] == '.') {
            output[j] = '!';
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
        i++;
    }

    // Output the result
    printf("\n\nYour mind-bending text is: %s\n", output);

    // Free memory
    free(input);
    free(output);

    return 0;
}