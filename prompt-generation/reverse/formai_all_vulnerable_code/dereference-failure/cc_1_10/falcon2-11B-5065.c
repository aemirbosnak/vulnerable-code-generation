//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define PORT 8080

void send_data(int sockfd, char* data, int length) {
    int sent = send(sockfd, data, length, 0);
    if (sent < 0) {
        perror("Error sending data");
    }
}

int main(int argc, char* argv[]) {
    int sockfd, new_socket, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <ip address>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("Connected to %s on port %d\n", argv[1], portno);

    while (1) {
        bzero(buffer, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            if (n < 0) {
                perror("Error reading from socket");
            }
            break;
        }

        printf("%s\n", buffer);
        send_data(sockfd, "Hello from Client\n", 21);
    }

    close(sockfd);
    return 0;
}