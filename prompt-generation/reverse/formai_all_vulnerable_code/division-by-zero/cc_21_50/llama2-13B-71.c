//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    srand(time(NULL));

    int random_number = rand() % 100;
    int result = 0;

    printf("Welcome to the arithmetic adventure! \n");

    while (1) {
        // Generate a random operation (add, sub, mul, div)
        int operation = rand() % 4;

        switch (operation) {
            case 0: // Addition
                result = random_number + rand() % 10;
                break;
            case 1: // Subtraction
                result = random_number - rand() % 10;
                break;
            case 2: // Multiplication
                result = random_number * rand() % 10;
                break;
            case 3: // Division
                result = random_number / rand() % 10;
                break;
        }

        // Print the result and ask the user for input
        printf("You have %d. Do you want to add, subtract, multiply, or divide? (type 'a', 's', 'm', or 'd')\n", result);
        char input = getchar();

        if (input == 'a' || input == 'A') {
            // Addition
            result += random_number;
            printf("You have %d now. Do you want to continue? (type 'y' or 'n')\n", result);
            char continue_input = getchar();

            if (continue_input == 'y' || continue_input == 'Y') {
                continue;
            } else {
                break;
            }
        } else if (input == 's' || input == 'S') {
            // Subtraction
            result -= random_number;
            printf("You have %d now. Do you want to continue? (type 'y' or 'n')\n", result);
            char continue_input = getchar();

            if (continue_input == 'y' || continue_input == 'Y') {
                continue;
            } else {
                break;
            }
        } else if (input == 'm' || input == 'M') {
            // Multiplication
            result *= random_number;
            printf("You have %d now. Do you want to continue? (type 'y' or 'n')\n", result);
            char continue_input = getchar();

            if (continue_input == 'y' || continue_input == 'Y') {
                continue;
            } else {
                break;
            }
        } else if (input == 'd' || input == 'D') {
            // Division
            result /= random_number;
            printf("You have %d now. Do you want to continue? (type 'y' or 'n')\n", result);
            char continue_input = getchar();

            if (continue_input == 'y' || continue_input == 'Y') {
                continue;
            } else {
                break;
            }
        } else {
            printf("Invalid input. Game over! \n");
            break;
        }
    }

    printf("You have reached the end of the adventure! Your final score is %d. \n", result);
    return 0;
}