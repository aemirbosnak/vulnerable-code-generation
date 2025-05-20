//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert month name to its corresponding number
int month_number(char *month) {
    if (strcmp(month, "Jan") == 0) {
        return 1;
    } else if (strcmp(month, "Feb") == 0) {
        return 2;
    } else if (strcmp(month, "Mar") == 0) {
        return 3;
    } else if (strcmp(month, "Apr") == 0) {
        return 4;
    } else if (strcmp(month, "May") == 0) {
        return 5;
    } else if (strcmp(month, "Jun") == 0) {
        return 6;
    } else if (strcmp(month, "Jul") == 0) {
        return 7;
    } else if (strcmp(month, "Aug") == 0) {
        return 8;
    } else if (strcmp(month, "Sep") == 0) {
        return 9;
    } else if (strcmp(month, "Oct") == 0) {
        return 10;
    } else if (strcmp(month, "Nov") == 0) {
        return 11;
    } else if (strcmp(month, "Dec") == 0) {
        return 12;
    } else {
        printf("Invalid Month\n");
        exit(0);
    }
}

// Function to convert date string to its corresponding Julian day number
int julian_day_number(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    return day + (153 * m + 2) / 5 + y * 365 + y / 4 - y / 100 + y / 400 - 32045;
}

// Function to convert Julian day number to date string
void julian_day_to_date(int jd, int *day, int *month, int *year) {
    int a, b, c, d, e, m;
    if (jd > 2299160) {
        a = jd + 32044;
        b = (4 * a + 3) / 146097;
        c = a - (b * 146097) / 4;
    } else {
        b = 0;
        c = jd + 32082;
    }
    d = (4 * c + 3) / 1461;
    e = c - (1461 * d) / 4;
    m = (5 * e + 2) / 153;
    *day = e - (153 * m + 2) / 5 + 1;
    *month = m + 3 - 12 * (m / 10);
    *year = b * 100 + d - 4800 + m / 10;
}

// Function to convert natural language date string to Julian day number
int natural_date_to_julian_day(char *date_string) {
    int day, month, year, jd;
    char *month_name = malloc(4);
    sscanf(date_string, "%d %s %d", &day, month_name, &year);
    month = month_number(month_name);
    jd = julian_day_number(day, month, year);
    free(month_name);
    return jd;
}

// Function to convert Julian day number to natural language date string
char *julian_day_to_natural_date(int jd) {
    int day, month, year;
    char *date_string = malloc(12);
    julian_day_to_date(jd, &day, &month, &year);
    sprintf(date_string, "%d %s %d", day, 
        (month == 1) ? "Jan" : (month == 2) ? "Feb" : (month == 3) ? "Mar" :
        (month == 4) ? "Apr" : (month == 5) ? "May" : (month == 6) ? "Jun" :
        (month == 7) ? "Jul" : (month == 8) ? "Aug" : (month == 9) ? "Sep" :
        (month == 10) ? "Oct" : (month == 11) ? "Nov" : "Dec", year);
    return date_string;
}

// Main function to test the converter
int main() {
    char *date_string = "25 Dec 2022";
    printf("Natural Language date_string: %s\n", date_string);
    int jd = natural_date_to_julian_day(date_string);
    printf("Julian Day: %d\n", jd);
    char *nd = julian_day_to_natural_date(jd);
    printf("Converted natural date_string: %s\n", nd);
    free(nd);
    return 0;
}