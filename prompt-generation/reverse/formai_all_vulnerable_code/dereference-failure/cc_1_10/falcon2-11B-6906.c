//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int server_fd, client_fd, n;
    struct sockaddr_in server_addr, client_addr;
    char buffer[256];
    pid_t pid;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &n);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s\n", inet_ntoa(client_addr.sin_addr));
        pid = fork();
        if (pid == 0) {
            close(server_fd);
            close(client_fd);

            while (1) {
                n = read(0, buffer, sizeof(buffer));
                if (n <= 0)
                    break;

                write(1, buffer, n);
            }

            exit(0);
        }

        close(server_fd);
        close(client_fd);

        wait(NULL);
    }

    return 0;
}