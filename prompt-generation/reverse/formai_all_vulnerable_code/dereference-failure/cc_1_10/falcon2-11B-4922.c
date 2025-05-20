//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 110
#define MAX_BUFFER 1024

int main() {
    int socket_fd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER];
    char response[MAX_BUFFER];

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("example.com");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char*)&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Username: ");
    fgets(buffer, MAX_BUFFER, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    send(socket_fd, buffer, strlen(buffer), 0);

    recv(socket_fd, buffer, MAX_BUFFER, 0);
    printf("%s\n", buffer);

    if (strcmp(buffer, "OK") == 0) {
        send(socket_fd, "user\r\n", strlen("user\r\n"), 0);
        recv(socket_fd, buffer, MAX_BUFFER, 0);
        printf("%s\n", buffer);
    }

    send(socket_fd, "pass\r\n", strlen("pass\r\n"), 0);
    recv(socket_fd, buffer, MAX_BUFFER, 0);
    printf("%s\n", buffer);

    send(socket_fd, "list\r\n", strlen("list\r\n"), 0);
    recv(socket_fd, buffer, MAX_BUFFER, 0);
    printf("%s\n", buffer);

    close(socket_fd);
    return 0;
}