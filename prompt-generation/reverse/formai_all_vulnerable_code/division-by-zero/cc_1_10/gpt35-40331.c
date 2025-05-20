//FormAI DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define NUM_THREADS 2

struct file_data {
     int fd;
     off_t size;
     char *data;
};

void *read_file(void *fd_data) {
     struct file_data *fd_info = (struct file_data *)fd_data;
     fd_info->data = malloc(fd_info->size+1);
     fd_info->data[fd_info->size] = '\0';
     int bytes_read = 0;
     while (bytes_read < fd_info->size) {
         int ret = read(fd_info->fd, fd_info->data+bytes_read, fd_info->size-bytes_read);
         if (ret <= 0) {
             if (ret < 0) {
                 fprintf(stderr, "Read error: %s\n", strerror(errno));
            }
             break;
         }
         bytes_read += ret;
     }
     close(fd_info->fd);
     return NULL;
}

void async_read_file(char *filename, char **file_data, off_t *file_size) {
     *file_data = NULL;
     *file_size = -1;
     int fd = open(filename, O_RDONLY);
     if (fd == -1) {
         fprintf(stderr, "Open error: %s\n", strerror(errno));
         return;
     }
     struct stat sb;
     if (fstat(fd, &sb) == -1) {
         fprintf(stderr, "Stat error: %s\n", strerror(errno));
         close(fd);
         return;
     }
     pthread_t threads[NUM_THREADS];
     struct file_data fd_infos[NUM_THREADS];
     int num_threads = sb.st_size / (sb.st_size / NUM_THREADS);
     int bytes_per_thread = sb.st_size / num_threads;
     *file_size = sb.st_size;
     for (int i = 0; i < num_threads; ++i) {
         fd_infos[i].fd = fd;
         fd_infos[i].size = (i == num_threads-1) ? sb.st_size - i*bytes_per_thread : bytes_per_thread;
         pthread_create(&threads[i], NULL, read_file, (void *)&fd_infos[i]);
     }
     for (int i = 0; i < num_threads; ++i) {
         pthread_join(threads[i], NULL);
     }
     *file_data = malloc(sb.st_size+1);
     *file_data[sb.st_size] = '\0';
     for (int i = 0; i < num_threads; ++i) {
         memcpy(*file_data+i*bytes_per_thread, fd_infos[i].data, fd_infos[i].size);
         free(fd_infos[i].data);
     }
     close(fd);
     return;
}

int main(int argc, char **argv) {
     if (argc != 2) {
         fprintf(stderr, "Usage: %s <file>\n", argv[0]);
         exit(1);
     }
     char *file_data;
     off_t file_size;
     async_read_file(argv[1], &file_data, &file_size);
     if (file_data) {
         printf("%s", file_data);
         free(file_data);
     }
     return 0;
 }