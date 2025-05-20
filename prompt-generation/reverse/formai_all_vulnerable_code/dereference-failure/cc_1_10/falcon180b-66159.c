//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char* server = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) error("socket() failed");

    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(server, "21", &hints, &servinfo)!= 0) error("getaddrinfo() failed");

    connect(sock, servinfo->ai_addr, servinfo->ai_addrlen);
    freeaddrinfo(servinfo);

    char* login = malloc(strlen(username) + strlen(password) + 3);
    sprintf(login, "%s %s", username, password);

    send(sock, login, strlen(login), 0);
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, BUFFER_SIZE, 0);

    printf("Server response: %s\n", buffer);

    close(sock);

    return 0;
}