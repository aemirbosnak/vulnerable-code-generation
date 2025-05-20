//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int month, day, year;
    char date[20];

    printf("\nWelcome to the C Natural Language Date Converter!\n");
    printf("Enter a date in natural language (e.g. March 1, 2022):\n");
    fgets(date, sizeof(date), stdin); // Read input from user
    
    char *token = strtok(date, " ,");
    month = find_month(token); // Use a function to get the numerical month from the string

    token = strtok(NULL, " ,");
    day = atoi(token); // Convert day string to int using atoi()

    token = strtok(NULL, " ,\n");
    year = atoi(token); // Convert year string to int using atoi()
    
    printf("\n%s converted to a numerical date is %02d/%02d/%04d!\n", date, month, day, year);
    printf("\nThanks for using the C Natural Language Date Converter. Have a great day!\n");
    
    return 0; // End of program
}

int find_month(char *month_string) {
    if (strcmp(month_string, "January") == 0) {
        return 1;
    }
    else if (strcmp(month_string, "February") == 0) {
        return 2;
    }
    else if (strcmp(month_string, "March") == 0) {
        return 3;
    }
    else if (strcmp(month_string, "April") == 0) {
        return 4;
    }
    else if (strcmp(month_string, "May") == 0) {
        return 5;
    }
    else if (strcmp(month_string, "June") == 0) {
        return 6;
    }
    else if (strcmp(month_string, "July") == 0) {
        return 7;
    }
    else if (strcmp(month_string, "August") == 0) {
        return 8;
    }
    else if (strcmp(month_string, "September") == 0) {
        return 9;
    }
    else if (strcmp(month_string, "October") == 0) {
        return 10;
    }
    else if (strcmp(month_string, "November") == 0) {
        return 11;
    }
    else if (strcmp(month_string, "December") == 0) {
        return 12;
    }
    else {
        printf("\nSorry, I couldn't understand the month name. Please try again.\n");
        exit(0);
    }
}