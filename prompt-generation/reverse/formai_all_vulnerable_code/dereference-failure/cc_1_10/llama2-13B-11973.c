//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define DISK_SIZE (1024 * 1024 * 10)
#define BLOCK_SIZE (512)

struct file {
    char *name;
    size_t size;
    size_t blocks;
    char *data;
};

struct directory {
    char *name;
    struct file *files;
    size_t num_files;
};

void simulate_disk_io(struct directory *root_dir) {
    int fd;
    char buffer[BLOCK_SIZE];
    size_t offset;

    // simulate disk reads
    for (size_t i = 0; i < 10; i++) {
        sprintf(root_dir->files[i].name, "file%zu", i);
        root_dir->files[i].size = (size_t)random() % (DISK_SIZE / BLOCK_SIZE);
        root_dir->files[i].blocks = root_dir->files[i].size / BLOCK_SIZE;
        memset(root_dir->files[i].data, 0, root_dir->files[i].blocks * BLOCK_SIZE);

        fd = open(root_dir->files[i].name, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }

        offset = (size_t)random() % (root_dir->files[i].size / BLOCK_SIZE);
        read(fd, buffer, offset);
        close(fd);

        printf("Read %zu bytes from file %s\n", offset, root_dir->files[i].name);
    }

    // simulate disk writes
    for (size_t i = 0; i < 10; i++) {
        sprintf(root_dir->files[i].name, "file%zu", i);
        root_dir->files[i].size = (size_t)random() % (DISK_SIZE / BLOCK_SIZE);
        root_dir->files[i].blocks = root_dir->files[i].size / BLOCK_SIZE;
        memset(root_dir->files[i].data, 0, root_dir->files[i].blocks * BLOCK_SIZE);

        fd = open(root_dir->files[i].name, O_RDWR);
        if (fd == -1) {
            perror("open");
            exit(1);
        }

        offset = (size_t)random() % (root_dir->files[i].size / BLOCK_SIZE);
        write(fd, buffer, offset);
        close(fd);

        printf("Wrote %zu bytes to file %s\n", offset, root_dir->files[i].name);
    }
}

int main() {
    struct directory *root_dir = malloc(sizeof(struct directory));
    root_dir->name = "root";
    root_dir->files = malloc(sizeof(struct file) * 10);
    root_dir->num_files = 10;

    simulate_disk_io(root_dir);

    return 0;
}