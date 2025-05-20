//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void connect_to_server(int *sockfd, const char *hostname) {
    struct hostent *server;
    struct sockaddr_in serv_addr;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) error("ERROR opening socket");

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(POP3_PORT);

    if (connect(*sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    char buffer[BUFFER_SIZE];
    recv(*sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("%s", buffer);
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("%s", buffer);
}

void list_emails(int sockfd) {
    send_command(sockfd, "LIST");
}

void retrieve_email(int sockfd, int msg_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d", msg_number);
    send_command(sockfd, command);
}

void delete_email(int sockfd, int msg_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "DELE %d", msg_number);
    send_command(sockfd, command);
}

void quit_connection(int sockfd) {
    send_command(sockfd, "QUIT");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    connect_to_server(&sockfd, hostname);

    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "USER %s", username);
    send_command(sockfd, buffer);

    snprintf(buffer, sizeof(buffer), "PASS %s", password);
    send_command(sockfd, buffer);

    list_emails(sockfd);

    printf("Select email number to retrieve: ");
    int email_number;
    scanf("%d", &email_number);
    retrieve_email(sockfd, email_number);

    printf("Do you want to delete this email? (1 for Yes, 0 for No): ");
    int delete_choice;
    scanf("%d", &delete_choice);
    if (delete_choice == 1) {
        delete_email(sockfd, email_number);
        printf("Email deleted.\n");
    }

    quit_connection(sockfd);
    close(sockfd);
    
    return 0;
}