//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// The adventure begins: connecting to the POP3 server
int connect_to_server(char *host, int port) {
    struct sockaddr_in addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    return sockfd;
}

// Greetings, POP3 server! Let's start the conversation
void send_greeting(int sockfd) {
    char *greeting = "HELO pop3.example.com\r\n";
    write(sockfd, greeting, strlen(greeting));
}

// Time to get the goods: retrieving our emails
void get_messages(int sockfd) {
    char *list_cmd = "LIST\r\n";
    char buffer[1024];
    write(sockfd, list_cmd, strlen(list_cmd));
    while (read(sockfd, buffer, sizeof(buffer)) > 0) {
        printf("%s", buffer);
    }
}

// Let's grab a specific email to examine it closer
void get_message(int sockfd, int message_number) {
    char cmd[128];
    sprintf(cmd, "RETR %d\r\n", message_number);
    write(sockfd, cmd, strlen(cmd));
    char buffer[1024];
    while (read(sockfd, buffer, sizeof(buffer)) > 0) {
        printf("%s", buffer);
    }
}

// Done exploring emails? Let's say our farewells
void quit_connection(int sockfd) {
    char *bye = "QUIT\r\n";
    write(sockfd, bye, strlen(bye));
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }
    char *server = argv[1];
    int port = atoi(argv[2]);
    int sockfd = connect_to_server(server, port);
    send_greeting(sockfd);
    get_messages(sockfd);
    get_message(sockfd, 1);
    quit_connection(sockfd);
    return 0;
}