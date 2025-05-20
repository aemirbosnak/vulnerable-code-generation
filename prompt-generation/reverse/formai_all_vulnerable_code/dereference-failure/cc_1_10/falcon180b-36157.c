//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTS 100
#define BUFFER_SIZE 1024

struct host_info {
    char *hostname;
    struct in_addr ip_addr;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host_file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    int num_hosts = 0;
    struct host_info hosts[MAX_HOSTS];

    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        if (num_hosts >= MAX_HOSTS) {
            printf("Error: Too many hosts\n");
            exit(1);
        }

        char *hostname = strtok(line, " ");
        if (hostname == NULL) {
            printf("Error: Invalid hostname\n");
            continue;
        }

        struct in_addr ip_addr;
        if (inet_pton(AF_INET, hostname, &ip_addr) <= 0) {
            printf("Error: Invalid IP address\n");
            continue;
        }

        hosts[num_hosts].hostname = strdup(hostname);
        hosts[num_hosts].ip_addr = ip_addr;
        num_hosts++;
    }

    fclose(fp);

    for (int i = 0; i < num_hosts; i++) {
        printf("Pinging %s (%s)...\n", hosts[i].hostname, inet_ntoa(hosts[i].ip_addr));
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error: %s\n", strerror(errno));
            continue;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(7);
        server_addr.sin_addr = hosts[i].ip_addr;

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            printf("Host is down\n");
        } else {
            printf("Host is up\n");
            close(sock);
        }
    }

    return 0;
}