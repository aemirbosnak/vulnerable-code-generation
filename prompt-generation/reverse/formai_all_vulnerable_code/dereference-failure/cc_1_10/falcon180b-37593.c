//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *server_name;
    char buffer[BUF_SIZE];
    const char *username = "username";
    const char *password = "password";
    const char *pop3_commands[] = {
        "USER %s\r\n",
        "PASS %s\r\n",
        "STAT\r\n",
        "QUIT\r\n"
    };
    int i;

    if (argc < 3) {
        printf("Usage:./pop3_client <server_name> <port_number>\n");
        exit(1);
    }

    server_name = argv[1];
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    server = gethostbyname(server_name);
    if (server == NULL) {
        printf("Error: Could not resolve server name\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = *(unsigned long *)server->h_addr;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    for (i = 0; i < sizeof(pop3_commands) / sizeof(pop3_commands[0]); i++) {
        sprintf(buffer, pop3_commands[i], username, password);
        send(sockfd, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUF_SIZE);
        recv(sockfd, buffer, BUF_SIZE, 0);

        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}