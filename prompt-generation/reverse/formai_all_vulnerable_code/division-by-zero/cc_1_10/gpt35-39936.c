//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() 
{
    char alphabets[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int total_time = 60, correct_count = 0, wrong_count = 0, typed_count = 0, i, j;
    char typed_string[100];
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < total_time) 
    {
        j = rand() % 52;
        printf("%c ", alphabets[j]);
        char input = getchar();

        if (input == '\n') 
        {
            break;
        }

        if (input == alphabets[j]) 
        {
            correct_count++;
        } 
        else 
        {
            wrong_count++;
        }
        typed_count++;
    }
    printf("\n\nYour result:\n");
    printf("Time taken: %d seconds\n", total_time);
    printf("Total typed: %d\n", typed_count);
    printf("Correct typed: %d\n", correct_count);
    printf("Wrong typed: %d\n", wrong_count);

    int accuracy = (correct_count * 100) / typed_count;
    printf("Accuracy: %d%%\n", accuracy);
    if (typed_count >= 50 && accuracy >= 70) 
    {
        printf("Congratulations! You have excellent typing skills!\n");
    } 
    else 
    {
        printf("Try again to improve your typing skills!\n");
    }

    return 0;
}