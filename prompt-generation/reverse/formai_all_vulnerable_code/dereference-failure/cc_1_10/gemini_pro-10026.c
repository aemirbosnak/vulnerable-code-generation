//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 80
#define DEFAULT_BUFFER_SIZE 1024

char *usage = "Usage: %s <hostname> [<port>]";

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, usage, argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = DEFAULT_PORT;
    if (argc >= 3) {
        port = atoi(argv[2]);
    }

    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        fprintf(stderr, "Error: Could not resolve hostname '%s'\n", hostname);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Could not create socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Could not connect to server");
        return EXIT_FAILURE;
    }

    char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char buffer[DEFAULT_BUFFER_SIZE];
    snprintf(buffer, DEFAULT_BUFFER_SIZE, request, hostname);

    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: Could not send request");
        return EXIT_FAILURE;
    }

    int n;
    while ((n = read(sockfd, buffer, DEFAULT_BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, n, stdout);
    }

    if (n < 0) {
        perror("Error: Could not receive response");
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}