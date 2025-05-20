//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to get the host name
void get_host_name(char *host, int port) {
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char hostname[NI_MAXHOST];

    // Resolve the host name
    if (gethostbyname(host) == NULL) {
        printf("Error: Host not found\n");
        exit(1);
    }

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    // Create a structure to hold the address of the server
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Assign the IP address from the hostent structure to the server address
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    // Print the host name
    gethostname(hostname, NI_MAXHOST);
    printf("Hostname: %s\n", hostname);

    // Close the socket
    close(socket_fd);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);
    get_host_name(host, port);

    return 0;
}