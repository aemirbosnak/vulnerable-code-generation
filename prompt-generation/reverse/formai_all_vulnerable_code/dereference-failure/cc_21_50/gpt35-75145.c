//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SERVER_NAME "smtp.gmail.com"
#define SERVER_PORT 587
#define MAIL_FROM "youremail@gmail.com"
#define RCPT_TO "recipientemail@gmail.com"
#define USERNAME "youremail@gmail.com"
#define PASSWORD "yourpassword"

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }
    
    struct hostent *server = gethostbyname(SERVER_NAME);
    if (server == NULL) {
        printf("Error getting host information\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr = *((struct in_addr *) server->h_addr);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    char buffer[1024];
    int num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    snprintf(buffer, sizeof(buffer), "EHLO %s\r\n", SERVER_NAME);
    if (send(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error sending data to server\n");
        return 1;
    }

    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    snprintf(buffer, sizeof(buffer), "STARTTLS\r\n");
    if (send(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error sending data to server\n");
        return 1;
    }

    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    FILE *stream = fdopen(sockfd, "r+");
    fprintf(stream, "AUTH LOGIN\r\n");
    fflush(stream);

    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    char encoded_username[1024];
    int username_length = snprintf(encoded_username, sizeof(encoded_username), "%s", USERNAME);
    for (int i = 0; i < username_length; i++) {
        encoded_username[i] = (char) (((encoded_username[i] >> 4) & 0xF) + 'A');
        encoded_username[i + username_length] = (char) ((encoded_username[i] & 0xF) + 'A');
    }
    encoded_username[2 * username_length] = '\0';

    char encoded_password[1024];
    int password_length = snprintf(encoded_password, sizeof(encoded_password), "%s", PASSWORD);
    for (int i = 0; i < password_length; i++) {
        encoded_password[i] = (char) (((encoded_password[i] >> 4) & 0xF) + 'A');
        encoded_password[i + password_length] = (char) ((encoded_password[i] & 0xF) + 'A');
    }
    encoded_password[2 * password_length] = '\0';

    fprintf(stream, "%s\r\n", encoded_username);
    fflush(stream);

    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    fprintf(stream, "%s\r\n", encoded_password);
    fflush(stream);

    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", MAIL_FROM);
    if (send(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error sending data to server\n");
        return 1;
    }

    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", RCPT_TO);
    if (send(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error sending data to server\n");
        return 1;
    }

    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    if (send(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error sending data to server\n");
        return 1;
    }

    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    snprintf(buffer, sizeof(buffer), "Subject: Testing SMTP Client\r\n");
    if (send(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error sending data to server\n");
        return 1;
    }

    snprintf(buffer, sizeof(buffer), "From: <%s>\r\n", MAIL_FROM);
    if (send(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error sending data to server\n");
        return 1;
    }

    snprintf(buffer, sizeof(buffer), "To: <%s>\r\n", RCPT_TO);
    if (send(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error sending data to server\n");
        return 1;
    }

    snprintf(buffer, sizeof(buffer), "Hello, this is a test message\n.\r\n");
    if (send(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error sending data to server\n");
        return 1;
    }

    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if (send(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error sending data to server\n");
        return 1;
    }

    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        printf("Error receiving data from server\n");
        return 1;
    }
    printf("%.*s", num_bytes, buffer);

    close(sockfd);
    return 0;
}