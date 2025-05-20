//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <curl/curl.h>

typedef struct {
    char *url;
    char *email;
    int refresh_interval;
} Website;

typedef struct {
    Website *websites;
    int num_websites;
} MonitorConfig;

bool is_website_up(char *url) {
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, true);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            return false;
        }
        int http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        curl_easy_cleanup(curl);
        return http_code == 200;
    }
}

void send_email_alert(char *email, char *url) {
    char command[1024];
    sprintf(command, "echo 'Website %s is down!' | mail -s 'Website Down Alert' %s", url, email);
    system(command);
}

void monitor_websites(Website *websites, int num_websites) {
    bool *website_status = calloc(num_websites, sizeof(bool));
    while (true) {
        for (int i = 0; i < num_websites; i++) {
            bool curr_status = is_website_up(websites[i].url);
            if (curr_status != website_status[i]) {
                website_status[i] = curr_status;
                if (!curr_status) {
                    send_email_alert(websites[i].email, websites[i].url);
                }
            }
        }
        sleep(websites[0].refresh_interval);
    }
    free(website_status);
}

int main() {
    Website websites[] = {
        {"https://www.google.com", "user@example.com", 60},
        {"https://www.facebook.com", "user@example.com", 60}
    };
    int num_websites = sizeof(websites) / sizeof(Website);
    MonitorConfig config = {websites, num_websites};
    monitor_websites(config.websites, config.num_websites);
    return 0;
}