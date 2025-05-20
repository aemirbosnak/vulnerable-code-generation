//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    // Who am I?
    struct hostent *host_info = gethostbyname("example.com");
    if (host_info == NULL)
    {
        fprintf(stderr, "Error: Could not resolve hostname\n");
        return EXIT_FAILURE;
    }

    // Where do I live?
    char my_ip[INET_ADDRSTRLEN];
    inet_ntop(host_info->h_addrtype, host_info->h_addr, my_ip, sizeof(my_ip));
    printf("My IP address is: %s\n", my_ip);

    // How do I connect to the world?
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "Error: Could not create socket\n");
        return EXIT_FAILURE;
    }

    // Where do I want to go?
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110); // POP3 port
    server_addr.sin_addr = *(struct in_addr *)host_info->h_addr;

    // Let's knock on the door
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        fprintf(stderr, "Error: Could not connect to server\n");
        return EXIT_FAILURE;
    }

    // Server, who are you?
    char server_response[1024];
    recv(sockfd, server_response, sizeof(server_response), 0);
    printf("Server: %s\n", server_response);

    // I am a POP3 client, let's chat
    const char *user = "username";
    const char *pass = "password";
    char user_cmd[1024];
    sprintf(user_cmd, "USER %s\r\n", user);
    send(sockfd, user_cmd, strlen(user_cmd), 0);
    recv(sockfd, server_response, sizeof(server_response), 0);
    printf("Server: %s\n", server_response);

    char pass_cmd[1024];
    sprintf(pass_cmd, "PASS %s\r\n", pass);
    send(sockfd, pass_cmd, strlen(pass_cmd), 0);
    recv(sockfd, server_response, sizeof(server_response), 0);
    printf("Server: %s\n", server_response);

    // What's in my mailbox?
    char list_cmd[] = "LIST\r\n";
    send(sockfd, list_cmd, strlen(list_cmd), 0);
    recv(sockfd, server_response, sizeof(server_response), 0);
    printf("Server: %s\n", server_response);

    // I've got mail, let me read it
    char retr_cmd[] = "RETR 1\r\n";
    send(sockfd, retr_cmd, strlen(retr_cmd), 0);
    recv(sockfd, server_response, sizeof(server_response), 0);
    printf("Server: %s\n", server_response);

    // Time to say goodbye
    char quit_cmd[] = "QUIT\r\n";
    send(sockfd, quit_cmd, strlen(quit_cmd), 0);
    recv(sockfd, server_response, sizeof(server_response), 0);
    printf("Server: %s\n", server_response);

    close(sockfd);
    return EXIT_SUCCESS;
}