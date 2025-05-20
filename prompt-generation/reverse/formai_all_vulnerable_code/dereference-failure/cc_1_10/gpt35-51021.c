//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Check for required arguments
    if (argc != 3) {
        printf("Usage: %s <server-address> <server-port>\n", argv[0]);
        exit(1);
    }

    // Initialize variables
    char buffer[BUFFER_SIZE];
    int sock_fd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Get server information
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: No such host\n");
        exit(1);
    }

    // Set server address
    portno = atoi(argv[2]);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send GET request to server
    char *request = "GET / HTTP/1.0\r\n\r\n";
    n = write(sock_fd, request, strlen(request));
    if (n < 0) {
        perror("Error sending request to server");
        exit(1);
    }

    // Receive response from server
    bzero(buffer, BUFFER_SIZE);
    while ((n = read(sock_fd, buffer, BUFFER_SIZE-1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }
    if (n < 0) {
        perror("Error receiving response from server");
        exit(1);
    }

    // Close socket
    close(sock_fd);

    return 0;
}