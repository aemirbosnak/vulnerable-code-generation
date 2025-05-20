//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define URL_MAX_LEN 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <URL> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    const char *output_file = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket");

    struct hostent *he = gethostbyname("www.google.com");
    if (!he) die("gethostbyname");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        die("connect");

    char request[URL_MAX_LEN];
    snprintf(request, URL_MAX_LEN, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: MyClient/1.0\r\nAccept: */*\r\n\r\n", url, url);

    if (send(sockfd, request, strlen(request), 0) < 0) die("send");

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    FILE *output = fopen(output_file, "wb");

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        fwrite(buffer, bytes_received, 1, output);
    }

    if (bytes_received < 0) die("recv");
    fclose(output);

    close(sockfd);
    return EXIT_SUCCESS;
}