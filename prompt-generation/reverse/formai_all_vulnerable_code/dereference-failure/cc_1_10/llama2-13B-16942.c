//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>

#define MAX_NAME_LEN 256
#define MAX_FILE_LEN 1024 * 1024
#define MAX_FILES 100

struct file {
    char name[MAX_NAME_LEN];
    size_t size;
    int handle;
};

struct file_system {
    struct file *files;
    int num_files;
};

void init_file_system(struct file_system *fs) {
    fs->files = calloc(MAX_FILES, sizeof(struct file));
    fs->num_files = 0;
}

int create_file(struct file_system *fs, const char *name, size_t size) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("File already exists: %s\n", name);
            return -1;
        }
    }

    struct file *file = &fs->files[fs->num_files];
    strcpy(file->name, name);
    file->size = size;
    file->handle = -1;
    fs->num_files++;

    return 0;
}

int open_file(struct file_system *fs, const char *name, int flags) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            break;
        }
    }

    if (i == fs->num_files) {
        printf("File not found: %s\n", name);
        return -1;
    }

    if (fs->files[i].handle != -1) {
        close(fs->files[i].handle);
    }

    fs->files[i].handle = open(name, flags);
    if (fs->files[i].handle == -1) {
        perror("open");
        return -1;
    }

    return 0;
}

int read_file(struct file_system *fs, const char *name, char *buf, size_t size) {
    int fd = open(name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    size_t bytes_read = read(fd, buf, size);
    close(fd);

    return bytes_read;
}

int write_file(struct file_system *fs, const char *name, const char *buf, size_t size) {
    int fd = open(name, O_WRONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    size_t bytes_written = write(fd, buf, size);
    close(fd);

    return bytes_written;
}

int delete_file(struct file_system *fs, const char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            break;
        }
    }

    if (i == fs->num_files) {
        printf("File not found: %s\n", name);
        return -1;
    }

    close(fs->files[i].handle);
    free(fs->files[i].name);
    fs->files[i].handle = -1;
    fs->num_files--;

    return 0;
}

int main() {
    struct file_system fs;
    init_file_system(&fs);

    // Create some files
    create_file(&fs, "file1.txt", 1024);
    create_file(&fs, "file2.txt", 2048);
    create_file(&fs, "file3.txt", 4096);

    // Open some files
    open_file(&fs, "file1.txt", O_RDONLY);
    open_file(&fs, "file2.txt", O_RDWR);
    open_file(&fs, "file3.txt", O_WRONLY);

    // Read from some files
    char buf[1024];
    read_file(&fs, "file1.txt", buf, 1024);
    read_file(&fs, "file2.txt", buf, 2048);
    read_file(&fs, "file3.txt", buf, 4096);

    // Write to some files
    char *buf1 = "Hello, world!";
    write_file(&fs, "file1.txt", buf1, strlen(buf1));
    char *buf2 = "This is a test.";
    write_file(&fs, "file2.txt", buf2, strlen(buf2));
    char *buf3 = "This is a longer test.";
    write_file(&fs, "file3.txt", buf3, strlen(buf3));

    // Delete some files
    delete_file(&fs, "file1.txt");
    delete_file(&fs, "file2.txt");
    delete_file(&fs, "file3.txt");

    return 0;
}