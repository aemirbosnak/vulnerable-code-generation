//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void read_response(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
        printf("Connection closed by server.\n");
        exit(1);
    }

    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    char auth_cmd[100];
    sprintf(auth_cmd, "USER %s\r\n", username);

    send(sock, auth_cmd, strlen(auth_cmd), 0);

    char response[BUFFER_SIZE];
    read_response(sock);

    char *status_code = strtok(response, " ");

    if (strcmp(status_code, "+OK")!= 0) {
        printf("Authentication failed.\n");
        exit(1);
    }

    char list_cmd[100];
    sprintf(list_cmd, "LIST\r\n");

    send(sock, list_cmd, strlen(list_cmd), 0);

    read_response(sock);

    close(sock);

    return 0;
}