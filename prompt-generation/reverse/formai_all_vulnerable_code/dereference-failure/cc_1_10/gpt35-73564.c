//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
// Scene: A mailbox on a street corner in Verona
// Characters: Romeo and Juliet
// Theme: Building a POP3 email client in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

// Function to print opening monologue
void printOpeningMonologue()
{
    printf("Two households, both alike in dignity,\n");
    printf("In fair Verona, where we lay our scene,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n");
    printf("Enter our hero, Romeo, seeking love,\n");
    printf("And his love, Juliet, seeking freedom,\n");
    printf("But neither know the power of technology,\n");
    printf("And the POP3 client they will soon build.\n\n");
}

int main(int argc, char *argv[])
{
    printOpeningMonologue();

    // Check for correct arguments
    if (argc != 3) {
        printf("Usage: %s <hostname> <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket!\n");
        exit(EXIT_FAILURE);
    }

    // Get the IP address from the hostname
    struct hostent *he;
    if ((he = gethostbyname(argv[1])) == NULL) {
        printf("Error: Could not get IP address from hostname!\n");
        exit(EXIT_FAILURE);
    }

    // Set the socket address information
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: Could not connect to server!\n");
        exit(EXIT_FAILURE);
    }

    // Receive message from server
    char buffer[MAX_BUFFER_SIZE];
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0) == -1) {
        printf("Error: Could not receive message from server!\n");
        exit(EXIT_FAILURE);
    }
    buffer[MAX_BUFFER_SIZE - 1] = '\0';
    printf("%s", buffer);

    // Send username to server
    char username[MAX_BUFFER_SIZE];
    printf("Enter username: ");
    fgets(username, MAX_BUFFER_SIZE, stdin);
    send(sockfd, username, strlen(username), 0);

    // Receive message from server
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0) == -1) {
        printf("Error: Could not receive message from server!\n");
        exit(EXIT_FAILURE);
    }
    buffer[MAX_BUFFER_SIZE - 1] = '\0';
    printf("%s", buffer);

    // Send password to server
    char password[MAX_BUFFER_SIZE];
    printf("Enter password: ");
    fgets(password, MAX_BUFFER_SIZE, stdin);
    send(sockfd, password, strlen(password), 0);

    // Receive message from server
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0) == -1) {
        printf("Error: Could not receive message from server!\n");
        exit(EXIT_FAILURE);
    }
    buffer[MAX_BUFFER_SIZE - 1] = '\0';
    printf("%s", buffer);

    // Send quit command to server
    char quit_command[] = "QUIT\r\n";
    send(sockfd, quit_command, strlen(quit_command), 0);

    // Receive message from server
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0) == -1) {
        printf("Error: Could not receive message from server!\n");
        exit(EXIT_FAILURE);
    }
    buffer[MAX_BUFFER_SIZE - 1] = '\0';
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}