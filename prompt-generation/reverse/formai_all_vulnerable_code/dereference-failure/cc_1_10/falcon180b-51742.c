//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 10
#define PORT "3490"

struct sockaddr_in server;

void main() {
    int sock, newsock, len, i;
    char buffer[1024];
    struct hostent *host;
    int hostlen;
    char *hostname;
    int portno;

    printf("Wireless Network Scanner\n");

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    puts("Enter IP Address of the Server:");
    scanf("%s", buffer);

    host = gethostbyname(buffer);

    if (host == NULL) {
        printf("No such host\n");
        exit(1);
    }

    hostlen = strlen(host->h_name);

    strcpy(hostname, host->h_name);

    server.sin_family = AF_INET;
    server.sin_port = htons(3490);
    server.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    puts("Connected to Server...");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter command: ");
        scanf("%s", buffer);

        if (strcmp(buffer, "scan") == 0) {
            if (send(sock, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                printf("Send failed\n");
                exit(1);
            }

            memset(buffer, 0, sizeof(buffer));
            if (recv(sock, buffer, sizeof(buffer), 0) <= 0) {
                printf("Receive failed\n");
                exit(1);
            }

            puts(buffer);
        } else if (strcmp(buffer, "exit") == 0) {
            close(sock);
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }
}