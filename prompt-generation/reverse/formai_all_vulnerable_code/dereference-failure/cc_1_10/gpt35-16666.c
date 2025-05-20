//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 110      //POP3 Port

char *username;
char *password;

void readResponse(int sockfd, char *buffer) {
    ssize_t n = read(sockfd, buffer, BUFFER_SIZE - 1);
    buffer[n] = '\0';
    printf("%s", buffer);
}

void sendCommand(int sockfd, const char* cmd) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s\r\n", cmd);
    write(sockfd, buffer, strlen(buffer));
    readResponse(sockfd, buffer);
}

bool authenticate(int sockfd) {
    char buffer[BUFFER_SIZE];
    readResponse(sockfd, buffer);

    sendCommand(sockfd, "USER");
    sprintf(buffer, "%s\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    readResponse(sockfd, buffer);

    sendCommand(sockfd, "PASS");
    sprintf(buffer, "%s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    readResponse(sockfd, buffer);

    return strstr(buffer, "OK") != NULL;
}

void retrieveMail(int sockfd) {
    sendCommand(sockfd, "STAT");

    char buffer[BUFFER_SIZE];
    readResponse(sockfd, buffer);

    int numMessages;
    sscanf(buffer, "+OK %d", &numMessages);

    if (numMessages > 0) {
        for (int i = 1; i <= numMessages; i++) {
            printf("\nMessage %d:\n", i);

            sendCommand(sockfd, "TOP");
            sprintf(buffer, "%d 5", i);
            sendCommand(sockfd, buffer);

            readResponse(sockfd, buffer);
            printf("%s", buffer);

            readResponse(sockfd, buffer);
            printf("%s", buffer);

            readResponse(sockfd, buffer);
            printf("%s", buffer);
        }
    }
    else {
        printf("No new messages.\n");
    }
}

int main() {
    char buffer[BUFFER_SIZE];

    printf("Enter your email username: ");
    scanf("%s", buffer);
    username = strdup(buffer);

    printf("Enter your email password: ");
    scanf("%s", buffer);
    password = strdup(buffer);

    struct hostent *host = gethostbyname("mail.server.com");

    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*(host->h_addr_list)));

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    readResponse(sockfd, buffer);
    if (!authenticate(sockfd)) {
        printf("Authentication failed.\n");
        return 1;
    }

    retrieveMail(sockfd);
    sendCommand(sockfd, "QUIT");
    close(sockfd);

    return 0;
}