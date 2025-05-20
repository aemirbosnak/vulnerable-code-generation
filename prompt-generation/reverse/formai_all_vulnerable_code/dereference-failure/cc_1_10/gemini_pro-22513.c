//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URLS 100

struct url_info {
    char *url;
    time_t last_checked;
    int status_code;
};

struct url_info urls[MAX_URLS];
int num_urls = 0;

// Function to check the status of a URL
int check_url(char *url) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res == CURLE_OK) {
            return 200;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

// Function to add a URL to the list of URLs to monitor
void add_url(char *url) {
    if (num_urls < MAX_URLS) {
        urls[num_urls].url = strdup(url);
        urls[num_urls].last_checked = time(NULL);
        urls[num_urls].status_code = -1;
        num_urls++;
    }
}

// Function to check the status of all URLs in the list
void check_all_urls() {
    int i;

    for (i = 0; i < num_urls; i++) {
        urls[i].status_code = check_url(urls[i].url);
        urls[i].last_checked = time(NULL);
    }
}

// Function to print the status of all URLs in the list
void print_status() {
    int i;

    printf("URL\t\t\tStatus\t\tLast Checked\n");
    for (i = 0; i < num_urls; i++) {
        printf("%s\t\t", urls[i].url);
        if (urls[i].status_code == 200) {
            printf("OK\t\t");
        } else {
            printf("ERROR\t\t");
        }
        printf("%s\n", ctime(&urls[i].last_checked));
    }
}

// Main function
int main(int argc, char **argv) {
    int i;

    // Check if the user has provided any URLs to monitor
    if (argc < 2) {
        printf("Usage: %s <url1> <url2> ... <urln>\n", argv[0]);
        return 1;
    }

    // Add the URLs to the list of URLs to monitor
    for (i = 1; i < argc; i++) {
        add_url(argv[i]);
    }

    // Check the status of all URLs in the list
    check_all_urls();

    // Print the status of all URLs in the list
    print_status();

    return 0;
}