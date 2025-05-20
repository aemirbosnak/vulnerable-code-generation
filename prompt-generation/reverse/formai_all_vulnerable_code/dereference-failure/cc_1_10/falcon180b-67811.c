//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX_LINE 1024
#define USER "username"
#define PASS "password"

char *get_line(int sock) {
    char line[MAX_LINE];
    memset(line, 0, MAX_LINE);
    int len = 0;
    while (len < MAX_LINE && (recv(sock, line + len, MAX_LINE - len, 0) > 0)) {
        len += strlen(line);
    }
    return strdup(line);
}

void send_command(int sock, char *command) {
    send(sock, command, strlen(command), 0);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket error\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("ftp.example.com");

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    char *reply = get_line(sock);
    if (strncmp(reply, "220", 3)!= 0) {
        printf("FTP server does not respond\n");
        exit(1);
    }

    send_command(sock, "USER " USER);
    send_command(sock, "PASS " PASS);

    char *welcome = get_line(sock);
    printf("FTP server welcome message: %s\n", welcome);

    send_command(sock, "PWD");
    char *pwd = get_line(sock);
    printf("Current directory: %s\n", pwd);

    send_command(sock, "CWD /pub/linux/kernel");
    send_command(sock, "LIST");

    char *list = get_line(sock);
    printf("Directory listing:\n%s\n", list);

    close(sock);
    return 0;
}