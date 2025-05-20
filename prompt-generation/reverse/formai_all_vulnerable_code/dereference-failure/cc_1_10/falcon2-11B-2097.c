//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int listen_fd, new_fd, addrlen;
    struct sockaddr_in serv_addr;
    int portno = atoi(argv[1]);
    int i;

    // Create socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind to the port
    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Queue up to 5 requests
    listen(listen_fd, 5);

    while (1) {
        // Accept incoming connections
        new_fd = accept(listen_fd, (struct sockaddr *)NULL, NULL);
        if (new_fd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Handle incoming requests
        char buffer[1024];
        printf("Received connection from %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));
        for (i = 0; i < 1024; i++)
            buffer[i] = '*';
        buffer[i++] = '\n';
        buffer[i] = '\0';
        send(new_fd, buffer, strlen(buffer), 0);
        close(new_fd);
    }

    close(listen_fd);
    return 0;
}