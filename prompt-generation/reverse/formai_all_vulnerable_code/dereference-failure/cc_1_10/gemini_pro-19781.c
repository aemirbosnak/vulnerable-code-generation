//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_BUF_SIZE 1024

// Helper function to send data to the server
int send_data(int sockfd, char *data) {
    int nbytes = send(sockfd, data, strlen(data), 0);
    if (nbytes < 0) {
        perror("send");
        return -1;
    }
    return nbytes;
}

// Helper function to receive data from the server
int recv_data(int sockfd, char *buf, int buf_size) {
    int nbytes = recv(sockfd, buf, buf_size - 1, 0);
    if (nbytes < 0) {
        perror("recv");
        return -1;
    }
    buf[nbytes] = '\0';
    return nbytes;
}

int main(int argc, char *argv[]) {
    // Check if the user provided the necessary arguments
    if (argc < 3) {
        printf("Usage: %s <server_ip> <username> <password>\n", argv[0]);
        return 1;
    }

    // Get the server IP address, username, and password from the command line
    char *server_ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, server_ip, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return 1;
    }
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    // Receive the welcome message from the server
    char buf[MAX_BUF_SIZE];
    if (recv_data(sockfd, buf, MAX_BUF_SIZE) < 0) {
        close(sockfd);
        return 1;
    }
    printf("%s", buf);

    // Send the USER command
    char user_cmd[MAX_BUF_SIZE];
    snprintf(user_cmd, MAX_BUF_SIZE, "USER %s\r\n", username);
    if (send_data(sockfd, user_cmd) < 0) {
        close(sockfd);
        return 1;
    }

    // Receive the response to the USER command
    if (recv_data(sockfd, buf, MAX_BUF_SIZE) < 0) {
        close(sockfd);
        return 1;
    }
    printf("%s", buf);

    // Send the PASS command
    char pass_cmd[MAX_BUF_SIZE];
    snprintf(pass_cmd, MAX_BUF_SIZE, "PASS %s\r\n", password);
    if (send_data(sockfd, pass_cmd) < 0) {
        close(sockfd);
        return 1;
    }

    // Receive the response to the PASS command
    if (recv_data(sockfd, buf, MAX_BUF_SIZE) < 0) {
        close(sockfd);
        return 1;
    }
    printf("%s", buf);

   
    // Send the QUIT command
    char quit_cmd[] = "QUIT\r\n";
    if (send_data(sockfd, quit_cmd) < 0) {
        close(sockfd);
        return 1;
    }

    // Receive the response to the QUIT command
    if (recv_data(sockfd, buf, MAX_BUF_SIZE) < 0) {
        close(sockfd);
        return 1;
    }
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}