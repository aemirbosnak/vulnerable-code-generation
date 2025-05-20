//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

/* Function to connect to the POP3 server */
int connect_to_server(char *hostname, char *port) {
    int sockfd;
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; 
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(hostname, port, &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    connect(sockfd, res->ai_addr, res->ai_addrlen);

    freeaddrinfo(res);
    return sockfd;
}

/* Function to read data from the POP3 server */
int read_from_server(int sockfd, char *buf, int len) {
    int bytes_received = 0;
    while (bytes_received < len) {
        int ret = read(sockfd, buf + bytes_received, len - bytes_received);
        if (ret == -1) {
            perror("Error reading data from server");
            exit(1);
        } else if (ret == 0) {
            break;
        }
        bytes_received += ret;
    }
    return bytes_received;
}

/* Function to send data to the POP3 server */
void send_to_server(int sockfd, char *buf) {
    int len = strlen(buf);
    int bytes_sent = 0;
    while (bytes_sent < len) {
        int ret = write(sockfd, buf + bytes_sent, len - bytes_sent);
        if (ret == -1) {
            perror("Error sending data to server");
            exit(1);
        }
        bytes_sent += ret;
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    /* Connect to the POP3 server */
    int sockfd = connect_to_server("pop3.server.com", "110");

    /* Read greeting message from server */
    char buf[1024];
    read_from_server(sockfd, buf, 1024);
    printf("%s\n", buf); // Should print "+OK POP3 server ready"

    /* Send user credentials to the server */
    char user_msg[256] = "USER username\n";
    char pass_msg[256] = "PASS password\n";
    send_to_server(sockfd, user_msg);
    send_to_server(sockfd, pass_msg);

    /* Read response from server */
    read_from_server(sockfd, buf, 1024);
    printf("%s\n", buf); // Should print "+OK Welcome username"

    /* Send command to list emails */
    char list_msg[256] = "LIST\n";
    send_to_server(sockfd, list_msg);

    /* Read response from server */
    read_from_server(sockfd, buf, 1024);
    printf("%s\n", buf); // Should print a list of emails

    /* Close connection */
    close(sockfd);
    return 0;
}