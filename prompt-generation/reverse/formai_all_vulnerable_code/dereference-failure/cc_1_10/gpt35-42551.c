//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<signal.h>

#define MAXWORDS 1000 // Maximum number of words that can be present in the input text.
#define MAXSIZE 1024 // Maximum size of each word (including null character).

/* Function to read the input text from the specified file descriptor. */
int read_input(int fd, char *buffer, size_t size)
{
    int bytes_read = 0;

    do {
        bytes_read = read(fd, buffer, size);
        if(bytes_read == -1) {
            if(errno == EINTR)
                continue;
            else
                return -1;
        }
        break;
    } while(1);

    return bytes_read;
}

/* Function to count the words in the given input text and print the result. */
void count_words(char *input_text, int bytes_read)
{
    int num_words = 0;

    for(int i=0; i<bytes_read; i++) {
        if(isspace(input_text[i])) {
            num_words++;
        }
    }

    printf("Number of words in the input text: %d\n", num_words+1);
}

int main(int argc, char **argv)
{
    int fd_input; // File descriptor to read input from.

    if(argc < 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        exit(0);
    }

    /* Open the input file for reading. */
    fd_input = open(argv[1], O_RDONLY);
    if(fd_input == -1) {
        perror("Error opening input file: ");
        exit(1);
    }

    /* Read the input text from the file descriptor. */
    char *input_text = calloc(MAXSIZE, sizeof(char));
    int bytes_read = read_input(fd_input, input_text, MAXSIZE);

    /* Count the number of words in the input text and print the result. */
    count_words(input_text, bytes_read);

    return 0;
}