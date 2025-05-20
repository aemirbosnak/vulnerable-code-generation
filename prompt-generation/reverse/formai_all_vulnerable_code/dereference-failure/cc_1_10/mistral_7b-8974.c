//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <URL> <OUTPUT_FILE>\n", argv[0]);
        return 1;
    }

    const char *url = argv[1];
    const char *output_file = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct hostent *he = gethostbyname("www.google.com");
    if (!he) {
        herror("gethostbyname");
        close(sockfd);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    const char *request =
        "GET %s HTTP/1.1\r\n"
        "Host: www.google.com\r\n"
        "User-Agent: Grateful C HTTP Client\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
        "Accept-Language: en-US,en;q=0.5\r\n"
        "Accept-Encoding: gzip, deflate, br\r\n"
        "Connection: keep-alive\r\n\r\n";

    char request_buffer[BUFFER_SIZE];
    snprintf(request_buffer, sizeof(request_buffer), request, url);

    if (write(sockfd, request_buffer, strlen(request_buffer)) < 0) {
        perror("write");
        close(sockfd);
        return 1;
    }

    char response[BUFFER_SIZE];
    ssize_t n;
    while ((n = read(sockfd, response, BUFFER_SIZE)) > 0) {
        fwrite(response, n, 1, stdout);
        fwrite(response, n, 1, output_file);
    }

    if (n < 0) {
        perror("read");
    }

    close(sockfd);

    printf("Data saved to %s\n", output_file);

    return 0;
}