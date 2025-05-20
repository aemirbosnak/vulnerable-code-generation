//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100
#define DATE_FORMAT_LENGTH 20

// Function to parse and convert natural language date
void convertDate(char *input) {
    struct tm timeInfo;
    char formattedDate[DATE_FORMAT_LENGTH];
    char *token;

    // Initialize the timeInfo structure
    memset(&timeInfo, 0, sizeof(timeInfo));
    timeInfo.tm_isdst = -1; // Let mktime determine if DST is in effect

    // Tokenizing input to extract date components
    token = strtok(input, " ");
    
    if (strcmp(token, "today") == 0) {
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(formattedDate, DATE_FORMAT_LENGTH, "%Y-%m-%d", tm_info);
        printf("Today's date is: %s\n", formattedDate);
        return;
    }

    // Parse based on the input structure
    if (strcmp(token, "tomorrow") == 0) {
        time_t t = time(NULL) + 86400; // Add a day
        struct tm *tm_info = localtime(&t);
        strftime(formattedDate, DATE_FORMAT_LENGTH, "%Y-%m-%d", tm_info);
        printf("Tomorrow's date will be: %s\n", formattedDate);
        return;
    }

    // Check for a specific date request
    if (strcmp(token, "on") == 0) {
        token = strtok(NULL, " "); // Get the   
        int day = atoi(token); // Get the day
        
        token = strtok(NULL, " "); // Expect the month
        int month;
        if (strcmp(token, "January") == 0) month = 1;
        else if (strcmp(token, "February") == 0) month = 2;
        else if (strcmp(token, "March") == 0) month = 3;
        else if (strcmp(token, "April") == 0) month = 4;
        else if (strcmp(token, "May") == 0) month = 5;
        else if (strcmp(token, "June") == 0) month = 6;
        else if (strcmp(token, "July") == 0) month = 7;
        else if (strcmp(token, "August") == 0) month = 8;
        else if (strcmp(token, "September") == 0) month = 9;
        else if (strcmp(token, "October") == 0) month = 10;
        else if (strcmp(token, "November") == 0) month = 11;
        else if (strcmp(token, "December") == 0) month = 12;

        token = strtok(NULL, " "); // Expect the year
        int year = atoi(token);

        // Setting the date
        timeInfo.tm_year = year - 1900;
        timeInfo.tm_mon = month - 1;
        timeInfo.tm_mday = day;

        // Convert to time_t and then format
        time_t rawtime = mktime(&timeInfo);
        strftime(formattedDate, DATE_FORMAT_LENGTH, "%Y-%m-%d", localtime(&rawtime));
        printf("The date you requested is: %s\n", formattedDate);
        return;
    }

    // Fallback if input doesn't match recognized patterns
    printf("I'm not sure how to interpret that date. Please try again!\n");
}

int main() {
    char input[MAX_INPUT_LENGTH];
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can ask me about dates like:\n");
    printf("1. 'today'\n");
    printf("2. 'tomorrow'\n");
    printf("3. 'on 15 May 2023'\n");
    printf("Type a date in natural language: ");

    // Read user input
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Convert and display the date
    convertDate(input);

    // Thank the user and exit
    printf("Thank you for using the date converter! Have a great day!\n");
    return 0;
}