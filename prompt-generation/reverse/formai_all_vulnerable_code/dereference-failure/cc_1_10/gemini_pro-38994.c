//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char **argv)
{
    struct tm tm;
    time_t timestamp;
    char *date_string, *time_string;
    int year, month, day, hour, minute, second;

    if (argc != 7)
    {
        printf("Usage: %s <year> <month> <day> <hour> <minute> <second>\n", argv[0]);
        return EXIT_FAILURE;
    }

    year = atoi(argv[1]);
    month = atoi(argv[2]);
    day = atoi(argv[3]);
    hour = atoi(argv[4]);
    minute = atoi(argv[5]);
    second = atoi(argv[6]);

    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;

    timestamp = mktime(&tm);

    if (timestamp == (time_t)-1)
    {
        printf("Invalid date or time specified.\n");
        return EXIT_FAILURE;
    }

    date_string = ctime(&timestamp);
    time_string = strptime(date_string, "%a %b %d %H:%M:%S %Y", &tm);

    if (time_string == NULL)
    {
        printf("Error parsing date string: %s\n", date_string);
        return EXIT_FAILURE;
    }

    printf("Date: %s", date_string);
    printf("Timestamp: %ld\n", timestamp);

    return EXIT_SUCCESS;
}