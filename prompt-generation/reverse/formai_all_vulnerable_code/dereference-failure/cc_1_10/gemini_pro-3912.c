//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <server IP> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send data to the server
    char buf[BUFF_SIZE];
    while (fgets(buf, BUFF_SIZE, stdin) != NULL) {
        if (send(sock, buf, strlen(buf), 0) == -1) {
            perror("send");
            exit(1);
        }

        // Receive data from the server
        if (recv(sock, buf, BUFF_SIZE, 0) == -1) {
            perror("recv");
            exit(1);
        }

        // Print the data received from the server
        printf("%s", buf);
    }

    // Close the socket
    close(sock);

    return 0;
}