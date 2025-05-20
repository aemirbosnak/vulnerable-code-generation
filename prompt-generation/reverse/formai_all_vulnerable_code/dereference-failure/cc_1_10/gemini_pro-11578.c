//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
// Let's embark on an enchanting C adventure to build a POP3 client!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Constants for our POP3 adventure
#define POP3_PORT 110
#define MAX_BUFFER_SIZE 1024
#define USERNAME "[YOUR_USERNAME]"
#define PASSWORD "[YOUR_PASSWORD]"

// Our valiant POP3 client function
void pop3_client() {
    // Step 1: Embark on a journey to find the POP3 server's address
    struct hostent *server_info = gethostbyname("pop.example.com");
    if (server_info == NULL) {
        // Oh dear, we couldn't find the server!
        perror("gethostbyname");
        exit(1);
    }

    // Step 2: Forge a connection with the POP3 server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        // Alas, we couldn't establish a connection!
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(POP3_PORT);
    memcpy(&server_address.sin_addr, server_info->h_addr, server_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        // Oh no, we couldn't connect to the server!
        perror("connect");
        exit(1);
    }

    // Step 3: Initiate a graceful conversation with the POP3 server
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        // The server isn't responding!
        perror("recv");
        exit(1);
    }
    printf("%s", buffer); // Print the server's greeting

    // Step 4: Embark on the USER adventure
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "USER %s\r\n", USERNAME); // Prepare our USER command
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        // Oh no, we couldn't send the USER command!
        perror("send");
        exit(1);
    }
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        // The server didn't understand our USER command!
        perror("recv");
        exit(1);
    }
    printf("%s", buffer); // Print the server's response to USER

    // Step 5: Bravely venture forth with the PASS command
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "PASS %s\r\n", PASSWORD); // Prepare our PASS command
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        // Alas, we couldn't send the PASS command!
        perror("send");
        exit(1);
    }
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        // The server didn't accept our PASS command!
        perror("recv");
        exit(1);
    }
    printf("%s", buffer); // Print the server's response to PASS

    // Step 6: List the messages on the server
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "LIST\r\n"); // Prepare our LIST command
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        // We couldn't send the LIST command!
        perror("send");
        exit(1);
    }
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        // The server didn't respond to our LIST command!
        perror("recv");
        exit(1);
    }
    printf("%s", buffer); // Print the server's response to LIST

    // Step 7: Close our connection with the POP3 server gracefully
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "QUIT\r\n"); // Prepare our QUIT command
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        // We couldn't send the QUIT command!
        perror("send");
        exit(1);
    }
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        // The server didn't respond to our QUIT command!
        perror("recv");
        exit(1);
    }
    printf("%s", buffer); // Print the server's response to QUIT

    close(sockfd); // Bid farewell to the POP3 server
}

int main() {
    printf("Welcome, adventurer! Let's embark on a POP3 client adventure!\n");
    pop3_client(); // Start our POP3 client journey
    printf("Your adventure has come to an end. Farewell, brave traveler!\n");
    return 0;
}