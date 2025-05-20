//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int server_fd, new_fd, chars_read;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char buffer[256];
    pid_t child_pid;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    listen(server_fd, 5);
    addr_len = sizeof(client_addr);

    while (1) {
        new_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (new_fd < 0) {
            perror("Error accepting connection");
            continue;
        }

        if (fork() == 0) {
            close(server_fd);
            close(new_fd);

            printf("Connected by %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            while (1) {
                chars_read = recv(new_fd, buffer, sizeof(buffer), 0);
                if (chars_read < 0) {
                    perror("Error reading from socket");
                    break;
                }

                buffer[chars_read] = '\0';
                printf("%s", buffer);

                send(new_fd, "You: ", 6, 0);
                chars_read = recv(new_fd, buffer, sizeof(buffer), 0);
                if (chars_read < 0) {
                    perror("Error reading from socket");
                    break;
                }

                buffer[chars_read] = '\0';
                printf("Client: %s\n", buffer);

                fflush(stdout);
            }

            close(new_fd);
            exit(0);
        }
    }

    close(server_fd);
    return 0;
}