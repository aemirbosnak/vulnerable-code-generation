//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: curious
/*Welcome to the curious program to build a POP3 client!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    /*Create a curious socket*/
    int curious_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (curious_socket < 0) {
        printf("Oops! Socket cannot be created!");
        exit(1);
    }
    
    /*Let's update the curious host name and port number*/
    char *curious_host = "mail.example.com";
    int curious_port = 110; /*Default POP3 port*/
    
    if (argc >= 2) {
        curious_host = argv[1];
    }
    
    if (argc >= 3) {
        curious_port = atoi(argv[2]);
    }
    
    /*Let's use gethostbyname to reslove the curious hostname*/
    struct hostent *curious_hostent = gethostbyname(curious_host);
    
    if (curious_hostent == NULL) {
        printf("Oops! Cannot resolve the hostname.");
        exit(1);
    }
    
    /*Let's create a curious address struct*/
    struct sockaddr_in curious_address;
    curious_address.sin_family = AF_INET;
    curious_address.sin_port = htons(curious_port);
    memcpy(&curious_address.sin_addr, curious_hostent->h_addr_list[0], curious_hostent->h_length);
    
    /*Let's connect the curious socket*/
    if (connect(curious_socket, (struct sockaddr *)&curious_address, sizeof(curious_address)) < 0) {
        printf("Oops! Socket cannot be connected!");
        exit(1);
    }
    
    /*Read the curious server response*/
    char response[1024];
    read(curious_socket, response, 1024);
    printf("%s", response);

    /*Let's login*/
    char *curious_user = "username";
    char *curious_pass = "password";
    char command[1024];
    sprintf(command, "USER %s\r\n", curious_user);
    write(curious_socket, command, strlen(command));
    read(curious_socket, response, 1024);
    printf("%s", response);
    sprintf(command, "PASS %s\r\n", curious_pass);
    write(curious_socket, command, strlen(command));
    read(curious_socket, response, 1024);
    printf("%s", response);

    /*Let's get the curious message count*/
    sprintf(command, "STAT\r\n");
    write(curious_socket, command, strlen(command));
    read(curious_socket, response, 1024);
    printf("You have %s",response);
    
    /*Let's get the curious message headers*/
    sprintf(command, "LIST\r\n");
    write(curious_socket, command, strlen(command));
    while (1) {
        read(curious_socket, response, 1024);
        if (strcmp(response, ".\r\n") == 0) {
            break;
        }
        printf("%s", response);
    }

    /*Let's get the curious message content*/
    sprintf(command, "RETR 1\r\n");
    write(curious_socket, command, strlen(command));
    while (1) {
        read(curious_socket, response, 1024);
        if (strcmp(response, ".\r\n") == 0) {
            break;
        }
        printf("%s", response);
    }
    
    /*Let's quit*/
    sprintf(command, "QUIT\r\n");
    write(curious_socket, command, strlen(command));
    read(curious_socket, response, 1024);
    printf("%s", response);
    
    /*Close the curious socket*/
    close(curious_socket);
    
    printf("\nHurray! You have successfully built a POP3 client!\n");
    return 0;
}