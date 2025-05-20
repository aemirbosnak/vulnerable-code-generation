//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <time.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char *hostname = argv[1];
    char send_buffer[BUFFER_SIZE];
    char receive_buffer[BUFFER_SIZE];

    // Initialize random seed
    srand(time(NULL));

    // Create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Get the host info
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr,
         (char *) &server_addr.sin_addr.s_addr,
         server->h_length);
    portno = ntohs(atoi(argv[2]));
    server_addr.sin_port = htons(portno);

    // Start the quantum scanning
    for (int quantum = 0; quantum < 10; quantum++) {
        for (int i = 0; i < MAX_PORTS; i += 7) {
            // Set up the random port number to scan
            int port_to_scan = rand() % (MAX_PORTS - i) + i;
            portno = htons(port_to_scan);
            server_addr.sin_port = portno;

            // Connect to the server
            if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
                // If connection failed, move on to the next port
                continue;
            }

            // Send a unique quantum packet
            snprintf(send_buffer, BUFFER_SIZE, "Quantum Scan Packet %d, Quantum %d, Port %d", quantum, i, port_to_scan);
            send(sockfd, send_buffer, strlen(send_buffer), 0);

            // Receive the response
            n = recv(sockfd, receive_buffer, BUFFER_SIZE, 0);
            if (n > 0) {
                // If response received, print the result
                printf("Host: %s, Port: %d, Response: %s\n", hostname, port_to_scan, receive_buffer);
            }

            // Close the connection
            close(sockfd);
        }
    }

    // Close the socket
    close(sockfd);
    return 0;
}