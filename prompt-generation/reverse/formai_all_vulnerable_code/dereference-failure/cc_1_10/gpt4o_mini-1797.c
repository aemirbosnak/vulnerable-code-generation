//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printGreeting() {
    printf("Welcome to the Shape Shifting Date Converter!\n");
    printf("Transform your dates from a simple format to something extraordinary!\n");
}

void getInput(char *dateStr) {
    printf("Enter a date in the format YYYY-MM-DD: ");
    fgets(dateStr, 11, stdin);
    // Remove newline character
    dateStr[strcspn(dateStr, "\n")] = 0;
}

int validateDate(const char *dateStr) {
    struct tm tm;
    char *ptr;
    
    // Try to parse the input date string
    ptr = strptime(dateStr, "%Y-%m-%d", &tm);
    
    // If parsing succeeded and reached the end of the string, it's valid
    if (ptr != NULL && *ptr == '\0') {
        // Convert to a valid timestamp to check validity
        time_t t = mktime(&tm);
        return (t != -1);
    }
    return 0;
}

void convertDate(const char *dateStr, char *outputStr) {
    struct tm tm;
    strptime(dateStr, "%Y-%m-%d", &tm);
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int day = tm.tm_mday;
    int month = tm.tm_mon; // tm_mon is 0-based
    int year = tm.tm_year + 1900; // tm_year is years since 1900

    snprintf(outputStr, 100, "%d %s, %d", day, months[month], year);
}

void printConvertedDate(const char *convertedDate) {
    printf("The converted date is: %s\n", convertedDate);
}

void shapeShift(const char *originalDate) {
    char convertedDate[100];
    convertDate(originalDate, convertedDate);
    printConvertedDate(convertedDate);
}

int main() {
    char dateStr[11];
    
    printGreeting();
    
    getInput(dateStr);
    
    if (validateDate(dateStr)) {
        shapeShift(dateStr);
    } else {
        printf("The date you entered is invalid. Please use the YYYY-MM-DD format.\n");
    }

    return 0;
}