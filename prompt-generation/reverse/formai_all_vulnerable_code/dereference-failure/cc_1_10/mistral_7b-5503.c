//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void parseDate(char *date, Date *output) {
    int index = 0;
    int day, month, year;
    char monthName[13][3] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // Extract day
    day = atoi(strtok(date, "/") - date);

    // Extract month
    strtok(NULL, "/");
    for (int i = 0; i < 12; i++) {
        if (strcmp(monthName[i], strtok(NULL, " ")) == 0) {
            month = i + 1;
            break;
        }
    }

    // Extract year
    year = atoi(strtok(NULL, "\0") - date);

    output->day = day;
    output->month = month;
    output->year = year;
}

long unixTime(Date date) {
    struct tm tm = {0};
    long seconds;

    tm.tm_year = date.year - 1900;
    tm.tm_mon = date.month - 1;
    tm.tm_mday = date.day;
    tm.tm_hour = tm.tm_min = tm.tm_sec = 0;

    seconds = mktime(&tm);
    return seconds;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <dd/mm/yyyy>\n", argv[0]);
        return 1;
    }

    Date date;
    long unixSeconds;

    parseDate(argv[1], &date);
    unixSeconds = unixTime(date);

    printf("The date %s%s%s, with a poetic heart,\n", date.day < 10 ? "0" : "", date.day,
           date.month < 10 ? "0" : "");
    printf("would whisper in soft tones,\n");
    printf("has passed %ld seconds,\n", unixSeconds);
    printf("since the silent hours of the Unix Epoch began.\n");

    return 0;
}