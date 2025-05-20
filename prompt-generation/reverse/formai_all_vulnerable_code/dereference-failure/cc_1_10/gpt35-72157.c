//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

#define MAX_PACKET_SIZE 4096
#define START_PORT 1
#define END_PORT 65535

struct sockaddr_in source,dest;

// Function to calculate Wi-Fi signal strength using RSSI
int calculateSignalStrength(int rssi) {
    if (rssi <= -100) {
        return 0;
    } else if (rssi >= -50) {
        return 100;
    } else {
        return 2 * (rssi + 100);
    }
}

// Function to print Wi-Fi signal strength as a bar graph
void printSignalStrength(int strength) {
    printf("Signal Strength: ");
    for (int i = 0; i < strength / 10; i++) {
        printf("|");
    }
    printf("\n");
}

// Function to scan for Wi-Fi access points on a given IP address and port
void scanAccessPoint(char* ip, int port) {
    int sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (sock == -1) {
        printf("Failed to create socket. Error: %s\n", strerror(errno));
        return;
    }

    source.sin_family = AF_INET;
    source.sin_addr.s_addr = INADDR_ANY;
    source.sin_port = htons(0);

    if (bind(sock,(struct sockaddr *)&source,sizeof(source)) == -1) {
        printf("Failed to bind socket. Error: %s\n", strerror(errno));
        close(sock);
        return;
    }

    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(ip);
    dest.sin_port = htons(port);

    if (connect(sock,(struct sockaddr *)&dest,sizeof(dest)) == -1) {
        printf("%s:%d - Connection Failed. Error: %s\n", ip, port, strerror(errno));
        close(sock);
        return;
    }

    int rssi = 0;
    char response[MAX_PACKET_SIZE] = {0};
    if (recv(sock, response, MAX_PACKET_SIZE, 0) != -1) {
        // Extract RSSI value from response
        char* rssiString = strstr(response, "RSSI=");
        if (rssiString != NULL) {
            rssi = atoi(rssiString+5);
        }
    }
    int signalStrength = calculateSignalStrength(rssi);
    printSignalStrength(signalStrength);

    close(sock);
}

int main() {
    char* ip = "192.168.1.1"; // Set IP address to scan for
    printf("Scanning Wi-Fi access points on %s...\n\n", ip);
    for (int port = START_PORT; port <= END_PORT; port++) {
        scanAccessPoint(ip, port);
    }
    printf("Scan Complete.\n");

    return 0;
}