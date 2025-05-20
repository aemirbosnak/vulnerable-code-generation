//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void die(char *s) {
    perror(s);
    exit(1);
}

void pop3_command(int sockfd, const char *cmd, char *response) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);

    ssize_t bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        die("recv");
    }
    response[bytes_received] = '\0';
    printf("Server Response: %s", response);
}

void authenticate(int sockfd, const char *user, const char *pass) {
    char response[BUFFER_SIZE];

    // Send USER command
    char user_cmd[BUFFER_SIZE];
    snprintf(user_cmd, sizeof(user_cmd), "USER %s", user);
    pop3_command(sockfd, user_cmd, response);

    // Send PASS command
    char pass_cmd[BUFFER_SIZE];
    snprintf(pass_cmd, sizeof(pass_cmd), "PASS %s", pass);
    pop3_command(sockfd, pass_cmd, response);
}

void list_messages(int sockfd) {
    char response[BUFFER_SIZE];
    pop3_command(sockfd, "LIST", response);
}

void read_message(int sockfd, int msg_number) {
    char response[BUFFER_SIZE];
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "RETR %d", msg_number);
    pop3_command(sockfd, cmd, response);
}

void delete_message(int sockfd, int msg_number) {
    char response[BUFFER_SIZE];
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "DELE %d", msg_number);
    pop3_command(sockfd, cmd, response);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char response[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("socket creation failed");
    }

    // Setup server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to your POP3 server's IP if needed

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        die("connection to server failed");
    }

    // Read the server's greeting
    recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[BUFFER_SIZE - 1] = '\0';
    printf("Server Greeting: %s", response);

    // Authenticate
    char user[50], pass[50];
    printf("Enter your username: ");
    fgets(user, sizeof(user), stdin);
    strtok(user, "\n"); // Remove newline
    
    printf("Enter your password: ");
    fgets(pass, sizeof(pass), stdin);
    strtok(pass, "\n"); // Remove newline
    
    authenticate(sockfd, user, pass);

    // List messages
    list_messages(sockfd);

    // Read a message
    int msg_number;
    printf("Enter message number to read: ");
    scanf("%d", &msg_number);
    read_message(sockfd, msg_number);

    // Delete a message
    printf("Do you want to delete message %d (1 for yes, 0 for no)? ", msg_number);
    int delete_choice;
    scanf("%d", &delete_choice);
    if (delete_choice) {
        delete_message(sockfd, msg_number);
    }

    // Quit the session
    pop3_command(sockfd, "QUIT", response);
    
    // Close the socket
    close(sockfd);
    return 0;
}