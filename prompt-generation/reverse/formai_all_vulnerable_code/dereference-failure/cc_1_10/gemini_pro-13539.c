//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time travel simulator struct
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeTravelSimulator;

// Create a new time travel simulator
TimeTravelSimulator *new_time_travel_simulator() {
    TimeTravelSimulator *tts = malloc(sizeof(TimeTravelSimulator));
    tts->year = 2023;
    tts->month = 1;
    tts->day = 1;
    tts->hour = 0;
    tts->minute = 0;
    tts->second = 0;
    return tts;
}

// Destroy a time travel simulator
void destroy_time_travel_simulator(TimeTravelSimulator *tts) {
    free(tts);
}

// Set the time of the time travel simulator
void set_time_travel_simulator_time(TimeTravelSimulator *tts, int year, int month, int day, int hour, int minute, int second) {
    tts->year = year;
    tts->month = month;
    tts->day = day;
    tts->hour = hour;
    tts->minute = minute;
    tts->second = second;
}

// Get the time of the time travel simulator
void get_time_travel_simulator_time(TimeTravelSimulator *tts, int *year, int *month, int *day, int *hour, int *minute, int *second) {
    *year = tts->year;
    *month = tts->month;
    *day = tts->day;
    *hour = tts->hour;
    *minute = tts->minute;
    *second = tts->second;
}

// Travel forward in time by a specified number of years
void time_travel_forward(TimeTravelSimulator *tts, int years) {
    tts->year += years;
}

// Travel backward in time by a specified number of years
void time_travel_backward(TimeTravelSimulator *tts, int years) {
    tts->year -= years;
}

// Travel forward in time by a specified number of months
void time_travel_forward_months(TimeTravelSimulator *tts, int months) {
    tts->month += months;
    if (tts->month > 12) {
        tts->year++;
        tts->month -= 12;
    }
}

// Travel backward in time by a specified number of months
void time_travel_backward_months(TimeTravelSimulator *tts, int months) {
    tts->month -= months;
    if (tts->month < 1) {
        tts->year--;
        tts->month += 12;
    }
}

// Travel forward in time by a specified number of days
void time_travel_forward_days(TimeTravelSimulator *tts, int days) {
    tts->day += days;
    int month_length = 30;
    if (tts->month == 2) {
        month_length = 28;
    } else if (tts->month == 4 || tts->month == 6 || tts->month == 9 || tts->month == 11) {
        month_length = 30;
    }
    if (tts->day > month_length) {
        tts->month++;
        tts->day -= month_length;
    }
}

// Travel backward in time by a specified number of days
void time_travel_backward_days(TimeTravelSimulator *tts, int days) {
    tts->day -= days;
    int month_length = 30;
    if (tts->month == 2) {
        month_length = 28;
    } else if (tts->month == 4 || tts->month == 6 || tts->month == 9 || tts->month == 11) {
        month_length = 30;
    }
    if (tts->day < 1) {
        tts->month--;
        tts->day += month_length;
    }
}

// Travel forward in time by a specified number of hours
void time_travel_forward_hours(TimeTravelSimulator *tts, int hours) {
    tts->hour += hours;
    if (tts->hour > 23) {
        tts->day++;
        tts->hour -= 24;
    }
}

// Travel backward in time by a specified number of hours
void time_travel_backward_hours(TimeTravelSimulator *tts, int hours) {
    tts->hour -= hours;
    if (tts->hour < 0) {
        tts->day--;
        tts->hour += 24;
    }
}

// Travel forward in time by a specified number of minutes
void time_travel_forward_minutes(TimeTravelSimulator *tts, int minutes) {
    tts->minute += minutes;
    if (tts->minute > 59) {
        tts->hour++;
        tts->minute -= 60;
    }
}

// Travel backward in time by a specified number of minutes
void time_travel_backward_minutes(TimeTravelSimulator *tts, int minutes) {
    tts->minute -= minutes;
    if (tts->minute < 0) {
        tts->hour--;
        tts->minute += 60;
    }
}

// Travel forward in time by a specified number of seconds
void time_travel_forward_seconds(TimeTravelSimulator *tts, int seconds) {
    tts->second += seconds;
    if (tts->second > 59) {
        tts->minute++;
        tts->second -= 60;
    }
}

// Travel backward in time by a specified number of seconds
void time_travel_backward_seconds(TimeTravelSimulator *tts, int seconds) {
    tts->second -= seconds;
    if (tts->second < 0) {
        tts->minute--;
        tts->second += 60;
    }
}

// Print the current time of the time travel simulator
void print_time_travel_simulator_time(TimeTravelSimulator *tts) {
    printf("%d-%02d-%02d %02d:%02d:%02d\n", tts->year, tts->month, tts->day, tts->hour, tts->minute, tts->second);
}

// Run the time travel simulator
int main() {
    // Create a new time travel simulator
    TimeTravelSimulator *tts = new_time_travel_simulator();

    // Set the initial time of the time travel simulator
    set_time_travel_simulator_time(tts, 2023, 1, 1, 0, 0, 0);

    // Travel forward in time by 10 years
    time_travel_forward(tts, 10);

    // Print the current time of the time travel simulator
    print_time_travel_simulator_time(tts);

    // Travel backward in time by 5 years
    time_travel_backward(tts, 5);

    // Print the current time of the time travel simulator
    print_time_travel_simulator_time(tts);

    // Travel forward in time by 3 months
    time_travel_forward_months(tts, 3);

    // Print the current time of the time travel simulator
    print_time_travel_simulator_time(tts);

    // Travel backward in time by 2 months
    time_travel_backward_months(tts, 2);

    // Print the current time of the time travel simulator
    print_time_travel_simulator_time(tts);

    // Destroy the time travel simulator
    destroy_time_travel_simulator(tts);

    return 0;
}