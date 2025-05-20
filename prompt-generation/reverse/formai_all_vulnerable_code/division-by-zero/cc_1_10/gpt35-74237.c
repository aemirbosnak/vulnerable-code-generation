//FormAI DATASET v1.0 Category: Math exercise ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int rand_num, answer, guess_count = 0;
    srand(time(0));
    rand_num = rand() % 100 + 1;

    printf("You have hacked into a top-secret system. To prove your worth, solve this equation:\n");
    printf("x^3 - 9x^2 + 23x - 15 = 0\n");

    do {
        printf("\nEnter your guess for the value of x: ");
        scanf("%d", &answer);
        guess_count++;
        if (answer != 3) {
            printf("WRONG GUESS! The system has detected your presence and started closing in...\n");
            printf("Try again! Your time is running out...\n");
        }
    } while (answer != 3);

    printf("You have solved the equation and prevented the system from detecting your presence!\n");
    printf("Now, for your next challenge...\n");

    int a, b, operator_choice, answer_choice, result;

    printf("Which operation do you want to perform?\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &operator_choice);
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);

    switch (operator_choice) {
        case 1:
            printf("%d + %d = ", a, b);
            scanf("%d", &answer_choice);
            result = a + b;
            break;
        case 2:
            printf("%d - %d = ", a, b);
            scanf("%d", &answer_choice);
            result = a - b;
            break;
        case 3:
            printf("%d * %d = ", a, b);
            scanf("%d", &answer_choice);
            result = a * b;
            break;
        case 4:
            printf("%d / %d = ", a, b);
            scanf("%d", &answer_choice);
            result = a / b;
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    guess_count++;

    if (answer_choice == result) {
        printf("You have correctly solved the problem and passed the test!\n");
    } else {
        printf("WRONG ANSWER! The system has detected your presence and shut down the virtual environment...\n");
        printf("GAME OVER!\n");
        guess_count = 0;
    }

    printf("\n\nYOU HAVE MADE %d TOTAL GUESSES!\n", guess_count);

    return 0;
}