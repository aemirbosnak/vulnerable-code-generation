//FormAI DATASET v1.0 Category: Online Examination System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, m, ans, score=0, max_score;
    char name[20];
    time_t t;

    // Seed random number generator
    srand((unsigned) time(&t));

    // Welcome message
    printf("Welcome to the C Online Examination System!\n\n");

    // Get student name and number of questions
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("How many questions would you like to answer? ");
    scanf("%d", &n);

    // Set max possible score
    max_score = n * 10;

    // Generate n questions for the student
    printf("\n");
    for(i=1; i<=n; i++) {
        int num1 = rand() % 10;
        int num2 = rand() % 10;
        int operator = rand() % 4;
        switch (operator) {
            case 0:
                printf("%d) %d + %d = ", i, num1, num2);
                ans = num1 + num2;
                break;
            case 1:
                printf("%d) %d - %d = ", i, num1, num2);
                ans = num1 - num2;
                break;
            case 2:
                printf("%d) %d * %d = ", i, num1, num2);
                ans = num1 * num2;
                break;
            case 3:
                printf("%d) %d / %d = ", i, num1, num2);
                ans = num1 / num2;
                break;
        }

        // Get student's answer and check if it's correct
        scanf("%d", &m);
        if(m == ans) {
            printf("\nCorrect!\n");
            score += 10;
        } else {
            printf("\nIncorrect. The correct answer is %d.\n", ans);
        }
    }

    // Display final score
    printf("\nThank you for taking the exam, %s.\n", name);
    printf("Your final score is %d out of %d.\n", score, max_score);

    return 0;
}