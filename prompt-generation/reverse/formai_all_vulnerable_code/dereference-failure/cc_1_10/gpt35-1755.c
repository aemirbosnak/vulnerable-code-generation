//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [server address] [port number]\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname %s\n", argv[1]);
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    memcpy(&server_address.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[BUF_SIZE];
    int bytes_received;

    for (;;) {
        printf("> ");
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';

        if (send(sock, buf, strlen(buf), 0) != strlen(buf)) {
            perror("send");
            return 1;
        }

        if (strcmp(buf, "QUIT") == 0) {
            break;
        }

        bytes_received = recv(sock, buf, sizeof(buf), 0);
        if (bytes_received < 0) {
            perror("recv");
            return 1;
        }

        buf[bytes_received] = '\0';
        printf("< %s\n", buf);
    }

    return 0;
}