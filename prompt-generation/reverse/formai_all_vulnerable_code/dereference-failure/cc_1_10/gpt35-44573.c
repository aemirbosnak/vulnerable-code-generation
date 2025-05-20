//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *months[12] = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};
const int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

typedef struct Date {
    int month;
    int day;
    int year;
} Date;

/* Function to convert a date to its corresponding day */
int dateToDay(Date date) {
    int day = date.day;
    int month = date.month;
    int year = date.year;

    int daySum = day;

    for (int i = 0; i < month - 1; i++) {
        daySum += daysInMonth[i];
    }

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        if (month > 2) {
            daySum++;
        }
    }

    int century = year / 100;
    int yearModCent = year % 100;

    int dayOfWeek = (daySum + yearModCent + (yearModCent / 4)
                     + (century / 4) + (5 * century)) % 7;

    return dayOfWeek;
}

/* Function to format the date in a user-friendly way */
void formatDate(Date date, char *output) {
    sprintf(output, "%s %d, %d", months[date.month - 1], date.day, date.year);
}

int main() {
    Date date;

    /* Get date input from user */
    char input[20];
    printf("Please enter a date (mm/dd/yyyy): ");
    fgets(input, 20, stdin);

    /* Parse the inputted date */
    char *token;
    token = strtok(input, "/");
    date.month = atoi(token);
    token = strtok(NULL, "/");
    date.day = atoi(token);
    token = strtok(NULL, "/");
    date.year = atoi(token);

    /* Convert date to day of the week */
    int dayOfWeek = dateToDay(date);

    /* Format date in user-friendly way */
    char output[20];
    formatDate(date, output);

    printf("%s was on a ", output);

    switch (dayOfWeek) {
        case 0:
            printf("Sunday.\n");
            break;
        case 1:
            printf("Monday.\n");
            break;
        case 2:
            printf("Tuesday.\n");
            break;
        case 3:
            printf("Wednesday.\n");
            break;
        case 4:
            printf("Thursday.\n");
            break;
        case 5:
            printf("Friday.\n");
            break;
        case 6:
            printf("Saturday.\n");
            break;
        default:
            printf("ERROR.\n");
    }

    return 0;
}