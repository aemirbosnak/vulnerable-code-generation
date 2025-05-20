//MISTRAL-7B DATASET v1.0 Category: Wireless Network Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SSID_LEN 32
#define BUF_SIZE 256
#define FRAME_LEN 1024

typedef struct {
    char ssid[SSID_LEN];
    int rssi;
} Network;

void print_networks(Network networks[], int count) {
    printf("Scan Results:\n");
    for (int i = 0; i < count; ++i) {
        printf("%s: %d dBm\n", networks[i].ssid, networks[i].rssi);
    }
}

int scan_networks(Network networks[], int max_networks, int *num_networks) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in broadcast_addr;
    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

    char req[32] = {"AT+CWSAP\r\n"};
    char buf[BUF_SIZE];
    int len = 0;
    int num_found = 0;

    for (int i = 0; i < max_networks && num_found < max_networks; ++i) {
        networks[i].rssi = -1;
        strcpy(networks[i].ssid, "");

        if (sendto(sockfd, req, strlen(req), 0, (struct sockaddr*)&broadcast_addr, sizeof(broadcast_addr)) < 0) {
            perror("sendto");
            close(sockfd);
            return 1;
        }

        memset(buf, 0, BUF_SIZE);
        len = recvfrom(sockfd, buf, BUF_SIZE, 0, NULL, NULL);
        if (len <= 0) {
            close(sockfd);
            return 1;
        }

        char *ssid_start = strstr(buf, ":SSID:");
        char *ssid_end = strstr(ssid_start, ":RSSI:");
        if (ssid_start && ssid_end) {
            int ssid_len = ssid_end - ssid_start;
            strncpy(networks[i].ssid, ssid_start + 8, ssid_len - 7);
            networks[i].ssid[ssid_len - 1] = '\0';
            sscanf(ssid_end + 6, "%d", &networks[i].rssi);
            num_found++;
        }

        usleep(100000); // Wait for a short time before scanning the next network
    }

    *num_networks = num_found;
    close(sockfd);
    return 0;
}

int main() {
    Network networks[32];
    int num_networks;

    if (scan_networks(networks, sizeof(networks) / sizeof(Network), &num_networks)) {
        printf("Failed to scan networks.\n");
        return 1;
    }

    print_networks(networks, num_networks);

    printf("Found %d networks.\n", num_networks);
    return 0;
}

// End of the code snippet