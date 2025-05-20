//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 100
#define USER_AGENT "Sherlock/1.0"
#define TIMEOUT 5

typedef struct {
    char url[256];
    int status;
    time_t last_checked;
} MonitoredSite;

MonitoredSite sites[MAX_URLS];
int site_count = 0;

void add_site(const char *url) {
    if (site_count < MAX_URLS) {
        strncpy(sites[site_count].url, url, sizeof(sites[site_count].url) - 1);
        sites[site_count].status = -1;  // Unknown status
        sites[site_count].last_checked = time(NULL);
        site_count++;
    } else {
        printf("Maximum site limit reached!\n");
    }
}

int check_site(const char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, USER_AGENT);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 0; // Failed to reach site
        }
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        return (response_code == 200) ? 1 : 0; // 1: UP, 0: DOWN
    }
    return 0; // Failure to initiate cURL
}

void monitor_sites() {
    while (1) {
        printf("----- Uptime Monitoring -----\n");
        for (int i = 0; i < site_count; i++) {
            int is_up = check_site(sites[i].url);
            sites[i].status = is_up;
            sites[i].last_checked = time(NULL);

            if (is_up) {
                printf("Site: %-30s Status: %-10s Last Checked: %s",
                       sites[i].url,
                       "UP",
                       ctime(&sites[i].last_checked));
            } else {
                printf("Site: %-30s Status: %-10s Last Checked: %s",
                       sites[i].url,
                       "DOWN",
                       ctime(&sites[i].last_checked));
            }
        }
        printf("Sleeping for 30 seconds...\n");
        sleep(30); // Wait before checking again
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT); // Initialize curl
    for (int i = 1; i < argc; i++) {
        add_site(argv[i]);
    }

    monitor_sites();

    curl_global_cleanup(); // Clean up curl
    return EXIT_SUCCESS;
}