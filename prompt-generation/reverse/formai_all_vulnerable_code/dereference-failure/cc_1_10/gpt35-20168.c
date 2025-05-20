//FormAI DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 10

char* getRandomIPAddress() {
    char* ip = malloc(sizeof(char) * 16);
    sprintf(ip, "%d.%d.%d.%d", rand() % 255, rand() % 255, rand() % 255, rand() % 255);
    return ip;
}

void ping(char* ip_address) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        printf("Failed to open socket\n");
        return;
    }

    bool is_responding = false;
    int i = 0;
    for (i = 0; i < 3; i++) {
        struct sockaddr_in server_addr = {0};
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        server_addr.sin_addr.s_addr = inet_addr(ip_address);

        char buffer[MAX_BUFFER_SIZE] = "PING";
        ssize_t bytes_sent = sendto(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
        if (bytes_sent < 0) {
            printf("Failed to send data\n");
            return;
        }

        char response[MAX_BUFFER_SIZE] = {0};
        struct sockaddr_in client_addr = {0};
        socklen_t addr_len = sizeof(client_addr);
        ssize_t bytes_received = recvfrom(sockfd, response, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &addr_len);
        if (bytes_received < 0) {
            printf("No response from %s\n", ip_address);
            return;
        } else {
            is_responding = true;
            printf("%s response: %s\n", ip_address, response);
        }

        sleep(1);
    }

    if (!is_responding) {
        printf("%s is down\n", ip_address);
    }
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++) {
        char* ip_address = getRandomIPAddress();
        printf("Pinging %s\n", ip_address);
        ping(ip_address);
    }

    return 0;
}