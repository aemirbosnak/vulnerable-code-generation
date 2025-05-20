//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in server;
    struct hostent *host;
    char *hostname;
    char *port_str;
    int port;
    int sockfd;

    // Check command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Convert the hostname to a numeric address
    hostname = argv[1];
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Unknown hostname '%s'\n", hostname);
        exit(1);
    }

    // Convert the port string to an integer
    port_str = getenv("PORT");
    if (port_str == NULL) {
        fprintf(stderr, "Error: No PORT environment variable specified\n");
        exit(1);
    }
    port = atoi(port_str);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Error: Invalid PORT environment variable value '%s'\n", port_str);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        exit(1);
    }

    // Fill in the server address
    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = *(unsigned long *) host->h_addr_list[0];
    server.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        exit(1);
    }

    // Send some data
    if (send(sockfd, "Hello, World!", strlen("Hello, World!"), 0) < 0) {
        fprintf(stderr, "Error: Failed to send data\n");
        exit(1);
    }

    // Receive some data
    if (recv(sockfd, "Received: ", 8, 0) < 0) {
        fprintf(stderr, "Error: Failed to receive data\n");
        exit(1);
    }
    printf("Received: %s\n", "Received: ");

    // Clean up
    close(sockfd);
    return 0;
}