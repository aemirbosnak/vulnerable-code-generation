//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Fetch a line from the server
char *get_line(int sock) {
    char *line = NULL;
    char c;
    int size = 0;

    while ((c = (char)recv(sock, &c, 1, 0)) > 0) {
        if (c == '\r') {
            if ((c = (char)recv(sock, &c, 1, 0)) != '\n') {
                return NULL;
            }
            break;
        }
        line = realloc(line, ++size);
        line[size - 1] = c;
    }

    return line;
}

// Send a command to the server
int send_command(int sock, char *command) {
    if (send(sock, command, strlen(command), 0) < 0) {
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;

    char *host, *user, *pass;

    if (argc < 4) {
        printf("Usage: %s <host> <user> <pass>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    user = argv[2];
    pass = argv[3];

    // Create a TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return 2;
    }

    // Connect to the POP3 server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(sock);
        return 3;
    }

    // Receive the welcome message
    char *line = get_line(sock);
    if (line == NULL) {
        perror("Error receiving welcome message");
        close(sock);
        return 4;
    }
    printf("%s\n", line);

    // Send the USER command
    if (send_command(sock, "USER ") < 0) {
        perror("Error sending USER command");
        close(sock);
        return 5;
    }
    if (send_command(sock, user) < 0) {
        perror("Error sending username");
        close(sock);
        return 5;
    }
    if (send_command(sock, "\r\n") < 0) {
        perror("Error sending line terminator");
        close(sock);
        return 5;
    }

    // Receive the response to the USER command
    line = get_line(sock);
    if (line == NULL) {
        perror("Error receiving response to USER command");
        close(sock);
        return 4;
    }
    printf("%s\n", line);

    // Send the PASS command
    if (send_command(sock, "PASS ") < 0) {
        perror("Error sending PASS command");
        close(sock);
        return 5;
    }
    if (send_command(sock, pass) < 0) {
        perror("Error sending password");
        close(sock);
        return 5;
    }
    if (send_command(sock, "\r\n") < 0) {
        perror("Error sending line terminator");
        close(sock);
        return 5;
    }

    // Receive the response to the PASS command
    line = get_line(sock);
    if (line == NULL) {
        perror("Error receiving response to PASS command");
        close(sock);
        return 4;
    }
    printf("%s\n", line);

    // Send the STAT command
    if (send_command(sock, "STAT\r\n") < 0) {
        perror("Error sending STAT command");
        close(sock);
        return 5;
    }

    // Receive the response to the STAT command
    line = get_line(sock);
    if (line == NULL) {
        perror("Error receiving response to STAT command");
        close(sock);
        return 4;
    }
    printf("%s\n", line);

    // Send the LIST command
    if (send_command(sock, "LIST\r\n") < 0) {
        perror("Error sending LIST command");
        close(sock);
        return 5;
    }

    // Receive the response to the LIST command
    while ((line = get_line(sock)) != NULL) {
        printf("%s\n", line);
    }

    // Send the RETR command
    if (send_command(sock, "RETR 1\r\n") < 0) {
        perror("Error sending RETR command");
        close(sock);
        return 5;
    }

    // Receive the response to the RETR command
    while ((line = get_line(sock)) != NULL) {
        printf("%s\n", line);
    }

    // Send the DELE command
    if (send_command(sock, "DELE 1\r\n") < 0) {
        perror("Error sending DELE command");
        close(sock);
        return 5;
    }

    // Receive the response to the DELE command
    line = get_line(sock);
    if (line == NULL) {
        perror("Error receiving response to DELE command");
        close(sock);
        return 4;
    }
    printf("%s\n", line);

    // Send the QUIT command
    if (send_command(sock, "QUIT\r\n") < 0) {
        perror("Error sending QUIT command");
        close(sock);
        return 5;
    }

    // Close the socket
    close(sock);

    return 0;
}