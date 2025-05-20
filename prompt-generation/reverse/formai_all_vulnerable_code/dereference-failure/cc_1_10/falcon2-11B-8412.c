//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080
#define SERVER_ADDRESS "127.0.0.1"

int main(int argc, char **argv)
{
    int sockfd, new_fd;
    struct sockaddr_in server_address;
    int addrlen = sizeof(server_address);

    int buffer_size = 1024;
    char buffer[buffer_size];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        exit(1);
    }

    if (argc == 2) {
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("socket");
            exit(1);
        }

        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT);
        if (inet_pton(AF_INET, SERVER_ADDRESS, &server_address.sin_addr) <= 0) {
            perror("inet_pton");
            exit(1);
        }

        if (connect(sockfd, (struct sockaddr *)&server_address, addrlen) == -1) {
            perror("connect");
            exit(1);
        }

        if (write(sockfd, argv[1], strlen(argv[1])) == -1) {
            perror("write");
            exit(1);
        }

        if (read(sockfd, buffer, buffer_size) == -1) {
            perror("read");
            exit(1);
        }

        printf("%s\n", buffer);

        close(sockfd);
        return 0;
    }
}