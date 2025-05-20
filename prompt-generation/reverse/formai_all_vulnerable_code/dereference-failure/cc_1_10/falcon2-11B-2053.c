//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to scan ports
int scan_port(int port) {
    int sockfd, valread;
    struct sockaddr_in serv_addr;
    char buffer[100];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("ERROR, couldn't resolve address!");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Send and receive data
    if ((valread = recv(sockfd, buffer, 100, 0)) < 0) {
        perror("ERROR receiving data");
        exit(EXIT_FAILURE);
    }

    printf("Received data: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}

// Function to scan ports in a range
int scan_ports(int start, int end) {
    for (int i = start; i <= end; i++) {
        scan_port(i);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <start port>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = start_port + 10; // scan 10 ports above the start port

    // Scan ports
    scan_ports(start_port, end_port);

    return 0;
}