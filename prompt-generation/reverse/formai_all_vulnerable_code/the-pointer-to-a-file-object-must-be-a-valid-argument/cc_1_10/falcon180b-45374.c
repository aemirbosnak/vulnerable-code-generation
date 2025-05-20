//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18
#define MAX_SCAN_RESULTS 10
#define MAX_DATA_SIZE 4096

struct wifi_data {
    char ssid[MAX_SSID_LENGTH];
    char bssid[MAX_BSSID_LENGTH];
    int signal_strength;
};

struct scan_result {
    int num_results;
    struct wifi_data results[MAX_SCAN_RESULTS];
};

void *scan_thread(void *arg) {
    struct scan_result *result = (struct scan_result *) arg;
    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    char cmd[80] = "iwlist wlan0 scan";
    FILE *fp = popen(cmd, "r");

    char line[MAX_DATA_SIZE];
    int num_results = 0;

    while (fgets(line, MAX_DATA_SIZE, fp)!= NULL) {
        if (strstr(line, "ESSID")!= NULL) {
            char *ssid_ptr = strstr(line, ":\"") + 2;
            char *bssid_ptr = strstr(line, "\"");
            if (ssid_ptr!= NULL && bssid_ptr!= NULL) {
                strncpy(result->results[num_results].ssid, ssid_ptr, MAX_SSID_LENGTH);
                strncpy(result->results[num_results].bssid, bssid_ptr, MAX_BSSID_LENGTH);
                result->results[num_results].signal_strength = -1;
                num_results++;
            }
        } else if (strstr(line, "Signal level")!= NULL) {
            char *ssid_ptr = strstr(line, ":") + 1;
            int i;
            for (i = 0; i < num_results; i++) {
                if (strcmp(result->results[i].ssid, ssid_ptr) == 0) {
                    char *signal_ptr = strstr(line, "dBm") + 4;
                    result->results[i].signal_strength = atoi(signal_ptr);
                    break;
                }
            }
        }
    }

    pclose(fp);
    close(sock);

    return NULL;
}

int main() {
    struct scan_result result;
    pthread_t thread_id;
    int i;

    pthread_create(&thread_id, NULL, scan_thread, &result);

    sleep(2);

    for (i = 0; i < MAX_SCAN_RESULTS; i++) {
        if (result.results[i].signal_strength!= -1) {
            printf("SSID: %s\nBSSID: %s\nSignal strength: %d dBm\n",
                   result.results[i].ssid, result.results[i].bssid, result.results[i].signal_strength);
        }
    }

    pthread_join(thread_id, NULL);

    return 0;
}