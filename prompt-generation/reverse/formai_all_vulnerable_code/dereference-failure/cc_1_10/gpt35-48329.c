//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: expert-level
#include <stdio.h>
#include <time.h>

// Function to convert given time to seconds
long long int time_to_secs(struct tm* t) {
    long long int hours = t->tm_hour;
    long long int minutes = t->tm_min;
    long long int seconds = t->tm_sec;
    
    return hours * 3600 + minutes * 60 + seconds;
}

// Function to convert given date to seconds
long long int date_to_secs(struct tm* t) {
    long long int year = t->tm_year + 1900;
    long long int month = t->tm_mon + 1;
    long long int day = t->tm_mday;
    
    if (month < 3) { // adjust month and year in case of Jan/Feb
        month += 12;
        year -= 1;
    }
    
    // Formula for calculating Julian calendar
    long long int a = year / 100;
    long long int b = a / 4;
    long long int c = 2 - a + b;
    long long int e = 365.25 * (year + 4716);
    long long int f = 30.6001 * (month + 1);
    
    return c + day + e + f - 1524.5;
}

int main() {
    time_t current_time;
    struct tm* current_date_time;
    
    // Get current date and time
    current_time = time(NULL);
    current_date_time = localtime(&current_time);
    
    // Get the current date and time in seconds
    long long int current_time_secs = time_to_secs(current_date_time);
    long long int current_date_secs = date_to_secs(current_date_time);
    
    // Ask user to enter a date and time to travel to
    printf("Enter the date and time to travel to (dd-mm-yyyy hh:mm:ss): ");
    struct tm travel_date_time = {0};
    scanf("%d-%d-%d %d:%d:%d", &travel_date_time.tm_mday, &travel_date_time.tm_mon, &travel_date_time.tm_year, &travel_date_time.tm_hour, &travel_date_time.tm_min, &travel_date_time.tm_sec);
    
    // Convert the travel date and time to seconds
    long long int travel_time_secs = time_to_secs(&travel_date_time);
    long long int travel_date_secs = date_to_secs(&travel_date_time);
    
    // Calculate the difference between the current date and time, and the travel date and time
    long long int diff_secs = travel_time_secs - current_time_secs;
    long long int diff_date_secs = travel_date_secs - current_date_secs;
    long long int diff_total_secs = diff_secs + (diff_date_secs * 86400); // 86400 seconds in a day
    
    // Determine whether the user is traveling to the past or future
    char* travel_word;
    if (diff_total_secs < 0) {
        travel_word = "traveling to the past";
    } else {
        travel_word = "traveling to the future";
    }
    
    printf("You are %s. The time and date difference is %lld seconds.\n", travel_word, diff_total_secs);
    
    return 0;
}