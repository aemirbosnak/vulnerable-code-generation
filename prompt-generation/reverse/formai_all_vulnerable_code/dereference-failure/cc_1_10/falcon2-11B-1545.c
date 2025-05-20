//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

// Function to perform a TCP connection to the specified IP address and port
int tcpConnect(const char* ipAddress, int port) {
    struct hostent* hostInfo = gethostbyname(ipAddress);
    if (hostInfo == NULL) {
        fprintf(stderr, "Error: Unable to resolve IP address\n");
        return 1;
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)hostInfo->h_addr, hostInfo->h_length);
    serverAddress.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        close(sockfd);
        return 1;
    }

    return sockfd;
}

int main() {
    int sockfd = tcpConnect("192.168.0.1", 80);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        return 1;
    }

    char buffer[256];
    if (read(sockfd, buffer, sizeof(buffer)) <= 0) {
        fprintf(stderr, "Error: Failed to read from server\n");
        close(sockfd);
        return 1;
    }

    printf("Response from server:\n%s\n", buffer);
    close(sockfd);

    return 0;
}