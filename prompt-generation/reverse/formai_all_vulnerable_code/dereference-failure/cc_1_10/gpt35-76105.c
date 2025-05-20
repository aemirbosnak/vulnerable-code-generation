//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/* Function to generate random numbers between two limits */
int generate_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to check if website is up or down */
bool is_up(const char *url) {
    int random = generate_random(1, 100);
    if (random <= 75) {
        printf("%s is up!\n", url);
        return true;
    } else {
        printf("%s is down!\n", url);
        return false;
    }
}

int main() {
    /* Array of website URLs to monitor */
    const char *urls[] = {"https://www.google.com", 
                          "https://www.facebook.com", 
                          "https://www.instagram.com", 
                          "https://www.linkedin.com", 
                          "https://www.twitter.com"};

    /* Loop to check URLs every minute */
    while (true) {
        time_t now = time(NULL);
        struct tm *tm_now = localtime(&now);
        int hour = tm_now->tm_hour;
        int minute = tm_now->tm_min;

        printf("[%02d:%02d] Checking website uptime...\n", hour, minute);

        for (int i = 0; i < 5; i++) {
            if (!is_up(urls[i])) {
                /* Code to handle website being down goes here */
            }
        }

        /* Sleep for 1 minute */
        printf("[%02d:%02d] Sleeping...\n", hour, minute);
        sleep(60);
    }

    return 0;
}