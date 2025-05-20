//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Self-referential SMTP client structure
typedef struct smtp_client {
    int sockfd;
    char *hostname;
    char *username;
    char *password;
    char *from;
    char *to;
    char *subject;
    char *body;
} smtp_client;

// Function to create a new SMTP client
smtp_client *smtp_client_new(char *hostname, char *username, char *password, char *from, char *to, char *subject, char *body) {
    smtp_client *client = malloc(sizeof(smtp_client));
    client->sockfd = -1;
    client->hostname = hostname;
    client->username = username;
    client->password = password;
    client->from = from;
    client->to = to;
    client->subject = subject;
    client->body = body;
    return client;
}

// Function to connect to the SMTP server
int smtp_client_connect(smtp_client *client) {
    struct sockaddr_in servaddr;
    struct hostent *he;
    
    if ((he = gethostbyname(client->hostname)) == NULL) {
        perror("gethostbyname");
        return -1;
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    memcpy(&servaddr.sin_addr, he->h_addr, he->h_length);
    
    if ((client->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    
    if (connect(client->sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return -1;
    }
    
    return 0;
}

// Function to send a command to the SMTP server
int smtp_client_send_command(smtp_client *client, char *command) {
    int len = strlen(command);
    if (send(client->sockfd, command, len, 0) != len) {
        perror("send");
        return -1;
    }
    return 0;
}

// Function to receive a response from the SMTP server
char *smtp_client_receive_response(smtp_client *client) {
    char *response = malloc(1024);
    int len = recv(client->sockfd, response, 1024, 0);
    if (len < 0) {
        perror("recv");
        free(response);
        return NULL;
    }
    response[len] = '\0';
    return response;
}

// Function to send the mail
int smtp_client_send_mail(smtp_client *client) {
    // Send HELO command
    if (smtp_client_send_command(client, "HELO localhost\r\n") < 0) {
        return -1;
    }
    // Receive response
    char *response = smtp_client_receive_response(client);
    if (response == NULL) {
        return -1;
    }
    free(response);
    
    // Send MAIL FROM command
    char command[1024];
    sprintf(command, "MAIL FROM:<%s>\r\n", client->from);
    if (smtp_client_send_command(client, command) < 0) {
        return -1;
    }
    // Receive response
    response = smtp_client_receive_response(client);
    if (response == NULL) {
        return -1;
    }
    free(response);
    
    // Send RCPT TO command
    sprintf(command, "RCPT TO:<%s>\r\n", client->to);
    if (smtp_client_send_command(client, command) < 0) {
        return -1;
    }
    // Receive response
    response = smtp_client_receive_response(client);
    if (response == NULL) {
        return -1;
    }
    free(response);
    
    // Send DATA command
    if (smtp_client_send_command(client, "DATA\r\n") < 0) {
        return -1;
    }
    // Receive response
    response = smtp_client_receive_response(client);
    if (response == NULL) {
        return -1;
    }
    free(response);
    
    // Send the email body
    char body[1024];
    sprintf(body, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n", client->from, client->to, client->subject, client->body);
    if (smtp_client_send_command(client, body) < 0) {
        return -1;
    }
    
    // Send QUIT command
    if (smtp_client_send_command(client, "QUIT\r\n") < 0) {
        return -1;
    }
    
    return 0;
}

// Function to free the SMTP client
void smtp_client_free(smtp_client *client) {
    if (client->sockfd >= 0) {
        close(client->sockfd);
    }
    free(client);
}

// Function to test the SMTP client
int main(int argc, char **argv) {
    if (argc < 8) {
        printf("Usage: %s hostname username password from to subject body\n", argv[0]);
        return 1;
    }
    
    // Create the SMTP client
    smtp_client *client = smtp_client_new(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
    
    // Connect to the SMTP server
    if (smtp_client_connect(client) < 0) {
        return 1;
    }
    
    // Send the mail
    if (smtp_client_send_mail(client) < 0) {
        return 1;
    }
    
    // Free the SMTP client
    smtp_client_free(client);
    
    return 0;
}