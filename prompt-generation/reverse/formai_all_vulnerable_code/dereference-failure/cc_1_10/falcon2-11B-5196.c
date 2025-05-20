//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {

    int server_fd, new_socket;
    struct sockaddr_in server_address;
    struct hostent *server;
    int yes = 1;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(PORT);

    if (connect(server_fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("connect failed");
        exit(1);
    }

    printf("Connection successful.\n");

    char input[100];
    bzero(input, 100);

    while (1) {
        printf("Enter message: ");
        fgets(input, 100, stdin);

        if (strcmp(input, "quit") == 0)
            break;

        send(server_fd, input, strlen(input), 0);
        if (recv(server_fd, input, 100, 0) == -1) {
            perror("recv failed");
            exit(1);
        }
    }

    close(server_fd);

    return 0;
}