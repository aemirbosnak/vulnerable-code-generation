//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 80

void send_request(int sd, char *ip, char *request) {
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip);
    sin.sin_port = htons(PORT);
    if (connect(sd, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        printf("Connection Error: %s: %d\n", ip, errno);
        exit(errno);
    }
    send(sd, request, strlen(request), 0);
}

void print_response(int sd) {
    char c[BUFFER_SIZE];
    int read_size = recv(sd, c, BUFFER_SIZE, 0);
    while (read_size > 0) {
        printf("%.*s", read_size, c);
        bzero(c, BUFFER_SIZE);
        read_size = recv(sd, c, BUFFER_SIZE, 0);
    }
    close(sd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *ip;
    struct hostent *he;
    if ((he = gethostbyname(url)) == NULL) {
        printf("Error resolving hostname: %s\n", hstrerror(h_errno));
        return 1;
    }
    ip = inet_ntoa(*(struct in_addr *)he->h_addr_list[0]);

    char *request;
    char *host;
    if (strncmp(url, "http://", 7) == 0) {
        request = strdup(url + 7);
        host = strsep(&request, "/");
    } else {
        printf("Invalid URL\n");
        return 1;
    }

    int sd = socket(AF_INET, SOCK_STREAM, 0);

    char *message = "GET / HTTP/1.1\r\n"
                    "Host: %s\r\n"
                    "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:74.0) Gecko/20100101 Firefox/74.0\r\n"
                    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
                    "Accept-Language: en-US,en;q=0.5\r\n"
                    "Upgrade-Insecure-Requests: 1\r\n"
                    "Connection: keep-alive\r\n\r\n";

    char *request_message = malloc(strlen(host) + strlen(message));
    sprintf(request_message, message, host);
    send_request(sd, ip, request_message);
    free(request_message);

    print_response(sd);

    return 0;
}