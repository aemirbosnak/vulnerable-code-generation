//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get corresponding number for month
int getMonth(char* month)
{
    if(strcmp(month, "January") == 0)
        return 1;
    else if(strcmp(month, "February") == 0)
        return 2;
    else if(strcmp(month, "March") == 0)
        return 3;
    else if(strcmp(month, "April") == 0)
        return 4;
    else if(strcmp(month, "May") == 0)
        return 5;
    else if(strcmp(month, "June") == 0)
        return 6;
    else if(strcmp(month, "July") == 0)
        return 7;
    else if(strcmp(month, "August") == 0)
        return 8;
    else if(strcmp(month, "September") == 0)
        return 9;
    else if(strcmp(month, "October") == 0)
        return 10;
    else if(strcmp(month, "November") == 0)
        return 11;
    else
        return 12;
}

int main()
{
    int day, year;
    char month[20];
    char date[30], month_num[2], day_num[2], year_num[4];

    printf("Hey there! Let's have some fun converting a C natural language date to a C standard date!\n");
    printf("Please enter the natural language date (e.g. January 12, 2000): ");

    // Get input date in natural language
    fgets(date, sizeof(date), stdin);

    // tokenize the input date
    char* token = strtok(date, " ,");
    strcpy(month, token);

    token = strtok(NULL, " ,");
    strcpy(day_num, token);

    token = strtok(NULL, " ,");
    strcpy(year_num, token);

    // get month number from month name
    int month_num_int = getMonth(month);

    // convert integers to string
    sprintf(month_num, "%d", month_num_int);
    sprintf(day_num, "%d", atoi(day_num));
    sprintf(year_num, "%d", atoi(year_num));

    // ensure day number and year number have proper length
    if(strlen(day_num) == 1) {
        char tmp[2] = {"0"};
        strcat(tmp, day_num);
        strcpy(day_num, tmp);
    }

    if(strlen(year_num) != 4) {
        printf("Oops! The year should have exactly 4 digits.\n");
        return 0;
    }

    // concatenate date components to generate standard C date
    strcat(year_num, "-");
    strcat(year_num, month_num);
    strcat(year_num, "-");
    strcat(year_num, day_num);

    printf("The equivalent C standard date format for %s is %s.\n", date, year_num);

    return 0;
}