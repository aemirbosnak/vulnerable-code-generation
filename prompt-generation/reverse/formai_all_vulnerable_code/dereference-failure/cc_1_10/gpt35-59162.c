//FormAI DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if(argc != 2) { // Check if user has provided correct arguments
        printf("Usage : %s <target host/IP>\n",argv[0]);
        exit(1);
    }

    char *target = argv[1];
    struct hostent *host;
    struct timeval tv;
    fd_set readfds;

    int start_port = 1;
    int end_port = 65535;

    memset(&tv, 0, sizeof(tv)); // Clear time value
    tv.tv_sec = 1;

    if((host = gethostbyname(target)) == NULL) { // Check if target host is valid
        printf("%s is an invalid hostname or IP address.\n", target);
        exit(1);
    }

    printf("Scanning ports of %s (%s):\n", host->h_name, inet_ntoa(*(struct in_addr *)host->h_addr));

    for(int i=start_port; i<=end_port; i++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0) {
            printf("Error creating socket.\n");
            exit(1);
        }

        struct sockaddr_in server;
        bzero(&server, sizeof(server)); // Clear server address structure
        server.sin_family = AF_INET;
        server.sin_port = htons(i);
        server.sin_addr = *((struct in_addr *)host->h_addr);

        int connection_status = connect(sockfd, (struct sockaddr *)&server, sizeof(server));

        if(connection_status == 0) {
            printf("Port %d - Open\n", i);
        } else {
            FD_ZERO(&readfds); // Clear file desciptor set readfds
            FD_SET(sockfd, &readfds); // Add file descriptor sockfd to set readfds

            connection_status = select(sockfd + 1, NULL, &readfds, NULL, &tv);

            if(connection_status == 1) {
                printf("Port %d - Open\n", i);
            } else {
                printf("Port %d - Closed\n", i);
            }
        }

        close(sockfd);
    }

    printf("Port scanning of %s (%s) is complete.\n", host->h_name, inet_ntoa(*(struct in_addr *)host->h_addr));

    return 0;
}