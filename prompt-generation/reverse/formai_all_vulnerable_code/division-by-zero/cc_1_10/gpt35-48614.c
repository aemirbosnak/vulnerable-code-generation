//FormAI DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, answer, count = 0;
    char choice;
    
    printf("\nWelcome to Math Exercise Program!\n\n");
    printf("Press Enter to start the program.");
    getchar(); // to wait for user input
    
    srand(time(NULL)); // to initialize random seed
    
    do {
        num1 = rand() % 101; // to generate random number between 0-100
        num2 = rand() % 101;
        
        switch (rand() % 4) {
            case 0:
                result = num1 + num2;
                printf("\n%d + %d = ", num1, num2);
                break;
            case 1:
                result = num1 - num2;
                printf("\n%d - %d = ", num1, num2);
                break;
            case 2:
                result = num1 * num2;
                printf("\n%d * %d = ", num1, num2);
                break;
            default:
                result = num1 / num2;
                printf("\n%d / %d = ", num1, num2);
        }
        
        scanf("%d", &answer);
        
        if (answer == result) {
            printf("Correct!\n");
            count++;
        } else {
            printf("Wrong! The correct answer is %d\n", result);
        }
        
        printf("\nDo you want to continue? (y/n) ");
        scanf(" %c", &choice); // to remove space after previous input
        
    } while (tolower(choice) == 'y');
    
    printf("\nYou have answered %d questions correctly.", count);
    
    return 0;
}