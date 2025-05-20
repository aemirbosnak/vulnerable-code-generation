//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
// Dynamic FTP client example in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to establish a TCP connection to the FTP server
int connect_to_server(char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sockfd;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    return sockfd;
}

// Function to send a command to the FTP server
void send_command(int sockfd, char *command) {
    // Send the command to the server
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read the response from the server
    char response[512];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Print the response to the console
    printf("%s", response);
}

// Function to retrieve a file from the FTP server
void get_file(int sockfd, char *filename) {
    // Send the RETR command to the server
    char command[512];
    sprintf(command, "RETR %s\r\n", filename);
    send_command(sockfd, command);

    // Open a file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    // Receive the file data from the server
    char buffer[512];
    while (recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
        fwrite(buffer, 1, strlen(buffer), fp);
    }

    // Close the file
    fclose(fp);
}

// Function to list the files on the FTP server
void list_files(int sockfd) {
    // Send the LIST command to the server
    send_command(sockfd, "LIST\r\n");

    // Read the response from the server
    char response[512];
    while (recv(sockfd, response, sizeof(response), 0) > 0) {
        // Print the response to the console
        printf("%s", response);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <hostname> <port> <command>\n", argv[0]);
        exit(1);
    }

    // Get the hostname, port, and command from the command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *command = argv[3];

    // Connect to the FTP server
    int sockfd = connect_to_server(hostname, port);

    // Send the command to the server
    send_command(sockfd, command);

    // Process the command
    if (strcmp(command, "LIST") == 0) {
        // List the files on the FTP server
        list_files(sockfd);
    } else if (strcmp(command, "GET") == 0) {
        // Retrieve a file from the FTP server
        get_file(sockfd, argv[4]);
    } else {
        // Send an error message to the console
        printf("Invalid command\n");
    }

    // Close the connection to the FTP server
    close(sockfd);

    return 0;
}