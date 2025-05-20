//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100

// A very serious enum for months. Don't laugh, it's a big deal.
enum {
    JAN = 1, FEB, MAR, APR, MAY, JUN,
    JUL, AUG, SEP, OCT, NOV, DEC
};

// This function will make sure we can understand dates like: "I was born on the 3rd of October, 1995."
int parse_date(char* input, struct tm* date) {
    int day, month, year;
    
    // Super serious regex pattern to parse dates. Totally doesn't involve magic.
    if (sscanf(input, "I was born on the %d of %[^,], %d.", &day, date->tm_zone, &year) == 3) {
        // Now we need to translate the month from its silly name to its number!
        if (strcmp(date->tm_zone, "January") == 0) month = JAN;
        else if (strcmp(date->tm_zone, "February") == 0) month = FEB;
        else if (strcmp(date->tm_zone, "March") == 0) month = MAR;
        else if (strcmp(date->tm_zone, "April") == 0) month = APR;
        else if (strcmp(date->tm_zone, "May") == 0) month = MAY;
        else if (strcmp(date->tm_zone, "June") == 0) month = JUN;
        else if (strcmp(date->tm_zone, "July") == 0) month = JUL;
        else if (strcmp(date->tm_zone, "August") == 0) month = AUG;
        else if (strcmp(date->tm_zone, "September") == 0) month = SEP;
        else if (strcmp(date->tm_zone, "October") == 0) month = OCT;
        else if (strcmp(date->tm_zone, "November") == 0) month = NOV;
        else if (strcmp(date->tm_zone, "December") == 0) month = DEC;
        else {
            printf("Oops! Unrecognized month! What year are we living in, anyway?\n");
            return -1;
        }
        
        date->tm_mday = day;
        date->tm_mon = month - 1; // tm_mon is 0-indexed. Because, why not?
        date->tm_year = year - 1900; // tm_year is years since 1900! What a trip down memory lane!
        date->tm_hour = 0;
        date->tm_min = 0;
        date->tm_sec = 0;

        return 0;
    } else {
        printf("Failed to parse your date. Maybe it was too funny?\n");
        return -1;
    }
}

// Here we’ll play our favorite guessing game: create a human-readable date string from a tm structure
void format_date(struct tm* date, char* buffer, size_t size) {
    strftime(buffer, size, "The date is: %A, %B %d, %Y. What a magnificent day!", date);
}

// Let's start our program like a grand feast - with an appetizer of human interaction!
int main() {
    char input[MAX_LEN];
    struct tm date;
    char buffer[MAX_LEN];

    printf("Welcome to the *Ultimate Date Converter*! 🎉\n");
    printf("Tell me, when were you born? (in this format: I was born on the 3rd of October, 1995.)\n");
    
    // Keep it light! 
    while (1) {
        printf("Just a little chit-chat: ");
        fgets(input, MAX_LEN, stdin);
        
        // If the user gets tired of typing, let them go away with a wink! 
        if (strcmp(input, "exit\n") == 0) {
            printf("Oh, you're leaving? But we were just about to have dessert! 🍰\n");
            break;
        }

        // Let's get serious (but not really) about parsing the date!
        if (parse_date(input, &date) == 0) {
            format_date(&date, buffer, sizeof(buffer));
            printf("%s\n", buffer);
        } else {
            printf("Try again, this time with less nonsense and more clarity! 🤔\n");
        }
    }

    printf("Thanks for playing the date game! Remember, you're timeless! 😄\n");
    return 0;
}