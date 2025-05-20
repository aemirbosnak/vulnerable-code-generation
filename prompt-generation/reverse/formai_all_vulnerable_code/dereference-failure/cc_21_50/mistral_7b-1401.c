//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LEN 11

int main(int argc, char *argv[]) {
    char str[MAX_LEN];
    int day, month, year, valid = 1;

    if (argc != 2) {
        printf("Usage: %s <date>\n", argv[0]);
        return 1;
    }

    strcpy(str, argv[1]);
    if (strlen(str) > MAX_LEN) {
        printf("Error: String too long\n");
        return 1;
    }

    // Validate input format
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            if (str[i] != '-' && str[i] != '/') {
                valid = 0;
                break;
            }
        }
    }

    if (!valid || (strlen(str) > 10 && *(str + 10) != ' ')) {
        printf("Error: Invalid date format\n");
        return 1;
    }

    // Parse date components
    sscanf(str, "%d-%d-%d", &day, &month, &year);

    if (strlen(str) < 10) {
        sscanf(str, "%d/%d/%d", &day, &month, &year);
    }

    // Validate date components
    if (day < 1 || day > 31 ||
        (month < 1 || month > 12 ||
         (month == 2 && (day > 29 || (day == 29 && !(year % 4) || day == 28)))) ||
        year < 1970) {

        printf("Error: Invalid date components\n");
        return 1;
    }

    // Convert date to Unix time
    struct tm *ptm = malloc(sizeof(struct tm));
    ptm->tm_sec = 0;
    ptm->tm_min = 0;
    ptm->tm_hour = 0;
    ptm->tm_mday = day;
    ptm->tm_mon = month - 1;
    ptm->tm_year = year - 1900;
    time_t unix_time = mktime(ptm);

    // Print Unix time and corresponding date
    printf("Unix time: %ld\n", (long)unix_time);
    printf("Corresponding date: %02d-%02d-%04d\n", day, month, year);

    free(ptm);
    return 0;
}