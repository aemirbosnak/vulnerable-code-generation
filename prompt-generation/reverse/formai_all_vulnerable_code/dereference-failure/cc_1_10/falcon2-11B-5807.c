//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[100];

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80); // Default HTTP port
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send a request to the server
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Print the response
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}