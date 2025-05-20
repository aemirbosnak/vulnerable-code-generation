//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_COMMAND_SIZE 1024
#define MAX_RESPONSE_SIZE 1024

/**
 * This function takes in the FTP server address and port number and
 * returns the client socket file descriptor.
 */
int ftp_connect(char* server_address, int port) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    struct hostent *he = gethostbyname(server_address);
    if (he == NULL) {
        perror("Failed to get host name");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    server_addr.sin_port = htons(port);

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to connect to server");
        exit(1);
    }

    char response[MAX_RESPONSE_SIZE];
    bzero(response, MAX_RESPONSE_SIZE);
    recv(sock_fd, response, MAX_RESPONSE_SIZE, 0);

    printf("%s", response);

    return sock_fd;
}

/**
 * This function takes in the command to be sent to the FTP server
 * and returns the response received from the server.
 */
char* ftp_send_command(int sock_fd, const char* command) {
    if (send(sock_fd, command, strlen(command), 0) == -1) {
        perror("Failed to send command to server");
        exit(1);
    }

    char response[MAX_RESPONSE_SIZE];
    bzero(response, MAX_RESPONSE_SIZE);
    recv(sock_fd, response, MAX_RESPONSE_SIZE, 0);

    return strdup(response);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: ./ftp_client <server_address> <server_port> <username>\n");
        exit(1);
    }

    char* server_address = argv[1];
    int port = atoi(argv[2]);
    char* username = argv[3];

    int sock_fd = ftp_connect(server_address, port);

    char command[MAX_RESPONSE_SIZE];

    sprintf(command, "USER %s\r\n", username);
    char* response = ftp_send_command(sock_fd, command);
    printf("%s", response);
    free(response);

    sprintf(command, "PASS %s\r\n", getpass("Enter password: "));
    response = ftp_send_command(sock_fd, command);
    printf("%s", response);
    free(response);

    sprintf(command, "SYST\r\n");
    response = ftp_send_command(sock_fd, command);
    printf("%s", response);
    free(response);

    sprintf(command, "QUIT\r\n");
    response = ftp_send_command(sock_fd, command);
    printf("%s", response);
    free(response);

    close(sock_fd);

    return 0;
}