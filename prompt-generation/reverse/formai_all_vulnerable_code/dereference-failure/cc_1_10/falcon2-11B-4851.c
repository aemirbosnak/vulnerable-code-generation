//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 30
#define DAYS_OF_WEEK 7

void convert_date(char* date_string) {
    int day_index = 0, month_index = 0, year_index = 0;
    char day[3], month[3], year[6];
    int month_length[DAYS_OF_WEEK] = {0, 3, 3, 3, 3, 3, 4};

    for (int i = 0; i < strlen(date_string); i++) {
        if (isdigit(date_string[i])) {
            year_index = 1;
        } else if (date_string[i] == '/') {
            year_index = 0;
        } else if (isalpha(date_string[i])) {
            if (isupper(date_string[i])) {
                day[day_index++] = date_string[i];
            } else if (islower(date_string[i])) {
                month[month_index++] = date_string[i];
            }
        }
    }

    strcpy(day, &day[day_index - 1]);
    strcpy(month, &month[month_index - 1]);

    if (month_length[month[0] - '0'] == 1) {
        if (month[0] == '1') {
            strcpy(month, "Jan");
        } else if (month[0] == '2') {
            strcpy(month, "Feb");
        } else if (month[0] == '3') {
            strcpy(month, "Mar");
        } else if (month[0] == '4') {
            strcpy(month, "Apr");
        } else if (month[0] == '5') {
            strcpy(month, "May");
        } else if (month[0] == '6') {
            strcpy(month, "Jun");
        } else if (month[0] == '7') {
            strcpy(month, "Jul");
        } else if (month[0] == '8') {
            strcpy(month, "Aug");
        } else if (month[0] == '9') {
            strcpy(month, "Sep");
        } else if (month[0] == '0') {
            strcpy(month, "Oct");
        }
    }

    strcpy(year, &year[year_index - 1]);

    printf("Date: %s/%s/%s\n", month, day, year);
}

int main() {
    char date_string[MAX_DATE_LENGTH];
    printf("Enter a date in natural language format: ");
    fgets(date_string, sizeof(date_string), stdin);
    date_string[strcspn(date_string, "\n")] = '\0';

    convert_date(date_string);

    return 0;
}