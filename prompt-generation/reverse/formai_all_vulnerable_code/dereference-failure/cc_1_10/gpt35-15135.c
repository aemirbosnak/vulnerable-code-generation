//FormAI DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLEN 128
#define BLOCKEDIPS "blockedips.txt" // Change as per requirement

// Function to check if an IP address is blocked
int checkBlockedIP(char* ipAddress) {
    FILE *fp;
    char blockedIP[MAXLEN];

    fp = fopen(BLOCKEDIPS, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", BLOCKEDIPS);
        return 0;
    }

    while (fgets(blockedIP, MAXLEN, fp) != NULL) {
        if (strcmp(ipAddress, blockedIP) == 0) {
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int main() {
    char ipAddress[MAXLEN];
    int sockfd, connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else {
        printf("Socket successfully created..\n");
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8888);

    // Bind the socket with the server address
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed...\n");
        exit(0);
    }
    else {
        printf("Socket successfully binded..\n");
    }

    // Listen for incoming connections
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else {
        printf("Server listening..\n");
    }

    len = sizeof(cliaddr);

    while (1) {
        // Accept the data packet from client and verification
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        if (connfd < 0) {
            printf("Server accept failed...\n");
            exit(0);
        }

        // Convert IP address to a string and check if it is blocked
        inet_ntop(AF_INET, &(cliaddr.sin_addr), ipAddress, MAXLEN);
        if (checkBlockedIP(ipAddress)) {
            printf("Blocked IP address %s attempted to establish connection. Connection refused.\n", ipAddress);
            close(connfd);
            continue;
        }

        // Connection accepted
        printf("Server accepted the client...\n");

        // Process client requests here

        // Close the connection
        close(connfd);
    }

    // Close the socket
    close(sockfd);
    return 0;
}