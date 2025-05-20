//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

void get_response(int sockfd) {
    char buffer[BUF_SIZE];
    int n;
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    if (n < 0)
        error("Error receiving response from server");

    printf("%s", buffer);
}

void send_command(int sockfd, char *cmd) {
    int n;
    n = send(sockfd, cmd, strlen(cmd), 0);
    if (n < 0)
        error("Error sending command to server");

    get_response(sockfd);
}

void login(int sockfd, char *username, char *password) {
    char buffer[BUF_SIZE];
    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    send_command(sockfd, buffer);
}

void list_messages(int sockfd) {
    send_command(sockfd, "LIST\r\n");
}

void fetch_message(int sockfd, int msg_num) {
    char buffer[BUF_SIZE];
    sprintf(buffer, "FETCH %d BODY[TEXT]\r\n", msg_num);
    send_command(sockfd, buffer);
}

void quit(int sockfd) {
    send_command(sockfd, "LOGOUT\r\n");
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Error connecting");

    printf("Welcome to my IMAP client\n");
    printf("Please enter your username: ");
    bzero(buffer, BUF_SIZE);
    fgets(buffer, BUF_SIZE-1, stdin);
    buffer[strlen(buffer)-1] = '\0'; // Remove newline character

    char *username = malloc(strlen(buffer) + 1);
    strcpy(username, buffer);

    printf("Please enter your password: ");
    bzero(buffer, BUF_SIZE);
    fgets(buffer, BUF_SIZE-1, stdin);
    buffer[strlen(buffer)-1] = '\0'; // Remove newline character

    char *password = malloc(strlen(buffer) + 1);
    strcpy(password, buffer);

    login(sockfd, username, password);

    char choice;
    do {
        printf("\nEnter 'l' to list messages or 'f' to fetch a specific message (q to quit): ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'l':
                list_messages(sockfd);
                break;
            case 'f':
                printf("Enter message number: ");
                int msg_num;
                scanf("%d", &msg_num);
                fetch_message(sockfd, msg_num);
                break;
            case 'q':
                quit(sockfd);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 'q');

    close(sockfd);

    return 0;
}