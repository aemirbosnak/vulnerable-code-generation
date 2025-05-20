//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_RESPONSE_LENGTH 1024
#define FTP_PORT 21

void die(char *error_message);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        die("USAGE: ftp_client <server_address> <username>");
    }

    char *server_address = argv[1];
    char *username = argv[2];

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        die("ERROR: Could not create socket");
    }

    struct hostent *server_info = gethostbyname(server_address);
    if (server_info == NULL) {
        die("ERROR: Could not resolve server address");
    }

    struct sockaddr_in server_address_info;
    memset(&server_address_info, 0, sizeof(server_address_info));
    server_address_info.sin_family = AF_INET;
    server_address_info.sin_addr = *(struct in_addr *) server_info->h_addr_list[0];
    server_address_info.sin_port = htons(FTP_PORT);

    if (connect(socket_fd, (struct sockaddr *) &server_address_info, sizeof(server_address_info)) != 0) {
        die("ERROR: Could not connect to server");
    }

    char response[MAX_RESPONSE_LENGTH];
    if (recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0) == -1) {
        die("ERROR: Unable to receive response from server");
    }

    printf("%s", response);

    char command[MAX_COMMAND_LENGTH];
    sprintf(command, "USER %s\r\n", username);
    if (send(socket_fd, command, strlen(command), 0) == -1) {
        die("ERROR: Unable to send username to server");
    }

    if (recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0) == -1) {
        die("ERROR: Unable to receive response from server");
    }

    printf("%s", response);

    close(socket_fd);
    return 0;
}

void die(char *error_message) {
    fprintf(stderr, "%s\n", error_message);
    exit(1);
}