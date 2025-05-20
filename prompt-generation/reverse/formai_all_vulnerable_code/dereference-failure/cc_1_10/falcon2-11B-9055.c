//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFF 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFF];

    // Get local machine name
    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "gethostbyname: unknown host\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = *(unsigned long *)server->h_addr;
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }

    // Send HTTP request
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Read response
    while ((n = read(sockfd, buffer, MAX_BUFF)) > 0) {
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}