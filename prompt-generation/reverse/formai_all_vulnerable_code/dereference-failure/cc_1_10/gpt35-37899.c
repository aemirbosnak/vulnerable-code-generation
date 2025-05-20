//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv)
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <server> <port> <username> <password>\n", argv[0]);
        exit(1);
    }
    
    char *server = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];
    
    struct hostent *he;
    struct sockaddr_in server_addr;
    int sock_fd;
    char buffer[BUFFER_SIZE];

    if ((he = gethostbyname(server)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr_list[0]);

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    recv(sock_fd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    send(sock_fd, buffer, strlen(buffer), 0);
    recv(sock_fd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    send(sock_fd, buffer, strlen(buffer), 0);
    recv(sock_fd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "LIST\r\n");
    send(sock_fd, buffer, strlen(buffer), 0);
    recv(sock_fd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    send(sock_fd, buffer, strlen(buffer), 0);

    close(sock_fd);
    return 0;
}