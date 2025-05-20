//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_INPUT_LEN 50

char *input = NULL;
size_t input_len = 0;
size_t line_len = 0;

void sanitize_input(char **str) {
    size_t len = strlen(*str);
    if (len > 0 && (*(*str) < ' ' || (*(*str) > '~'))) {
        printf("Invalid character found in input! Please try again.\n");
        free(*str);
        *str = malloc(1);
        *(*str) = '\0';
        return;
    }
    // Remove newline character if present
    if (len > 0 && (*(str + len - 1) == '\n')) {
        *str = realloc(*str, len - 1);
        memmove(*str, *str, len - 1);
        (*str)[len - 1] = '\0';
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--------- Enthusiastic User Input Sanitizer ---------");
        printf("\n1. Enter your name\n2. Enter a string\n3. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        if (choice == 1) {
            printf("Enter your name: ");
            getline(&input, &input_len, stdin);
            sanitize_input(&input);
            printf("Hello, %s!\n", input);
            free(input);
        } else if (choice == 2) {
            printf("Enter a string: ");
            getline(&input, &line_len, stdin);
            input_len = strlen(input);
            if (input_len > MAX_INPUT_LEN) {
                printf("Input too long! Please enter a string of maximum %d characters.\n", MAX_INPUT_LEN);
                free(input);
                continue;
            }
            sanitize_input(&input);
            printf("You entered: %s\n", input);
            free(input);
        } else {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}