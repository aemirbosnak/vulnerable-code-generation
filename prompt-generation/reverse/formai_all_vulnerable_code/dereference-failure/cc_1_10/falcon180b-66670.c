//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <host> <username> <password>\n", argv[0]);
        return -1;
    }

    char *host = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket\n");
        return -1;
    }

    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        printf("Error: Host not found\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        return -1;
    }

    char login_cmd[100];
    sprintf(login_cmd, "USER %s\r\n", username);
    send(sock, login_cmd, strlen(login_cmd), 0);

    char pass_cmd[100];
    sprintf(pass_cmd, "PASS %s\r\n", password);
    send(sock, pass_cmd, strlen(pass_cmd), 0);

    char *response = (char *)malloc(BUFFER_SIZE);
    memset(response, 0, BUFFER_SIZE);

    int bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error: Failed to receive response\n");
        return -1;
    }

    printf("Server response: %s\n", response);

    close(sock);
    return 0;
}