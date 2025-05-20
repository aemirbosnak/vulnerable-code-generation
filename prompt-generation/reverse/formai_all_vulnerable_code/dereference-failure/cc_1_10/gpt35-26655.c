//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char **argv) {
    int socket_fd, port_number, bytes_sent;
    struct sockaddr_in server_info;
    struct hostent *host_info;
    char message[1024], response[4096];

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <port> <message>\n", argv[0]);
        exit(1);
    }

    port_number = atoi(argv[2]);

    if ((host_info = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", strerror(errno));
        exit(1);
    }

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_info, 0, sizeof(server_info));
    server_info.sin_family = AF_INET;
    server_info.sin_port = htons(port_number);
    memcpy(&server_info.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(socket_fd, (struct sockaddr *) &server_info, sizeof(server_info)) < 0) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    snprintf(message, sizeof(message), "%s\r\n", argv[3]);

    if ((bytes_sent = send(socket_fd, message, strlen(message), 0)) < 0) {
        fprintf(stderr, "Error sending message: %s\n", strerror(errno));
        exit(1);
    }

    if (recv(socket_fd, response, sizeof(response), 0) < 0) {
        fprintf(stderr, "Error receiving response: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server response: %s\n", response);

    close(socket_fd);

    return 0;
}