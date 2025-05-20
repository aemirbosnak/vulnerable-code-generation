//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <time.h>

int main() {

    time_t current_time, dest_time;
    struct tm *current_tm, *dest_tm;
    char time_str[100];

    // Get current time
    current_time = time(NULL);
    current_tm = localtime(&current_time);

    // Set destination time
    dest_tm = localtime(&current_time);
    dest_tm->tm_year = 2045 - 1900;
    dest_tm->tm_mon = 6 - 1;
    dest_tm->tm_mday = 15;
    dest_tm->tm_hour = 14;
    dest_tm->tm_min = 30;
    dest_tm->tm_sec = 0;
    dest_tm->tm_isdst = -1;
    dest_time = mktime(dest_tm);

    // Set time interval and initial message
    long int interval = 1000000000;
    printf("Welcome to the Time Travel Simulator!\n");

    // Loop until destination time is reached
    while (current_time < dest_time) {

        // Calculate time difference
        long int diff = (long int) difftime(dest_time, current_time);

        // Display remaining time
        int years = diff / (365 * 24 * 60 * 60);
        diff %= 365 * 24 * 60 * 60;
        int days = diff / (24 * 60 * 60);
        diff %= 24 * 60 * 60;
        int hours = diff / (60 * 60);
        diff %= 60 * 60;
        int minutes = diff / 60;
        int seconds = diff % 60;
        printf("Time until destination: %02d years, %02d days, %02d:%02d:%02d\n", years, days, hours, minutes, seconds);

        // Wait for interval
        for (long int i = 0; i < interval; i++);

        // Update current time
        current_time = time(NULL);
        current_tm = localtime(&current_time);

    }

    // Display arrival message and destination time
    printf("You have arrived at your destination!\n");
    strftime(time_str, 100, "%Y-%m-%d %H:%M:%S", dest_tm);
    printf("Destination time: %s\n", time_str);

    return 0;
}