//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include <stdio.h>
#include <string.h>

// function to get the month number from month name
int getMonthNumber(char* monthName) {
    char* months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    for(int i=0; i<12; i++) {
        if(strcmp(monthName, months[i]) == 0) {
            return i+1;
        }
    }
    return -1;
}

// function to validate the input date
int isValidDate(int day, int month, int year) {
    if(year < 0 || month < 1 || month > 12) {
        return 0;
    }
    int daysInMonth;
    if(month == 2) {
        if(year%4 == 0 && (year%100 != 0 || year%400 == 0)) { // leap year check
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }
    if(day < 1 || day > daysInMonth) {
        return 0;
    }
    return 1;
}

// function to convert natural language date to YYYY-MM-DD format
void convertToYYYYMMDD(char* input, char* output) {
    char* day, *month, *year;
    strtok(input, " "); // remove the word "on"
    day = strtok(NULL, " ,"); // get day
    month = strtok(NULL, " ,"); // get month
    if(getMonthNumber(month) == -1) { // invalid month name
        sprintf(output, "Invalid month name!");
        return;
    }
    year = strtok(NULL, ""); // get year
    int dayNumber = atoi(day);
    int monthNumber = getMonthNumber(month);
    int yearNumber = atoi(year);
    if(!isValidDate(dayNumber, monthNumber, yearNumber)) { // invalid date
        sprintf(output, "Invalid date!");
        return;
    }
    sprintf(output, "%04d-%02d-%02d", yearNumber, monthNumber, dayNumber); // format output string
}

int main() {
    char input[50], output[20];
    printf("Enter natural language date (e.g. 'on 13 December, 2022'): ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline
    convertToYYYYMMDD(input, output);
    printf("%s\n", output);
    return 0;
}