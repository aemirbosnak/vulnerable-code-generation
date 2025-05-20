//LLAMA2-13B DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define GRATITUDE_MESSAGE "You are amazing! Thank you for being you!"

void gratitudeMessage(void);
void printGratitudeMessage(void);

int main(void)
{
    srand(time(NULL));

    // Generate a random word of gratitude
    char *word = malloc(sizeof(char) * MAX_LENGTH);
    for (int i = 0; i < MAX_LENGTH; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    // Print the gratitude message with the random word
    gratitudeMessage();
    printGratitudeMessage();

    // Give a hug to the user
    printf("🤗\n");

    return 0;
}

void gratitudeMessage(void)
{
    // Generate a random number of exclamation marks
    int exclamationMarks = rand() % 5 + 1;

    // Print the gratitude message with the random number of exclamation marks
    for (int i = 0; i < exclamationMarks; i++) {
        printf("!");
    }
    printf("\n");
}

void printGratitudeMessage(void)
{
    // Print the gratitude message with a random font size
    for (int i = 0; i < 10; i++) {
        printf("%c", GRATITUDE_MESSAGE[rand() % strlen(GRATITUDE_MESSAGE)]);
        printf(" ");
    }
    printf("\n");
}