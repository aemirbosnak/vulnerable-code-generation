//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <date>\n", argv[0]);
        return 1;
    }

    char *date = argv[1];
    char *day = strtok(date, " ");
    char *month = strtok(NULL, " ");
    char *year = strtok(NULL, " ");

    time_t timestamp;
    if (strcmp(day, "Monday") == 0)
        day = "1";
    else if (strcmp(day, "Tuesday") == 0)
        day = "2";
    else if (strcmp(day, "Wednesday") == 0)
        day = "3";
    else if (strcmp(day, "Thursday") == 0)
        day = "4";
    else if (strcmp(day, "Friday") == 0)
        day = "5";
    else if (strcmp(day, "Saturday") == 0)
        day = "6";
    else if (strcmp(day, "Sunday") == 0)
        day = "7";

    timestamp = mktime((struct tm *) localtime(&day));

    if (strcmp(month, "January") == 0)
        month = "01";
    else if (strcmp(month, "February") == 0)
        month = "02";
    else if (strcmp(month, "March") == 0)
        month = "03";
    else if (strcmp(month, "April") == 0)
        month = "04";
    else if (strcmp(month, "May") == 0)
        month = "05";
    else if (strcmp(month, "June") == 0)
        month = "06";
    else if (strcmp(month, "July") == 0)
        month = "07";
    else if (strcmp(month, "August") == 0)
        month = "08";
    else if (strcmp(month, "September") == 0)
        month = "09";
    else if (strcmp(month, "October") == 0)
        month = "10";
    else if (strcmp(month, "November") == 0)
        month = "11";
    else if (strcmp(month, "December") == 0)
        month = "12";

    timestamp += mktime((struct tm *) localtime(&month));

    if (strcmp(year, "2020") == 0)
        year = "20";
    else if (strcmp(year, "2021") == 0)
        year = "21";
    else if (strcmp(year, "2022") == 0)
        year = "22";

    timestamp += mktime((struct tm *) localtime(&year));

    printf("%s\n", ctime(&timestamp));
    return 0;
}