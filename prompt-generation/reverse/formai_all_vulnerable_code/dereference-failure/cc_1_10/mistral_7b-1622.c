//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 110
#define MAXDATASIZE 1024
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXDATASIZE];
    char *greeting = "+OK ApocalypsePOP3Client v1.0\r\n";
    char *user_prompt = "+USER <your_email_address>\r\n";
    char *pass_prompt = "+PASS <your_password>\r\n";
    char *quit_cmd = "+QUIT\r\n";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        die("ERROR opening socket");

    server = gethostbyname("mail.ruins.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        die("ERROR connecting");

    // Greet the server
    write(sockfd, greeting, strlen(greeting));

    // Send USER command
    write(sockfd, user_prompt, strlen(user_prompt));
    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send PASS command
    write(sockfd, pass_prompt, strlen(pass_prompt));
    memset(buffer, 0, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE, stdin);
    write(sockfd, buffer, strlen(buffer));

    // Process mail
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        read(sockfd, buffer, BUFFER_SIZE);
        printf("%s", buffer);

        if (strstr(buffer, "+OK") != NULL) {
            char cmd[10] = "LIST\r\n";
            write(sockfd, cmd, strlen(cmd));
        }

        if (strstr(buffer, "+QUIT") != NULL) {
            break;
        }
    }

    close(sockfd);
    return 0;
}