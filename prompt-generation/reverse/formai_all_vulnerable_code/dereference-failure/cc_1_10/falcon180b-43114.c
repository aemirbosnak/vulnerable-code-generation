//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void send_command(int sock, char *command) {
    send(sock, command, strlen(command), 0);
}

void receive_response(int sock, char *response) {
    bzero(response, BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE, 0);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char command[BUFFER_SIZE], response[BUFFER_SIZE];

    // Check command line arguments
    if (argc!= 4) {
        printf("Usage: %s <server_address> <username> <password>\n", argv[0]);
        exit(1);
    }

    // Connect to server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        printf("Error: Failed to connect to server.\n");
        exit(1);
    }

    // Login to server
    send_command(sock, "USER ");
    send_command(sock, argv[2]);
    receive_response(sock, response);

    send_command(sock, "PASS ");
    send_command(sock, argv[3]);
    receive_response(sock, response);

    // Change working directory
    send_command(sock, "CWD /");
    receive_response(sock, response);

    // List files in directory
    send_command(sock, "LIST");
    receive_response(sock, response);
    printf("%s\n", response);

    // Close connection
    close(sock);

    return 0;
}