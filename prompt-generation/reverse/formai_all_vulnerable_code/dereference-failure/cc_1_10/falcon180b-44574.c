//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of given length
char *generateRandomString(int length) {
    char *string = (char *)malloc(length * sizeof(char));
    if (string == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        string[i] = rand() % 26 + 'a';
    }
    string[length - 1] = '\0';
    return string;
}

// Function to print the given string with a delay of 1 second between each character
void printStringWithDelay(char *string) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        printf("%c", string[i]);
        fflush(stdout);
        usleep(1000000);
    }
    printf("\n");
}

// Function to calculate the typing speed in words per minute (WPM)
float calculateWPM(int charactersTyped, int timeTaken) {
    float wpm = (float)charactersTyped / (timeTaken / 60);
    return wpm;
}

int main() {
    int length, charactersTyped, timeTaken;
    char *string;
    float wpm;

    // Get the length of the random string from the user
    printf("Enter the length of the random string: ");
    scanf("%d", &length);

    // Generate a random string of given length
    string = generateRandomString(length);

    // Print the string with a delay of 1 second between each character
    printf("Type the following string:\n");
    printStringWithDelay(string);

    // Get the time taken by the user to type the string
    time_t start, end;
    time(&start);
    charactersTyped = 0;
    while (getchar()!= '\n') {
        if (getchar() == string[charactersTyped]) {
            charactersTyped++;
        } else {
            printf("\nError: Invalid character!\n");
            exit(1);
        }
    }
    time(&end);
    timeTaken = end - start;

    // Calculate the typing speed in WPM
    wpm = calculateWPM(length, timeTaken);

    // Print the typing speed in WPM
    printf("Your typing speed is: %.2f WPM\n", wpm);

    return 0;
}