//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A happy little struct for storing our expression data
typedef struct {
    char *expression;
    int parsed;
} expression_t;

// A prototype for our happy little function that we'll be writing
expression_t *parse_expression(char *expression);

int main() {
    // Let's make a happy little array of expressions
    char *expressions[] = {
        "1 + 2",
        "3 * 4",
        "(5 + 6) * 7",
        "8 - 9"
    };

    // Now let's loop through our array and parse each expression
    for (int i = 0; i < 4; i++) {
        // We'll create a new expression struct for each iteration
        expression_t *expression = parse_expression(expressions[i]);

        // Now let's print out the happy little expression
        printf("Expression: %s\n", expression->expression);

        // And let's see if it parsed happily
        if (expression->parsed) {
            printf("Parsed: Yes\n");
        } else {
            printf("Parsed: No\n");
        }

        // Finally, let's free our happy little expression
        free(expression);
    }

    return 0;
}

// This is our happy little function that parses an expression
expression_t *parse_expression(char *expression) {
    // Let's create a new expression struct and copy our expression into it
    expression_t *result = malloc(sizeof(expression_t));
    result->expression = strdup(expression);

    // Now let's pretend we're actually doing some parsing here...

    // And finally, let's pretend we're done parsing and set our parsed flag to true
    result->parsed = 1;

    // And here's our happy little parsed expression
    return result;
}