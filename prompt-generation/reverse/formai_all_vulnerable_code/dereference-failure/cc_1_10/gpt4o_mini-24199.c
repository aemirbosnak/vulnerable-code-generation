//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_INPUT 256
#define MAX_HISTORY 100

typedef struct History {
    char expression[MAX_INPUT];
    double result;
} History;

History history[MAX_HISTORY];
int history_count = 0;

void add_to_history(const char *expression, double result) {
    if (history_count < MAX_HISTORY) {
        strncpy(history[history_count].expression, expression, MAX_INPUT);
        history[history_count].result = result;
        history_count++;
    } else {
        printf("History is full. Cannot save the expression.\n");
    }
}

void show_history() {
    printf("\n=== Calculation History ===\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s = %lf\n", i + 1, history[i].expression, history[i].result);
    }
    printf("============================\n");
}

double evaluate_expression(const char *expression) {
    double result = 0.0;
    char *end_ptr;
    result = strtod(expression, &end_ptr); // Simple evaluation for demonstration

    if (*end_ptr == '\0') {
        return result;
    } else {
        printf("Invalid expression format! Returning 0.\n");
        return 0.0;
    }
}

void greet_user() {
    printf("=======================================\n");
    printf("  C-CyberCalc v1.0 - Neon Nights\n");
    printf("  A scientific calculator for hackers\n");
    printf("=======================================\n");
}

void display_menu() {
    printf("\nChoose an action:\n");
    printf("1. Calculate\n");
    printf("2. Show history\n");
    printf("3. Exit\n");
}

int main() {
    char input[MAX_INPUT];
    double result;

    greet_user();
    
    while (1) {
        display_menu();
        printf("Your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline after choice

        switch (choice) {
            case 1: // Calculate
                printf("Enter expression (use spaces for operators, e.g., '3 + 5'): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character

                result = evaluate_expression(input);
                printf("Result: %lf\n", result);
                add_to_history(input, result);
                break;

            case 2: // Show history
                show_history();
                break;

            case 3: // Exit
                printf("Goodbye, brave soul of the Neon City!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}