//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to send a command to the POP3 server
int send_command(int sockfd, char *cmd) {
    int len = strlen(cmd);
    if (send(sockfd, cmd, len, 0) != len) {
        perror("send");
        return -1;
    }
    return 0;
}

// Function to receive a response from the POP3 server
int receive_response(int sockfd, char *buf, int buf_size) {
    int len = recv(sockfd, buf, buf_size, 0);
    if (len < 0) {
        perror("recv");
        return -1;
    }
    buf[len] = '\0';
    return 0;
}

// Function to authenticate with the POP3 server
int authenticate(int sockfd, char *user, char *pass) {
    char buf[1024];

    // Send the USER command
    if (send_command(sockfd, "USER ") < 0) {
        return -1;
    }
    if (send_command(sockfd, user) < 0) {
        return -1;
    }
    if (receive_response(sockfd, buf, sizeof(buf)) < 0) {
        return -1;
    }

    // Send the PASS command
    if (send_command(sockfd, "PASS ") < 0) {
        return -1;
    }
    if (send_command(sockfd, pass) < 0) {
        return -1;
    }
    if (receive_response(sockfd, buf, sizeof(buf)) < 0) {
        return -1;
    }

    return 0;
}

// Function to list all messages on the POP3 server
int list_messages(int sockfd) {
    char buf[1024];

    // Send the LIST command
    if (send_command(sockfd, "LIST") < 0) {
        return -1;
    }
    if (receive_response(sockfd, buf, sizeof(buf)) < 0) {
        return -1;
    }

    // Print the list of messages
    printf("Message list:\n");
    char *line = strtok(buf, "\r\n");
    while (line != NULL) {
        printf("%s\n", line);
        line = strtok(NULL, "\r\n");
    }

    return 0;
}

// Function to retrieve a specific message from the POP3 server
int retrieve_message(int sockfd, int msg_num) {
    char buf[1024];

    // Send the RETR command
    if (send_command(sockfd, "RETR ") < 0) {
        return -1;
    }
    if (send_command(sockfd, msg_num) < 0) {
        return -1;
    }
    if (receive_response(sockfd, buf, sizeof(buf)) < 0) {
        return -1;
    }

    // Print the message
    printf("Message %d:\n", msg_num);
    char *line = strtok(buf, "\r\n");
    while (line != NULL) {
        printf("%s\n", line);
        line = strtok(NULL, "\r\n");
    }

    return 0;
}

// Function to delete a specific message from the POP3 server
int delete_message(int sockfd, int msg_num) {
    char buf[1024];

    // Send the DELE command
    if (send_command(sockfd, "DELE ") < 0) {
        return -1;
    }
    if (send_command(sockfd, msg_num) < 0) {
        return -1;
    }
    if (receive_response(sockfd, buf, sizeof(buf)) < 0) {
        return -1;
    }

    return 0;
}

// Function to quit the POP3 server
int quit(int sockfd) {
    char buf[1024];

    // Send the QUIT command
    if (send_command(sockfd, "QUIT") < 0) {
        return -1;
    }
    if (receive_response(sockfd, buf, sizeof(buf)) < 0) {
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buf[1024];

    // Check if the user has specified the POP3 server address and port
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Set the server address and port
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Receive the welcome message from the server
    if (receive_response(sockfd, buf, sizeof(buf)) < 0) {
        return 1;
    }
    printf("Welcome message: %s\n", buf);

    // Authenticate with the server
    if (authenticate(sockfd, "user", "pass") < 0) {
        return 1;
    }

    // List all messages on the server
    if (list_messages(sockfd) < 0) {
        return 1;
    }

    // Retrieve a specific message from the server
    if (retrieve_message(sockfd, 1) < 0) {
        return 1;
    }

    // Delete a specific message from the server
    if (delete_message(sockfd, 1) < 0) {
        return 1;
    }

    // Quit the server
    if (quit(sockfd) < 0) {
        return 1;
    }

    return 0;
}