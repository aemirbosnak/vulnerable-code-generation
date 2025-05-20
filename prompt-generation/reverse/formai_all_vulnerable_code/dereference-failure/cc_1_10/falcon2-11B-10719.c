//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/select.h>
#include <netinet/in.h>

#define SERVER "imap.gmail.com"
#define PORT 143

int main(void) {
    int socket_fd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    printf("Connecting to %s:%d\n", SERVER, PORT);

    server = gethostbyname(SERVER);
    if (server == NULL) {
        printf("Error: Unknown host\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, *(unsigned char *)(server->h_addr), server->h_length);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Connection failed\n");
        return 1;
    }

    char command[128];
    int mailbox_count;

    printf("Authenticating...\n");
    if (send(socket_fd, "LOGIN \"your_username\" \"your_password\"\r\n", 29, 0) < 0) {
        printf("Error: Authentication failed\n");
        return 1;
    }

    if (send(socket_fd, "CAPABILITY\r\n", 13, 0) < 0) {
        printf("Error: Could not send CAPABILITY command\n");
        return 1;
    }

    if (send(socket_fd, "LIST \"\" \"\" \"\"\r\n", 29, 0) < 0) {
        printf("Error: Could not send LIST command\n");
        return 1;
    }

    memset(command, 0, sizeof(command));
    memset(command, '\0', sizeof(command));

    while ((n = recv(socket_fd, command, sizeof(command), 0)) > 0) {
        if (strcmp(command, "OK") == 0) {
            mailbox_count = atoi(strtok(command, " "));
            printf("Mailbox count: %d\n", mailbox_count);
        }
    }

    close(socket_fd);
    return 0;
}