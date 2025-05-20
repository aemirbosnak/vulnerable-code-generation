//Falcon-180B DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int num1, num2, operation;
    int sum = 0, correct_answers = 0;
    int total_questions = 10;

    for (int i = 0; i < total_questions; i++) {
        num1 = rand() % 100;
        num2 = rand() % 100;
        operation = rand() % 4;

        switch (operation) {
            case 0:
                printf("Question %d: %d + %d = ", i+1, num1, num2);
                scanf("%d", &sum);
                if (sum == num1 + num2) {
                    printf("Correct!\n");
                    correct_answers++;
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 1:
                printf("Question %d: %d - %d = ", i+1, num1, num2);
                scanf("%d", &sum);
                if (sum == num1 - num2) {
                    printf("Correct!\n");
                    correct_answers++;
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 2:
                printf("Question %d: %d * %d = ", i+1, num1, num2);
                scanf("%d", &sum);
                if (sum == num1 * num2) {
                    printf("Correct!\n");
                    correct_answers++;
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 3:
                printf("Question %d: %d / %d = ", i+1, num1, num2);
                scanf("%d", &sum);
                if (sum == num1 / num2) {
                    printf("Correct!\n");
                    correct_answers++;
                } else {
                    printf("Incorrect.\n");
                }
                break;
        }
    }

    printf("You got %d out of %d correct.\n", correct_answers, total_questions);

    return 0;
}