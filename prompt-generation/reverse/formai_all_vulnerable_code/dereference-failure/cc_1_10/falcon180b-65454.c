//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define MAX_COMMAND_LENGTH 100
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 32

char username[MAX_USERNAME_LENGTH + 1] = {0};
char password[MAX_PASSWORD_LENGTH + 1] = {0};
char server_address[20] = {0};

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <server_address> <username> <password> <command>\n", argv[0]);
        return 1;
    }

    strcpy(server_address, argv[1]);
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);
    strcpy(argv[4], "LIST");

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to connect to server\n");
        return 1;
    }

    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    sprintf(send_buffer, "USER %s\r\n", username);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    sprintf(send_buffer, "PASS %s\r\n", password);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    sprintf(send_buffer, "QUOTE SITE CHMOD 777 %s\r\n", argv[4]);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    close(sockfd);
    return 0;
}