//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <regex.h>

int main() {
    char input[100];
    printf("Enter a string with parentheses: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    char *p = strdup(input);
    regex_t regex;
    if (regcomp(&regex, "\\([^()]*(?:\\([^()]*(?:\\([^()]*(?:\\([^()]*)?)?)?)?)?)?\\)", 0)!= 0) {
        fprintf(stderr, "Compilation error\n");
        return 1;
    }

    int result = regexec(&regex, p, 0, NULL, 0);
    if (result!= 0) {
        fprintf(stderr, "Regex match error\n");
        return 1;
    }

    char *output = malloc(strlen(p) * sizeof(char));
    int stack[100];
    int top = -1;
    for (char *q = p; *q!= '\0'; q++) {
        if (*q == '(') {
            top++;
            stack[top] = *q;
        } else if (*q == ')') {
            top--;
            if (top < 0) {
                fprintf(stderr, "Unbalanced parentheses\n");
                return 1;
            } else {
                output[top] = stack[top];
            }
        } else {
            output[top] = *q;
        }
    }
    output[top] = '\0';

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

    free(p);
    regfree(&regex);
    return 0;
}