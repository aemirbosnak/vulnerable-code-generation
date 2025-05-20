//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int sockfd;

void error(const char *msg) {
    perror(msg);
    exit(0);
}

void send_command(const char *cmd) {
    int n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        error("Error writing to socket");
    }
}

void read_response() {
    char buffer[BUFFER_SIZE];
    int n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("Error reading from socket");
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        return 0;
    }

    int portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting");
    }

    read_response(); // Read server banner

    send_command("a001 LOGIN username password\n"); // Replace username and password with yours
    read_response();

    send_command("a002 LIST \"\" \"*\"\n"); // List all mailboxes
    read_response();

    send_command("a003 EXAMINE INBOX\n"); // Examine the INBOX
    read_response();

    send_command("a004 FETCH 1 BODY[]\n"); // Fetch the first message
    read_response();

    send_command("a005 STORE 1 +FLAGS \\Seen\n"); // Mark message as read
    read_response();

    send_command("a006 LOGOUT\n"); // Logout
    read_response();

    close(sockfd);

    return 0;
}