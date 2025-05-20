//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define MAX_URLS 10
#define CHECK_INTERVAL 5

volatile sig_atomic_t keepRunning = 1;

void intHandler(int dummy) {
    keepRunning = 0;
}

typedef struct {
    char *url;
    int status;
    int response_time; // measured in milliseconds
} Monitor;

Monitor monitors[MAX_URLS];
int monitor_count = 0;

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb; // we discard the response data
}

void *check_url(void *arg) {
    Monitor *monitor = (Monitor *)arg;
    CURL *curl;
    CURLcode res;
    struct timeval start, end;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, monitor->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1); // We only want the HTTP header
        
        while (keepRunning) {
            gettimeofday(&start, NULL);
            res = curl_easy_perform(curl);
            gettimeofday(&end, NULL);

            if(res != CURLE_OK) {
                printf("Could not connect to %s: %s\n", monitor->url, curl_easy_strerror(res));
                monitor->status = 0;  // down
            } else {
                long response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                monitor->status = (response_code == 200) ? 1 : 0; // up/down
            }

            monitor->response_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;

            printf("Checked %s - Status: %s, Response Time: %d ms\n", monitor->url,
                   monitor->status ? "UP" : "DOWN", monitor->response_time);

            sleep(CHECK_INTERVAL); // wait before next check
        }
        curl_easy_cleanup(curl);
    }
    return NULL;
}

void start_monitoring() {
    pthread_t threads[MAX_URLS];
    for (int i = 0; i < monitor_count; i++) {
        pthread_create(&threads[i], NULL, check_url, (void *)&monitors[i]);
    }
    for (int i = 0; i < monitor_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

void load_urls(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    while (fgets(monitors[monitor_count].url, sizeof(monitors[monitor_count].url), file) && monitor_count < MAX_URLS) {
        monitors[monitor_count].url[strcspn(monitors[monitor_count].url, "\n")] = '\0'; // remove newline
        monitors[monitor_count].status = -1; // unknown status
        monitors[monitor_count].response_time = -1; // unknown response time
        monitor_count++;
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    signal(SIGINT, intHandler);

    load_urls(argv[1]);

    printf("Starting website uptime monitor...\n\n");
    start_monitoring();

    printf("\nMonitoring stopped.\n");

    return EXIT_SUCCESS;
}