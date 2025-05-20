//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024
#define POP3_PORT 110

/* Function prototypes */
void error(const char *msg);
int connect_to_server(char *server_address);
int receive_response(int fd, char *buffer);
void send_request(int fd, char *request);
void login(int fd, char *username, char *password);
void print_message(int fd, int message_number);
void delete_message(int fd, int message_number);
void quit(int fd);

int main(int argc, char *argv[])
{
    int sockfd, n;
    char buffer[MAX_BUFFER_SIZE];
    
    /* Check for valid number of arguments */
    if (argc < 4) {
        fprintf(stderr,"usage: %s server_address username password\n", argv[0]);
        exit(0);
    }

    /* Connect to server */
    sockfd = connect_to_server(argv[1]);

    /* Receive welcome message */
    if (receive_response(sockfd, buffer) < 1) {
        error("Failed to receive welcome message");
    }

    /* Login */
    login(sockfd, argv[2], argv[3]);

    /* Print messages */
    print_message(sockfd, 1);
    print_message(sockfd, 2);

    /* Delete message */
    delete_message(sockfd, 2);

    /* Quit */
    quit(sockfd);

    return 0;
}

/* Function to handle errors */
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

/* Function to connect to server */
int connect_to_server(char *server_address)
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Failed to open socket");
    }

    /* Get server information */
    server = gethostbyname(server_address);
    if (server == NULL) {
        fprintf(stderr,"Failed to find host");
        exit(0);
    }

    /* Configure serv_addr */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(POP3_PORT);

    /* Connect to server */
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("Failed to connect to server");
    }

    return sockfd;
}

/* Function to receive response */
int receive_response(int fd, char *buffer)
{
    bzero(buffer, MAX_BUFFER_SIZE);
    return read(fd, buffer, MAX_BUFFER_SIZE-1);
}

/* Function to send request */
void send_request(int fd, char *request)
{
    write(fd, request, strlen(request));
}

/* Function to login */
void login(int fd, char *username, char *password)
{
    char buffer[MAX_BUFFER_SIZE];

    /* Send username */
    sprintf(buffer, "USER %s\r\n", username);
    send_request(fd, buffer);
    receive_response(fd, buffer);

    /* Send password */
    sprintf(buffer, "PASS %s\r\n", password);
    send_request(fd, buffer);
    receive_response(fd, buffer);
}

/* Function to print message */
void print_message(int fd, int message_number)
{
    char buffer[MAX_BUFFER_SIZE];

    /* Send RETR command */
    sprintf(buffer, "RETR %d\r\n", message_number);
    send_request(fd, buffer);

    /* Receive response */
    receive_response(fd, buffer);

    /* Print message */
    printf("%s\n", buffer);
}

/* Function to delete message */
void delete_message(int fd, int message_number)
{
    char buffer[MAX_BUFFER_SIZE];

    /* Send DELE command */
    sprintf(buffer, "DELE %d\r\n", message_number);
    send_request(fd, buffer);
    receive_response(fd, buffer);
}

/* Function to quit */
void quit(int fd)
{
    char buffer[MAX_BUFFER_SIZE];

    /* Send QUIT command */
    sprintf(buffer, "QUIT\r\n");
    send_request(fd, buffer);
    receive_response(fd, buffer);

    /* Close socket */
    close(fd);
}