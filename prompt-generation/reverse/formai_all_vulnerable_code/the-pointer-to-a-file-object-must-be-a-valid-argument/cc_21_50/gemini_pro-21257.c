//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_PORT 110
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    // Get the hostname and username from the command line.
    char *hostname = argv[1];
    char *username = argv[2];

    // Get the IP address of the POP3 server.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Could not get the IP address of the POP3 server.\n");
        exit(1);
    }

    // Create a socket to connect to the POP3 server.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Could not create a socket.\n");
        exit(1);
    }

    // Connect to the POP3 server.
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(POP3_PORT);
    sin.sin_addr = *(struct in_addr *) host->h_addr;
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        fprintf(stderr, "Could not connect to the POP3 server.\n");
        exit(1);
    }

    // Read the welcome message from the POP3 server.
    char line[MAX_LINE];
    if (fgets(line, MAX_LINE, sock) == NULL) {
        fprintf(stderr, "Could not read the welcome message from the POP3 server.\n");
        exit(1);
    }

    // Send the USER command to the POP3 server.
    sprintf(line, "USER %s\r\n", username);
    if (send(sock, line, strlen(line), 0) < 0) {
        fprintf(stderr, "Could not send the USER command to the POP3 server.\n");
        exit(1);
    }

    // Read the response from the POP3 server.
    if (fgets(line, MAX_LINE, sock) == NULL) {
        fprintf(stderr, "Could not read the response from the POP3 server.\n");
        exit(1);
    }

    // Check the response from the POP3 server.
    if (strncmp(line, "+OK", 3) != 0) {
        fprintf(stderr, "The POP3 server did not accept the USER command.\n");
        exit(1);
    }

    // Send the PASS command to the POP3 server.
    char password[MAX_LINE];
    printf("Enter your password: ");
    fgets(password, MAX_LINE, stdin);
    sprintf(line, "PASS %s\r\n", password);
    if (send(sock, line, strlen(line), 0) < 0) {
        fprintf(stderr, "Could not send the PASS command to the POP3 server.\n");
        exit(1);
    }

    // Read the response from the POP3 server.
    if (fgets(line, MAX_LINE, sock) == NULL) {
        fprintf(stderr, "Could not read the response from the POP3 server.\n");
        exit(1);
    }

    // Check the response from the POP3 server.
    if (strncmp(line, "+OK", 3) != 0) {
        fprintf(stderr, "The POP3 server did not accept the PASS command.\n");
        exit(1);
    }

    // Send the STAT command to the POP3 server.
    strcpy(line, "STAT\r\n");
    if (send(sock, line, strlen(line), 0) < 0) {
        fprintf(stderr, "Could not send the STAT command to the POP3 server.\n");
        exit(1);
    }

    // Read the response from the POP3 server.
    if (fgets(line, MAX_LINE, sock) == NULL) {
        fprintf(stderr, "Could not read the response from the POP3 server.\n");
        exit(1);
    }

    // Check the response from the POP3 server.
    if (strncmp(line, "+OK", 3) != 0) {
        fprintf(stderr, "The POP3 server did not accept the STAT command.\n");
        exit(1);
    }

    // Print the number of messages and the size of the mailbox.
    int num_messages, size_mailbox;
    sscanf(line, "+OK %d %d", &num_messages, &size_mailbox);
    printf("There are %d messages in the mailbox.\n", num_messages);
    printf("The size of the mailbox is %d bytes.\n", size_mailbox);

    // Send the LIST command to the POP3 server.
    strcpy(line, "LIST\r\n");
    if (send(sock, line, strlen(line), 0) < 0) {
        fprintf(stderr, "Could not send the LIST command to the POP3 server.\n");
        exit(1);
    }

    // Read the response from the POP3 server.
    int i;
    for (i = 0; i < num_messages; i++) {
        if (fgets(line, MAX_LINE, sock) == NULL) {
            fprintf(stderr, "Could not read the response from the POP3 server.\n");
            exit(1);
        }

        // Check the response from the POP3 server.
        if (strncmp(line, "+OK", 3) != 0) {
            fprintf(stderr, "The POP3 server did not accept the LIST command.\n");
            exit(1);
        }

        // Print the message number and the size of the message.
        int message_number, size_message;
        sscanf(line, "+OK %d %d", &message_number, &size_message);
        printf("Message %d is %d bytes.\n", message_number, size_message);
    }

    // Send the QUIT command to the POP3 server.
    strcpy(line, "QUIT\r\n");
    if (send(sock, line, strlen(line), 0) < 0) {
        fprintf(stderr, "Could not send the QUIT command to the POP3 server.\n");
        exit(1);
    }

    // Read the response from the POP3 server.
    if (fgets(line, MAX_LINE, sock) == NULL) {
        fprintf(stderr, "Could not read the response from the POP3 server.\n");
        exit(1);
    }

    // Check the response from the POP3 server.
    if (strncmp(line, "+OK", 3) != 0) {
        fprintf(stderr, "The POP3 server did not accept the QUIT command.\n");
        exit(1);
    }

    // Close the socket.
    close(sock);

    return 0;
}