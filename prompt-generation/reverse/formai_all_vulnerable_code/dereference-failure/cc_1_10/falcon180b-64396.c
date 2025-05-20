//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void error(char* message) {
    perror(message);
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
    if (sock == -1) {
        error("socket");
    }

    struct hostent* host = gethostbyname(server);
    if (host == NULL) {
        error("gethostbyname");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);
    serv_addr.sin_addr.s_addr = *(unsigned long*)host->h_addr;

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error("connect");
    }

    char* login_message = "USER ";
    strcat(login_message, username);
    strcat(login_message, "\r\n");

    send(sock, login_message, strlen(login_message), 0);

    char* password_message = "PASS ";
    strcat(password_message, password);
    strcat(password_message, "\r\n");

    send(sock, password_message, strlen(password_message), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        printf("%s", buffer);
    }

    close(sock);

    return 0;
}