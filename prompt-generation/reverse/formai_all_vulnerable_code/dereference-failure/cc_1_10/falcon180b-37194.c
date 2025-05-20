//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024
#define POP3_PORT 110

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char host[64];
    char user[64];
    char pass[64];
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int command_len;
    int response_len;
    int i;

    // Check command line arguments
    if (argc!= 5) {
        printf("Usage: %s <host> <user> <pass> <command>\n", argv[0]);
        return 1;
    }

    // Set host, user, and password
    strcpy(host, argv[1]);
    strcpy(user, argv[2]);
    strcpy(pass, argv[3]);

    // Connect to server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        die("connect");
    }

    // Authenticate
    sprintf(command, "USER %s\r\n", user);
    send(sock, command, strlen(command), 0);
    response_len = recv(sock, response, MAX_RESPONSE_LENGTH, 0);
    if (response_len <= 0) {
        die("recv");
    }
    response[response_len] = '\0';

    sprintf(command, "PASS %s\r\n", pass);
    send(sock, command, strlen(command), 0);
    response_len = recv(sock, response, MAX_RESPONSE_LENGTH, 0);
    if (response_len <= 0) {
        die("recv");
    }
    response[response_len] = '\0';

    // Send command
    strcpy(command, argv[4]);
    command_len = strlen(command);
    send(sock, command, command_len, 0);
    response_len = recv(sock, response, MAX_RESPONSE_LENGTH, 0);
    if (response_len <= 0) {
        die("recv");
    }
    response[response_len] = '\0';

    // Print response
    printf("Response:\n%s", response);

    close(sock);
    return 0;
}