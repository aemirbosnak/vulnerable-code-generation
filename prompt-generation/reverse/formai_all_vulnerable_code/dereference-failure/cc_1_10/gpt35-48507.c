//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    // initialize variables
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];
    int port = 80;
    char *server_ip = "127.0.0.1";
    char *http_request = "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:59.0) Gecko/20100101 Firefox/59.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: en-US,en;q=0.5\r\nAccept-Encoding: gzip, deflate\r\nConnection: close\r\n\r\n";
    
    // check command-line arguments
    if (argc > 1) {
        server_ip = argv[1];
    }
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // set server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_address.sin_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // send HTTP request
    sprintf(message, http_request, server_ip);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        printf("Error sending request\n");
        return 1;
    }

    // receive and print response
    while (recv(sockfd, buffer, BUFFER_SIZE, 0)) {
        printf("%s", buffer);
    }

    // close socket
    close(sockfd);

    return 0;
}