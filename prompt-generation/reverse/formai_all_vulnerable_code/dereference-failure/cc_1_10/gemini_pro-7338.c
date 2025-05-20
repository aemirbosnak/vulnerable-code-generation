//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Romeo's words
#define POP3_USER "USER"
#define POP3_PASS "PASS"
#define POP3_LIST "LIST"
#define POP3_RETR "RETR"
#define POP3_QUIT "QUIT"

// Juliet's replies
#define POP3_OK "+OK"
#define POP3_ERR "-ERR"

// Our rendezvous point
#define POP3_PORT 110

// Let's meet
int connect_to_server(char *hostname) {
    struct hostent *host = gethostbyname(hostname);
    struct sockaddr_in server_addr;

    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    return sockfd;
}

// Romeo's sweet nothings
void send_command(int sockfd, char *command) {
    printf("%s\n", command);
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

// Juliet's enchanting replies
char *receive_response(int sockfd) {
    char *response = malloc(1024);
    int len = recv(sockfd, response, 1023, 0);
    response[len] = '\0';
    printf("%s\n", response);
    return response;
}

// Romeo's confession
void login(int sockfd, char *username, char *password) {
    send_command(sockfd, POP3_USER);
    char *response = receive_response(sockfd);
    if (strncmp(response, POP3_OK, 3) != 0) {
        fprintf(stderr, "Error logging in: %s\n", response);
        exit(1);
    }

    send_command(sockfd, POP3_PASS);
    response = receive_response(sockfd);
    if (strncmp(response, POP3_OK, 3) != 0) {
        fprintf(stderr, "Error logging in: %s\n", response);
        exit(1);
    }
}

// Romeo's longing for Juliet's messages
void list_messages(int sockfd) {
    send_command(sockfd, POP3_LIST);
    char *response = receive_response(sockfd);
    if (strncmp(response, POP3_OK, 3) != 0) {
        fprintf(stderr, "Error listing messages: %s\n", response);
        exit(1);
    }

    while (1) {
        response = receive_response(sockfd);
        if (strcmp(response, ".") == 0) {
            break;
        }

        printf("%s\n", response);
    }
}

// Romeo's ardent desire to possess Juliet's messages
void retrieve_message(int sockfd, int message_number) {
    char command[1024];
    sprintf(command, "%s %d", POP3_RETR, message_number);
    send_command(sockfd, command);
    char *response = receive_response(sockfd);
    if (strncmp(response, POP3_OK, 3) != 0) {
        fprintf(stderr, "Error retrieving message: %s\n", response);
        exit(1);
    }

    while (1) {
        response = receive_response(sockfd);
        if (strcmp(response, ".") == 0) {
            break;
        }

        printf("%s\n", response);
    }
}

// Romeo's farewell to Juliet
void quit(int sockfd) {
    send_command(sockfd, POP3_QUIT);
    char *response = receive_response(sockfd);
    if (strncmp(response, POP3_OK, 3) != 0) {
        fprintf(stderr, "Error quitting: %s\n", response);
        exit(1);
    }

    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    int sockfd = connect_to_server(argv[1]);
    login(sockfd, argv[2], argv[3]);
    list_messages(sockfd);
    retrieve_message(sockfd, 1);
    quit(sockfd);

    return 0;
}