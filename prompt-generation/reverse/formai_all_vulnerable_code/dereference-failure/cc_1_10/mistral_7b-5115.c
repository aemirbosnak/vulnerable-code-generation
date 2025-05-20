//MISTRAL-7B DATASET v1.0 Category: Wireless Network Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SSID_LENGTH 32
#define CHANNEL_COUNT 11
#define BUFFER_SIZE 256

int main() {
    int sockfd, i, j, result;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char ssid[SSID_LENGTH];
    char channel[3];
    char scan_cmd[100];

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    // Set up server address
    server = gethostbyname("192.168.1.1"); // Replace with your router IP
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80); // Replace with your router port

    // Send WiFi scan command
    sprintf(scan_cmd, "GET /wifi-scan%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: C Wireless Scanner\r\nAccept: text/plain\r\nConnection: close\r\n\r\n", "\r\n", inet_ntoa(serv_addr.sin_addr));

    // Send command to router
    write(sockfd, scan_cmd, strlen(scan_cmd));

    // Receive response from router
    bzero(buffer, BUFFER_SIZE);
    result = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (result < 0) {
        perror("ERROR receiving data from socket");
        return 1;
    }

    // Parse response and print SSIDs and channels
    char *start, *end;
    for (i = 0; i < CHANNEL_COUNT; i++) {
        for (j = 0; j < strlen(buffer); j++) {
            if (buffer[j] == '\n' && buffer[j - 1] == ':') {
                start = &buffer[j + 1];
                end = memchr(start, ':', strlen(start));
                if (end != NULL) {
                    sscanf(start, "%s %s", ssid, channel);
                    printf("SSID: %s, Channel: %s\n", ssid, channel);
                }
                break;
            }
        }
        if (j >= strlen(buffer)) {
            break;
        }
    }

    // Close socket
    close(sockfd);

    return 0;
}