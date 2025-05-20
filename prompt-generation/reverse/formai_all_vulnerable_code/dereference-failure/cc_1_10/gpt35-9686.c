//FormAI DATASET v1.0 Category: Port Scanner ; Style: Alan Touring
// This program is a unique C Port Scanner in Alan Turing style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc , char *argv[]) {
    int sock ;
    struct sockaddr_in sin ;
    struct hostent *host ;
    int i , j ;
    int max_port = 10000 ;
    int min_port = 1 ;
    int start_port = 1 ;
    char *target ;

    if(argc == 2) {
        target = argv[1] ;
    } else if(argc == 4) {
        target = argv[1] ;
        min_port = atoi(argv[2]) ;
        max_port = atoi(argv[3]) ;
        if(min_port > max_port) {
            int temp = min_port ;
            min_port = max_port ;
            max_port = temp ;
        }
    } else {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]) ;
        fprintf(stderr, "Usage: %s <host> <min_port> <max_port>\n", argv[0]) ;
        return EXIT_FAILURE ;
    }

    if((host = gethostbyname(target)) == NULL) {
        perror("gethostbyname") ;
        return EXIT_FAILURE ;
    }

    memset(&sin, 0, sizeof(sin)) ;
    sin.sin_family = AF_INET ;
    sin.sin_addr = *((struct in_addr *)host->h_addr) ;

    fprintf(stdout, "Starting Port Scanner on %s\n", target) ;

    for(i = start_port ; i < max_port ; ++i) {
        sin.sin_port = htons(i) ;
        sock = socket(AF_INET , SOCK_STREAM , 0) ;
        if(sock < 0) {
            perror("socket") ;
            continue ;
        }

        if(connect(sock, (struct sockaddr *)&sin , sizeof(sin)) < 0) {
            // Port is closed or filtered
            close(sock) ;
            continue ;
        } else {
            // Port is open
            fprintf(stdout, "Port %d is open\n", i) ;
            close(sock) ;
        }
    }

    return EXIT_SUCCESS ;
}