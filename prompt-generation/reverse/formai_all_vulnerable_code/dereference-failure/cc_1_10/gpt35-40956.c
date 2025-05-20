//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE  1024
#define SERVER_PORT  993 // IMAP SSL port
#define SERVER_NAME  "mail.example.com"
#define LOGIN_NAME   "username"
#define LOGIN_PASS   "password"

int communicate(int sockfd, char* buffer, char* msg) {
    int bytes_sent = send(sockfd, msg, strlen(msg), 0);
    if (bytes_sent < 0) {
        perror("send");
        return 0;
    }
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        return 0;
    }
    buffer[bytes_received] = '\0';
    return 1;
}

int main() {
    // 1. Create a socket instance
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
  
    // 2. Establish a connection with the server
    struct hostent* server = gethostbyname(SERVER_NAME);
    if (!server) {
        perror("gethostbyname");
        exit(1);
    }
  
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *(struct in_addr*)server->h_addr;
    server_addr.sin_port = htons(SERVER_PORT);
  
    if (connect(sockfd, (struct sockaddr*)&server_addr, 
        sizeof(struct sockaddr_in)) < 0) {
            perror("connect");
            exit(1);
    }

    // 3. Read server greeting message
    char buffer[BUFFER_SIZE];
    if (!communicate(sockfd, buffer, "")) {
        exit(1);
    }
    printf("%s", buffer);
  
    // 4. Send login command
    char login_msg[BUFFER_SIZE];
    sprintf(login_msg, "LOGIN %s %s\r\n", LOGIN_NAME, LOGIN_PASS);
    if (!communicate(sockfd, buffer, login_msg)) {
        exit(1);
    }

    // 5. Read server response to login command
    printf("%s", buffer);
  
    // 6. Send select command to choose inbox folder
    char select_msg[] = "SELECT INBOX\r\n";
    if (!communicate(sockfd, buffer, select_msg)) {
        exit(1);
    }
  
    // 7. Read server response to select command
    printf("%s", buffer);
  
    // 8. Send fetch command to retrieve message(s)
    char fetch_msg[] = "FETCH 1 BODY[TEXT]\r\n";
    if (!communicate(sockfd, buffer, fetch_msg)) {
        exit(1);
    }
  
    // 9. Read server response to fetch command
    printf("%s", buffer);
  
    // 10. Close connection
    if (close(sockfd) < 0) {
        perror("close");
        exit(1);
    }
  
    return 0;
}