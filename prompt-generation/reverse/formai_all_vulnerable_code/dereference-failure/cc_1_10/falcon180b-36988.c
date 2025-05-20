//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_LINE 2048
#define MAX_COMMAND 1024

#define POP3_PORT 110
#define POP3_USER "username"
#define POP3_PASS "password"
#define POP3_SERVER "pop3.example.com"

int main(int argc, char **argv) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char *user, *pass;
    char line[MAX_LINE];
    char command[MAX_COMMAND];
    int count = 0;
    int auth_count = 0;
    int state = 0;

    user = POP3_USER;
    pass = POP3_PASS;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    host = gethostbyname(POP3_SERVER);
    if (host == NULL) {
        fprintf(stderr, "Unknown host %s\n", POP3_SERVER);
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    memcpy(&server.sin_addr, host->h_addr, host->h_length);
    server.sin_port = htons(POP3_PORT);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    while (1) {
        memset(line, 0, MAX_LINE);
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            break;
        }
        strcat(command, line);
        if (strcmp(command, "quit\r\n") == 0) {
            break;
        }
        if (send(sock, command, strlen(command), 0) == -1) {
            perror("send");
            exit(1);
        }
        memset(line, 0, MAX_LINE);
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            break;
        }
        fprintf(stdout, "%s", line);
    }

    close(sock);
    exit(0);
}