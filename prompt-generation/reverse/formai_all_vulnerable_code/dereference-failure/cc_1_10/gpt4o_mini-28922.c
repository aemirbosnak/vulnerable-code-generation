//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to evaluate a mathematical expression given as string
int evaluateExpression(const char *expr) {
    int result = 0;
    int currentNumber = 0;
    char operator = '+';
    
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        
        // Check if the character is a digit
        if (isdigit(ch)) {
            currentNumber = currentNumber * 10 + (ch - '0');
        }
        
        // If the character is an operator or it's the last character, evaluate
        if (!isdigit(ch) || i == strlen(expr) - 1) {
            if (operator == '+') {
                result += currentNumber;
            } else if (operator == '-') {
                result -= currentNumber;
            }
            currentNumber = 0; // Reset the current number
            operator = ch; // Update the operator
        }
    }
    return result;
}

// Function to count the number of terms in an expression
int countTerms(const char *expr) {
    int count = 0;
    int length = strlen(expr);
    
    for (int i = 0; i < length; i++) {
        if (expr[i] == '+' || expr[i] == '-') {
            count++;
        }
    }
    
    return count + 1; // Add one for the last term
}

// Function to split expression into an array of terms
char** splitExpression(const char *expr, int *numTerms) {
    *numTerms = countTerms(expr);
    char **terms = (char**)malloc(*numTerms * sizeof(char*));
    
    char *temp = strdup(expr); // Duplicate the input string
    char *token = strtok(temp, "+-");
    
    int index = 0;
    while (token != NULL) {
        terms[index] = strdup(token); // Copy the term
        token = strtok(NULL, "+-");
        index++;
    }
    
    free(temp); // Free duplicated string
    return terms;
}

// Function to print terms of the expression
void printTerms(char **terms, int numTerms) {
    printf("Terms in the expression:\n");
    for (int i = 0; i < numTerms; i++) {
        printf("Term %d: %s\n", i + 1, terms[i]);
        free(terms[i]); // Free each term
    }
    free(terms); // Free the terms array
}

// Main function
int main() {
    char expression[100];
    
    // Input mathematical expression from the user
    printf("Enter a mathematical expression (e.g., 5+3-2+8): ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0; // Removes newline character

    // Evaluate the expression
    int result = evaluateExpression(expression);
    printf("Result of the expression \"%s\" is: %d\n", expression, result);

    // Count and print terms
    int numTerms;
    char **terms = splitExpression(expression, &numTerms);
    printTerms(terms, numTerms);

    return 0;
}