//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and port
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Get the IP address of the hostname
    struct hostent *hp = gethostbyname(hostname);
    if (hp == NULL) {
        fprintf(stderr, "Error: Could not get IP address of hostname\n");
        return EXIT_FAILURE;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)*hp->h_addr_list;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Error: Could not connect to server\n");
        return EXIT_FAILURE;
    }

    // Send a message to the server
    char *msg = "Hello, world!\n";
    if (send(sock, msg, strlen(msg), 0) == -1) {
        fprintf(stderr, "Error: Could not send message to server\n");
        return EXIT_FAILURE;
    }

    // Receive a message from the server
    char buff[BUFF_SIZE];
    if (recv(sock, buff, BUFF_SIZE, 0) == -1) {
        fprintf(stderr, "Error: Could not receive message from server\n");
        return EXIT_FAILURE;
    }

    // Print the message from the server
    printf("%s", buff);

    // Close the socket
    if (close(sock) == -1) {
        fprintf(stderr, "Error: Could not close socket\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}