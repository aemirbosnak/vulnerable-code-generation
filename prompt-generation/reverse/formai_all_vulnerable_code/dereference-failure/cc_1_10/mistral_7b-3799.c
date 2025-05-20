//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void convert_date(char date[11]) {
    int day, month, year, total_days;
    struct tm tm;
    sscanf(date, "%d-%d-%d", &day, &month, &year);

    // Adjust for 0-indexed month and 1900-based year
    month--;
    year += 1900;

    // Convert date to number of days since 01-01-1970
    mktime(&tm);
    tm.tm_year = year - 1900;
    tm.tm_mon = month;
    tm.tm_mday = day;
    tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
    total_days = mktime(&tm) / 86400;

    printf("The number of days elapsed since 01-01-1970 for the given date is: %d\n", total_days);
}

int main(int argc, char *argv[]) {
    char date[11];

    if (argc != 2) {
        printf("Usage: %s <dd-mm-yyyy>\n", argv[0]);
        return 1;
    }

    strcpy(date, argv[1]);

    // Data validation
    if (strlen(date) != 10) {
        printf("Invalid date format. Use dd-mm-yyyy format.\n");
        return 1;
    }

    for (int i = 0; i < strlen(date); i++) {
        if (isdigit(date[i]) == 0 && date[i] != '-') {
            printf("Invalid character(s) found in the given date.\n");
            return 1;
        }
    }

    convert_date(date);
    return 0;
}