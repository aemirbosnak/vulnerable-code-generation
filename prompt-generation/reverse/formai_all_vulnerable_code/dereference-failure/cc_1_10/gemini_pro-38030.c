//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_PATH_SIZE 256

void print_usage(char *program_name) {
    printf("Usage: %s <hostname> <port> <username> <password>\n", program_name);
    printf("Example: %s example.com 21 username password\n", program_name);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Parse command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the FTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the welcome message from the FTP server
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    buffer[bytes_received] = '\0';

    // Print the welcome message to the console
    printf("%s\n", buffer);

    // Send the username to the FTP server
    char user_command[MAX_BUFFER_SIZE];
    snprintf(user_command, MAX_BUFFER_SIZE, "USER %s\r\n", username);
    if (send(sockfd, user_command, strlen(user_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response from the FTP server
    bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    buffer[bytes_received] = '\0';

    // Print the response to the console
    printf("%s\n", buffer);

    // Send the password to the FTP server
    char pass_command[MAX_BUFFER_SIZE];
    snprintf(pass_command, MAX_BUFFER_SIZE, "PASS %s\r\n", password);
    if (send(sockfd, pass_command, strlen(pass_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response from the FTP server
    bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    buffer[bytes_received] = '\0';

    // Print the response to the console
    printf("%s\n", buffer);

    // Enter the FTP command loop
    while (1) {
        // Prompt the user for a command
        printf("> ");
        char command[MAX_BUFFER_SIZE];
        fgets(command, MAX_BUFFER_SIZE, stdin);

        // Remove the newline character from the command
        command[strlen(command) - 1] = '\0';

        // Send the command to the FTP server
        if (send(sockfd, command, strlen(command), 0) == -1) {
            perror("send");
            return EXIT_FAILURE;
        }

        // Read the response from the FTP server
        bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
        if (bytes_received == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }
        buffer[bytes_received] = '\0';

        // Print the response to the console
        printf("%s\n", buffer);

        // Check if the user entered the QUIT command
        if (strcmp(command, "QUIT") == 0) {
            break;
        }
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}