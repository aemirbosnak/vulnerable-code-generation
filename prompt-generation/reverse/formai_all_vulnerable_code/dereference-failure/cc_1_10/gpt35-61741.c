//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LEN 11 // Maximum length of a date in string format

// Function to convert a date string from natural language format to standard 
// (dd/mm/yyyy) format
char* convert_date(char* date_str) {
    char* month_arr[12] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    char* day_str, *month_str, *year_str, *slash_ptr;
    char day_num[3], month_num[3], year_num[5];
    int day, month, year;
    char* standard_date = (char*)malloc(MAX_DATE_LEN * sizeof(char));

    // Split the date string into day, month and year
    day_str = strtok(date_str, " ");
    month_str = strtok(NULL, " ");
    year_str = strtok(NULL, " ");

    // Convert month from string to number
    for (int i = 0; i < 12; i++) {
        if (strcmp(month_str, month_arr[i]) == 0) {
            month = i + 1; // Month numbers start from 1
            break;
        }
    }

    // Extract day and year from their respective strings
    slash_ptr = strchr(day_str, '/');
    strncpy(day_num, day_str, slash_ptr - day_str);
    day_num[slash_ptr - day_str] = '\0';
    day = atoi(day_num);

    strncpy(year_num, year_str, 4);
    year_num[4] = '\0';
    year = atoi(year_num);

    // Format the date into standard dd/mm/yyyy format
    sprintf(standard_date, "%02d/%02d/%04d", day, month, year);
    
    return standard_date;
}

int main() {
    char date_str[MAX_DATE_LEN];
    char* standard_date;

    // Read the date string from user
    printf("Enter a date in natural language format (e.g. January 1st, 2022): ");
    fgets(date_str, MAX_DATE_LEN, stdin);

    // Remove newline character at the end of the string
    date_str[strcspn(date_str, "\n")] = '\0';

    // Convert the date into standard format
    standard_date = convert_date(date_str);

    // Print the converted date
    printf("The date in standard format is: %s\n", standard_date);

    free(standard_date); // Free the allocated memory

    return 0;
}