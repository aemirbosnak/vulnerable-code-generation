//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s server_address port username\n", argv[0]);
        exit(1);
    }

    char *server_address = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, server_address, &server.sin_addr);

    connect(sock, (struct sockaddr *) &server, sizeof(server));

    char buf[BUFSIZE];
    int n;

    char *user_cmd = "USER ";
    char *pass_cmd = "PASS ";
    char *stat_cmd = "STAT\r\n";
    char *list_cmd = "LIST\r\n";
    char *quit_cmd = "QUIT\r\n";

    // async command sequence
    sprintf(buf, "%s%s\r\n", user_cmd, username);
    write(sock, buf, strlen(buf));
    sleep(1); // wait for response
    read(sock, buf, BUFSIZE);
    printf("%s", buf);

    sprintf(buf, "%s%s\r\n", pass_cmd, "password");
    write(sock, buf, strlen(buf));
    sleep(1); // wait for response
    read(sock, buf, BUFSIZE);
    printf("%s", buf);

    write(sock, stat_cmd, strlen(stat_cmd));
    sleep(1); // wait for response
    n = read(sock, buf, BUFSIZE);
    buf[n] = '\0';
    printf("%s", buf);

    write(sock, list_cmd, strlen(list_cmd));
    sleep(1); // wait for response
    n = read(sock, buf, BUFSIZE);
    buf[n] = '\0';
    printf("%s", buf);

    write(sock, quit_cmd, strlen(quit_cmd));
    sleep(1); // wait for response

    close(sock);

    return 0;
}