//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_BUF_SIZE 1024

// Read a line from the socket and return it as a string.
char *read_line(int sockfd) {
    char *buf = malloc(MAX_BUF_SIZE);
    int bytes_read = 0;
    while ((bytes_read = read(sockfd, buf + bytes_read, 1)) > 0) {
        if (buf[bytes_read - 1] == '\n') {
            buf[bytes_read - 1] = '\0';
            break;
        }
    }
    if (bytes_read < 0) {
        free(buf);
        return NULL;
    }
    return buf;
}

// Send a command to the POP3 server and return the server's response.
char *send_command(int sockfd, char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    return read_line(sockfd);
}

int main() {
    // Connect to the POP3 server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(POP3_PORT);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }

    // Receive the server's greeting.
    char *greeting = read_line(sockfd);
    printf("Server greeting: %s\n", greeting);

    // Send the USER command.
    char *user = "someone";
    char buf[MAX_BUF_SIZE];
    snprintf(buf, sizeof(buf), "USER %s\r\n", user);
    char *response = send_command(sockfd, buf);
    printf("Server response: %s\n", response);

    // Send the PASS command.
    char *pass = "thepassword";
    snprintf(buf, sizeof(buf), "PASS %s\r\n", pass);
    response = send_command(sockfd, buf);
    printf("Server response: %s\n", response);

    // Send the LIST command.
    response = send_command(sockfd, "LIST\r\n");
    printf("Server response: %s\n", response);

    // Send the RETR command.
    int msg_num = 1;
    snprintf(buf, sizeof(buf), "RETR %d\r\n", msg_num);
    response = send_command(sockfd, buf);
    printf("Server response: %s\n", response);

    // Print the message body.
    char *line;
    while ((line = read_line(sockfd)) != NULL) {
        printf("%s\n", line);
    }

    // Send the QUIT command.
    response = send_command(sockfd, "QUIT\r\n");
    printf("Server response: %s\n", response);

    close(sockfd);
    return 0;
}