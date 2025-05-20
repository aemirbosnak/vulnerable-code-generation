//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_HOSTNAME_LENGTH 256
#define HOST_BUFFER_SIZE 1024
#define TIMEOUT_SECONDS 1
#define PORT 80  // HTTP port

void check_qos(const char *hostname) {
    struct sockaddr_in serverAddr;
    int sockfd;
    char buffer[HOST_BUFFER_SIZE];
    struct timeval timeout;
    fd_set readfds;
    ssize_t bytes_sent, bytes_received;
    
    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", hostname);
        return;
    }
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    memcpy(&serverAddr.sin_addr, host->h_addr, host->h_length);
    
    // Set socket options for timeout
    timeout.tv_sec = TIMEOUT_SECONDS;
    timeout.tv_usec = 0;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return;
    }
    
    // Send HTTP GET request for QoS monitoring
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Sending failed");
        close(sockfd);
        return;
    }
    
    // Initialize file descriptor set
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    // Wait for server response
    int result = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
    if (result > 0 && FD_ISSET(sockfd, &readfds)) {
        // Read response from server
        while ((bytes_received = recv(sockfd, buffer, HOST_BUFFER_SIZE - 1, 0)) > 0) {
            buffer[bytes_received] = '\0'; // null terminate
            printf("%s", buffer); // Display received data
        }
    } else if (result == 0) {
        printf("Response timed out\n");
    } else {
        perror("Receiving failed");
    }

    // Cleanup
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Monitoring QoS for: %s\n", argv[1]);
    check_qos(argv[1]);

    return EXIT_SUCCESS;
}