//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Check command line arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }

    // Convert hostname to IP address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(0);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(0);
    }

    // Set up address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(0);
    }

    // Send HTTP request
    char *request = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, argv[1]);
    strcat(request, ":");
    strcat(request, argv[2]);
    strcat(request, "\r\n\r\n");

    if (write(sockfd, request, strlen(request)) < 0) {
        perror("ERROR writing request");
        exit(0);
    }

    // Receive response
    char buffer[4096];
    while ((n = read(sockfd, buffer, 4096)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}