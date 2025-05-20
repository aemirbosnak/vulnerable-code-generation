//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A Scientific Natural Language Date Converter Program
 * 
 * Compiled by [Your Name]
 * Date: [Current Date]
 */

// Function to convert month name to its corresponding number
int getMonth(char* month) {
    char months[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; ++i) {
        if (strcmp(month, months[i]) == 0) {
            return i + 1;
        }
    }
    return 0;
}

// Function to convert date in natural language to its corresponding C-compatible format
char* convertToCDate(char* naturalDate) {
    char* token = strtok(naturalDate, " ");
    int month = getMonth(token);
    if (month == 0) {
        return "Invalid month name!";
    }
    token = strtok(NULL, " ");
    int day = atoi(token);
    if (day <= 0 || day > 31) {
        return "Invalid day number!";
    }
    token = strtok(NULL, " ");
    int year = atoi(token);
    if (year <= 0) {
        return "Invalid year number!";
    }
    char* cDate = (char*) malloc(sizeof(char) * 11);
    snprintf(cDate, 11, "%04d-%02d-%02d", year, month, day);
    return cDate;
}

// Main function to test the program
int main() {
    char naturalDate[20];
    printf("Enter a date in natural language (Ex: Jan 10 2022): ");
    fgets(naturalDate, 20, stdin);
    char* cDate = convertToCDate(naturalDate);
    printf("Natural Language Date: %s\n", naturalDate);
    printf("C-Compatible Date: %s\n", cDate);
    free(cDate);
    return 0;
}