//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

// define the maximum buffer size
#define MAX_BUFFER_SIZE 1024

// define the maximum command line argument size
#define MAX_ARG_SIZE 256

int main(int argc, char *argv[]) {

    int sock_fd, port_no, n;
    char buffer[MAX_BUFFER_SIZE], command[MAX_ARG_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // check for the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // get the port number from the arguments
    port_no = atoi(argv[2]);

    // create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        fprintf(stderr, "Error: failed to create socket\n");
        exit(1);
    }

    // get the host by name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host: %s\n", argv[1]);
        exit(1);
    }

    // set the server address structure
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port_no);

    // connect to the server
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: failed to connect to server\n");
        exit(1);
    }

    // receive welcome message from the server
    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sock_fd, buffer, MAX_BUFFER_SIZE);
    if (n < 0) {
        fprintf(stderr, "Error: failed to receive welcome message\n");
        exit(1);
    }
    printf("%s", buffer);

    // loop for sending commands to the server
    while (1) {
        printf("Enter command: ");
        bzero(command, MAX_ARG_SIZE);
        fgets(command, MAX_ARG_SIZE, stdin);

        // send the command to the server
        n = write(sock_fd, command, strlen(command));
        if (n < 0) {
            fprintf(stderr, "Error: failed to send command\n");
            exit(1);
        }

        // receive response from the server
        bzero(buffer, MAX_BUFFER_SIZE);
        n = read(sock_fd, buffer, MAX_BUFFER_SIZE);
        if (n < 0) {
            fprintf(stderr, "Error: failed to receive response\n");
            exit(1);
        }
        printf("%s", buffer);

        // check for exit command
        if (strcmp(command, "exit\n") == 0) {
            break;
        }
    }

    // close the socket
    close(sock_fd);

    return 0;
}