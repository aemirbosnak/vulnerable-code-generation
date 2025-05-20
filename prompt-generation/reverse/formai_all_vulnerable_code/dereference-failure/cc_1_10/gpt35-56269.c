//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for fortunes
struct fortune {
    char* message;
    int rating;
};

// Function to get the current time
void get_time(int* hour, int* minute) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    *hour = tm.tm_hour;
    *minute = tm.tm_min;
}

// Main function
int main() {
    // Fortune messages
    char* early_morning[] = {
        "The early bird catches the worm.",
        "You will soon receive a gift.",
        "Your hard work will pay off soon."
    };
    int early_morning_length = 3;

    char* late_morning[] = {
        "You will meet someone new today.",
        "Your creativity will be at its peak today.",
        "Take a chance, it will pay off."
    };
    int late_morning_length = 3;

    char* afternoon[] = {
        "Be patient, good things come to those who wait.",
        "You will learn something new today.",
        "Your positivity will bring you success."
    };
    int afternoon_length = 3;

    char* evening[] = {
        "Your dedication will be noticed by others.",
        "You will make a new friend today.",
        "Your future looks bright."
    };
    int evening_length = 3;

    char* night[] = {
        "Take time to relax and unwind.",
        "You have a bright future ahead of you.",
        "Your hard work will pay off in the long run."
    };
    int night_length = 3;

    // Get the current time
    int hour, minute;
    get_time(&hour, &minute);

    // Select a fortune based on the time of day
    struct fortune f;
    if (hour >= 4 && hour < 7) {
        int index = rand() % early_morning_length;
        f.message = early_morning[index];
        f.rating = 3;
    }
    else if (hour >= 7 && hour < 11) {
        int index = rand() % late_morning_length;
        f.message = late_morning[index];
        f.rating = 5;
    }
    else if (hour >= 11 && hour < 15) {
        int index = rand() % afternoon_length;
        f.message = afternoon[index];
        f.rating = 4;
    }
    else if (hour >= 15 && hour < 19) {
        int index = rand() % evening_length;
        f.message = evening[index];
        f.rating = 4;
    }
    else {
        int index = rand() % night_length;
        f.message = night[index];
        f.rating = 3;
    }

    // Print the fortune
    printf("Your fortune for today:\n");
    printf("%s\n", f.message);

    // Print rating
    printf("Rating: %d/5\n", f.rating);

    return 0;
}