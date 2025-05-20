//FormAI DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>

#define MAX_FILES 100
#define MAX_FILENAME_LEN 256
#define MAX_BLOCK_SIZE 8192
#define BLOCK_SIZE 1024

// File block
struct file_block
{
    char file_data[BLOCK_SIZE];
    int size;
    int written;
};

// File entry
struct file_entry
{
    char name[MAX_FILENAME_LEN];
    time_t mtime;
    struct file_block blocks[MAX_BLOCK_SIZE];
    int num_blocks;
};

// File synchronization message
struct sync_message {
    int type;
    int file_num;
    struct file_entry file_info;
};

// List of files in the directory
struct file_entry files[MAX_FILES];
int num_files = 0;

// Signal handler for killing a child process
void sig_handler(int signum) {
    printf("Killing child process...\n");
    exit(1);
}

// Send message to all other processes
void send_message(int pipe_fd[], struct sync_message *msg) {
    for (int i = 0; i < num_files; i++) {
        if (i != msg->file_num) {
            write(pipe_fd[i * 2 + 1], msg, sizeof(struct sync_message));
        }
    }
}

// Receive message from a specific process
void receive_message(int pipe_fd[], int file_num, struct sync_message *msg) {
    read(pipe_fd[file_num * 2], msg, sizeof(struct sync_message));
}

// Add file to the list of files
void add_file(char *name) {
    struct file_entry entry;
    strcpy(entry.name, name);
    entry.mtime = 0;
    entry.num_blocks = 0;
    files[num_files++] = entry;
}

// Get file index by name
int get_file_index(char *name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Synchronize all files in the directory
void synchronize(int pipe_fd[]) {
    struct dirent *dirp;
    DIR *dp;
    while (1) {
        // Check for new files
        dp = opendir(".");
        while ((dirp = readdir(dp)) != NULL) {
            if (dirp->d_type == DT_REG) {
                int index = get_file_index(dirp->d_name);
                if (index == -1) {
                    add_file(dirp->d_name);
                    printf("Added new file: %s\n", dirp->d_name);
                }
            }
        }
        closedir(dp);

        // Check for modified files
        for (int i = 0; i < num_files; i++) {
            struct stat sb;
            if (stat(files[i].name, &sb) == 0) {
                if (sb.st_mtime > files[i].mtime) {
                    files[i].mtime = sb.st_mtime;
                    printf("Modified file: %s\n", files[i].name);
                    // Read blocks of the file
                    FILE *fp;
                    fp = fopen(files[i].name, "r");
                    int block_num = 0;
                    while (!feof(fp)) {
                        struct file_block block;
                        block.size = fread(block.file_data, 1, BLOCK_SIZE, fp);
                        block.written = 0;
                        files[i].blocks[block_num++] = block;
                    }
                    fclose(fp);
                    files[i].num_blocks = block_num;

                    // Send file to other processes
                    struct sync_message msg;
                    msg.type = 1;
                    msg.file_num = i;
                    msg.file_info = files[i];
                    send_message(pipe_fd, &msg);
                }
            }
        }

        sleep(5);
    }
}

// Synchronize file with the other processes
void synchronize_file(int pipe_fd[], struct sync_message *msg) {
    int file_num = msg->file_num;
    struct file_entry file_info = msg->file_info;
    for (int i = 0; i < file_info.num_blocks; i++) {
        struct file_block block = file_info.blocks[i];
        int block_written = 0;
        while (block_written < block.size) {
            int write_size = block.size - block_written;
            if (write_size > BLOCK_SIZE) {
                write_size = BLOCK_SIZE;
            }
            if (block.written == 0) {
                printf("Receiving block %d of file %s\n", i, file_info.name);
            }
            write_size = write(pipe_fd[file_num * 2], block.file_data + block_written, write_size);
            if (write_size < 0) {
                if (errno == EINTR) {
                    continue;
                }
                else {
                    printf("Error writing block: %d\n", errno);
                    return;
                }
            }
            block.written += write_size;
            block_written += write_size;
        }
        file_info.blocks[i] = block;
        if (block.written == block.size) {
            printf("Received block %d of file %s\n", i, file_info.name);
        }
    }
    files[file_num] = file_info;
}

// Main function
int main() {
    // Create pipes for all other processes
    int pipe_fd[num_files * 2];
    for (int i = 0; i < num_files; i++) {
        if (pipe(pipe_fd + i * 2) == -1) {
            printf("Error creating pipe: %d\n", errno);
            return 1;
        }
    }

    // Start child processes
    for (int i = 0; i < num_files; i++) {
        pid_t pid;
        pid = fork();
        if (pid == -1) {
            printf("Error creating child process\n");
            return 1;
        }
        if (pid == 0) {
            // Child process
            signal(SIGINT, sig_handler);
            printf("Started child process for file %s\n", files[i].name);
            while (1) {
                struct sync_message msg;
                receive_message(pipe_fd, i, &msg);
                if (msg.type == 1) {
                    synchronize_file(pipe_fd, &msg);
                }
            }
            exit(0);
        }
        else {
            // Parent process
            close(pipe_fd[i * 2]);
            printf("Created pipe with child process for file %s\n", files[i].name);
        }
    }

    // Synchronize all files in the directory
    synchronize(pipe_fd);

    return 0;
}