//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_DEVICES 10
#define MAX_SSID_LENGTH 32

struct wifi_device {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

int main() {
    int sock = 0;
    int result = 0;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buffer[1024];
    char *token = NULL;
    int num_devices = 0;
    struct wifi_device devices[MAX_DEVICES];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1234);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (num_devices < MAX_DEVICES) {
        memset(buffer, 0, sizeof(buffer));
        result = recv(sock, buffer, sizeof(buffer), 0);
        if (result <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        token = strtok(buffer, " ");
        strcpy(devices[num_devices].ssid, token);

        token = strtok(NULL, " ");
        devices[num_devices].signal_strength = atoi(token);

        num_devices++;
    }

    close(sock);

    printf("Number of devices: %d\n", num_devices);

    for (int i = 0; i < num_devices; i++) {
        printf("Device %d: %s, Signal strength: %d\n", i+1, devices[i].ssid, devices[i].signal_strength);
    }

    return 0;
}