//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(hostname);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result < 0) {
        perror("connect");
        exit(1);
    }

    char message[1024];
    sprintf(message, "USER john\r\n");
    write(sock, message, strlen(message));

    sprintf(message, "PASS password\r\n");
    write(sock, message, strlen(message));

    if (read(sock, message, sizeof(message)) > 0) {
        printf("Welcome %s!\r\n", message);
    } else {
        printf("Failed to authenticate\n");
    }

    close(sock);
    return 0;
}