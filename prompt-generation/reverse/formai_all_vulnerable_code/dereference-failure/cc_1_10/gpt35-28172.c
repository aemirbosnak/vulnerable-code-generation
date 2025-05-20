//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LEN 1024

int main(int argc, char* argv[]) {
    // set up connection
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // read banner
    char banner[MAX_LEN];
    read(sock, banner, sizeof(banner));
    printf("%s", banner);

    // send login
    char login[MAX_LEN];
    sprintf(login, "a001 login %s %s\r\n", argv[2], argv[3]);
    write(sock, login, strlen(login));

    // read response
    char response[MAX_LEN];
    read(sock, response, sizeof(response));
    printf("%s", response);

    // select inbox
    char select_command[MAX_LEN];
    sprintf(select_command, "a002 select inbox\r\n");
    write(sock, select_command, strlen(select_command));

    // read select response
    char select_response[MAX_LEN];
    read(sock, select_response, sizeof(select_response));
    printf("%s", select_response);

    // fetch emails
    char fetch_command[MAX_LEN];
    sprintf(fetch_command, "a003 fetch 1:* full\r\n");
    write(sock, fetch_command, strlen(fetch_command));

    // read fetch response
    char fetch_response[MAX_LEN];
    read(sock, fetch_response, sizeof(fetch_response));
    printf("%s", fetch_response);

    // close connection
    char logout[MAX_LEN];
    sprintf(logout, "a004 logout\r\n");
    write(sock, logout, strlen(logout));
    close(sock);

    return 0;
}