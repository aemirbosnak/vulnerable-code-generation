//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result;
    char operator;
    float decimal1, decimal2, decimalResult;
    int count = 0;
    int limit = 10;

    srand(time(NULL));
    printf("Welcome to the Arithmetic Game!\n");
    printf("You will be given %d problems to solve.\n", limit);
    printf("Enter your name: ");
    scanf("%s", &operator);

    while(count < limit) {
        num1 = rand() % 100;
        num2 = rand() % 100;

        switch(rand() % 4) {
            case 0:
                printf("Problem %d: %d + %d = ", count+1, num1, num2);
                scanf("%d", &result);
                if(result == num1 + num2) {
                    printf("Correct!\n");
                    count++;
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 1:
                printf("Problem %d: %d - %d = ", count+1, num1, num2);
                scanf("%d", &result);
                if(result == num1 - num2) {
                    printf("Correct!\n");
                    count++;
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 2:
                printf("Problem %d: %d * %d = ", count+1, num1, num2);
                scanf("%d", &result);
                if(result == num1 * num2) {
                    printf("Correct!\n");
                    count++;
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 3:
                printf("Problem %d: %d / %d = ", count+1, num1, num2);
                scanf("%f", &decimal1);
                if(decimal1 == num1 / num2) {
                    printf("Correct!\n");
                    count++;
                } else {
                    printf("Incorrect.\n");
                }
                break;
        }
    }

    printf("Congratulations! You have completed the Arithmetic Game.\n");
    return 0;
}