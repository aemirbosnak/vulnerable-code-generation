//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Custom futuristic date format
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int millisecond;
} CyberDate;

// Convert a CyberDate to epoch time
long cyberDateToEpoch(CyberDate date) {
    struct tm timeinfo;
    timeinfo.tm_year = date.year - 1900;
    timeinfo.tm_mon = date.month - 1;
    timeinfo.tm_mday = date.day;
    timeinfo.tm_hour = date.hour;
    timeinfo.tm_min = date.minute;
    timeinfo.tm_sec = date.second;
    timeinfo.tm_isdst = -1;  // Not applicable for futuristic dates
    return mktime(&timeinfo);
}

// Convert epoch time to a CyberDate
CyberDate epochToCyberDate(long epochTime) {
    struct tm *timeinfo = localtime(&epochTime);
    CyberDate date;
    date.year = timeinfo->tm_year + 1900;
    date.month = timeinfo->tm_mon + 1;
    date.day = timeinfo->tm_mday;
    date.hour = timeinfo->tm_hour;
    date.minute = timeinfo->tm_min;
    date.second = timeinfo->tm_sec;
    date.millisecond = 0;  // Not supported in epoch time
    return date;
}

// Get the current CyberDate
CyberDate getCurrentCyberDate() {
    time_t now = time(NULL);
    return epochToCyberDate(now);
}

// Print a CyberDate in the futuristic format
void printCyberDate(CyberDate date) {
    printf("%04d-%02d-%02dT%02d:%02d:%02d.%03dZ",
        date.year, date.month, date.day, date.hour, date.minute, date.second, date.millisecond);
}

int main() {
    // Get the current CyberDate
    CyberDate now = getCurrentCyberDate();

    // Print the current CyberDate
    printf("Current CyberDate: ");
    printCyberDate(now);
    printf("\n");

    // Convert the current CyberDate to epoch time
    long epochTime = cyberDateToEpoch(now);

    // Print the epoch time
    printf("Epoch time: %ld\n", epochTime);

    // Convert the epoch time back to a CyberDate
    CyberDate convertedDate = epochToCyberDate(epochTime);

    // Print the converted CyberDate
    printf("Converted CyberDate: ");
    printCyberDate(convertedDate);
    printf("\n");

    return 0;
}