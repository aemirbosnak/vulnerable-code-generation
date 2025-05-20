//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 21
#define MAX_LINE 1024
#define USER "anonymous"
#define PASS "love@example.com"

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <filename>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: Invalid IP address\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    char login[MAX_LINE];
    sprintf(login, "USER %s\r\n", USER);
    send(sock, login, strlen(login), 0);

    char pass[MAX_LINE];
    sprintf(pass, "PASS %s\r\n", PASS);
    send(sock, pass, strlen(pass), 0);

    char command[MAX_LINE];
    sprintf(command, "RETR %s\r\n", argv[2]);
    send(sock, command, strlen(command), 0);

    char buffer[MAX_LINE];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("Error: Failed to receive data\n");
            exit(1);
        }

        if (strstr(buffer, "226")!= NULL) {
            printf("File transfer complete\n");
            break;
        }

        FILE *fp = fopen(argv[2], "ab");
        if (fp == NULL) {
            printf("Error: Failed to open file\n");
            exit(1);
        }

        fwrite(buffer, 1, bytes_received, fp);
        fclose(fp);
    }

    close(sock);
    return 0;
}