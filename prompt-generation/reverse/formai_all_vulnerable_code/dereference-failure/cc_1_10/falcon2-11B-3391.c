//Falcon2-11B DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    char hostname[] = "www.google.com";

    // Step 1: Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Step 2: Create the address of the server
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    // Step 3: Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR: Connect failed\n");
        exit(1);
    }

    // Step 4: Send a request to the server
    printf("Sending request...\n");
    n = write(sockfd, "GET / HTTP/1.1\r\n\r\n", 37);
    if (n < 0) {
        fprintf(stderr, "ERROR: Write failed\n");
        exit(1);
    }

    // Step 5: Receive the response from the server
    printf("Receiving response...\n");
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        fprintf(stderr, "ERROR: Read failed\n");
        exit(1);
    }
    buffer[n] = '\0';

    // Step 6: Display the response from the server
    printf("Response: %s\n", buffer);

    // Step 7: Close the socket
    close(sockfd);

    return 0;
}