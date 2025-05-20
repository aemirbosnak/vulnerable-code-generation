//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT "12345"
#define BUFLEN 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFLEN];
    struct hostent *host_info;
    double temperature;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    host_info = gethostbyname("localhost");
    if (host_info == NULL) {
        printf("Error getting host information\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));
    server_addr.sin_addr.s_addr = *(unsigned long *)host_info->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUFLEN);
        if (recv(sockfd, buffer, BUFLEN, 0) < 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        temperature = atof(buffer);
        printf("Current temperature: %.2lf\n", temperature);
        sleep(5);
    }

    close(sockfd);
    return 0;
}