//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

// Function to connect to a POP3 server
int connectToPop3Server(char* server, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *host;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return -1;
    }

    host = gethostbyname(server);
    if (host == NULL) {
        perror("Error finding host");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    return sockfd;
}

// Function to send a command to the POP3 server
int sendPop3Command(int sockfd, char* command) {
    char buffer[BUFFER_SIZE];
    int n;

    // Send command
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Error sending command");
        return -1;
    }

    // Receive response
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving response");
        return -1;
    }
    buffer[n] = '\0';

    printf("%s", buffer);

    // Check if response is ok
    if (buffer[0] == '+') {
        return 0;
    } else {
        return -1;
    }
}

// Function to fetch an email from the POP3 server
int fetchEmail(int sockfd, int index) {
    char buffer[BUFFER_SIZE];
    int n;

    // Send command to retrieve email
    sprintf(buffer, "RETR %d\r\n", index);
    if (sendPop3Command(sockfd, buffer) < 0) {
        return -1;
    }

    // Read email contents
    while ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    printf("\n");

    return 0;
}

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    int n;

    sockfd = connectToPop3Server("example.com", 110);
    if (sockfd < 0) {
        exit(1);
    }

    // Read welcome message
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving welcome message");
        exit(1);
    }
    buffer[n] = '\0';

    printf("%s", buffer);

    // Send login credentials
    sendPop3Command(sockfd, "USER username\r\n");
    sendPop3Command(sockfd, "PASS password\r\n");

    // List emails
    sendPop3Command(sockfd, "LIST\r\n");

    // Fetch email with index 1
    fetchEmail(sockfd, 1);

    // Quit session
    sendPop3Command(sockfd, "QUIT\r\n");

    close(sockfd);

    return 0;
}