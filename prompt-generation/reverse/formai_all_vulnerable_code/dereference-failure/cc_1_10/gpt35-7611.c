//FormAI DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char filename[50];
    char input[200];
    time_t now;
    struct tm *currentTime;
    FILE *fp;

    printf("Welcome to your Digital Diary!\n");
    printf("What would you like to name today's diary entry? ");
    fgets(filename, sizeof(filename), stdin);  // Get the filename from the user
    strtok(filename, "\n");  // Remove the newline character from the input

    now = time(NULL);
    currentTime = localtime(&now);

    // Create the filename using today's date
    sprintf(filename + strlen(filename), "_%d-%d-%d.txt", currentTime->tm_mon+1, currentTime->tm_mday, currentTime->tm_year+1900);

    fp = fopen(filename, "w");  // Open the file in write mode

    if(fp == NULL) {
        printf("Oops, something went wrong. Please try again later.\n");
        return 1;
    }

    printf("Great! You've started a new diary entry.\n");
    printf("Type away your thoughts and musings, and when you're done, type 'save' on a new line to save your entry.\n");

    while(1) {
        fgets(input, sizeof(input), stdin);  // Get user input

        if(strcmp(input, "save\n") == 0) {  // If user types 'save', break out of loop and close file
            printf("Saving diary entry as %s ...\n", filename);
            break;
        }

        fprintf(fp, "%s", input);  // Write input to file
    }

    fclose(fp);  // Close the file

    printf("Diary entry saved!\n"); 

    return 0;
}