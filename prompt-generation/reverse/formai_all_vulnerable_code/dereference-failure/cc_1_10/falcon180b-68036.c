//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int ping(const char *hostname, int port) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        print_error("socket failed");
    }

    if ((server = gethostbyname(hostname)) == NULL) {
        print_error("gethostbyname failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = *((unsigned long *) server->h_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        print_error("connect failed");
    }

    if (send(sockfd, "PING", strlen("PING"), 0) == -1) {
        print_error("send failed");
    }

    if ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) <= 0) {
        print_error("recv failed");
    }

    close(sockfd);

    if (strcmp(buffer, "PONG") == 0) {
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    int result = ping(argv[1], atoi(argv[2]));

    if (result == 0) {
        printf("Host is reachable.\n");
    } else {
        printf("Host is not reachable.\n");
    }

    return result;
}