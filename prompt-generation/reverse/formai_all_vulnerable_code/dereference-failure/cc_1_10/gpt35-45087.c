//FormAI DATASET v1.0 Category: System administration ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define SECRET_KEY "my_magic_key"
#define MAX_ATTEMPTS 5
#define LOCK_FILE "/var/lock/myapp.lock"
#define LOG_FILE "/var/log/myapp.log"

void log_message(char *filename, char *message) {
    time_t now;
    struct tm *tm_struct;
    char log_time[20];
    FILE *log_file;
    
    now = time(NULL);
    tm_struct = localtime(&now);
    strftime(log_time, sizeof(log_time), "%m/%d/%Y %T", tm_struct);
    
    log_file = fopen(filename, "a");
    if (log_file == NULL) {
        printf("Could not open log file %s\n", filename);
        return;
    }
    
    fprintf(log_file, "[%s] %s\n", log_time, message);
    fclose(log_file);
}

void lock(void) {
    int fd;
    if ((fd = open(LOCK_FILE, O_RDWR|O_CREAT, 0644)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    if (flock(fd, LOCK_EX|LOCK_NB) == -1) {
        if (errno == EWOULDBLOCK) {
            printf("Another instance of the program is already running\n");
            exit(EXIT_SUCCESS);
        }
        perror("flock");
        exit(EXIT_FAILURE);
    }
}

void unlock(void) {
    int fd;
    if ((fd = open(LOCK_FILE, O_RDWR|O_CREAT, 0644)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    if (flock(fd, LOCK_UN) == -1) {
        perror("flock");
        exit(EXIT_FAILURE);
    }
    close(fd);
}

int main(int argc, char **argv) {
    char input[50];
    int attempt = 0;
    
    lock();
    
    while (1) {
        printf("Enter the secret key to access the configuration: ");
        scanf("%s", input);
        
        if (strcmp(input, SECRET_KEY) == 0) {
            printf("Access granted. You can edit the configuration now.\n");
            break;
        }
        
        log_message(LOG_FILE, "Incorrect secret key provided");
        printf("Incorrect secret key. Try again.\n");
        
        attempt++;
        if (attempt >= MAX_ATTEMPTS) {
            printf("Maximum number of attempts reached. Program will exit.\n");
            log_message(LOG_FILE, "Maximum number of attempts reached");
            exit(EXIT_FAILURE);
        }
    }
    
    unlock();
    
    return 0;
}