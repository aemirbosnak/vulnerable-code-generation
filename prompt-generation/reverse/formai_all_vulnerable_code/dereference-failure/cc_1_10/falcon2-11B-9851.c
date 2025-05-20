//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char *date;
    char *formatted;
} Date;

void format_date(Date *date) {
    char *month_names[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
        NULL
    };

    char month[5];
    char day[5];
    char year[5];

    strcpy(month, date->date + 4);
    strcpy(day, date->date + 7);
    strcpy(year, date->date + 10);

    if (isdigit(date->date[6])) {
        strcpy(date->formatted, "Jan");
    } else if (date->date[6] == '0' && isdigit(date->date[5])) {
        strcpy(date->formatted, "Jan");
    } else {
        strcpy(date->formatted, month_names[month[0] - '0']);
        strcat(date->formatted, day);
        strcat(date->formatted, year);
    }
}

void display_date(Date *date) {
    printf("Date: %s\n", date->date);
    printf("Formatted Date: %s\n", date->formatted);
}

int main() {
    Date date = {"2019-01-15", ""};

    format_date(&date);
    display_date(&date);

    return 0;
}