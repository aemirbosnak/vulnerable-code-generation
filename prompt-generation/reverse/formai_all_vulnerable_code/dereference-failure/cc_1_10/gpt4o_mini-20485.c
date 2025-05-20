//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(const char *hostname) {
    struct sockaddr_in server_addr;
    int sockfd;

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    // Connecting to IMAP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        error("ERROR connecting");

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    ssize_t n;
    n = write(sockfd, command, strlen(command));
    if (n < 0) 
        error("ERROR writing to socket");
    
    // Adding a newline to signal end of command
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) 
        error("ERROR reading from socket");

    printf("%s\n", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", username, password);
    send_command(sockfd, command);
}

void list_mailboxes(int sockfd) {
    char command[] = "A002 LIST \"\" \"*\"\r\n";
    send_command(sockfd, command);
}

void fetch_email(int sockfd, const char *mailbox, int email_number) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A003 FETCH %d BODY[]\r\n", email_number);
    send_command(sockfd, command);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = create_socket(hostname);
    
    // Login to the IMAP server
    login(sockfd, username, password);

    // List mailboxes
    list_mailboxes(sockfd);

    // Fetch a sample email (for demonstration, we fetch the first email)
    fetch_email(sockfd, "INBOX", 1);

    // Close the socket
    close(sockfd);
    return 0;
}