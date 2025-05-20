//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096
#define SERVER_PORT 80

typedef struct {
    int sockfd;
    struct sockaddr_in serv_addr;
} t_client;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <hostname> <port>\n", program_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    t_client client = {-1, {.sin_family = AF_INET, .sin_port = htons(port), .sin_addr.s_addr = INADDR_ANY}};

    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        die("socket");
    }

    int connect_status = connect(sockfd, (struct sockaddr *)&client.serv_addr, sizeof(client.serv_addr));
    if (connect_status < 0) {
        die("connect");
    }

    printf("Connected to %s:%d\n", inet_ntoa(client.serv_addr.sin_addr), ntohs(client.serv_addr.sin_port));

    char request[MAX_BUFFER_SIZE] = "GET / HTTP/1.1\r\nHost: %s:%d\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nUser-Agent: Linus-Torvalds-HTTP-Client/0.1\r\nConnection: keep-alive\r\n\r\n";
    snprintf(request, sizeof(request), request, hostname, port);

    ssize_t sent_bytes = send(sockfd, request, strlen(request), 0);
    if (sent_bytes < 0) {
        die("send");
    }

    char response[MAX_BUFFER_SIZE];
    ssize_t received_bytes = recv(sockfd, response, sizeof(response) - 1, 0);
    if (received_bytes < 0) {
        die("recv");
    }

    response[received_bytes] = '\0';

    printf("Response:\n%s\n", response);

    close(sockfd);
    return EXIT_SUCCESS;
}