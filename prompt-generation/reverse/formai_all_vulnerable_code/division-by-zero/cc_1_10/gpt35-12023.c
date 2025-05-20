//FormAI DATASET v1.0 Category: Educational ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {

    int A = 100;
    int B = 50;
    int C = 200;

    printf("Welcome to the Surrealist Calculator!\n\n");

    printf("Please enter a random number between 1 and 50: ");
    scanf("%d", &A);

    printf("\nPlease enter a different random number between 100 and 200: ");
    scanf("%d", &C);

    if(A < 25) {
        printf("\nWhoa! Your first number is pretty small!\n");
    }
    else if(A < 50) {
        printf("\nHmm... your first number is definitely interesting.\n");
    }
    else {
        printf("\nAn excellent choice for your first number!\n");
    }

    if(C < 120) {
        printf("Your second number is quite small...\n");
    }
    else if(C < 180) {
        printf("Your second number is a bit more proportionate...\n");
    }
    else {
        printf("Wow! Your second number is big and beautiful!\n");
    }

    printf("\nNow, let's do some calculations! ");

    printf("\n\n%d + %d = %d\n", A, B, (A + B));

    printf("\n%d - %d = %d\n", C, B, (C - B));

    printf("\n%d * %d = %d\n", A, C, (A * C));

    printf("\n%d / %d = %d\n", C, A, (C / A));

    printf("\nThanks for exploring the surreal world of calculation with me today. Goodbye!\n");


    return 0;
}