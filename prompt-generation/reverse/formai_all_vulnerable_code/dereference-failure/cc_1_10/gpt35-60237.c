//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>

int main(int argc, char** argv){
    char buf[1024];
    int fd;
    ssize_t num_read;
    char* meminfo_path = "/proc/meminfo";
    
    while(1){
        //Open the meminfo file for reading
        fd = open(meminfo_path, O_RDONLY);
        if(fd == -1){
            fprintf(stderr, "Error opening %s: %s\n", meminfo_path, strerror(errno));
            exit(EXIT_FAILURE);
        }
        
        //Read the file and look for the line starting with "MemAvailable:"
        num_read = read(fd, buf, 1023);
        if(num_read == -1){
            fprintf(stderr, "Error reading %s: %s\n", meminfo_path, strerror(errno));
            exit(EXIT_FAILURE);
        }
        buf[num_read] = '\0';
        char* line_start = strstr(buf, "MemAvailable:");
        if(line_start == NULL){
            fprintf(stderr, "Error: Could not find MemAvailable line in %s\n", meminfo_path);
            exit(EXIT_FAILURE);
        }
        line_start += 13; //Skip "MemAvailable:" string
        
        //Parse the available memory value and convert to integer
        char* end = NULL;
        long available_mem = strtol(line_start, &end, 0);
        if(end == NULL){
            fprintf(stderr, "Error: Could not parse available memory value in %s\n", meminfo_path);
            exit(EXIT_FAILURE);
        }
        
        //Print the available memory usage in MB
        printf("Available memory usage: %ld MB\n", available_mem/1024);
        
        //Close the file and sleep for 5 seconds
        close(fd);
        sleep(5);
    }
    
    return 0;
}