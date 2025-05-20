//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serverAddr.sin_port = htons(PORT);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        fprintf(stderr, "Error connecting: %s\n", strerror(errno));
        return 1;
    }

    char msg[256];
    while (1) {
        printf("Enter command (on/off/toggle): ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = '\0';

        if (strcmp(msg, "on") == 0) {
            printf("Turning lights on...\n");
            send(sock, "on\n", 3, 0);
        } else if (strcmp(msg, "off") == 0) {
            printf("Turning lights off...\n");
            send(sock, "off\n", 3, 0);
        } else if (strcmp(msg, "toggle") == 0) {
            printf("Toggling lights...\n");
            send(sock, "toggle\n", 6, 0);
        } else {
            fprintf(stderr, "Unknown command: %s\n", msg);
        }

        printf("Waiting for response...\n");
        int len = recv(sock, msg, sizeof(msg), 0);
        if (len < 0) {
            fprintf(stderr, "Error receiving: %s\n", strerror(errno));
            return 1;
        }
        printf("Received response: %s\n", msg);
    }

    return 0;
}