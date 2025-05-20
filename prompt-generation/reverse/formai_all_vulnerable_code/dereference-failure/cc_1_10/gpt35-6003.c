//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[512];
    const char* http_request_body = "Hello, World!";

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Send HTTP Request
    char http_request[512] = "";
    sprintf(http_request, "POST / HTTP/1.1\r\n"
                           "Host: localhost:%d\r\n"
                           "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:58.0) Gecko/20100101 Firefox/58.0\r\n"
                           "Accept: */*\r\n"
                           "Content-Length: %ld\r\n"
                           "Content-Type: text/plain\r\n"
                           "\r\n"
                           "%s",
                           portno, strlen(http_request_body), http_request_body);

    n = write(sockfd, http_request, strlen(http_request));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive HTTP Response
    bool headers_recieved = false;
    while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {

        buffer[n] = '\0';

        // Check if Headers have been recieved
        if (headers_recieved) {
            printf("%s", buffer);
            continue;
        }

        if (strstr(buffer, "\r\n\r\n")) {
            headers_recieved = true;
            printf("%s", buffer + strlen("\r\n\r\n"));
            continue;
        }

        printf("%s", buffer);
    }

    if (n < 0) {
        error("ERROR reading from socket");
    }

    close(sockfd);

    return 0;
}