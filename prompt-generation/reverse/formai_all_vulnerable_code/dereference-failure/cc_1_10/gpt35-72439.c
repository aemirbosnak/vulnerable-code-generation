//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[4096];

    if (argc < 3) {
        printf("Usage: %s hostname portno\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: cannot open socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (!server) {
        printf("Error: no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: cannot connect to host\n");
        exit(1);
    }

    printf("Enter HTTP request: ");
    bzero(buffer, 4096);
    fgets(buffer, 4096, stdin);

    char* request = strtok(buffer, "\n");

    // Send HTTP request
    n = write(sockfd, request, strlen(request));

    if (n < 0) {
        printf("Error: cannot send HTTP request\n");
        exit(1);
    }

    // Receive HTTP response
    bzero(buffer, 4096);
    n = read(sockfd, buffer, 4095);

    if (n < 0) {
        printf("Error: cannot receive HTTP response\n");
        exit(1);
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}