//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    srand(now);
    
    printf("Welcome to the Time Travel Simulator!\n");
    printf("This program will take you on a journey to a random time period.\n\n");
    
    printf("Press Enter to begin...\n\n");
    getchar();
    
    printf("Calculating the destination time...\n");
    
    int years = rand() % 2001 - 1000; // Random integer between -1000 and 1000
    int months = rand() % 12; // Random integer between 0 and 11
    int days = rand() % 31; // Random integer between 0 and 30
    
    printf("\nYou will travel %d years, %d months, and %d days into the past or future.\n", years, months, days);
    
    struct tm dest_time = *t; // Copy current time
    dest_time.tm_year += years;
    dest_time.tm_mon += months;
    dest_time.tm_mday += days;
    
    time_t dest = mktime(&dest_time); // Convert to time_t
    
    if (dest == (time_t) -1) { // Error checking
        perror("mktime");
        exit(EXIT_FAILURE);
    }
    
    printf("Press Enter to begin time travel...\n\n");
    getchar();
    
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    
    printf("You have arrived at your destination time!\n\n");
    
    char dest_str[80];
    strftime(dest_str, sizeof(dest_str), "%c", &dest_time);
    printf("It is now %s.\n", dest_str);
    
    printf("Thank you for using the Time Travel Simulator!\n");
    
    return 0;
}