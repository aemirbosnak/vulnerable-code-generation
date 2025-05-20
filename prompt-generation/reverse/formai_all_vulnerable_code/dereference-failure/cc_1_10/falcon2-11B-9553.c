//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to handle connection and data transfer
void http_client(const char* url) {
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buf[1024];
    char request[1024];
    char response[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        exit(1);
    }

    // Convert URL to IP address
    server = gethostbyname(url);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        exit(1);
    }

    // Copy server address to sockaddr_in structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, 
         (char *) &serv_addr.sin_addr.s_addr, 
         server->h_length);
    serv_addr.sin_port = htons(80);  // HTTP is on port 80

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR connecting\n");
        exit(1);
    }

    printf("Connected to %s\n", url);

    // Send HTTP GET request
    sprintf(request, "GET / HTTP/1.0\r\n\r\n");
    write(sockfd, request, strlen(request));

    // Receive response
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        printf("ERROR reading from socket\n");
        exit(1);
    }
    buf[n] = '\0';

    // Print response
    printf("%s", buf);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    http_client(argv[1]);

    return 0;
}