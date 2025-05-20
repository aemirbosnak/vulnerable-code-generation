//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert natural language date to dd/mm/yyyy format
void convertToDate(char* natural_language_date) {
    int month = 0, day = 0, year = 0;
    char *date_parts[3];

    // Split the natural language date into month, day and year parts
    date_parts[0] = strtok(natural_language_date, "/");
    date_parts[1] = strtok(NULL, "/");
    date_parts[2] = strtok(NULL, "/");

    // Check if the month part is valid
    if (!isdigit(*date_parts[0]) || (atoi(date_parts[0]) < 1 || atoi(date_parts[0]) > 12)) {
        printf("Invalid month\n");
        return;
    }

    // Check if the day part is valid
    if (!isdigit(*date_parts[1]) || (atoi(date_parts[1]) < 1 || atoi(date_parts[1]) > 31)) {
        printf("Invalid day\n");
        return;
    }

    // Check if the year part is valid
    if (!isdigit(*date_parts[2]) || (atoi(date_parts[2]) < 1 || atoi(date_parts[2]) > 99)) {
        printf("Invalid year\n");
        return;
    }

    // Convert the month, day and year parts to their respective integers
    month = atoi(date_parts[0]);
    day = atoi(date_parts[1]);
    year = atoi(date_parts[2]);

    // Format the date as dd/mm/yyyy
    printf("%02d/%02d/%04d\n", day, month, year);
}

int main() {
    char natural_language_date[100];
    printf("Enter a natural language date in the format 'dd/mm/yyyy':\n");
    fgets(natural_language_date, sizeof(natural_language_date), stdin);

    // Remove any trailing newline characters from the input
    natural_language_date[strcspn(natural_language_date, "\n")] = '\0';

    // Convert the natural language date to dd/mm/yyyy format
    convertToDate(natural_language_date);

    return 0;
}