//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX 100

int main(int argc, char *argv[]) {
    int sock, numbytes;
    struct hostent *he;
    struct sockaddr_in dest;
    char buffer[MAX];

    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    he = gethostbyname(argv[1]);
    if (he == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    dest.sin_family = AF_INET;
    dest.sin_port = htons(7);
    dest.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sock, (struct sockaddr *)&dest, sizeof(dest)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    while (1) {
        printf("Enter message: ");
        fgets(buffer, MAX, stdin);
        send(sock, buffer, strlen(buffer), 0);
        memset(buffer, 0, MAX);
        numbytes = recv(sock, buffer, MAX, 0);
        if (numbytes <= 0) {
            printf("Connection closed\n");
            break;
        }
        printf("Received message: %s\n", buffer);
    }

    close(sock);
    return 0;
}