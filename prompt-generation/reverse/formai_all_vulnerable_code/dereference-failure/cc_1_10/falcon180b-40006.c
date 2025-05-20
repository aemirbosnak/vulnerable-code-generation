//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    char input[100];
    char *token;
    struct tm date;
    int year, month, day;
    int i;

    // Initialize the date structure with default values
    date.tm_year = 1900;
    date.tm_mon = 0;
    date.tm_mday = 1;

    // Get the input string from the user
    printf("Enter a date in the format 'DD/MM/YYYY': ");
    scanf("%s", input);

    // Parse the input string to extract the day, month, and year
    token = strtok(input, "/");
    day = atoi(token);
    token = strtok(NULL, "/");
    month = atoi(token);
    token = strtok(NULL, "/");
    year = atoi(token);

    // Validate the input and set the corresponding fields in the date structure
    if (day < 1 || day > 31) {
        printf("Invalid day\n");
        return 1;
    }
    if (month < 1 || month > 12) {
        printf("Invalid month\n");
        return 1;
    }
    if (year < 1900 || year > 9999) {
        printf("Invalid year\n");
        return 1;
    }
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;

    // Convert the date structure to a string representation in the format 'DD/MM/YYYY'
    i = strftime(input, sizeof(input), "%d/%m/%Y", &date);
    printf("The date in the format 'DD/MM/YYYY' is: %s\n", input);

    return 0;
}