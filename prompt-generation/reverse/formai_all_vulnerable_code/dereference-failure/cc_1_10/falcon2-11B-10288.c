//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <time.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int i, port, client_sock, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    struct protoent *proto;
    char buffer[256], host[256];

    if (argc < 3) {
        printf("Usage: %s <target> <port>\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);
    port = atoi(argv[2]);

    if ((server = gethostbyname(host)) == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(1);
    }

    if ((proto = getprotobyname("tcp")) == NULL) {
        fprintf(stderr, "ERROR: Protocol not supported\n");
        exit(1);
    }

    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("ERROR connecting");
        exit(1);
    }

    for (i = 0; i < 100; i++) {
        if ((n = recv(client_sock, buffer, 255, 0)) == -1) {
            perror("ERROR receiving");
            exit(1);
        }

        printf("Received: %s\n", buffer);
    }

    if (close(client_sock) == -1) {
        perror("ERROR closing socket");
        exit(1);
    }

    return 0;
}