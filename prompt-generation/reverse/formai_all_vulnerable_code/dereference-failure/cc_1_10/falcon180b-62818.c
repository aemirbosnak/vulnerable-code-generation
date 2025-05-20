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
#define MAX_COMMANDS 10
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *commands[MAX_COMMANDS];
    int num_commands = 0;
    int i;

    if (argc < 3) {
        printf("Usage:./ftp_client <hostname> <port>\n");
        return 1;
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (TRUE) {
        memset(buffer, 0, BUFFER_SIZE);
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        commands[num_commands] = strdup(buffer);
        num_commands++;

        if (num_commands >= MAX_COMMANDS) {
            printf("Maximum number of commands reached\n");
            break;
        }
    }

    for (i = 0; i < num_commands; i++) {
        send(socket_fd, commands[i], strlen(commands[i]), 0);
        memset(buffer, 0, BUFFER_SIZE);
        recv(socket_fd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    close(socket_fd);

    return 0;
}