//FormAI DATASET v1.0 Category: Date and time ; Style: recursive
#include <stdio.h>
#include <time.h>

void displayDateTime(int hour, int min, int sec, int year, int month, int day) {
    printf("%02d:%02d:%02d %02d/%02d/%d\n", hour, min, sec, month, day, year);
    // Check if we have reached maximum recursion depth
    if (hour == 23 && min == 59 && sec == 59) {
        return;
    }
    // Update time variables
    if (sec < 59) {
        sec++;
    } else {
        sec = 0;
        if (min < 59) {
            min++;
        } else {
            min = 0;
            hour++;
            if (hour > 23) {
                hour = 0;
                // Update date variables
                if (day < 31) {
                    day++;
                } else {
                    day = 1;
                    if (month < 12) {
                        month++;
                    } else {
                        month = 1;
                        year++;
                    }
                }
            }
        }
    }
    // Call function recursively
    displayDateTime(hour, min, sec, year, month, day);
}

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int hour = tm.tm_hour;
    int min = tm.tm_min;
    int sec = tm.tm_sec;
    int year = tm.tm_year + 1900;
    int month = tm.tm_mon + 1;
    int day = tm.tm_mday;
    // Call recursive function to display date and time
    displayDateTime(hour, min, sec, year, month, day);
    return 0;
}