//FormAI DATASET v1.0 Category: Networking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUFSIZE 1024

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUFSIZE];

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    if((server_socket = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    if(listen(server_socket, 1) < 0) {
        perror("listen() failed");
        exit(1);
    }

    fprintf(stderr, "Server ready, waiting for client...\n");

    if((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, NULL)) < 0) {
        perror("accept() failed");
        exit(1);
    }

    fprintf(stderr, "Client accepted!\n");

    int len = 0;
    while((len = read(client_socket, buf, BUFSIZE)) > 0) {
        if(write(client_socket, buf, len) < 0) {
            perror("write() failed");
            exit(1);
        }
        printf("Echoed %d bytes\n", len);
    }

    if(len < 0) {
        perror("read() failed");
        exit(1);
    }

    close(client_socket);
    close(server_socket);

    return 0;
}