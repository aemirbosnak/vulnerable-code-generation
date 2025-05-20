//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>  // for close()

// Helper function to establish a TCP connection to the FTP server
int connect_to_server(char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sockfd;

    // Convert the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return -1;
    }

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Connect to the FTP server
    int sockfd = connect_to_server(argv[1], atoi(argv[2]));
    if (sockfd == -1) {
        fprintf(stderr, "Error connecting to server\n");
        return EXIT_FAILURE;
    }

    // Send the FTP command
    const char *cmd = "USER anonymous\n";
    if (send(sockfd, cmd, strlen(cmd), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server response
    char buf[512];
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Print the server response
    printf("%s", buf);

    // Close the connection
    close(sockfd);

    return EXIT_SUCCESS;
}