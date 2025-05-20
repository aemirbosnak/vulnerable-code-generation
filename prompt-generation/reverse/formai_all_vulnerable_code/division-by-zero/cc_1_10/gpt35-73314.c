//FormAI DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, answer, user_answer;
    char operator, choice;
    int score = 0;
    srand(time(NULL));
    printf("Welcome to the Math Quiz Program!\n");
    do {
        printf("Choose an operator (+ - * /): ");
        scanf(" %c", &operator);
        printf("Enter the range of numbers to practice: \n");
        printf("First number: ");
        scanf("%d", &num1);
        printf("Second number: ");
        scanf("%d", &num2);
        printf("How many questions would you like to answer? ");
        int num_questions;
        scanf("%d", &num_questions);
        for (int i = 1; i <= num_questions; i++) {
            int num_a = rand() % (num2 + 1 - num1) + num1;
            int num_b = rand() % (num2 + 1 - num1) + num1;
            switch(operator) {
                case '+':
                    printf("\nQuestion %d: %d + %d = ", i, num_a, num_b);
                    answer = num_a + num_b;
                    break;
                case '-':
                    printf("\nQuestion %d: %d - %d = ", i, num_a, num_b);
                    answer = num_a - num_b;
                    break;
                case '*':
                    printf("\nQuestion %d: %d * %d = ", i, num_a, num_b);
                    answer = num_a * num_b;
                    break;
                case '/':
                    printf("\nQuestion %d: %d / %d = ", i, num_a, num_b);
                    answer = num_a / num_b;
                    break;
                default:
                    printf("\nInvalid operator entered!\n");
                    exit(0);
            }
            scanf("%d", &user_answer);
            if (user_answer == answer) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer is %d.\n", answer);
            }
        }
        printf("Your score is %d out of %d.\n", score, num_questions);
        printf("Would you like to try again? (y/n)");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("Thanks for using the Math Quiz Program!\n");
    return 0;
}