//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if entered year is a leap year or not
bool isLeapYear(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int main() {
    // Variables to store current time and time travel duration
    int current_time, time_travel_duration;
    // Variables to store the year, month, day, time and time zone
    int year, month, day, hour, minute, second, time_zone;
    // Temporary variables
    int temp_year, temp_month, temp_day, temp_hour, temp_minute, temp_second;

    // Get current time from user
    printf("Enter current time (format: hh:mm:ss): ");
    scanf("%d:%d:%d", &hour, &minute, &second);
    current_time = hour*3600 + minute*60 + second;

    // Get time travel duration from user
    printf("Enter time travel duration (format: hh:mm:ss): ");
    scanf("%d:%d:%d", &hour, &minute, &second);
    time_travel_duration = hour*3600 + minute*60 + second;

    // Get current date from user
    printf("Enter current date (format: yyyy-mm-dd): ");
    scanf("%d-%d-%d", &year, &month, &day);

    // Get timezone from user
    printf("Enter time zone (+/- hrs from UTC): ");
    scanf("%d", &time_zone);

    // Convert current time to UTC
    current_time -= time_zone*3600;
    if(current_time < 0)
        current_time += 86400;

    // Handling negative time travel duration
    if(time_travel_duration < 0) {
        time_travel_duration += 86400;
        current_time += time_travel_duration;
        if(current_time >= 86400) {
            current_time -= 86400;
            day--;
            if(day < 1) {
                month--;
                if(month < 1) {
                    year--;
                    month = 12;
                }
                day = 31;
                if(month == 2) {
                    if(isLeapYear(year))
                        day = 29;
                    else
                        day = 28;
                } else if(month == 4 || month == 6 || month == 9 || month == 11)
                    day = 30;
            }
        }
    } else {
        current_time += time_travel_duration;
        if(current_time >= 86400) {
            current_time -= 86400;
            day++;
            if(day > 31 || (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day > 29 && month == 2 && isLeapYear(year)) || (day > 28 && month == 2)) {
                day = 1;
                month++;
                if(month > 12) {
                    year++;
                    month = 1;
                }
            }
        }
    }

    // Get temporary variables
    temp_year = year;
    temp_month = month;
    temp_day = day;
    temp_hour = current_time/3600;
    temp_minute = (current_time - temp_hour*3600)/60;
    temp_second = current_time - temp_hour*3600 - temp_minute*60;

    // Convert UTC back to local time zone
    temp_hour += time_zone;
    if(temp_hour < 0)
        temp_hour += 24;
    else if(temp_hour >= 24)
        temp_hour -= 24;

    // Display final time and date
    printf("After time travel, the date and time is: %d-%02d-%02d %02d:%02d:%02d\n", temp_year, temp_month, temp_day, temp_hour, temp_minute, temp_second);

    return 0;
}