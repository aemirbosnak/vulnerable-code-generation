//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Take a deep breath and let's get started with our IMAP journey!
int main() {

    // First, let's establish a connection to the IMAP server. Like a good handshake!
    int sockfd, port = 993; // Who doesn't like port 993?
    struct hostent *server; // This will hold the server's address information
    char *hostname = "imap.example.com"; // Replace with your server's hostname

    if((server = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Time to create a socket! This is our gateway to IMAP land.
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Now, let's connect to the server. Cross your fingers!
    struct sockaddr_in server_addr;
    memset((char *)&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Hurray! Connection established. Let's say hello to the server.
    char buffer[1024]; // A buffer to store our messages in
    recv(sockfd, buffer, sizeof(buffer), 0); // Let's see what the server says
    printf("%s", buffer); // Print it out, let's chat!

    // Now, we can start sending commands to retrieve our precious emails! Let's list those mailboxes!
    const char *list_command = "LIST \"\"\n"; // Our command to list mailboxes
    send(sockfd, list_command, strlen(list_command), 0); // Send the command to the server

    // Time to receive the list of mailboxes. Patience, young grasshopper!
    memset(buffer, '\0', sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0); // Receive the server's response
    printf("%s", buffer); // Let's see what mailboxes we have

    // Let's pick a mailbox and retrieve its messages. We're getting closer to our emails!
    const char *select_command = "SELECT \"Inbox\"\n"; // Our command to select the Inbox
    send(sockfd, select_command, strlen(select_command), 0); // Send the command to the server

    // Now, we wait for the server to confirm our selection.
    memset(buffer, '\0', sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0); // Let's hear from the server
    printf("%s", buffer); // Print the server's response

    // Ready to fetch the messages from our chosen mailbox! Let's do this!
    const char *fetch_command = "FETCH 1:5 BODY.PEEK[TEXT]\n"; // Fetching messages 1 to 5
    send(sockfd, fetch_command, strlen(fetch_command), 0); // Send the command to the server

    // Time to receive the messages. This is where the magic happens!
    memset(buffer, '\0', sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0); // Receive the server's response

    // Finally, let's print the messages and admire our hard work!
    printf("%s", buffer); // Display the messages in all their glory

    // Time to bid farewell to the server.
    const char *quit_command = "QUIT\n"; // Our graceful goodbye
    send(sockfd, quit_command, strlen(quit_command), 0); // Send the farewell message

    close(sockfd); // Close the socket, we're done here!

    return EXIT_SUCCESS; // Mission accomplished, let's celebrate!
}