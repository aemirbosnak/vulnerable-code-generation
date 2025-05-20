//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <curl/curl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_URL_LENGTH 256
#define MAX_FILENAME_LENGTH 512
#define MAX_TIME_STRING_LENGTH 32

// Function to get the current time as a string
void get_current_time(char *time_string) {
    time_t rawtime;
    struct tm *info;

    time(&rawtime);
    info = localtime(&rawtime);

    strftime(time_string, MAX_TIME_STRING_LENGTH, "%Y-%m-%d %H:%M:%S", info);
}

// Function to create a unique filename for the log file
void get_unique_filename(char *filename) {
    char time_string[MAX_TIME_STRING_LENGTH];

    get_current_time(time_string);

    snprintf(filename, MAX_FILENAME_LENGTH, "uptime-monitor-%s.log", time_string);
}

// Function to check the uptime of a website
int check_uptime(char *url, char *filename) {
    CURL *curl;
    CURLcode res;
    long response_code;
    FILE *fp;
    char time_string[MAX_TIME_STRING_LENGTH];

    // Initialize the curl session
    curl = curl_easy_init();
    if (!curl) {
        return -1;
    }

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the timeout for the request
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Set the user agent for the request
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "uptime-monitor/1.0");

    // Set the file to write the response to
    fp = fopen(filename, "a");
    if (!fp) {
        curl_easy_cleanup(curl);
        return -1;
    }
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    // Perform the request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fclose(fp);
        curl_easy_cleanup(curl);
        return -1;
    }

    // Get the response code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Get the current time
    get_current_time(time_string);

    // Write the response code and time to the log file
    fprintf(fp, "%s: %ld\n", time_string, response_code);

    // Close the file
    fclose(fp);

    // Cleanup the curl session
    curl_easy_cleanup(curl);

    return 0;
}

int main(int argc, char *argv[]) {
    char *url = NULL;
    char *filename = NULL;
    char unique_filename[MAX_FILENAME_LENGTH];
    int interval = 60;
    int count = 0;
    int i;

    // Parse the command-line arguments
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0) {
            url = argv[i + 1];
        } else if (strcmp(argv[i], "-f") == 0) {
            filename = argv[i + 1];
        } else if (strcmp(argv[i], "-i") == 0) {
            interval = atoi(argv[i + 1]);
        } else if (strcmp(argv[i], "-c") == 0) {
            count = atoi(argv[i + 1]);
        }
    }

    // Check if the URL is specified
    if (!url) {
        printf("Error: URL not specified\n");
        return -1;
    }

    // Check if the filename is specified
    if (!filename) {
        get_unique_filename(unique_filename);
        filename = unique_filename;
    }

    // Check if the interval is valid
    if (interval <= 0) {
        printf("Error: Interval must be greater than 0\n");
        return -1;
    }

    // Check if the count is valid
    if (count < 0) {
        printf("Error: Count must be greater than or equal to 0\n");
        return -1;
    }

    // Run the uptime monitor
    while (count == 0 || count > 0) {
        if (check_uptime(url, filename) == 0) {
            printf("Website is up\n");
        } else {
            printf("Website is down\n");
        }

        if (count > 0) {
            count--;
        }

        sleep(interval);
    }

    return 0;
}