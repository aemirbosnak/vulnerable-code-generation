//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
// Program to convert natural language dates into standard date format
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global arrays to store month names and their corresponding numbers
const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int month_nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

// Function to get the month number based on the month name
int get_month_num(char *month){
    for(int i = 0; i < 12; i++){
        if(strcmp(month, months[i]) == 0){
            return month_nums[i];
        }
    }
    return -1; // Invalid month
}

// Function to convert the input string into a date format
char *convert_date(char *input_string){
    char *day = strtok(input_string, " ");
    char *month = strtok(NULL, " ");
    char *year = strtok(NULL, " ");

    // Get the month number
    int month_num = get_month_num(month);

    // If input string is not in the correct format, return an error message
    if(day == NULL || month == NULL || year == NULL || month_num == -1){
        char *error_str = "Error: Invalid input format!";
        return error_str;
    }

    // Convert day and year strings into integers
    int day_int = atoi(day);
    int year_int = atoi(year);

    // Check for valid day and year inputs
    if(day_int < 1 || day_int > 31 || year_int < 1){
        char *error_str = "Error: Invalid day or year!";
        return error_str;
    }

    // Check for valid month input for a non-leap year
    if(month_num == 2 && day_int > 28){
        char *error_str = "Error: Invalid day for February in a non-leap year!";
        return error_str;
    }
    else if((month_num == 4 || month_num == 6 || month_num == 9 || month_num == 11) && day_int > 30){
        char *error_str = "Error: Invalid day for this month!";
        return error_str;
    }

    // Convert day and month numbers to strings
    char day_str[3];
    sprintf(day_str, "%d", day_int);

    char month_str[3];
    sprintf(month_str, "%d", month_num);

    // Format the date string in the format dd/mm/yyyy
    char *date_str = (char*)malloc(11 * sizeof(char));
    strcat(date_str, day_str);
    strcat(date_str, "/");
    strcat(date_str, month_str);
    strcat(date_str, "/");
    strcat(date_str, year);

    return date_str;
}

// Main function to run the program
int main(){
    // Sample input sentences
    char *input1 = "Today is July 28th 2021";
    char *input2 = "I was born on December 25th 2000";

    // Convert the input strings into date strings
    char *output1 = convert_date(input1);
    char *output2 = convert_date(input2);

    // Print the output strings
    printf("Input string: %s \nOutput string: %s\n", input1, output1);
    printf("Input string: %s \nOutput string: %s\n", input2, output2);

    return 0;
}