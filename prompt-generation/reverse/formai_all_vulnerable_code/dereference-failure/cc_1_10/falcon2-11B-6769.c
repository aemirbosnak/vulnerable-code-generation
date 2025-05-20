//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: accurate
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/tcp.h>

int main(int argc, char *argv[]) {
    int sockfd, new_fd, valread;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[1024];
    int opt = 1;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("Error listening");
        exit(1);
    }

    while (1) {
        new_fd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&valread);
        if (new_fd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        bzero(buf, 1024);
        valread = read(new_fd, buf, 1024);
        if (valread < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        printf("Received: %s\n", buf);
        if (strstr(buf, "firewall")!= NULL) {
            printf("Blocking connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
            close(new_fd);
        }
    }

    close(sockfd);
    return 0;
}