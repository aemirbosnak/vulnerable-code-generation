//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MIN_NUMBER 1

int main() {
    int number, operation, choice;
    char input[50];

    srand(time(NULL));

    while (1) {
        system("cls");

        printf("Welcome to Arithmetic Land!\n");
        printf("---------------------------------\n");

        printf("Choose an operation (+, -, *, /, %): ");
        scanf(" %c", &operation);

        printf("Enter two numbers: ");
        scanf(" %d%c", &number, &choice);

        if (operation == '+') {
            printf("Addition: %d + %d = ", number, choice);
            printf("%d\n", number + choice);
        } else if (operation == '-') {
            printf("Subtraction: %d - %d = ", number, choice);
            printf("%d\n", number - choice);
        } else if (operation == '*') {
            printf("Multiplication: %d x %d = ", number, choice);
            printf("%d\n", number * choice);
        } else if (operation == '/') {
            printf("Division: %d / %d = ", number, choice);
            printf("%d\n", number / choice);
        } else if (operation == '%') {
            printf("Modulus: %d %c %d = ", number, operation, choice);
            printf("%d\n", number % choice);
        }

        printf("Do you want to play again (y/n)? ");
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    return 0;
}