//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert c natural language date to numeric date
void convertDate(char* natural_lang, char* numeric_date) {
    char* token;
    char delimiter[3] = " ";
    char months[12][3] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
    char* month_num;
    char* day;
    char* year;

    // get month in numeric form
    token = strtok(natural_lang, delimiter);
    for (int i = 0; i < 12; i++) {
        if (strcmp(token, months[i]) == 0) {
            month_num = (char*) malloc(3);
            sprintf(month_num, "%02d", i+1);
            break;
        }
    }

    // get day
    token = strtok(NULL, delimiter);
    day = (char*) malloc(3);
    sprintf(day, "%02d", atoi(token));

    // get year
    token = strtok(NULL, delimiter);
    year = (char*) malloc(5);
    sprintf(year, "%04d", atoi(token));

    // construct numeric date string
    strcpy(numeric_date, year);
    strcat(numeric_date, "-");
    strcat(numeric_date, month_num);
    strcat(numeric_date, "-");
    strcat(numeric_date, day);
}

int main() {
    char natural_lang[30];
    char numeric_date[11];

    printf("Welcome to the date converter game!\n");
    printf("Please enter a date in natural language format (e.g. 'Feb 14 2022'): ");
    fgets(natural_lang, 30, stdin);

    convertDate(natural_lang, numeric_date);

    printf("You entered: %s\n", natural_lang);
    printf("Numeric date: %s\n", numeric_date);

    return 0;
}