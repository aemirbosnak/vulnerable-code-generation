//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define SMTP_PORT 25
#define POP3_PORT 110
#define BUFFER_SIZE 1024

int smtp_connect(char *hostname, char *username, char *password) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return -1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    // Read greeting message from server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    // Send username to server
    sprintf(buffer, "EHLO %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    // Send password to server
    sprintf(buffer, "AUTH LOGIN\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    sprintf(buffer, "%s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    sprintf(buffer, "%s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    return sockfd;
}

void smtp_disconnect(int sockfd) {
    close(sockfd);
}

int smtp_send(char *recipient, char *subject, char *body, int sockfd) {
    char buffer[BUFFER_SIZE];

    // Set sender address
    sprintf(buffer, "MAIL FROM: <%s>\r\n", "sender@example.com");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    // Set recipient address
    sprintf(buffer, "RCPT TO: <%s>\r\n", recipient);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    // Start data transfer
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    // Send email headers and body
    sprintf(buffer, "From: sender@example.com\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n",
            recipient, subject, body);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    return 0;
}

int pop3_connect(char *hostname, char *username, char *password) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return -1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    // Read greeting message from server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    // Send username to server
    sprintf(buffer, "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    // Send password to server
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    return sockfd;
}

void pop3_disconnect(int sockfd) {
    close(sockfd);
}

int pop3_receive(char **sender, char **subject, char **body, int sockfd) {
    char buffer[BUFFER_SIZE];
    char *header_end;
    char *body_end;

    // Send LIST command to server
    sprintf(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%s", buffer);

    // Parse message number from server response
    char *line = strtok(buffer, " ");
    line = strtok(NULL, " ");
    int message_number = atoi(line);

    if (message_number == 0) {
        // No new messages
        return 0;
    }

    // Send RETR command to server
    sprintf(buffer, "RETR %d\r\n", message_number);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }

    // Read message headers and body from server
    *sender = NULL;
    *subject = NULL;
    *body = NULL;
    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        if (*sender == NULL && strncmp(buffer, "From: ", 6) == 0) {
            // Parse sender email address
            char *start = buffer + 6;
            char *end = strchr(start, '\r');
            int length = end - start;
            *sender = malloc(length + 1);
            strncpy(*sender, start, length);
            (*sender)[length] = '\0';
        } else if (*subject == NULL && strncmp(buffer, "Subject: ", 9) == 0) {
            // Parse subject line
            char *start = buffer + 9;
            char *end = strchr(start, '\r');
            int length = end - start;
            *subject = malloc(length + 1);
            strncpy(*subject, start, length);
            (*subject)[length] = '\0';
        } else if (*body != NULL || strncmp(buffer, "\r\n", 2) != 0) {
            // Append to body text
            int length = strlen(buffer);
            if (*body == NULL) {
                *body = malloc(length + 1);
                strncpy(*body, buffer, length);
                (*body)[length] = '\0';
            } else {
                int old_length = strlen(*body);
                *body = realloc(*body, old_length + length + 1);
                strncpy(*body + old_length, buffer, length);
                (*body)[old_length + length] = '\0';
            }
        } else {
            // End of header section
            *body = malloc(1);
            (*body)[0] = '\0';
            header_end = buffer;
            break;
        }
    }

    // Read message body from server
    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        if (*body == NULL) {
            *body = malloc(strlen(buffer) + 1);
            strcpy(*body, buffer);
        } else {
            int old_length = strlen(*body);
            *body = realloc(*body, old_length + strlen(buffer) + 1);
            strcpy(*body + old_length, buffer);
        }

        if ((body_end = strstr(*body, "\r\n.\r\n")) != NULL) {
            body_end[2] = '\0';
            break;
        }
    }

    // Remove header section from body text
    int header_length = header_end - *body;
    memmove(*body, *body + header_length + 2, strlen(*body) - header_length - 2);
    (*body)[strlen(*body) - header_length - 2] = '\0';

    return 1;
}

int main() {
    int smtp_sockfd, pop3_sockfd;
    char *sender, *subject, *body;

    // Connect to SMTP server
    smtp_sockfd = smtp_connect("smtp.example.com", "username", "password");
    if (smtp_sockfd < 0) {
        return 1;
    }

    // Send email
    if (smtp_send("recipient@example.com", "Test email", "Hello World!", smtp_sockfd) < 0) {
        smtp_disconnect(smtp_sockfd);
        return 1;
    }

    // Disconnect from SMTP server
    smtp_disconnect(smtp_sockfd);

    // Connect to POP3 server
    pop3_sockfd = pop3_connect("pop3.example.com", "username", "password");
    if (pop3_sockfd < 0) {
        return 1;
    }

    // Receive email
    if (pop3_receive(&sender, &subject, &body, pop3_sockfd) > 0) {
        printf("Received email:\n");
        printf("Sender: %s\nSubject: %s\nBody: %s\n", sender, subject, body);
    }

    // Disconnect from POP3 server
    pop3_disconnect(pop3_sockfd);

    if (sender != NULL) {
        free(sender);
    }
    if (subject != NULL) {
        free(subject);
    }
    if (body != NULL) {
        free(body);
    }

    return 0;
}