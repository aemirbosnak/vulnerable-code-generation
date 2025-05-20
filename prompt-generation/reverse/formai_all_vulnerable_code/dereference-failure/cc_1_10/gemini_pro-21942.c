//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: asynchronous
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <openssl/ssl.h>

#define PORT 25

// The following function is used to handle the SIGPIPE signal, which is sent when a socket is closed while there is still data to be written.
void sigpipe_handler(int signo) {
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments was provided.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and message from the command line arguments.
    char *hostname = argv[1];
    char *message = argv[2];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Install the SIGPIPE handler.
    if (signal(SIGPIPE, sigpipe_handler) == SIG_ERR) {
        perror("signal");
        return EXIT_FAILURE;
    }

    // Get the IP address of the SMTP server.
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hostname);
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr = *(struct in_addr *)hostent->h_addr_list[0];
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command.
    char helo_cmd[256];
    snprintf(helo_cmd, sizeof(helo_cmd), "HELO %s\r\n", hostname);
    if (send(sockfd, helo_cmd, strlen(helo_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    char recv_buf[256];
    if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the SMTP server.
    printf("%s", recv_buf);

    // Send the MAIL FROM command.
    char mail_from_cmd[256];
    snprintf(mail_from_cmd, sizeof(mail_from_cmd), "MAIL FROM: <%s>\r\n", getenv("USER"));
    if (send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the SMTP server.
    printf("%s", recv_buf);

    // Send the RCPT TO command.
    char rcpt_to_cmd[256];
    snprintf(rcpt_to_cmd, sizeof(rcpt_to_cmd), "RCPT TO: <%s>\r\n", argv[1]);
    if (send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the SMTP server.
    printf("%s", recv_buf);

    // Send the DATA command.
    char data_cmd[256];
    snprintf(data_cmd, sizeof(data_cmd), "DATA\r\n");
    if (send(sockfd, data_cmd, strlen(data_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the SMTP server.
    printf("%s", recv_buf);

    // Send the message.
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the CRLF.
    char crlf[2];
    snprintf(crlf, sizeof(crlf), "\r\n");
    if (send(sockfd, crlf, strlen(crlf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the dot.
    char dot[2];
    snprintf(dot, sizeof(dot), ".");
    if (send(sockfd, dot, strlen(dot), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the SMTP server.
    printf("%s", recv_buf);

    // Send the QUIT command.
    char quit_cmd[256];
    snprintf(quit_cmd, sizeof(quit_cmd), "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}