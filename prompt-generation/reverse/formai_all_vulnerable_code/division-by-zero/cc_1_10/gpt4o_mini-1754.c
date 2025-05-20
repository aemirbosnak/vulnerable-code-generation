//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 5

void display_welcome_message() {
    printf("============================================\n");
    printf("           Welcome to Math Quiz!           \n");
    printf("============================================\n");
    printf("You will be asked %d randomly generated math questions.\n", NUM_QUESTIONS);
    printf("Try to answer them correctly for the highest score!\n\n");
}

int generate_random_number(int limit) {
    return rand() % limit;
}

char get_random_operation() {
    char operations[] = {'+', '-', '*', '/'};
    return operations[generate_random_number(4)];
}

void generate_question(int *num1, int *num2, char *operation) {
    *operation = get_random_operation();

    switch (*operation) {
        case '+':
            *num1 = generate_random_number(100);
            *num2 = generate_random_number(100);
            break;
        case '-':
            *num1 = generate_random_number(100);
            *num2 = generate_random_number(*num1);
            break;
        case '*':
            *num1 = generate_random_number(12); // 0 to 11
            *num2 = generate_random_number(12); // 0 to 11
            break;
        case '/':
            *num2 = generate_random_number(11) + 1; // Avoid division by 0
            *num1 = *num2 * generate_random_number(12); // Ensure num1 is a multiple of num2
            break;
    }
}

int get_user_answer(int num1, int num2, char operation) {
    int answer;
    printf("What is %d %c %d? ", num1, operation, num2);
    scanf("%d", &answer);
    return answer;
}

int calculate_correct_answer(int num1, int num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

void display_score(int score) {
    printf("\nYou finished the quiz!\n");
    printf("Your score: %d out of %d\n", score, NUM_QUESTIONS);
    printf("Thank you for playing!\n");
}

int main() {
    int score = 0;
    int question_num, num1, num2, user_answer, correct_answer;
    char operation;

    // Initialize random number generator
    srand(time(0));

    display_welcome_message();

    for (question_num = 0; question_num < NUM_QUESTIONS; question_num++) {
        generate_question(&num1, &num2, &operation);
        
        user_answer = get_user_answer(num1, num2, operation);
        correct_answer = calculate_correct_answer(num1, num2, operation);

        if (user_answer == correct_answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n\n", correct_answer);
        }
    }

    display_score(score);

    return 0;
}