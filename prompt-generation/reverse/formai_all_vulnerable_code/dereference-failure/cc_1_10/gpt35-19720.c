//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        error("Usage: ./imap_client <server_ip> <port>");
    }

    // Set up socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Set up server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    // Get banner
    char banner[MAX_BUFFER_SIZE];
    memset(&banner, 0, sizeof(banner));
    if (recv(sockfd, banner, sizeof(banner), 0) < 0) {
        error("Error receiving banner");
    }
    printf("%s", banner);

    // Send login command
    char username[MAX_BUFFER_SIZE];
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;
    char login_cmd[MAX_BUFFER_SIZE];
    sprintf(login_cmd, "a001 LOGIN %s ", username);
    if (send(sockfd, login_cmd, strlen(login_cmd), 0) < 0) {
        error("Error sending login command");
    }

    // Get login response
    char login_resp[MAX_BUFFER_SIZE];
    memset(&login_resp, 0, sizeof(login_resp));
    if (recv(sockfd, login_resp, sizeof(login_resp), 0) < 0) {
        error("Error receiving login response");
    }
    printf("%s", login_resp);

    // Send password command
    char password[MAX_BUFFER_SIZE];
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;
    char password_cmd[MAX_BUFFER_SIZE];
    sprintf(password_cmd, "a002 %s\r\n", password);
    if (send(sockfd, password_cmd, strlen(password_cmd), 0) < 0) {
        error("Error sending password command");
    }

    // Get password response
    char password_resp[MAX_BUFFER_SIZE];
    memset(&password_resp, 0, sizeof(password_resp));
    if (recv(sockfd, password_resp, sizeof(password_resp), 0) < 0) {
        error("Error receiving password response");
    }
    printf("%s", password_resp);

    // Send select command
    char select_cmd[MAX_BUFFER_SIZE];
    sprintf(select_cmd, "a003 SELECT INBOX\r\n");
    if (send(sockfd, select_cmd, strlen(select_cmd), 0) < 0) {
        error("Error sending select command");
    }

    // Get select response
    char select_resp[MAX_BUFFER_SIZE];
    memset(&select_resp, 0, sizeof(select_resp));
    if (recv(sockfd, select_resp, sizeof(select_resp), 0) < 0) {
        error("Error receiving select response");
    }
    printf("%s", select_resp);

    // Send logout command
    char logout_cmd[MAX_BUFFER_SIZE];
    sprintf(logout_cmd, "a004 LOGOUT\r\n");
    if (send(sockfd, logout_cmd, strlen(logout_cmd), 0) < 0) {
        error("Error sending logout command");
    }

    // Get logout response
    char logout_resp[MAX_BUFFER_SIZE];
    memset(&logout_resp, 0, sizeof(logout_resp));
    if (recv(sockfd, logout_resp, sizeof(logout_resp), 0) < 0) {
        error("Error receiving logout response");
    }
    printf("%s", logout_resp);

    // Close socket
    close(sockfd);

    return 0;
}