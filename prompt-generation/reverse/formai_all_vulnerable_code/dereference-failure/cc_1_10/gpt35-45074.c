//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_DEVICES 256

struct device {
    char name[BUF_SIZE];
    char ip[BUF_SIZE];
};

int get_local_ip(char* ip) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        return -1;
    }

    struct sockaddr_in srv;
    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = inet_addr("8.8.8.8");
    srv.sin_port = htons(80);

    if (connect(sock, (struct sockaddr*) &srv, sizeof(srv)) == -1) {
        return -1;
    }

    struct sockaddr_in local;
    socklen_t size = sizeof(local);
    if (getsockname(sock, (struct sockaddr*) &local, &size) == -1) {
        return -1;
    }

    strcpy(ip, inet_ntoa(local.sin_addr));
    return 0;
}

int main() {
    char local_ip[BUF_SIZE];
    if (get_local_ip(local_ip) == -1) {
        printf("Failed to get local IP address.\n");
        return 1;
    }

    char* subnet = strtok(local_ip, ".");
    subnet = strtok(NULL, ".");
    subnet = strtok(NULL, ".");
    subnet = strtok(NULL, ".");
    if (subnet == NULL) {
        printf("Failed to generate subnet.\n");
        return 1;
    }

    char cmd[BUF_SIZE];
    sprintf(cmd, "nmap -sP %s.* 2>/dev/null | grep \"Nmap scan report for\" | awk '{printf $5 \"\\n\"}'", subnet);

    FILE* pipe = popen(cmd, "r");
    if (pipe == NULL) {
        printf("Failed to execute Nmap command.\n");
        return 1;
    }

    char buf[BUF_SIZE];
    struct device devices[MAX_DEVICES];
    int num_devices = 0;

    while (fgets(buf, BUF_SIZE, pipe)) {
        if (num_devices >= MAX_DEVICES) {
            printf("Too many devices found.\n");
            break;
        }

        strcpy(devices[num_devices].ip, buf);

        struct hostent* host = gethostbyaddr(devices[num_devices].ip, strlen(devices[num_devices].ip), AF_INET);
        if (host == NULL) {
            sprintf(devices[num_devices].name, "%s", "N/A");
        } else {
            sprintf(devices[num_devices].name, "%s", host->h_name);
        }

        num_devices++;
    }

    pclose(pipe);

    printf("\nFound %d devices on the network:\n\n", num_devices);
    for (int i = 0; i < num_devices; i++) {
        printf("%-15s %s", devices[i].ip, devices[i].name);
    }

    return 0;
}