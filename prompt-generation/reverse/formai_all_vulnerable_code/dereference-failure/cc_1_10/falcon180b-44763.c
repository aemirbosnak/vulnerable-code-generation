//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        printf("Error getting host information\n");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *buffer = malloc(BUFFER_SIZE);
    memset(buffer, 0, BUFFER_SIZE);

    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);

    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response);

    close(sock);
    return 0;
}