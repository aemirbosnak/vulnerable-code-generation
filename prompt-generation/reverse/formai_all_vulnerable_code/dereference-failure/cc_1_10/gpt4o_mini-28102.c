//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// A dreamlike structure, where our FTP client shall dwell
typedef struct {
    char *host;
    int port;
    char *username;
    char *password;
} FTPClient;

// The ephemeral dance of creation
FTPClient *create_client(const char *host, int port, const char *username, const char *password) {
    FTPClient *client = malloc(sizeof(FTPClient));
    client->host = strdup(host);
    client->port = port;
    client->username = strdup(username);
    client->password = strdup(password);
    return client;
}

// The cauldron of connection, bubbling with anticipation
int connect_to_server(FTPClient *client) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "A gust of wind swept through, connection faltered.\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(client->port);
    inet_pton(AF_INET, client->host, &server_addr.sin_addr);

    // Ensnaring the server's spirit
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "The bridge to the world, elusive and distant.\n");
        close(sockfd);
        return -1;
    }
    return sockfd;
}

// Whispering the secrets of login
void login_to_ftp(int sockfd, FTPClient *client) {
    char command[256];

    snprintf(command, sizeof(command), "USER %s\r\n", client->username);
    send(sockfd, command, strlen(command), 0);
    bzero(command, 256);
    recv(sockfd, command, sizeof(command), 0);
    printf("Server Response: %s\n", command);

    snprintf(command, sizeof(command), "PASS %s\r\n", client->password);
    send(sockfd, command, strlen(command), 0);
    bzero(command, 256);
    recv(sockfd, command, sizeof(command), 0);
    printf("Server Response: %s\n", command);
}

// The surreal spirals of file listing
void list_files(int sockfd) {
    char command[256];

    snprintf(command, sizeof(command), "LIST\r\n");
    send(sockfd, command, strlen(command), 0);
    
    char buffer[1024];
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Files in the cosmic ether:\n%s\n", buffer);
}

// The fleeting nature of disconnection
void disconnect_ftp(int sockfd) {
    char command[] = "QUIT\r\n";
    send(sockfd, command, strlen(command), 0);
    close(sockfd);
    printf("The connection sighs and retreats into the shadows.\n");
}

// The embodiment of surrealism in our FTP creation
int main() {
    // A dreamer's ornate details
    const char *host = "192.168.1.1"; // A phantasmal IP
    int port = 21;
    const char *username = "dreamer";
    const char *password = "whispering_echoes";

    FTPClient *ftp_client = create_client(host, port, username, password);

    int sockfd = connect_to_server(ftp_client);
    if (sockfd < 0) {
        free(ftp_client->host);
        free(ftp_client->username);
        free(ftp_client->password);
        free(ftp_client);
        return -1;
    }

    // Engaging with the fabric of the FTP world
    login_to_ftp(sockfd, ftp_client);
    list_files(sockfd);
    
    // The echoes of parting
    disconnect_ftp(sockfd);

    // Concluding the reverie
    free(ftp_client->host);
    free(ftp_client->username);
    free(ftp_client->password);
    free(ftp_client);

    return 0;
}