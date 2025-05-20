//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

// Custom email header structure
typedef struct {
    char *from;
    char *to;
    char *subject;
    char *body;
} email_header;

// Custom email client function
void send_email(char *server, char *port, email_header *header) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was created successfully
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get the server's IP address
    struct hostent *he = gethostbyname(server);

    // Check if the server's IP address was found
    if (he == NULL) {
        perror("Error getting server's IP address");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr = *(struct in_addr *)he->h_addr_list[0];

    // Check if the connection was successful
    int rc = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Check if the connection was successful
    if (rc < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send the email header
    char buffer[BUFSIZE];

    // Construct the header
    sprintf(buffer, "MAIL FROM: <%s>\r\n", header->from);
    send(sockfd, buffer, strlen(buffer), 0);

    // Construct the header
    sprintf(buffer, "RCPT TO: <%s>\r\n", header->to);
    send(sockfd, buffer, strlen(buffer), 0);

    // Construct the header
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Construct the header
    sprintf(buffer, "From: %s\r\n", header->from);
    send(sockfd, buffer, strlen(buffer), 0);

    // Construct the header
    sprintf(buffer, "To: %s\r\n", header->to);
    send(sockfd, buffer, strlen(buffer), 0);

    // Construct the header
    sprintf(buffer, "Subject: %s\r\n", header->subject);
    send(sockfd, buffer, strlen(buffer), 0);

    // Construct the header
    sprintf(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Construct the header
    sprintf(buffer, "%s\r\n", header->body);
    send(sockfd, buffer, strlen(buffer), 0);

    // Construct the header
    sprintf(buffer, ".\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Close the socket
    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the required arguments are provided
    if (argc != 5) {
        printf("Usage: %s <server> <port> <from> <to>\n", argv[0]);
        exit(1);
    }

    // Check if the server's IP address is valid
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        printf("Invalid server address\n");
        exit(1);
    }

    // Create an email header
    email_header header;
    header.from = argv[3];
    header.to = argv[4];
    header.subject = "Test email";
    header.body = "This is a test email from the custom email client.";

    // Send the email
    send_email(argv[1], argv[2], &header);

    // Exit the program
    return 0;
}