//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 32
#define BUFFER_SIZE (WIDTH * HEIGHT * BPP / 8)

typedef struct {
    char *data;
    size_t size;
} buffer_t;

buffer_t *load_image(const char *filename) {
    buffer_t *buffer = malloc(sizeof(buffer_t));
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("Error statting file");
        close(fd);
        return NULL;
    }
    size_t file_size = sb.st_size;
    buffer->data = mmap(NULL, file_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (buffer->data == MAP_FAILED) {
        perror("Error mmapping file");
        close(fd);
        return NULL;
    }
    buffer->size = file_size;
    close(fd);
    return buffer;
}

void save_image(const char *filename, buffer_t *buffer) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        munmap(buffer->data, buffer->size);
        return;
    }
    if (ftruncate(fd, buffer->size) == -1) {
        perror("Error truncating file");
        close(fd);
        munmap(buffer->data, buffer->size);
        return;
    }
    if (write(fd, buffer->data, buffer->size) != buffer->size) {
        perror("Error writing to file");
        close(fd);
        munmap(buffer->data, buffer->size);
        return;
    }
    close(fd);
    munmap(buffer->data, buffer->size);
}

void editor(buffer_t *buffer) {
    char c;
    int x = 0;
    int y = 0;
    while (1) {
        printf("Editor> ");
        scanf("%c", &c);
        if (c == 'q') {
            break;
        }
        if (c == 'x' || c == 'X') {
            x++;
        } else if (c == 'y' || c == 'Y') {
            y++;
        } else if (c == 'l' || c == 'L') {
            x--;
        } else if (c == 'h' || c == 'H') {
            y--;
        }
        for (int i = 0; i < BUFFER_SIZE; i += BPP) {
            if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                buffer->data[i + y * WIDTH * BPP] = (buffer->data[i + y * WIDTH * BPP] & 0x000000FF) |
                                                    (c == 'x' || c == 'X' ? 0x00000100 : 0);
            }
        }
    }
}

int main(void) {
    buffer_t *buffer = load_image("image.jpg");
    if (buffer == NULL) {
        perror("Error loading image");
        return 1;
    }
    editor(buffer);
    save_image("edited_image.jpg", buffer);
    munmap(buffer->data, buffer->size);
    return 0;
}