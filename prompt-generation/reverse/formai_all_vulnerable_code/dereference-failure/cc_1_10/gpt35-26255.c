//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_IP_LENGTH 16
#define MAX_DEVICES 100
#define PORT 8080

int get_device_list(char device_list[MAX_DEVICES][MAX_IP_LENGTH]) {
    FILE *fp;
    char line[MAX_IP_LENGTH];
    int count = 0;

    fp = popen("/sbin/ifconfig | grep 'inet addr:' | cut -d: -f2 | awk '{print $1}'", "r");
    if (fp == NULL) {
        printf("Failed to get device list. Error: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(line, MAX_IP_LENGTH, fp)) {
        line[strcspn(line, "\n")] = 0;
        strcpy(device_list[count], line);
        ++count;
    }

    pclose(fp);
    return count;
}

void map_network(char device_list[MAX_DEVICES][MAX_IP_LENGTH], int device_count) {
    int sock, read_size;
    struct sockaddr_in server;
    char server_response[2000];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket. Error: %s\n", strerror(errno));
        exit(1);
    }

    for (int i = 0; i < device_count; ++i) {
        server.sin_addr.s_addr = inet_addr(device_list[i]);
        server.sin_family = AF_INET;
        server.sin_port = htons(PORT);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Device at IP %s and port %d is ONLINE.\n", device_list[i], PORT);
        } else {
            printf("Device at IP %s is OFFLINE.\n", device_list[i]);
        }
    }

    close(sock);
}

int main() {
    char device_list[MAX_DEVICES][MAX_IP_LENGTH];
    int device_count;

    device_count = get_device_list(device_list);
    map_network(device_list, device_count);

    return 0;
}