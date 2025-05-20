//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Variables for socket communication
    int socket_fd, conn_fd, rec_len;
    char buffer[BUFSIZ];
    struct sockaddr_in servaddr;
    struct hostent *he;

    // Check if hostname and port are provided as command line arguments
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: Failed to create socket");
        return 1;
    }

    // Get the hostent for the given hostname
    if ((he = gethostbyname(argv[1])) == NULL) {
        perror("Error: Failed to get host");
        return 1;
    }

    // Set the socket address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr = *((struct in_addr *) he->h_addr_list[0]);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("Error: Failed to connect to server");
        return 1;
    }

    // Send HTTP GET request to the server
    char *request = "GET / HTTP/1.0\r\n\r\n";
    if (send(socket_fd, request, strlen(request), 0) <= 0) {
        perror("Error: Failed to send request to server");
        return 1;
    }

    // Receive the response from the server
    memset(&buffer, 0, sizeof(buffer));
    while ((rec_len = recv(socket_fd, buffer, BUFSIZ-1, 0)) > 0) {
        buffer[rec_len] = '\0';
        printf("%s", buffer);
    }

    // Close the socket connection
    close(socket_fd);

    return 0;
}