//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to scan a single port
int scan_port(int port) {
    // Create a socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return -1;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        return -1;
    }

    // Send a message to the server
    char msg[] = "GET / HTTP/1.1\r\nHost: ";
    send(sockfd, msg, strlen(msg), 0);

    // Read the server's response
    char response[1024];
    int nbytes = recv(sockfd, response, sizeof(response), 0);

    // Close the socket
    close(sockfd);

    return nbytes;
}

// Function to scan a range of ports
int scan_ports(int min_port, int max_port) {
    int n_ports = max_port - min_port + 1;
    for (int i = min_port; i <= max_port; i++) {
        if (scan_port(i) > 0) {
            printf("Port %d is open\n", i);
        }
    }

    return n_ports;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <min_port> <max_port>\n", argv[0]);
        return 1;
    }

    int min_port = atoi(argv[1]);
    int max_port = atoi(argv[2]);
    int n_ports = scan_ports(min_port, max_port);

    printf("Scanned %d ports:\n", n_ports);
    return 0;
}