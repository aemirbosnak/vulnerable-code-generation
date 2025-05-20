//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

//Function to recursively scan and check for viruses in each file
void scan_file(char* filename) {
    FILE* file_pointer = fopen(filename, "r");
    char* buffer = (char*) malloc(1024);
    size_t read = fread(buffer, 1, 1024, file_pointer);
    while(read > 0) {
        // Here, you can add your own virus detection code
        for(int i=0; i<read-3; i++) {
            if(buffer[i] == 'v' && buffer[i+1] == 'i' && buffer[i+2] == 'r' && buffer[i+3] == 'u') {
                printf("File %s is infected with a virus!\n", filename);
                return;
            }
        }
        read = fread(buffer, 1, 1024, file_pointer);
    }
    fclose(file_pointer);
    free(buffer);
}

//Function to recursively check all files and directories
void check_directory(char* dirname) {
    DIR* directory_pointer = opendir(dirname);
    if(directory_pointer == NULL) {
        return;
    }
    struct dirent* entry = readdir(directory_pointer);
    while(entry != NULL) {
        char* filename = entry->d_name;
        if(filename[0] != '.') {
            char* filepath = (char*) malloc(strlen(dirname) + strlen(filename) + 2);
            sprintf(filepath, "%s/%s", dirname, filename);
            struct stat statbuf;
            stat(filepath, &statbuf);
            if(S_ISDIR(statbuf.st_mode)) { //It is a directory
                check_directory(filepath);
            } else { //It is a file
                scan_file(filepath);
            }
            free(filepath);
        }
        entry = readdir(directory_pointer);
    }
    closedir(directory_pointer);
}

//Function to connect to a remote server to download files to scan
void connect_to_server(char* server_address) {
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if(getaddrinfo(server_address, "12345", &hints, &result) != 0) {
        perror("Could not get remote addressinfo!");
        exit(1);
    }
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if(sockfd == -1) {
        perror("Could not create socket!");
        exit(1);
    }
    if(connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("Could not connect to remote server!");
        exit(1);
    }
    char* buffer = (char*) malloc(1024);
    int filedescriptor;
    while(1) {
        size_t read = recv(sockfd, buffer, 1024, 0);
        if(read == 0) {
            break;
        } else if(read == -1) {
            if(errno == EINTR) {
                continue;
            }
            perror("Failed to receive data from server!");
            break;
        }
        if(filedescriptor == 0) {
            char* filename = strstr(buffer, ":") + 1;
            filedescriptor = open(filename, O_CREAT | O_RDWR, S_IRWXU);
            if(filedescriptor == -1) {
                perror("Could not create file to write data to!");
                break;
            }
        }
        write(filedescriptor, buffer, read);
    }
    close(filedescriptor);
    free(buffer);
    close(sockfd);
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Please provide a filename or directory to check for viruses.\n");
        return 1;
    }
    if(strcmp(argv[1], "--remote") == 0) {
        connect_to_server(argv[2]);
    } else {
        struct stat statbuf;
        stat(argv[1], &statbuf);
        if(S_ISDIR(statbuf.st_mode)) { //It is a directory
            check_directory(argv[1]);
        } else { //It is a file
            scan_file(argv[1]);
        }
    }
    return 0;
}