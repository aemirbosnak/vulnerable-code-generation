//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int connect_to_server(char* host, char* port){
    struct addrinfo hints, *res, *p;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(host, port, &hints, &res);
    if(status != 0){
        printf("Error: %s\n", gai_strerror(status));
        exit(1);
    }

    for(p = res; p != NULL; p = p->ai_next){
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(sockfd == -1) continue;

        if(connect(sockfd, p->ai_addr, p->ai_addrlen) != -1) break;

        close(sockfd);
    }

    if(p == NULL){
        printf("Error: Unable to connect to the server\n");
        exit(1);
    }

    freeaddrinfo(res);
    return sockfd;
}

int pop3_login(int sockfd, char* username, char* password){
    char buf[BUF_SIZE];
    int num_bytes;

    num_bytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
    if(num_bytes == -1){
        printf("Error: Unable to receive data from server\n");
        exit(1);
    }

    buf[num_bytes] = '\0';
    printf("%s\n", buf);

    sprintf(buf, "USER %s\r\n", username);
    if(send(sockfd, buf, strlen(buf), 0) == -1){
        printf("Error: Unable to send data to server\n");
        exit(1);
    }

    num_bytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
    if(num_bytes == -1){
        printf("Error: Unable to receive data from server\n");
        exit(1);
    }

    buf[num_bytes] = '\0';
    printf("%s\n", buf);

    sprintf(buf, "PASS %s\r\n", password);
    if(send(sockfd, buf, strlen(buf), 0) == -1){
        printf("Error: Unable to send data to server\n");
        exit(1);
    }

    num_bytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
    if(num_bytes == -1){
        printf("Error: Unable to receive data from server\n");
        exit(1);
    }

    buf[num_bytes] = '\0';
    printf("%s\n", buf);

    if(strncmp(buf, "+OK", 3) == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void get_mail(int sockfd, int mail_number){
    char buf[BUF_SIZE];
    int num_bytes;

    sprintf(buf, "RETR %d\r\n", mail_number);
    if(send(sockfd, buf, strlen(buf), 0) == -1){
        printf("Error: Unable to send data to server\n");
        exit(1);
    }

    num_bytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
    if(num_bytes == -1){
        printf("Error: Unable to receive data from server\n");
        exit(1);
    }

    buf[num_bytes] = '\0';
    printf("%s\n", buf);

    while(1){
        num_bytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
        if(num_bytes == -1){
            printf("Error: Unable to receive data from server\n");
            exit(1);
        }

        buf[num_bytes] = '\0';
        printf("%s", buf);

        if(strstr(buf, "\r\n.\r\n") != NULL){
            break;
        }
    }
}

void list_mails(int sockfd){
    char buf[BUF_SIZE];
    int num_bytes;

    if(send(sockfd, "LIST\r\n", 6, 0) == -1){
        printf("Error: Unable to send data to server\n");
        exit(1);
    }

    num_bytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
    if(num_bytes == -1){
        printf("Error: Unable to receive data from server\n");
        exit(1);
    }

    buf[num_bytes] = '\0';
    printf("%s\n", buf);

    while(1){
        num_bytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
        if(num_bytes == -1){
            printf("Error: Unable to receive data from server\n");
            exit(1);
        }

        buf[num_bytes] = '\0';
        printf("%s", buf);

        if(strstr(buf, "\r\n.\r\n") != NULL){
            break;
        }
    }
}

void delete_mail(int sockfd, int mail_number){
    char buf[BUF_SIZE];
    int num_bytes;

    sprintf(buf, "DELE %d\r\n", mail_number);
    if(send(sockfd, buf, strlen(buf), 0) == -1){
        printf("Error: Unable to send data to server\n");
        exit(1);
    }

    num_bytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
    if(num_bytes == -1){
        printf("Error: Unable to receive data from server\n");
        exit(1);
    }

    buf[num_bytes] = '\0';
    printf("%s\n", buf);
}

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("Usage: pop3_client hostname portnumber username\n");
        exit(1);
    }

    int sockfd = connect_to_server(argv[1], argv[2]);
    if(pop3_login(sockfd, argv[3], "password") == 0){
        printf("Error: Unable to login to server\n");
        exit(1);
    }

    list_mails(sockfd);

    printf("Enter the number of the mail you want to read: ");
    int mail_number;
    scanf("%d", &mail_number);

    get_mail(sockfd, mail_number);

    printf("Do you want to delete this mail? (y/n): ");
    char response;
    scanf(" %c", &response);

    if(response == 'y'){
        delete_mail(sockfd, mail_number);
        printf("Mail deleted\n");
    }

    close(sockfd);
    return 0;
}