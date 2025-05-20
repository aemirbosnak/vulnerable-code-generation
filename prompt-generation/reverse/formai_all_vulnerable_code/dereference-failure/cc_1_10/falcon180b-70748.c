//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SAMPLES 100
#define MAX_DATA_SIZE 1024

struct wifi_data {
    int signal_strength;
    time_t timestamp;
};

int main() {
    FILE *fp;
    char line[MAX_DATA_SIZE];
    char *token;
    struct wifi_data data;
    int samples = 0;

    fp = fopen("wifi_data.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_DATA_SIZE, fp)!= NULL) {
        token = strtok(line, ",");
        data.signal_strength = atoi(token);
        token = strtok(NULL, ",");
        strptime(token, "%Y-%m-%d %H:%M:%S", &data.timestamp);
        samples++;
        if (samples >= MAX_SAMPLES) {
            break;
        }
    }

    fclose(fp);

    if (samples == 0) {
        printf("No data found.\n");
        exit(0);
    }

    int total_signal_strength = 0;
    time_t oldest_timestamp = data.timestamp;
    time_t newest_timestamp = data.timestamp;

    for (int i = 0; i < samples; i++) {
        total_signal_strength += data.signal_strength;

        if (data.timestamp < oldest_timestamp) {
            oldest_timestamp = data.timestamp;
        }

        if (data.timestamp > newest_timestamp) {
            newest_timestamp = data.timestamp;
        }

        data = (struct wifi_data){0};
    }

    double average_signal_strength = (double) total_signal_strength / samples;
    int days_since_oldest_timestamp = difftime(time(NULL), mktime(&oldest_timestamp));
    int days_since_newest_timestamp = difftime(time(NULL), mktime(&newest_timestamp));

    printf("Total samples: %d\n", samples);
    printf("Average signal strength: %.2f\n", average_signal_strength);
    printf("Days since oldest timestamp: %d\n", days_since_oldest_timestamp);
    printf("Days since newest timestamp: %d\n", days_since_newest_timestamp);

    return 0;
}