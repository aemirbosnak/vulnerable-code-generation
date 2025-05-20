//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEAP_YEAR(year) (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))

int main(int argc, char *argv[]) {
    int year, month, day;
    
    if (argc != 4) {
        printf("Usage: %s <year> <month> <day>\n", argv[0]);
        return 1;
    }

    year = atoi(argv[1]);
    month = atoi(argv[2]);
    day = atoi(argv[3]);

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date: month=%d day=%d\n", month, day);
        return 1;
    }

    int m, d, q;
    double a, b, j;

    m = month;
    d = day;

    // Adjust for January 1, 1582
    if (LEAP_YEAR(year)) {
        if (month < 10 && day >= 29) {
            day -= 1;
            month++;
        }
    } else if (month == 2 && day >= 29) {
        day -= 1;
        month++;
    }

    q = year / 100;
    a = (double)(year - 1500 + 4800 + (month - 14)) / 100.0;
    b = 2.0 * a + (double)(q / 4) + (double)(cint((q / 100.0) * 0.75)) - (double)(3 * (q % 100) / 100.0) + (double)(q % 100) / 400.0;
    j = floor(365.25 * (year + 4716));
    j += floor(30.6001 * (double)((int)(month + 9) % 14));
    j += day + b - 1524.5;

    printf("Julian Day Number: %.16f\n", j);
    printf("Unix Time: %ld\n", (long)j * 86400L);

    return 0;
}

// Helper function to round down to the nearest integer
inline int cint(double x) {
    return (int)(x >= 0 ? x : ceil(x));
}