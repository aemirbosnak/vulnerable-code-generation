//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// A happy and helpful FTP client!

// Constants
#define FTP_PORT 21
#define BUFSIZE 1024
#define USERNAME "ftpuser"
#define PASSWORD "ftppassword"

// Function prototypes
int connect_to_ftp_server(char *hostname, int port);
int send_command(int sockfd, char *command);
int receive_response(int sockfd, char *buf, int bufsize);

// Main function
int main(int argc, char **argv) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Connect to the FTP server
    int sockfd = connect_to_ftp_server(argv[1], FTP_PORT);
    if (sockfd == -1) {
        fprintf(stderr, "Error: could not connect to FTP server\n");
        return EXIT_FAILURE;
    }

    // Login to the FTP server
    if (send_command(sockfd, "USER " USERNAME) == -1) {
        fprintf(stderr, "Error: could not send USER command\n");
        return EXIT_FAILURE;
    }

    if (send_command(sockfd, "PASS " PASSWORD) == -1) {
        fprintf(stderr, "Error: could not send PASS command\n");
        return EXIT_FAILURE;
    }

    // Send a LIST command to the FTP server
    if (send_command(sockfd, "LIST") == -1) {
        fprintf(stderr, "Error: could not send LIST command\n");
        return EXIT_FAILURE;
    }

    // Receive the response from the FTP server
    char buf[BUFSIZE];
    if (receive_response(sockfd, buf, BUFSIZE) == -1) {
        fprintf(stderr, "Error: could not receive response from FTP server\n");
        return EXIT_FAILURE;
    }

    // Print the response to the user
    printf("%s\n", buf);

    // Close the connection to the FTP server
    close(sockfd);

    return EXIT_SUCCESS;
}

// Connect to the FTP server
int connect_to_ftp_server(char *hostname, int port) {
    // Get the IP address of the FTP server
    struct hostent *hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        fprintf(stderr, "Error: could not get IP address of FTP server\n");
        return -1;
    }

    // Create a socket for the FTP connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: could not create socket\n");
        return -1;
    }

    // Connect to the FTP server
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr = *(struct in_addr *)hostinfo->h_addr;

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        fprintf(stderr, "Error: could not connect to FTP server\n");
        return -1;
    }

    return sockfd;
}

// Send a command to the FTP server
int send_command(int sockfd, char *command) {
    int n = send(sockfd, command, strlen(command), 0);
    if (n == -1) {
        fprintf(stderr, "Error: could not send command to FTP server\n");
        return -1;
    }

    return n;
}

// Receive a response from the FTP server
int receive_response(int sockfd, char *buf, int bufsize) {
    int n = recv(sockfd, buf, bufsize - 1, 0);
    if (n == -1) {
        fprintf(stderr, "Error: could not receive response from FTP server\n");
        return -1;
    }

    buf[n] = '\0';
    return n;
}