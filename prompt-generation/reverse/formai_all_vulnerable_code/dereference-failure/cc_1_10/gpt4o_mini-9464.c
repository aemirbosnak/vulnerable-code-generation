//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_server(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting to server");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    if (write(sockfd, command, strlen(command)) < 0) {
        error("ERROR writing to socket");
    }
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    int n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    read_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    read_response(sockfd);
}

void list_emails(int sockfd) {
    send_command(sockfd, "LIST\r\n");
    read_response(sockfd);
}

void fetch_email(int sockfd, const char *email_number) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "RETR %s\r\n", email_number);
    send_command(sockfd, command);
    read_response(sockfd);
}

void delete_email(int sockfd, const char *email_number) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "DELE %s\r\n", email_number);
    send_command(sockfd, command);
    read_response(sockfd);
}

void quit(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_server(hostname);

    read_response(sockfd);
    login(sockfd, username, password);
    list_emails(sockfd);
    
    char email_number[4];
    printf("Enter the email number to fetch (or 'q' to quit): ");
    while (fgets(email_number, sizeof(email_number), stdin)) {
        email_number[strcspn(email_number, "\n")] = 0;  // Remove newline character

        if (strcmp(email_number, "q") == 0) {
            break;
        }
        
        fetch_email(sockfd, email_number);
        
        printf("Do you want to delete this email? (y/n): ");
        char delete_choice;
        scanf(" %c", &delete_choice);
        if (delete_choice == 'y') {
            delete_email(sockfd, email_number);
            printf("Email number %s deleted.\n", email_number);
        }
        
        printf("Enter another email number to fetch (or 'q' to quit): ");
        getchar();  // Clear the newline character left by scanf
    }

    quit(sockfd);
    return 0;
}