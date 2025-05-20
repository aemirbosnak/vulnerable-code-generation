//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int connect_to_server(char* server_name, char* port_number) {
    struct addrinfo hints, *serv_info, *p;
    int sockfd, status;

    // Clear the hints struct
    memset(&hints, 0, sizeof hints);

    // Set up the hints struct
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get the information about the server
    if ((status = getaddrinfo(server_name, port_number, &hints, &serv_info)) != 0) {
        fprintf(stderr, "Error: Failed to get address information: %s\n", gai_strerror(status));
        exit(1);
    }

    // Loop through the results and connect to the first working address
    for (p = serv_info; p != NULL; p = p->ai_next) {
        // Create the socket
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        // Check if the socket was created successfully
        if (sockfd == -1) {
            perror("Error: Could not create socket");
            continue;
        }

        // Connect to the server
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("Error: Could not connect to server");
            continue;
        }

        // If we made it here, we successfully connected to the server
        break;
    }

    // Make sure we connected to the server
    if (p == NULL) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        exit(1);
    }

    // Free the serv_info struct
    freeaddrinfo(serv_info);

    // Return the socket file descriptor
    return sockfd;
}

void send_command(int sockfd, char* command) {
    char buffer[BUFFER_SIZE];

    // Send the command to the server
    send(sockfd, command, strlen(command), 0);

    // Receive the server's response
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Print the server's response
    printf("Response: %s\n", buffer);
}

int main(int argc, char** argv) {
    // Check if the correct number of arguments were supplied
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server address> <port number>\n", argv[0]);
        exit(1);
    }

    // Get the server address and port number from the command line arguments
    char* server_address = argv[1];
    char* port_number = argv[2];

    // Connect to the server
    int sockfd = connect_to_server(server_address, port_number);

    // Send a HELO command to the server
    send_command(sockfd, "HELO paranoid.com\r\n");

    // Send a MAIL FROM command to the server
    send_command(sockfd, "MAIL FROM: <john.doe@paranoid.com>\r\n");

    // Send a RCPT TO command to the server
    send_command(sockfd, "RCPT TO: <jane.smith@paranoid.com>\r\n");

    // Send a DATA command to the server
    send_command(sockfd, "DATA\r\n");

    // Send the email contents to the server
    send_command(sockfd, "Subject: Confidential Information\r\nThis email contains highly confidential information.\r\n.\r\n");

    // Send a QUIT command to the server
    send_command(sockfd, "QUIT\r\n");

    // Close the socket
    close(sockfd);

    return 0;
}