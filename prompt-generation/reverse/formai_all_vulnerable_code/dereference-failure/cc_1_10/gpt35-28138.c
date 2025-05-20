//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [METHOD] [URL] [PORT]\n", argv[0]);
        printf("Example: %s GET http://www.example.com/ 80\n", argv[0]);
        return 1;
    }

    // Parse URL
    char *protocol, *host, *path;
    protocol = strtok(argv[2], ":/");
    host = strtok(NULL, ":/");
    path = strtok(NULL, "");

    if (path == NULL) {
        path = "/";
    }

    printf("Protocol: %s\nHost: %s\nPath: %s\n", protocol, host, path);

    // Lookup host IP address
    struct hostent *he;
    struct in_addr **addr_list;

    if ((he = gethostbyname(host)) == NULL) {
        printf("Failed to lookup IP address for %s\n", host);
        return 1;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    // Connect to server
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[3]));

    if (inet_pton(AF_INET, inet_ntoa(*addr_list[0]), &server_addr.sin_addr) <= 0) {
        printf("Failed to convert IP address: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to connect: %s\n", strerror(errno));
        return 1;
    }

    // Send request
    char *request = (char *) malloc(BUFFER_SIZE * sizeof(char));
    sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1], path, host);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        printf("Failed to send request: %s\n", strerror(errno));
        return 1;
    }

    // Receive response
    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    printf("\n");

    // Cleanup
    close(sockfd);
    free(request);

    return 0;
}