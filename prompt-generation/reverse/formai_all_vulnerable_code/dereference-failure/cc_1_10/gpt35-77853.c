//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

// Function to create a socket connection
int openSocket(const char *host, const char *service) {
    struct addrinfo hints, *res, *p;
    int sock_fd;

    // Build the hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get the address information
    if ((getaddrinfo(host, service, &hints, &res)) != 0) {
        perror("Unable to get address information");
        exit(EXIT_FAILURE);
    }

    // Loop through the results and connect to the first one possible
    for (p = res; p != NULL; p = p->ai_next) {
        if ((sock_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
            continue;
        if (connect(sock_fd, p->ai_addr, p->ai_addrlen) == 0)
            break;
        close(sock_fd);
    }

    // Free the addrinfo list
    freeaddrinfo(res);

    // Make sure we connected to something
    if (p == NULL) {
        perror("Unable to connect to host");
        exit(EXIT_FAILURE);
    }

    return sock_fd;
}

// Function to read response from server
void readResponse(int sock_fd) {
    int n = 0;
    char buf[BUF_SIZE];

    // Loop through and read the response
    while ((n = read(sock_fd, buf, BUF_SIZE-1)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
        if (buf[strlen(buf)-1] == '\n')
            break;
    }

    // Make sure we read something
    if (n < 0) {
        perror("Unable to read data from server");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main(int argc, char **argv) {
    int sock_fd;
    char *host, *service, buffer[BUF_SIZE];
    char from[BUF_SIZE], to[BUF_SIZE], subject[BUF_SIZE], message[BUF_SIZE*10];

    // Make sure we have enough arguments
    if (argc < 4) {
        printf("Usage: %s [host] [port] [email address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Set up our variables
    host = argv[1];
    service = argv[2];
    sprintf(from, "MAIL FROM: <%s>\n", argv[3]);
    printf("From: %s", from);
    printf("To: ");
    fgets(to, BUF_SIZE-1, stdin);
    printf("Subject: ");
    fgets(subject, BUF_SIZE-1, stdin);
    printf("Message: ");
    fgets(message, BUF_SIZE*10-1, stdin);

    // Open the socket connection
    sock_fd = openSocket(host, service);

    // Read the initial response from the server
    readResponse(sock_fd);

    // Send the HELO command
    sprintf(buffer, "HELO %s\n", host);
    write(sock_fd, buffer, strlen(buffer));
    readResponse(sock_fd);

    // Send the MAIL command
    write(sock_fd, from, strlen(from));
    readResponse(sock_fd);

    // Send the RCPT command
    sprintf(buffer, "RCPT TO:<%s>\n", to);
    write(sock_fd, buffer, strlen(buffer));
    readResponse(sock_fd);

    // Send the DATA command
    write(sock_fd, "DATA\n", 5);
    readResponse(sock_fd);

    // Send the message headers
    sprintf(buffer, "From: <%s>\r\n", argv[3]);
    write(sock_fd, buffer, strlen(buffer));
    sprintf(buffer, "To: <%s>\r\n", to);
    write(sock_fd, buffer, strlen(buffer));
    sprintf(buffer, "Subject: %s\r\n", subject);
    write(sock_fd, buffer, strlen(buffer));

    // Send the message body
    write(sock_fd, "\r\n", 2);
    write(sock_fd, message, strlen(message));

    // Send the end-of-message marker
    write(sock_fd, "\r\n.\r\n", 5);
    readResponse(sock_fd);

    // Send the QUIT command
    write(sock_fd, "QUIT\n", 5);
    readResponse(sock_fd);

    // Close the socket
    close(sock_fd);

    return EXIT_SUCCESS;
}