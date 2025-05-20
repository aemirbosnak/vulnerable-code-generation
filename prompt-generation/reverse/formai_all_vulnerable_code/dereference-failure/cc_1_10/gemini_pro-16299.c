//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define FTP_PORT 21

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the FTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the USER command
    char *user = "username";
    char *user_cmd = "USER ";
    char *user_cmd_full = malloc(strlen(user_cmd) + strlen(user) + 1);
    strcpy(user_cmd_full, user_cmd);
    strcat(user_cmd_full, user);
    strcat(user_cmd_full, "\r\n");
    if (send(sock, user_cmd_full, strlen(user_cmd_full), 0) < 0) {
        perror("send");
        exit(1);
    }
    free(user_cmd_full);

    // Receive the response from the FTP server
    char response[512];
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Send the PASS command
    char *password = "password";
    char *pass_cmd = "PASS ";
    char *pass_cmd_full = malloc(strlen(pass_cmd) + strlen(password) + 1);
    strcpy(pass_cmd_full, pass_cmd);
    strcat(pass_cmd_full, password);
    strcat(pass_cmd_full, "\r\n");
    if (send(sock, pass_cmd_full, strlen(pass_cmd_full), 0) < 0) {
        perror("send");
        exit(1);
    }
    free(pass_cmd_full);

    // Receive the response from the FTP server
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // List the files in the current directory
    char *list_cmd = "LIST\r\n";
    if (send(sock, list_cmd, strlen(list_cmd), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response from the FTP server
    while (recv(sock, response, sizeof(response), 0) > 0) {
        printf("%s", response);
    }

    // Close the socket
    close(sock);

    return 0;
}