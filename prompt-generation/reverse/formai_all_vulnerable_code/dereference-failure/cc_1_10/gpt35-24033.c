//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* function to sanitize user input */
char* sanitize_input(char* input) {

    /* allocate memory of same size of input string */
    char* sanitized_input = malloc(sizeof(char) * strlen(input));

    /* loop through the input string */
    int i, j = 0;
    for(i = 0; i < strlen(input); i++) {

        /* check if character is an alphabet or a digit */
        if(isalpha(input[i]) || isdigit(input[i])) {
            /* if yes, add to sanitized string */
            sanitized_input[j] = input[i];
            j++;
        }
    }

    /* terminate sanitized string with null character */
    sanitized_input[j] = '\0';

    /* return sanitized string */
    return sanitized_input;

}

int main() {

    printf("Enter your input: ");
    /* allocate memory to store user input */
    char* user_input = malloc(sizeof(char) * 100);
    /* use fgets to read user input */
    fgets(user_input, 100, stdin);

    /* sanitize user input using sanitize_input function */
    char* sanitized_input = sanitize_input(user_input);

    printf("Sanitized input: %s\n", sanitized_input);

    /* free memory allocated for user input and sanitized input */
    free(user_input);
    free(sanitized_input);

    return 0;
}