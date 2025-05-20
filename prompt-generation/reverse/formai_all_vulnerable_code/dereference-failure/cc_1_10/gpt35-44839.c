//FormAI DATASET v1.0 Category: System boot optimizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 1024

char *get_line() {
    char *line = malloc(MAX_LINE);
    fgets(line, MAX_LINE, stdin);
    if(line[strlen(line)-1] == '\n') {
        line[strlen(line)-1] = '\0';
    }
    return line;
}

int main() {
    printf("Welcome to C System Boot Optimizer\n");
    printf("Please enter the number of programs you want to optimize (max 10): ");
    int num_programs = atoi(get_line());
    if(num_programs > 10) {
        printf("Sorry, the maximum number of programs is 10\n");
        return 1;
    }

    char *program_list[num_programs];
    for(int i=0; i<num_programs; i++) {
        printf("Enter the path of program %d: ", i+1);
        char *path = get_line();
        program_list[i] = malloc(strlen(path)+1);
        strcpy(program_list[i], path);
        free(path);
    }

    printf("Enter the boot delay (in seconds): ");
    int delay = atoi(get_line());

    printf("Boot optimization starts in ");
    for(int i=5; i>0; i--) {
        sleep(1);
        printf("%d... ", i);
        fflush(stdout);
    }
    printf("GO!\n");

    for(int i=0; i<num_programs; i++) {
        printf("Optimizing %s\n", program_list[i]);
        char cmd[strlen(program_list[i])+10];
        sprintf(cmd, "sleep %d; %s", delay, program_list[i]);
        system(cmd);
    }

    printf("Done optimizing!\n");
    return 0;
}