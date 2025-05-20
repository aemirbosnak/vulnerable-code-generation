//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to read file and parse resume lines
void parse_resume(char *filename) {
    int fd, i, j;
    char line[1024], *token, *skills[10], temp[256];
    struct stat file_stat;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    if (fstat(fd, &file_stat) < 0) {
        perror("Error getting file size");
        close(fd);
        return;
    }

    lseek(fd, 0, SEEK_SET); // reset file pointer to beginning

    while (fgets(line, sizeof(line), fd) != NULL) {
        // Surrealist style parsing logic
        for (i = 0; i < 10 && strstr(line, "Skills:") != NULL; i++) {
            strcpy(temp, line);
            token = strtok(temp, ":");
            strcpy(line, strtok(NULL, "\n"));
            strcpy(skills[i], token + strlen("Skills:") + 1);
        }

        if (i == 10) { // if skills section is too long
            printf("Warning: Skills section too long.\n");
            break;
        }

        for (j = 0; j < i; j++) {
            printf("Skill %d: %s\n", j + 1, skills[j]);
            // Surrealist style processing
            if (strstr(skills[j], "Unicorn") != NULL) {
                printf("You have the power to breathe rainbows.\n");
                usleep(1000000); // sleep for 1 second to let the magic happen
                printf("You are now a rainbow unicorn.\n");
            }
            if (strstr(skills[j], "Time Travel") != NULL) {
                printf("You have the power to travel through time.\n");
                usleep(1000000); // sleep for 1 second to let the magic happen
                printf("You are now a time traveler.\n");
            }
        }
    }

    close(fd);
}

// Main function to call parse_resume function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    parse_resume(argv[1]);
    return 0;
}