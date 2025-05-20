//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PORTS 65535

int main() {
    int port_number;
    char host_name[256];
    char banner[256];
    struct sockaddr_in sock_addr;
    int sock_fd;
    int i;

    printf("Enter host name: ");
    scanf("%s", host_name);

    printf("Enter port number: ");
    scanf("%d", &port_number);

    sock_fd = socket(AF_INET, SOCK_STREAM, htons(port_number));
    if (sock_fd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port_number);
    strcpy(sock_addr.sin_addr.s_addr, host_name);

    if (connect(sock_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1) {
        perror("Error connecting to socket");
        exit(1);
    }

    printf("Banner: ");
    recv(sock_fd, banner, 256, 0);
    printf("%s\n", banner);

    for (i = 0; i < MAX_PORTS; i++) {
        port_number++;
        sock_fd = socket(AF_INET, SOCK_STREAM, htons(port_number));
        if (sock_fd == -1) {
            perror("Error creating socket");
            exit(1);
        }

        sock_addr.sin_family = AF_INET;
        sock_addr.sin_port = htons(port_number);
        strcpy(sock_addr.sin_addr.s_addr, host_name);

        if (connect(sock_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1) {
            perror("Error connecting to socket");
            exit(1);
        }

        printf("Port %d: ", port_number);
        recv(sock_fd, banner, 256, 0);
        printf("%s\n", banner);
    }

    close(sock_fd);
    return 0;
}