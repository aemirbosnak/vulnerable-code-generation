//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define MONITORED_URL "http://example.com"
#define MAX_ATTEMPTS 10
#define TIME_INTERVAL 5 // in seconds

typedef struct {
    int up;
    int down;
} UptimeStats;

void log_event(int attempt, const char *status) {
    FILE *log_file = fopen("uptime_log.txt", "a");
    if (log_file) {
        time_t now = time(NULL);
        char *time_str = ctime(&now);
        time_str[strlen(time_str) - 1] = '\0'; // Remove newline
        fprintf(log_file, "[%s] Attempt %d: %s\n", time_str, attempt, status);
        fclose(log_file);
    }
}

void update_stats(UptimeStats *stats, int result) {
    if (result == CURLE_OK) {
        stats->up++;
    } else {
        stats->down++;
    }
}

void print_report(UptimeStats *stats) {
    printf("Uptime Report:\n");
    printf("Site was UP: %d times\n", stats->up);
    printf("Site was DOWN: %d times\n", stats->down);
    double total_checks = stats->up + stats->down;
    if (total_checks > 0) {
        double uptime_percentage = (double)stats->up / total_checks * 100;
        printf("Uptime Percentage: %.2f%%\n", uptime_percentage);
    } else {
        printf("No checks performed yet.\n");
    }
}

int main() {
    CURL *curl;
    CURLcode res;
    UptimeStats stats = {0, 0};

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        for(int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
            curl_easy_setopt(curl, CURLOPT_URL, MONITORED_URL);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1); // No body needed, we just want the response code
            res = curl_easy_perform(curl);

            if(res == CURLE_OK) {
                long response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                if(response_code == 200) {
                    log_event(attempt, "UP");
                    update_stats(&stats, CURLE_OK);
                } else {
                    log_event(attempt, "DOWN - Non-200 Response");
                    update_stats(&stats, CURLE_COULDNT_CONNECT);
                }
            } else {
                log_event(attempt, "DOWN - Connection Failed");
                update_stats(&stats, res);
            }

            sleep(TIME_INTERVAL);
        }
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    
    print_report(&stats);
    return 0;
}