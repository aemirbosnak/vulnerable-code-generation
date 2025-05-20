//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_DATA_SIZE 1024

typedef struct {
    int sockfd;
    char *host;
    int port;
    char *user;
    char *pass;
} ftp_client_t;

int ftp_client_connect(ftp_client_t *client) {
    struct sockaddr_in serv_addr;
    
    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        perror("socket");
        return -1;
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(client->host);
    serv_addr.sin_port = htons(client->port);
    
    if (connect(client->sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }
    
    return 0;
}

int ftp_client_login(ftp_client_t *client) {
    char buf[MAX_DATA_SIZE];
    
    // Send USER command
    snprintf(buf, sizeof(buf), "USER %s\r\n", client->user);
    if (send(client->sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return -1;
    }
    
    // Receive response
    if (recv(client->sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return -1;
    }
    
    // Check response code
    if (buf[0] != '3') {
        printf("Login failed: %s\n", buf);
        return -1;
    }
    
    // Send PASS command
    snprintf(buf, sizeof(buf), "PASS %s\r\n", client->pass);
    if (send(client->sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return -1;
    }
    
    // Receive response
    if (recv(client->sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return -1;
    }
    
    // Check response code
    if (buf[0] != '2') {
        printf("Login failed: %s\n", buf);
        return -1;
    }
    
    return 0;
}

int ftp_client_list(ftp_client_t *client) {
    char buf[MAX_DATA_SIZE];
    
    // Send LIST command
    if (send(client->sockfd, "LIST\r\n", 6, 0) < 0) {
        perror("send");
        return -1;
    }
    
    // Receive response
    while (1) {
        if (recv(client->sockfd, buf, sizeof(buf), 0) < 0) {
            perror("recv");
            return -1;
        }
        
        // Check for end of response
        if (strcmp(buf, ".\r\n") == 0) {
            break;
        }
        
        // Print response
        printf("%s", buf);
    }
    
    return 0;
}

int ftp_client_retrieve(ftp_client_t *client, char *filename) {
    char buf[MAX_DATA_SIZE];
    FILE *fp;

    // Open file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Send RETR command
    snprintf(buf, sizeof(buf), "RETR %s\r\n", filename);
    if (send(client->sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return -1;
    }

    // Receive response
    if (recv(client->sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return -1;
    }

    // Check response code
    if (buf[0] != '1') {
        printf("Error retrieving file: %s\n", buf);
        return -1;
    }

    // Receive file data
    while (1) {
        if (recv(client->sockfd, buf, sizeof(buf), 0) < 0) {
            perror("recv");
            return -1;
        }

        // Check for end of data
        if (strcmp(buf, ".\r\n") == 0) {
            break;
        }

        // Write data to file
        fwrite(buf, 1, strlen(buf), fp);
    }

    // Close file
    fclose(fp);

    return 0;
}

int ftp_client_disconnect(ftp_client_t *client) {
    close(client->sockfd);
    return 0;
}

int main(int argc, char **argv) {
    ftp_client_t client;
    
    if (argc != 6) {
        printf("Usage: %s <host> <port> <user> <pass> <command>\n", argv[0]);
        return -1;
    }
    
    client.host = argv[1];
    client.port = atoi(argv[2]);
    client.user = argv[3];
    client.pass = argv[4];
    
    if (ftp_client_connect(&client) < 0) {
        return -1;
    }
    
    if (ftp_client_login(&client) < 0) {
        return -1;
    }
    
    if (strcmp(argv[5], "LIST") == 0) {
        ftp_client_list(&client);
    } else if (strcmp(argv[5], "RETR") == 0) {
        ftp_client_retrieve(&client, argv[6]);
    }
    
    ftp_client_disconnect(&client);
    
    return 0;
}