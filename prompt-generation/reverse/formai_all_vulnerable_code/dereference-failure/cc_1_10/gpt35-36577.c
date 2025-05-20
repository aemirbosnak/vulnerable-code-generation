//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void handle_error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

void connect_to_server(int sockfd, char *server_address, int port_number) {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    server = gethostbyname(server_address);

    if (server == NULL) {
        fprintf(stderr, "Error: No such host exists.\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port_number);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        handle_error("Error: Could not connect to server.");
}

void send_request(int sockfd, char *request) {
    int bytes_sent = write(sockfd, request, strlen(request));

    if (bytes_sent < 0)
        handle_error("Error: Could not send request.");
}

void receive_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    memset(response, 0, BUFFER_SIZE);

    bytes_received = read(sockfd, response, BUFFER_SIZE - 1);

    if (bytes_received < 0)
        handle_error("Error: Could not receive response.");

    printf("%s", response);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server-address> <port-number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        handle_error("Error: Could not create socket.");

    connect_to_server(sockfd, argv[1], atoi(argv[2]));

    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";

    send_request(sockfd, request);

    receive_response(sockfd);

    close(sockfd);
    return 0;
}