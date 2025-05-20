//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LEN 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LEN];
    int n;

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Convert the IP address and port number to network format
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to server\n");

    // Receive data from the server
    while (1) {
        bzero(buffer, MAX_LEN);
        n = read(sockfd, buffer, MAX_LEN);
        if (n <= 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        // Check for intrusion
        if (strncmp(buffer, "intrusion", n) == 0) {
            printf("Intrusion detected!\n");
            exit(1);
        }

        // Send data to the server
        write(sockfd, buffer, n);
    }

    return 0;
}