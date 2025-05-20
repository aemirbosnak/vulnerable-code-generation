//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX 100

struct sockaddr_in server_addr;
int sock;

char *get_in_addr(struct sockaddr *sa) {
    if (sa->sa_family == AF_INET) {
        return inet_ntoa((((struct sockaddr_in *) sa)->sin_addr));
    }
    return "unknown";
}

void error_handling(char *message) {
    perror(message);
    exit(0);
}

int main(int argc, char **argv) {
    int opt = 1;
    int addrlen = sizeof(server_addr);
    char buffer[MAX];

    if (argc < 4) {
        printf("Usage: %s <IP address> <port number> <message>\n", argv[0]);
        exit(0);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error_handling("connect failed");
    }

    send(sock, argv[3], strlen(argv[3]), 0);
    recv(sock, buffer, MAX, 0);

    printf("Message received from server: %s\n", buffer);

    close(sock);
    return 0;
}