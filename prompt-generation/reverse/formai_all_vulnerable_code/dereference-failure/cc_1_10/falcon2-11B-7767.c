//Falcon2-11B DATASET v1.0 Category: Networking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in servaddr;
    int serv_sock;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if ((serv_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    if (connect(serv_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    while (1) {
        int n = read(serv_sock, buffer, sizeof(buffer));
        if (n < 0) {
            fprintf(stderr, "Error reading from socket\n");
            exit(1);
        }
        printf("%s\n", buffer);

        if (n == 0) {
            break;
        }

        int m = write(serv_sock, buffer, n);
        if (m < 0) {
            fprintf(stderr, "Error writing to socket\n");
            exit(1);
        }
    }

    close(serv_sock);
    return 0;
}