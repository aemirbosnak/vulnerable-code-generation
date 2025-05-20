//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_MIN 1
#define PORT_MAX 65535

int create_socket(char *address, int port)
{
    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(address);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

int check_port(char *address, int port)
{
    int sockfd;

    sockfd = create_socket(address, port);

    if (recv(sockfd, NULL, 0, MSG_PEEK) >= 0) {
        close(sockfd);
        return 1;
    }

    close(sockfd);
    return 0;
}

int main(int argc, char **argv)
{
    int i, ports, count = 0;
    char *address;

    if (argc < 3) {
        printf("Usage: %s <ip address> <ports>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    address = argv[1];
    ports = atoi(argv[2]);

    printf("Scanning ports %d to %d of %s\n", PORT_MIN, PORT_MAX, address);

    for (i = PORT_MIN; i <= PORT_MAX; i++) {
        if (check_port(address, i)) {
            printf("Port %d is open\n", i);
            count++;
        }
    }

    printf("Total open ports: %d\n", count);

    return 0;
}