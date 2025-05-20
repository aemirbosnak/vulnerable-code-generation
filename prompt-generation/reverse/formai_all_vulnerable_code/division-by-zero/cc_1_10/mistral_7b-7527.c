//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OPERAND 100
#define MAX_OPERATIONS 10
#define MIN_OPERATIONS 5

typedef enum {ADD, SUB, MUL, DIV} Operation;

Operation randomOperation() {
    return (Operation)(rand() % 4);
}

int randomNumber() {
    return rand() % (MAX_OPERAND + 1);
}

int main() {
    srand(time(NULL));

    int a, b, result;
    Operation op;

    for (int i = 0; i < 10; i++) {
        a = randomNumber();
        b = randomNumber();

        op = randomOperation();

        printf("Expressions %d and %d %s %s = ", i + 1, a,
            (op == ADD ? "+" : (op == SUB ? "-" : (op == MUL ? "*" : "/"))),
            (op == ADD || op == SUB ? b : ""));

        scanf("%d", &result);

        switch (op) {
            case ADD:
                if (a + b != result) {
                    printf("Incorrect answer. Try again.\n");
                    i--;
                }
                break;
            case SUB:
                if (a - b != result) {
                    printf("Incorrect answer. Try again.\n");
                    i--;
                }
                break;
            case MUL:
                if (a * b != result) {
                    printf("Incorrect answer. Try again.\n");
                    i--;
                }
                break;
            case DIV:
                if (a / b != result) {
                    printf("Incorrect answer. Try again.\n");
                    i--;
                } else if (b == 0) {
                    printf("Cannot divide by zero.\n");
                    i--;
                }
                break;
        }
    }

    printf("\nCongratulations! You have completed the typing speed test.\n");

    return 0;
}