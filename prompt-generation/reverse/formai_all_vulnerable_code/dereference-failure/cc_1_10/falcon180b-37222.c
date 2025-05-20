//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

struct ftp_data {
    char host[256];
    int port;
    char username[32];
    char password[32];
};

int main(int argc, char *argv[]) {
    if (argc!= 6) {
        printf("Usage: %s host port username password\n", argv[0]);
        return 1;
    }

    struct ftp_data data;
    strcpy(data.host, argv[1]);
    data.port = atoi(argv[2]);
    strcpy(data.username, argv[3]);
    strcpy(data.password, argv[4]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct hostent *host = gethostbyname(data.host);
    if (host == NULL) {
        printf("Error resolving host\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(data.port);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char login_msg[1024];
    sprintf(login_msg, "USER %s\r\n", data.username);
    send(sock, login_msg, strlen(login_msg), 0);

    char pass_msg[1024];
    sprintf(pass_msg, "PASS %s\r\n", data.password);
    send(sock, pass_msg, strlen(pass_msg), 0);

    char welcome_msg[BUFFER_SIZE];
    recv(sock, welcome_msg, BUFFER_SIZE, 0);
    printf("Server response: %s", welcome_msg);

    return 0;
}