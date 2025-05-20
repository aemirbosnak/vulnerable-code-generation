//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define PORT 110
#define MAXLINE 1024

int sockfd;
struct sockaddr_in servaddr;

/* Function to print error messages */
void error( const char *msg ) {
    perror( msg );
    exit( 1 );
}

/* Function to receive response from server */
int recv_response() {
    char buffer[MAXLINE];
    int n;
    if ( (n = read( sockfd, buffer, MAXLINE )) < 0 )
        error( "Unable to read data from server" );
    printf( "%s", buffer );
    if ( strstr( buffer, "+OK" ) == buffer )
        return 0;
    return -1;
}

/* Function to send command to server */
void send_command( char *cmd ) {
    if ( write( sockfd, cmd, strlen( cmd ) ) != strlen( cmd ) )
        error( "Unable to write data to server" );
}

/* Function to authenticate user */
void auth_user() {
    char username[MAXLINE], password[MAXLINE];
    printf( "Username: " );
    fgets( username, MAXLINE, stdin );
    printf( "Password: " );
    fgets( password, MAXLINE, stdin );
    /* Send username */
    send_command( "USER " );
    send_command( username );
    recv_response();
    /* Send password */
    send_command( "PASS " );
    send_command( password );
    recv_response();
}

/* Function to display mailbox overview */
void show_mailbox() {
    send_command( "STAT\r\n" );
    recv_response();
}

/* Function to retrieve mail */
void retrieve_mail() {
    int i, n;
    char buffer[MAXLINE];
    send_command( "LIST\r\n" );
    recv_response();
    printf( "Enter message ID: " );
    scanf( "%d", &i );
    sprintf( buffer, "RETR %d\r\n", i );
    send_command( buffer );
    recv_response();
    while ( (n = read( sockfd, buffer, MAXLINE )) > 0 )
        write( 1, buffer, n ); /* Write to standard output */
    if ( n < 0 )
        error( "Unable to read data from server" );
}

int main( int argc, char **argv ) {
    char hostname[MAXLINE];
    struct hostent *hp;

    if ( argc != 2 ) {
        printf( "Usage: %s <server>\n", argv[0] );
        exit( 1 );
    }

    /* Create a socket */
    sockfd = socket( AF_INET, SOCK_STREAM, 0 );
    if ( sockfd < 0 )
        error( "Unable to create socket" );

    /* Initialize server address */
    bzero( &servaddr, sizeof( servaddr ) );
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons( PORT );
    strcpy( hostname, argv[1] );
    hp = gethostbyname( hostname );
    if ( hp == NULL )
        error( "Unknown server address" );
    bcopy( hp->h_addr, &servaddr.sin_addr, hp->h_length );

    /* Connect to server */
    if ( connect( sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr) ) < 0 )
        error( "Unable to connect to server" );

    /* Get header message from server */
    recv_response();

    /* Authenticate user */
    auth_user();

    /* Show mailbox overview */
    show_mailbox();

    /* Retrieve mail */
    retrieve_mail();

    /* Quit */
    send_command( "QUIT\r\n" );
    recv_response();

    /* Close socket */
    close( sockfd );

    return 0;
}