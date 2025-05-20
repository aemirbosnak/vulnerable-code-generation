//FormAI DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define a struct for storing mental calculations
typedef struct calculation {
    int a;
    int b;
    char operator;
    int answer;
} Calculation;

// Declare a function for performing mental calculations
int calculate(int a, char operator, int b) {
    int answer;
    switch(operator) {
        case '+':
            answer = a + b;
            break;
        case '-':
            answer = a - b;
            break;
        case '*':
            answer = a * b;
            break;
        case '/':
            answer = a / b;
            break;
        default:
            printf("Invalid operator");
            answer = 0;
    }
    return answer;
}

int main() {
    // Declare variables
    char name[20];
    int age;
    int score = 0;
    int num_calculations;
    Calculation *calculations;

    // Welcome the user to the program
    printf("Greetings! Welcome to the Futuristic Mental Arithmetic Program!\n");
    printf("Please tell me your name: ");
    scanf("%s", name);
    printf("And how old are you, %s? ", name);
    scanf("%d", &age);
    
    // Generate random number of calculations
    srand(time(NULL));
    num_calculations = rand() % 10 + 1;
    
    // Allocate memory for calculations
    calculations = malloc(num_calculations * sizeof(Calculation));

    // Ask user if they are ready to start
    printf("\nAre you ready to start, %s? (Y/N) ", name);
    char response;
    scanf(" %c", &response);

    if(response == 'Y' || response == 'y') {
        printf("\nGreat! Let's begin.\n");
        for(int i = 0; i < num_calculations; i++) {
            if(i > 0) {
                printf("\nNext question:\n");
            }
            // Generate random numbers and operator
            int a = rand() % 100;
            int b = rand() % 100;
            char operator_array[4] = {'+', '-', '*', '/'};
            char operator = operator_array[rand() % 4];

            // Ask user to perform mental calculation
            printf("What is %d %c %d? ", a, operator, b);
            int user_answer;
            scanf("%d", &user_answer);

            // Calculate correct answer
            int correct_answer = calculate(a, operator, b);

            // Store calculation in struct
            Calculation calculation = {a, b, operator, correct_answer};
            calculations[i] = calculation;

            // Check if user answer is correct
            if(user_answer == correct_answer) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %d.\n", correct_answer);
            }
        }
        // Print out final score
        printf("\nYou scored %d out of %d.\n", score, num_calculations);

        // Prompt user to view their mental calculation history
        printf("\nWould you like to see your mental calculation history? (Y/N) ");
        char response;
        scanf(" %c", &response);

        if(response == 'Y' || response == 'y') {
            printf("\nHere is your mental calculation history:\n\n");
            for(int i = 0; i < num_calculations; i++) {
                printf("%d %c %d = %d\n", calculations[i].a, calculations[i].operator, calculations[i].b, calculations[i].answer);
            }
        }

        // Free memory
        free(calculations);
    } else {
        printf("\nAlright, maybe next time. Goodbye!");
    }

    return 0;
}