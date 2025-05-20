//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
void scan_networks(void);
void display_networks(char* ssid);
void exit_program(void);

int main(int argc, char **argv) {
    scan_networks();
    return 0;
}

void scan_networks(void) {
    char line[256];
    char ssid[50];
    char bssid[18];
    char freq[10];
    char channel[3];
    char quality[4];

    // Run iwlist command
    system("iwlist wlan0 scan | grep -v 'ESSID:' | grep -v 'Cell'| grep -v 'Channel' | grep -v 'Quality' > temp.txt");

    // Read temp.txt into memory
    FILE *fp = fopen("temp.txt", "r");
    fgets(line, sizeof(line), fp);
    int num_lines = 0;
    while(fgets(line, sizeof(line), fp)!= NULL) {
        num_lines++;
    }
    fclose(fp);

    // Filter out irrelevant lines
    char **arr = (char **)malloc(num_lines * sizeof(char *));
    char **curr = arr;
    for(int i = 0; i < num_lines; i++) {
        *curr++ = (char *)malloc(sizeof(char) * 256);
    }
    int index = 0;
    FILE *fp2 = fopen("temp.txt", "r");
    while(fgets(line, sizeof(line), fp2)!= NULL) {
        if(strstr(line, "ESSID")) {
            strncpy(ssid, line, 50);
            strtok(ssid, ":");
            strtok(ssid, ":");
            strtok(ssid, ":");
            strcpy(bssid, ssid);
            strtok(ssid, ":");
            strcpy(freq, ssid);
            strtok(ssid, ":");
            strcpy(channel, ssid);
            strtok(ssid, ":");
            strcpy(quality, ssid);
            printf("%s\t%s\t%s\t%s\t%s\n", bssid, freq, channel, quality, ssid);
            index++;
        }
    }
    free(arr[index]);
    for(int i = index - 1; i >= 0; i--) {
        free(arr[i]);
    }
    free(arr);
    fclose(fp2);
}

void display_networks(char *ssid) {
    printf("%s\t", ssid);
}

void exit_program(void) {
    exit(0);
}