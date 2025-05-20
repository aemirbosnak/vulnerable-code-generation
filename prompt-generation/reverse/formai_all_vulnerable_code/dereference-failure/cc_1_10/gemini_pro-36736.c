//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Custom data structure to store FTP commands
typedef struct ftp_command {
    char *command;
    char *arg;
} ftp_command;

// Utility function to send a command to the FTP server
int send_command(int sockfd, ftp_command command) {
    // Send the command to the server
    int sent = send(sockfd, command.command, strlen(command.command), 0);
    if (sent < 0) {
        perror("send");
        return -1;
    }

    // Send the argument to the server (if any)
    if (command.arg) {
        sent = send(sockfd, command.arg, strlen(command.arg), 0);
        if (sent < 0) {
            perror("send");
            return -1;
        }
    }

    // Send a newline character to terminate the command
    sent = send(sockfd, "\n", 1, 0);
    if (sent < 0) {
        perror("send");
        return -1;
    }

    return 0;
}

// Utility function to receive a response from the FTP server
int receive_response(int sockfd) {
    // Receive the response from the server
    char response[512];
    int received = recv(sockfd, response, sizeof(response), 0);
    if (received < 0) {
        perror("recv");
        return -1;
    }

    // Print the response to the console
    printf("%s", response);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the hostname and port number from the arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for communicating with the FTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Specify the address of the FTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(hostname, &server_addr.sin_addr);

    // Connect to the FTP server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the welcome message from the FTP server
    receive_response(sockfd);

    // Send the username and password to the FTP server
    ftp_command user_command = {"USER", "anonymous"};
    send_command(sockfd, user_command);
    receive_response(sockfd);
    ftp_command pass_command = {"PASS", "anonymous@example.com"};
    send_command(sockfd, pass_command);
    receive_response(sockfd);

    // Send the `ls` command to the FTP server
    ftp_command ls_command = {"LS", NULL};
    send_command(sockfd, ls_command);

    // Receive the output of the `ls` command from the FTP server
    receive_response(sockfd);

    // Close the connection to the FTP server
    close(sockfd);

    return 0;
}