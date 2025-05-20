//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

#define BUF_SIZE 100

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];

    memset(&server_addr, 0, sizeof(server_addr)); // Initialize server address to 0

    // Create socket
    if((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server_addr values
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("<POP3 Server IP Address>");
    server_addr.sin_port = htons(110); // POP3 port number

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Receive and print server response
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    // Send user authentication
    sprintf(buf, "USER <username>\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    // Send password authentication
    sprintf(buf, "PASS <password>\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    // Send command to list messages
    sprintf(buf, "LIST\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    // Send command to retrieve first message
    sprintf(buf, "RETR 1\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    // Send quit command and close socket
    sprintf(buf, "QUIT\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s\n", buf);
    close(sock);

    return 0;
}