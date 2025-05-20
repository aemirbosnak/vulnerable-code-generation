//MISTRAL-7B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define WIFI_SCAN_TIME 5
#define MAX_AP_COUNT 255

typedef struct {
    char ssid[32];
    int rssi;
    int sqm;
} wifi_ap;

void scan_wifi(wifi_ap ap[], int* num_ap) {
    int fd, ret;
    char line[128];
    char command[64];

    snprintf(command, sizeof(command), "iwscan wlan0 mon | grep -B 1 'Cell' | awk '/[^:]+:/ {printf \"%s\", \$2}' | tr -d '\n' | sed 's/\ //g' | tr '\n' '\0' | tr -d '\0' | tr '\n' ' ' | sed 's/ //g' | tr '\n' '\0' | tr -d '\0' | tr '\n' ' ' | sed 's/[[:space:]]\+$//g' > wifi_scan.txt");
    system(command);

    fd = open("wifi_scan.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening scan file");
        return;
    }

    fgets(line, sizeof(line), fd);
    fclose(fd);

    char* token = strtok(line, " ");
    *num_ap = 0;

    while (token != NULL) {
        int ap_index = *num_ap++;
        wifi_ap* current_ap = &ap[ap_index];
        strcpy(current_ap->ssid, token);
        token = strtok(NULL, " ");
        current_ap->rssi = atoi(token);
        token = strtok(NULL, " ");
        current_ap->sqm = atoi(token);

        if (token != NULL) {
            printf("Invalid format: %s\n", token);
            break;
        }
    }

    remove("wifi_scan.txt");
}

int main() {
    wifi_ap ap[MAX_AP_COUNT];
    int num_ap;

    printf("Scanning Wi-Fi networks...\n");
    scan_wifi(ap, &num_ap);

    if (num_ap == 0) {
        printf("No Wi-Fi networks found.\n");
        return 1;
    }

    printf("\n%-32s %-5s %-5s\n", "SSID", "RSSI (dBm)", "Signal Quality (SQM)");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < num_ap; i++) {
        wifi_ap* current_ap = &ap[i];
        printf("%-32s %-5d %-5d\n", current_ap->ssid, current_ap->rssi, current_ap->sqm);
    }

    printf("\nFinished analyzing Wi-Fi networks.\n");

    return 0;
}