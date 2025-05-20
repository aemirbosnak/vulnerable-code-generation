//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
/*
 * Date Converter Program
 * By: Your Name
 * Date: Current Date
 * 
 * This program converts dates from natural language to numerical format.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define BUFFER_SIZE 1024


char* natural_to_numeric(const char* date_str);


/**
 * The main function of the program.
 */
int main(int argc, char* argv[]) {
    char date_buffer[BUFFER_SIZE];
    
    printf("Enter a date in natural language: ");
    fgets(date_buffer, BUFFER_SIZE, stdin);
    
    char* numeric_date = natural_to_numeric(date_buffer);
    
    if (numeric_date == NULL) {
        printf("Error: Unable to convert date.");
    } else {
        printf("Numerical format: %s\n", numeric_date);
    }
    
    free(numeric_date);
    return 0;
}


/**
 * Takes a date string in natural language and returns the corresponding numerical format.
 * 
 * @param date_str the natural language date string (e.g. "September 1, 2021")
 * @return the numerical format date string (e.g. "20210901") or NULL if an error occurs
 */
char* natural_to_numeric(const char* date_str) {
    char* numeric_date = malloc(sizeof(char) * 9);
    int year = 0, month = 0, day = 0;

    // Parse month
    if (sscanf(date_str, "%*s %d", &day) != 1) {
        goto error;
    }
    date_str = strchr(date_str, ' ') + 1;

    char* month_str = strsep((char **) &date_str, " ,");
    if (strcmp(month_str, "January") == 0) {
        month = 1;
    } else if (strcmp(month_str, "February") == 0) {
        month = 2;
    } else if (strcmp(month_str, "March") == 0) {
        month = 3;
    } else if (strcmp(month_str, "April") == 0) {
        month = 4;
    } else if (strcmp(month_str, "May") == 0) {
        month = 5;
    } else if (strcmp(month_str, "June") == 0) {
        month = 6;
    } else if (strcmp(month_str, "July") == 0) {
        month = 7;
    } else if (strcmp(month_str, "August") == 0) {
        month = 8;
    } else if (strcmp(month_str, "September") == 0) {
        month = 9;
    } else if (strcmp(month_str, "October") == 0) {
        month = 10;
    } else if (strcmp(month_str, "November") == 0) {
        month = 11;
    } else if (strcmp(month_str, "December") == 0) {
        month = 12;
    } else {
        goto error;
    }

    // Parse day
    if (*date_str != ',') {
        goto error;
    }
    date_str++;
    if (sscanf(date_str, " %d", &year) != 1) {
        goto error;
    }

    // Generate numerical date
    sprintf(numeric_date, "%d%02d%02d", year, month, day);
    return numeric_date;

    // Handle error and cleanup
    error:
    free(numeric_date);
    return NULL;
}