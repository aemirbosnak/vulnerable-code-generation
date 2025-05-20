//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT 993

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void converse_with_imap_server(int sockfd) {
    char buffer[BUF_SIZE];
    char *user = "funnyuser@funnydomain.com"; // Don't you ever laugh at my email!
    char *pass = "supersecrectpassword";      // I hope no hackers read this!

    // Say Hello to the server
    snprintf(buffer, BUF_SIZE, "* OK IMAP ready for login!\n");
    write(sockfd, buffer, strlen(buffer));
  
    read(sockfd, buffer, BUF_SIZE);
    printf("Server says: %s", buffer);

    // Logging in
    snprintf(buffer, BUF_SIZE, "A001 LOGIN %s %s\r\n", user, pass);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUF_SIZE);
    printf("Server responds to LOGIN: %s", buffer);

    // Listing mailboxes
    snprintf(buffer, BUF_SIZE, "A002 LIST \"\" *\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUF_SIZE);
    printf("Available mailboxes: %s", buffer);

    // Fetching emails
    snprintf(buffer, BUF_SIZE, "A003 SELECT INBOX\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUF_SIZE);
    printf("Selected INBOX: %s", buffer);

    // Goodbye
    snprintf(buffer, BUF_SIZE, "A004 LOGOUT\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUF_SIZE);
    printf("Server says bye: %s\n", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
  
    // Funnily initiate the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Socket creation failed, are you sure your computer is still functional?");
    }

    // Fun with hostnames
    host = gethostbyname("imap.funnyserver.com"); // A funny server!
    if (host == NULL) {
        die("Could not find the funny server, are you sure it's not on vacation?");
    }

    // Set up the funny server address structure
    memset(&server_addr, 0, sizeof(server_addr)); 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(PORT); 
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connection attempt with a bit of humor
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection failed, maybe they're out of coffee!");
    }

    printf("Giggles on the way... Connecting to the IMAP server!\n");
    converse_with_imap_server(sockfd);

    // Close the socket and prance away
    close(sockfd);
    printf("Disconnected from the crazy server, but not before a good chuckle!\n");
    return 0;
}