//FormAI DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {

    // The case begins.
    printf("It was a dull evening in London, and the weather was not helping either. I was lost in the gloomy thoughts of my mind, when a message came through the telegraph.\n");
    printf("It was a desperate plea for help from an old friend of mine who was in charge of a confidential government project.");

    // Check for error in opening file.
    FILE *file_ptr;
    file_ptr = fopen("confidential.txt", "r");
    if (file_ptr == NULL) {
        printf("I knew I had to act fast, so I rushed to their office to check the error.\n");
        printf("It seems that the file could not be opened. What kind of a situation was this, I thought.\n");
        perror("Error");
        exit(1);
    }

    // The case continues.
    printf("I entered the building, and there he was, my dear old friend, Professor Moriarty, pacing back and forth in his office, looking distressed.");

    // Check for invalid input.
    int num;
    printf("He handed me some papers and begged me to take a look. As I was going through them, I noticed a strange input value - %d.\n", num);
    if (num < 0 || num > 10) {
        printf("This input is invalid. I must handle this error immediately!\n");
        fprintf(stderr, "Invalid input. Please enter a number between 0 and 10.\n");
        exit(1);
    }

    // The case takes a turn.
    printf("As I was leaving the office, I heard a loud noise coming from the basement. It seemed like something was not right.\n");
    printf("I went to the basement and saw that the power supply had been cut off. This is serious, I thought.\n");

    // Check for divide by zero error.
    int a = 10, b = 0, result;
    printf("I figured out that the power supply had been cut off due to a divide by zero error. I must fix this before it's too late.\n");
    if (b == 0) {
        printf("Divide by zero is not allowed. This must be handled promptly!\n");
        fprintf(stderr, "Error: Division by zero.\n");
        exit(1);
    }
    else {
        result = a / b;
    }

    // The case concludes.
    printf("After an intense investigation, I found out that the power supply issue was caused by a malicious software installed by a rival company.");
    printf("I made sure to secure the system, and gave Professor Moriarty some advice on how to avoid such errors in the future.\n");
    printf("As I left the building, I couldn't help but wonder - what other errors may lie ahead, waiting to be uncovered?\n");

    return 0;
}