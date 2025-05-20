//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    char hostname[256];
    int port = 80;
    int sockfd, bytes_received;
    int max_speed = 0;
    char buffer[1024];
    struct hostent *host;
    struct sockaddr_in server_addr;
    double start_time, end_time;

    printf("Enter the hostname or IP address: ");
    scanf("%s", hostname);

    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Invalid hostname or IP address.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = *(unsigned long *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server.\n");
        exit(1);
    }

    start_time = time(NULL);
    bytes_received = 0;

    while (bytes_received < 1024) {
        bytes_received += recv(sockfd, buffer, 1024 - bytes_received, 0);
    }

    end_time = time(NULL);
    close(sockfd);

    max_speed = bytes_received / (end_time - start_time);

    printf("Your internet speed is: %.2f bytes per second.\n", max_speed);

    return 0;
}