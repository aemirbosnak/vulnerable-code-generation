//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <ip_address> <port_number>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_address.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char message[256];
    fd_set read_fds;
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(sock, &read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
        
        if (select(sock+1, &read_fds, NULL, NULL, NULL) == -1) {
            printf("Error in select()\n");
            break;
        }

        if (FD_ISSET(sock, &read_fds)) {
            memset(message, 0, sizeof(message));
            int n = read(sock, message, sizeof(message));
            if (n < 1) {
                printf("Server closed connection\n");
                break;
            }
            printf("%s\n", message);
        }

        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            fgets(message, sizeof(message), stdin);
            int n = write(sock, message, strlen(message));
            if (n < 1) {
                printf("Error writing to server\n");
                break;
            }
        }

    }

    close(sock);

    return 0;
}