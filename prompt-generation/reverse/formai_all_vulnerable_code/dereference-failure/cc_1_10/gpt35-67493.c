//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define PORT 80

int getSignalStrength(const char *ssid) {
    char cmd[100];
    sprintf(cmd, "iwconfig wlan0 | grep %s | awk '{print $4}'", ssid);
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        return -1;
    }
    char buffer[10];
    fgets(buffer, 10, fp);
    pclose(fp);
    return atoi(buffer);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char recvline[4096];
    char *ssid = "MyWiFi";

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    if ((n = inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr)) <= 0) {
        fprintf(stderr, "Failed to convert IP: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Failed to connect: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        int signal = getSignalStrength(ssid);
        if (signal == -1) {
            fprintf(stderr, "Failed to get signal strength: %s\n", strerror(errno));
            exit(1);
        }
        printf("Signal Strength of %s: %d\n", ssid, signal);
        usleep(5000000); // wait for 5 seconds
    }

    close(sockfd);

    return 0;
}