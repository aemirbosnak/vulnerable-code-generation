//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ssid[20];
    char bssid[18];
    char channel[5];
    char signal[5];
} wireless_network;

int main() {
    char output[1024];
    char buffer[1024];
    wireless_network *networks[10];
    int count = 0;

    // Use system call to execute wireless network scanner
    system("iwlist wlan0 scanning | egrep 'ESSID|Address|Channel|Signal' > output.txt");

    // Open file and read output
    FILE *f = fopen("output.txt", "r");
    while (fgets(buffer, sizeof(buffer), f)) {
        strcat(output, buffer);
    }
    fclose(f);

    // Parse output and store in struct
    char *line = strtok(output, "\n");
    while (line != NULL) {
        if (strstr(line, "ESSID")) {
            // Store SSID
            wireless_network *nw = (wireless_network*) malloc(sizeof(wireless_network));
            char *begin = strchr(line, '\"');
            char *end = strchr(begin+1, '\"');
            int length = end-begin-1;
            strncpy(nw->ssid, begin+1, length);
            nw->ssid[length] = '\0';
            networks[count++] = nw;
        }
        else if (strstr(line, "Address")) {
            // Store BSSID
            char *bssid = line + strlen(line) - 17;
            wireless_network *nw = networks[count-1];
            strncpy(nw->bssid, bssid, 17);
            nw->bssid[17] = '\0';
        }
        else if (strstr(line, "Channel")) {
            // Store channel
            char *channel = line + strlen(line) - 1;
            wireless_network *nw = networks[count-1];
            strncpy(nw->channel, channel, 1);
            nw->channel[1] = '\0';
        }
        else if (strstr(line, "Signal")) {
            // Store signal strength
            char *begin = strchr(line, '-');
            char *end = strchr(line, 'd');
            int length = end-begin+1;
            strncpy(networks[count-1]->signal, begin+1, length);
            networks[count-1]->signal[length] = '\0';
        }
        line = strtok(NULL, "\n");
    }

    // Print results
    printf("%-20s%-18s%s%8s\n", "SSID", "BSSID", "Channel", "Signal");
    for (int i = 0; i < count; i++) {
        wireless_network *nw = networks[i];
        printf("%-20s%-18s%-9s%-7s\n", nw->ssid, nw->bssid, nw->channel, nw->signal);
    }
    return 0;
}