//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define MAX_DEVICES 10
#define MAX_SCAN_TIME 10000 // 10 seconds

struct device {
    char name[64];
    int signal_strength;
};

void signal_handler(int signum) {
    printf("Signal %d received, exiting...\n", signum);
    exit(0);
}

int main() {
    int sock, status;
    struct sockaddr_in server_addr;
    char buffer[1024];
    struct device devices[MAX_DEVICES];
    int num_devices = 0;
    int scan_time = MAX_SCAN_TIME;

    signal(SIGINT, signal_handler);

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9);
    inet_pton(AF_INET, "224.0.0.1", &server_addr.sin_addr);

    while (scan_time > 0) {
        status = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
        if (status > 0) {
            buffer[status] = '\0';
            printf("Received broadcast message: %s\n", buffer);

            struct device* device = NULL;
            for (int i = 0; i < num_devices; i++) {
                if (strcmp(devices[i].name, buffer) == 0) {
                    device = &devices[i];
                    break;
                }
            }

            if (device == NULL) {
                if (num_devices >= MAX_DEVICES) {
                    printf("Maximum number of devices reached\n");
                } else {
                    printf("New device detected: %s\n", buffer);
                    strcpy(device->name, buffer);
                    device->signal_strength = 0;
                    num_devices++;
                }
            } else {
                int signal_strength = atoi(buffer + strlen(buffer) - 2);
                device->signal_strength = signal_strength;
            }
        }

        usleep(100000);
        scan_time--;
    }

    close(sock);
    return 0;
}