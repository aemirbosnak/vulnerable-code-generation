//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int connect_to_server(const char *hostname, int port) {
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname\n");
        exit(1);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr = *((struct in_addr *)host->h_addr);
    memset(&(address.sin_zero), 0, 8);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Could not connect to server");
        exit(1);
    }

    return sockfd;
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    while (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "\r\n.\r\n") != NULL) {
            break;
        }
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    }
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
}

int main() {
    int sockfd = connect_to_server("pop.example.com", 110);
    receive_response(sockfd);

    send_command(sockfd, "USER username");
    receive_response(sockfd);

    send_command(sockfd, "PASS password");
    receive_response(sockfd);

    send_command(sockfd, "STAT");
    receive_response(sockfd);

    send_command(sockfd, "LIST");
    receive_response(sockfd);

    send_command(sockfd, "RETR 1");
    receive_response(sockfd);

    send_command(sockfd, "QUIT");
    receive_response(sockfd);

    close(sockfd);

    return 0;
}