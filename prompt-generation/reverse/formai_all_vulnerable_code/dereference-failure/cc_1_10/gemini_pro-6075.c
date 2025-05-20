//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trim leading and trailing whitespace from a string
char *trim(char *str) {
    size_t len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    while (isspace(*start))
        start++;

    while (isspace(*end) && end >= start)
        end--;

    *(end + 1) = '\0';
    return start;
}

// Validate an integer input
int get_int(const char *prompt) {
    char input[1024];
    int value;

    do {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // Remove trailing newline

        if (sscanf(input, "%d", &value) != 1) {
            printf("Invalid input. Please enter an integer.\n");
        }
    } while (sscanf(input, "%d", &value) != 1);

    return value;
}

// Validate a string input with a maximum length
char *get_string(const char *prompt, size_t max_len) {
    char *input = NULL;
    size_t len;

    do {
        printf("%s", prompt);
        input = fgets(input, max_len + 1, stdin);
        input[strcspn(input, "\n")] = 0;  // Remove trailing newline

        len = strlen(input);
        if (len == 0 || len > max_len) {
            printf("Invalid input. Please enter a string with a maximum length of %zu characters.\n", max_len);
        }
    } while (len == 0 || len > max_len);

    input = trim(input);  // Trim leading and trailing whitespace
    return input;
}

int main() {
    int age;
    char *name;

    printf("Hello, world!\n");

    age = get_int("Enter your age: ");
    name = get_string("Enter your name: ", 100);

    printf("Your name is %s and you are %d years old.\n", name, age);

    free(name);  // Free the memory allocated for the name string

    return 0;
}