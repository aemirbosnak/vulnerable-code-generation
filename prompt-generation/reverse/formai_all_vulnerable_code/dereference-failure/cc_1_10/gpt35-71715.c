//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];
    bzero(buffer, BUF_SIZE);

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Connected to POP3 server...\n");

    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if(!ctx){
        ERR_print_errors_fp(stderr);
        exit(1);
    }
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if(SSL_connect(ssl) == -1){
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    printf("Connected using SSL...\n");

    char username[BUF_SIZE], password[BUF_SIZE];

    printf("Enter your username: ");
    fgets(username, BUF_SIZE, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter your password: ");
    fgets(password, BUF_SIZE, stdin);
    password[strcspn(password, "\n")] = '\0';

    // send the USER command
    char user_cmd[BUF_SIZE];
    snprintf(user_cmd, BUF_SIZE, "USER %s\n", username);
    SSL_write(ssl, user_cmd, strlen(user_cmd));

    SSL_read(ssl, buffer, BUF_SIZE);
    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("%s\n", buffer);
        exit(1);
    }

    // send the PASS command
    char pass_cmd[BUF_SIZE];
    snprintf(pass_cmd, BUF_SIZE, "PASS %s\n", password);
    SSL_write(ssl, pass_cmd, strlen(pass_cmd));

    SSL_read(ssl, buffer, BUF_SIZE);
    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("%s\n", buffer);
        exit(1);
    }

    printf("Authentication successful...\n");

    // send the STAT command
    SSL_write(ssl, "STAT\n", strlen("STAT\n"));

    SSL_read(ssl, buffer, BUF_SIZE);
    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("%s\n", buffer);
        exit(1);
    }

    // print the number of messages and their total size
    int num_msgs, total_size;
    sscanf(buffer, "+OK %d %d", &num_msgs, &total_size);
    printf("You have %d messages, total size is %d bytes.\n", num_msgs, total_size);

    // send the LIST command
    SSL_write(ssl, "LIST\n", strlen("LIST\n"));

    SSL_read(ssl, buffer, BUF_SIZE);
    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("%s\n", buffer);
        exit(1);
    }

    // print the list of messages and their sizes
    printf("Message list:\n");
    while (1) {
        SSL_read(ssl, buffer, BUF_SIZE);
        if (strncmp(buffer, ".", 1) == 0) {
            break;
        }
        printf("%s", buffer);
    }

    // choose a message to read
    printf("Enter the number of the message you want to read: ");
    char msg_num[BUF_SIZE];
    fgets(msg_num, BUF_SIZE, stdin);
    msg_num[strcspn(msg_num, "\n")] = '\0';

    // send the RETR command
    char retr_cmd[BUF_SIZE];
    snprintf(retr_cmd, BUF_SIZE, "RETR %s\n", msg_num);
    SSL_write(ssl, retr_cmd, strlen(retr_cmd));

    SSL_read(ssl, buffer, BUF_SIZE);
    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("%s\n", buffer);
        exit(1);
    }

    // print the message
    printf("Message:\n");
    while (1) {
        n = SSL_read(ssl, buffer, BUF_SIZE);
        if (n <= 0) {
            break;
        }
        fwrite(buffer, 1, n, stdout);
    }

    SSL_shutdown(ssl);
    close(sockfd);

    return 0;
}