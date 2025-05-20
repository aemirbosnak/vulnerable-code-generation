//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT          993
#define BUFFER_SIZE   512
#define SERVER_SIZE   100
#define EMAIL_SIZE    100
#define PASSWORD_SIZE 100

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *servername) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    server = gethostbyname(servername);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return -1;
    }
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
          (char *)&server_addr.sin_addr.s_addr,
          server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);  // IMAP protocol requires CRLF after commands
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    while ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break; // Stop reading once we received a complete response
        }
    }
}

void login(int sockfd, const char *email, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, BUFFER_SIZE, "A001 LOGIN %s %s", email, password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    receive_response(sockfd);
}

void fetch_email(int sockfd, const char *mailbox, int message_number) {
    char command[BUFFER_SIZE];

    snprintf(command, BUFFER_SIZE, "A003 FETCH %d BODY[]", message_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void cleanup(int sockfd) {
    close(sockfd);
}

int main() {
    char servername[SERVER_SIZE];
    char email[EMAIL_SIZE];
    char password[PASSWORD_SIZE];

    printf("Enter IMAP server (e.g., imap.gmail.com): ");
    scanf("%s", servername);

    printf("Enter your email address: ");
    scanf("%s", email);

    printf("Enter your email password: ");
    scanf("%s", password);

    int sockfd = connect_to_server(servername);
    if (sockfd < 0) {
        return 1;
    }

    // Log in to the IMAP server
    login(sockfd, email, password);

    // List mailboxes
    printf("\nMailboxes:\n");
    list_mailboxes(sockfd);

    // Fetch a specific email (example uses the first email)
    printf("\nFetching email 1 from Inbox...\n");
    fetch_email(sockfd, "INBOX", 1);

    // Clean up and close the connection
    cleanup(sockfd);

    return 0;
}