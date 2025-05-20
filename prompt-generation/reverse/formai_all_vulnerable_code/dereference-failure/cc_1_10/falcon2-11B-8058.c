//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 12345

int main(int argc, char *argv[]) {

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    struct hostent *server;

    int server_fd, new_fd;
    int n;

    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        return 1;
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *((long *)server->h_addr);
    server_addr.sin_port = htons(PORT);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        fprintf(stderr, "Error opening socket\n");
        return 1;
    }

    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    listen(server_fd, 1);

    while ((new_fd = accept(server_fd, NULL, NULL)) > 0) {
        char buffer[1024];

        bzero(buffer, sizeof(buffer));
        n = read(new_fd, buffer, sizeof(buffer));

        if (n > 0) {
            write(new_fd, buffer, n);
            printf("Client: %s\n", buffer);
        } else if (n < 0) {
            perror("Error reading from client");
            close(new_fd);
        } else {
            printf("Client disconnected\n");
            close(new_fd);
        }
    }

    close(server_fd);

    return 0;
}