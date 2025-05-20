//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

// Function to get the website uptime
int get_uptime(char *url, int interval, int duration) {
    CURL *curl;
    CURLcode res;
    double avg_uptime = 0;
    int i;

    // Initialize CURL
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return -1;
    }

    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set timeout
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Set user agent
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36");

    // Fetch the website
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return -1;
    }

    // Calculate the uptime
    for (i = 0; i < duration; i++) {
        // Sleep for the specified interval
        sleep(interval);

        // Fetch the website again
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            // Website is up
            avg_uptime += 1;
        }
    }

    // Calculate the average uptime
    avg_uptime /= duration;

    // Cleanup CURL
    curl_easy_cleanup(curl);

    // Return the average uptime
    return (int)(avg_uptime * 100);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <url> <interval> <duration>\n", argv[0]);
        return -1;
    }

    // Get the website uptime
    int uptime = get_uptime(argv[1], atoi(argv[2]), atoi(argv[3]));
    if (uptime < 0) {
        fprintf(stderr, "Error getting website uptime\n");
        return -1;
    }

    // Print the uptime
    printf("Website uptime: %d%%\n", uptime);

    return 0;
}