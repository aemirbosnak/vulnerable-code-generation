//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <string.h>

// function to convert month name to its corresponding numerical value
int convert_month(char* month_name) {
    if(strcmp(month_name, "January") == 0) {
        return 1;
    } else if(strcmp(month_name, "February") == 0) {
        return 2;
    } else if(strcmp(month_name, "March") == 0) {
        return 3;
    } else if(strcmp(month_name, "April") == 0) {
        return 4;
    } else if(strcmp(month_name, "May") == 0) {
        return 5;
    } else if(strcmp(month_name, "June") == 0) {
        return 6;
    } else if(strcmp(month_name, "July") == 0) {
        return 7;
    } else if(strcmp(month_name, "August") == 0) {
        return 8;
    } else if(strcmp(month_name, "September") == 0) {
        return 9;
    } else if(strcmp(month_name, "October") == 0) {
        return 10;
    } else if(strcmp(month_name, "November") == 0) {
        return 11;
    } else {
        return 12;
    }
}

int main() {
    // get input from user
    printf("Enter a date (DD-MMM-YYYY format): ");
    char input[12];
    fgets(input, 12, stdin);
    // remove newline character at end of input
    input[strlen(input) - 1] = '\0';
    
    // parse input into day, month, year
    char* token = strtok(input, "-");
    int day = atoi(token);
    token = strtok(NULL, "-");
    int month = convert_month(token);
    token = strtok(NULL, "-");
    int year = atoi(token);

    // print output
    printf("The date you entered is: %d-%d-%d\n", day, month, year);
    
    return 0;
}