//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

void ftp_client(int sock) {
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char file_name[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int len;

    printf("Enter FTP server IP address: ");
    scanf("%s", &command);

    printf("Enter username: ");
    scanf("%s", &username);

    printf("Enter password: ");
    scanf("%s", &password);

    strcat(command, " ");
    strcat(command, username);
    strcat(command, " ");
    strcat(command, password);
    strcat(command, "\r\n");

    send(sock, command, strlen(command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("FTP server response: %s\n", buffer);

    strcat(command, "LIST\r\n");
    send(sock, command, strlen(command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("FTP server response: %s\n", buffer);

    strcat(command, "RETR ");
    printf("Enter file name: ");
    scanf("%s", &file_name);
    strcat(command, file_name);
    strcat(command, "\r\n");

    send(sock, command, strlen(command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("FTP server response: %s\n", buffer);

    close(sock);
}

int main() {
    int sock;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    printf("Enter FTP server IP address: ");
    char *server = (char*)malloc(1024);
    scanf("%s", server);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, server, &server_addr.sin_addr);
    server_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to FTP server\n");
        return 1;
    }

    ftp_client(sock);

    return 0;
}