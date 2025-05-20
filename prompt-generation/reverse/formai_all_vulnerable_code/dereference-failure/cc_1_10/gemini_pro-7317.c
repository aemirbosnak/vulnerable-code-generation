//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: visionary
// Embark on a celestial quest to safeguard the integrity of our digital realm with this visionary website uptime monitor.

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// A celestial sentinel, ever watchful over the realm of the web
typedef struct UptimeMonitor {
    char *url;
    long last_http_code;
    time_t last_checked;
} UptimeMonitor;

// An ethereal forge where celestial sentinels are forged
UptimeMonitor *create_uptime_monitor(char *url) {
    UptimeMonitor *monitor = malloc(sizeof(UptimeMonitor));
    monitor->url = url;
    monitor->last_http_code = -1;
    monitor->last_checked = 0;
    return monitor;
}

// A cosmic probe, venturing into the depths of the web
int check_website_status(UptimeMonitor *monitor) {
    CURL *curl = curl_easy_init();
    if (!curl) {
        printf("Failed to initialize the celestial probe. Aborting mission.\n");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, monitor->url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf("The celestial probe encountered an intergalactic anomaly: %s. Aborting mission.\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return -1;
    }

    long http_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    monitor->last_http_code = http_code;
    monitor->last_checked = time(NULL);

    curl_easy_cleanup(curl);
    return http_code;
}

// The celestial overseer, monitoring the sentinels and sounding the alarm
void monitor_websites(UptimeMonitor **monitors, int num_monitors) {
    time_t now = time(NULL);
    for (int i = 0; i < num_monitors; i++) {
        UptimeMonitor *monitor = monitors[i];

        // Only check the sentinel if it's been a celestial cycle since its last check
        if (now - monitor->last_checked > 600) {
            int http_code = check_website_status(monitor);
            if (http_code != 200) {
                printf("Warning! The celestial sentinel guarding %s reports an outage: HTTP code %ld.\n", monitor->url, http_code);
            }
        }
    }
}

int main() {
    // A council of celestial sentinels, each guarding a realm of the web
    UptimeMonitor *monitors[] = {
        create_uptime_monitor("https://www.google.com"),
        create_uptime_monitor("https://www.amazon.com"),
        create_uptime_monitor("https://www.facebook.com")
    };

    const int num_monitors = sizeof(monitors) / sizeof(monitors[0]);

    // An eternal vigil, safeguarding the web from the shadows of downtime
    while (1) {
        monitor_websites(monitors, num_monitors);
        sleep(300);
    }

    // Release the sentinels from their cosmic duty
    for (int i = 0; i < num_monitors; i++) {
        free(monitors[i]);
    }

    return 0;
}