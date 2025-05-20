//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 1024
#define MAX_RESPONSE_LEN 4096
#define DEFAULT_TIMEOUT 5

void print_usage() {
    printf("Usage: ping <hostname>\n");
}

int main(int argc, char *argv[]) {
    if(argc!= 2) {
        print_usage();
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN - 1);
    hostname[MAX_HOSTNAME_LEN - 1] = '\0';

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    char data[MAX_DATA_LEN];
    snprintf(data, MAX_DATA_LEN, "PING %s", hostname);

    sendto(sock, data, strlen(data), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char response[MAX_RESPONSE_LEN];
    memset(response, 0, sizeof(response));

    int response_len = recv(sock, response, MAX_RESPONSE_LEN, 0);
    if(response_len <= 0) {
        printf("No response from server\n");
        close(sock);
        return 1;
    }

    close(sock);

    printf("Response: %s\n", response);

    return 0;
}