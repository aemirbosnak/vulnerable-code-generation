//FormAI DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

int main()
{
    int fd[2];
    char *message = "Hello, Interprocess Communication!";
    char* buffer;

    if(pipe(fd) == -1){
        printf("Failed to create pipe!");
        return 1;
    }

    int pid = fork();

    if(pid > 0){
        // Parent Process
        close(fd[0]);
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    else if(pid == 0){ 
        // Child Process
        close(fd[1]);
        int file_size = lseek(fd[0], 0, SEEK_END);
        lseek(fd[0], 0, SEEK_SET); 
        buffer = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd[0], 0);

        int i = 0;
        while(buffer[i] != '\0'){
            if(i % 2 == 0)
                buffer[i] = toupper(buffer[i]);
            i++;
        }
        printf("%s\n", buffer);
        close(fd[0]);

        munmap(buffer, file_size);
    }
    else{
        printf("Failed to create child process!");
        return 1;
    }

    return 0;
}