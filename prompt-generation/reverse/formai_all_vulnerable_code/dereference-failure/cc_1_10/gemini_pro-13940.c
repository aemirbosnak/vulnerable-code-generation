//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 25

int main(int argc, char *argv[]) {
    // Parse command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <recipient> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *recipient = argv[1];
    const char *message = argv[2];

    // Resolve recipient's hostname
    struct hostent *host = gethostbyname(recipient);
    if (!host) {
        fprintf(stderr, "Failed to resolve hostname %s: %s\n", recipient, strerror(errno));
        return EXIT_FAILURE;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(DEFAULT_PORT);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Failed to connect to server: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the HELO command
    if (send_command(sock, "HELO localhost\r\n") != 0) {
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    char mail_from[1024];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM: <%s>\r\n", getlogin());
    if (send_command(sock, mail_from) != 0) {
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    char rcpt_to[1024];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO: <%s>\r\n", recipient);
    if (send_command(sock, rcpt_to) != 0) {
        return EXIT_FAILURE;
    }

    // Send the DATA command
    if (send_command(sock, "DATA\r\n") != 0) {
        return EXIT_FAILURE;
    }

    // Send the message body
    if (send_data(sock, message) != 0) {
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    if (send_command(sock, "QUIT\r\n") != 0) {
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}

int send_command(int sock, const char *command) {
    if (send(sock, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Failed to send command %s: %s\n", command, strerror(errno));
        return -1;
    }

    // Read the response from the server
    char response[1024];
    int n = recv(sock, response, sizeof(response), 0);
    if (n < 0) {
        fprintf(stderr, "Failed to read response from server: %s\n", strerror(errno));
        return -1;
    }

    // Check the response code
    if (response[0] != '2') {
        fprintf(stderr, "Server returned error code %s\n", response);
        return -1;
    }

    return 0;
}

int send_data(int sock, const char *data) {
    // Send the data to the server
    if (send(sock, data, strlen(data), 0) < 0) {
        fprintf(stderr, "Failed to send data: %s\n", strerror(errno));
        return -1;
    }

    // Send a final period to indicate the end of the message
    if (send(sock, "\r\n.\r\n", 5, 0) < 0) {
        fprintf(stderr, "Failed to send final period: %s\n", strerror(errno));
        return -1;
    }

    return 0;
}