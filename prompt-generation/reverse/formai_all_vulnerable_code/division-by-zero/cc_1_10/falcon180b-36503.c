//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char ch;
    int score = 0, correct = 0, wrong = 0;
    float speed = 0;
    char sentence[100];
    int length, i;
    time_t start, end;

    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the sentence from the user
    printf("Enter the length of the sentence: ");
    scanf("%d", &length);

    // Generate a random sentence
    for(i=0; i<length; i++) {
        ch = rand() % 26 + 'a';
        sentence[i] = ch;
    }
    sentence[length] = '\0';

    // Print the sentence
    printf("\n%s\n", sentence);

    // Start the timer
    start = clock();

    // Get the user's choice
    printf("\nChoose a, b, c or d as your solution.\n");
    scanf(" %c", &ch);

    // Read the characters from the keyboard
    while((ch = getchar())!= '\n') {
        // Check if the character is correct
        if(ch == sentence[correct]) {
            correct++;
        } else {
            wrong++;
        }
        correct %= length;

        // Print the character
        putchar(ch);
    }

    // Stop the timer
    end = clock();

    // Calculate the speed
    speed = (float)length / (double)(end - start);

    // Print the results
    printf("\nYou scored %d out of %d.\n", score, length);
    printf("Your speed was %.2f characters per second.\n", speed);

    return 0;
}