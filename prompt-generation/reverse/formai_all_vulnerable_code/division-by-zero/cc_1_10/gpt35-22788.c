//FormAI DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    
    printf("Welcome to the post-apocalyptic world!\n\n");
    printf("You need to use all your mathematical skills to survive here.\n\n");
    printf("We'll be generating a random arithmetic task for you to solve. If you get it right, you get to live another day. If you get it wrong... well, let's just say it won't be pretty.\n\n");
    
    int num1 = rand() % 100;
    int num2 = rand() % 100;
    char op = rand() % 4;

    switch(op) {
        case 0: // addition
            printf("What is %d + %d?\n", num1, num2);
            int ans;
            scanf("%d", &ans);
            if(ans == num1 + num2) {
                printf("Congratulations! You get to live another day.\n");
            }
            else {
                printf("Sorry, that was incorrect. You will now be banished into the wastelands.\n");
            }
            break;
            
        case 1: // subtraction
            printf("What is %d - %d?\n", num1, num2);
            scanf("%d", &ans);
            if(ans == num1 - num2) {
                printf("Congratulations! You get to live another day.\n");
            }
            else {
                printf("Sorry, that was incorrect. You will now be banished into the wastelands.\n");
            }
            break;
            
        case 2: // multiplication
            printf("What is %d * %d?\n", num1, num2);
            scanf("%d", &ans);
            if(ans == num1 * num2) {
                printf("Congratulations! You get to live another day.\n");
            }
            else {
                printf("Sorry, that was incorrect. You will now be banished into the wastelands.\n");
            }
            break;
            
        case 3: // division
            printf("What is %d / %d? (round to the nearest integer)\n", num1, num2);
            scanf("%d", &ans);
            if(ans == num1 / num2) {
                printf("Congratulations! You get to live another day.\n");
            }
            else {
                printf("Sorry, that was incorrect. You will now be banished into the wastelands.\n");
            }
            break;
    }
    
    return 0;
}