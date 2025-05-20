//FormAI DATASET v1.0 Category: File Encyptor ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <aio.h>

void read_callback(__sigval_t sigval);

typedef struct {
  struct aiocb cb;
  char* buffer;
} aio_context;

int main(int argc, char* argv[]) {

  if (argc != 3) {
    printf("Usage: %s <source file> <destination file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char* src_path = argv[1];
  const char* dest_path = argv[2];

  int src_fd = open(src_path, O_RDONLY);
  if (src_fd < 0) {
    int err = errno;
    printf("Could not open %s: %s\n", src_path, strerror(err));
    exit(EXIT_FAILURE);
  }

  int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (dest_fd < 0) {
    int err = errno;
    printf("Could not open %s: %s\n", dest_path, strerror(err));
    close(src_fd);
    exit(EXIT_FAILURE);
  }

  const size_t buffer_size = 1024;
  char* buffer = malloc(buffer_size);
  if (!buffer) {
    printf("Could not allocate buffer\n");
    close(src_fd);
    close(dest_fd);
    exit(EXIT_FAILURE);
  }

  aio_context context;
  memset(&context.cb, 0, sizeof(context.cb));
  context.cb.aio_fildes = src_fd;
  context.cb.aio_buf = buffer;
  context.cb.aio_nbytes = buffer_size;
  context.cb.aio_sigevent.sigev_notify = SIGEV_THREAD;
  context.cb.aio_sigevent.sigev_notify_function = read_callback;
  context.cb.aio_sigevent.sigev_notify_attributes = NULL;
  context.cb.aio_sigevent.sigev_value.sival_ptr = &context;

  off_t offset = 0;
  int count = 0;
  while ((count = aio_read(&context.cb)) > 0) {
    while (aio_error(&context.cb) == EINPROGRESS) {
      // yield CPU and let the read operation complete
      usleep(1000);
    }

    int read_result = aio_return(&context.cb);
    if (read_result < 0) {
      printf("Encountered error while reading from file\n");
      break;
    }

    for (int i = 0; i < read_result; i++) {
      buffer[i] ^= 0xFF;
    }

    context.cb.aio_fildes = dest_fd;
    context.cb.aio_offset = offset;
    context.cb.aio_nbytes = read_result;
    context.buffer = buffer;

    while (aio_write(&context.cb) == -1 && errno == EAGAIN) {
      // yield CPU and let the write operation begin
      usleep(1000);
    }

    while (aio_error(&context.cb) == EINPROGRESS) {
      // yield CPU and let the write operation complete
      usleep(1000);
    }

    int write_result = aio_return(&context.cb);
    if (write_result < 0) {
      printf("Encountered error while writing to file\n");
      break;
    }

    offset += write_result;
  }

  if (count == -1) {
    int err = aio_error(&context.cb);
    printf("Encountered error while scheduling read operation: %s\n", strerror(err));
  }

  free(buffer);
  close(src_fd);
  close(dest_fd);
}

void read_callback(__sigval_t sigval) {
  aio_context* context = (aio_context*)sigval.sival_ptr;

  for (int i = 0; i < context->cb.aio_nbytes; i++) {
    context->buffer[i] ^= 0xFF;
  }

  context->cb.aio_fildes = *(int*)context->cb.aio_sigevent.sigev_value.sival_ptr;
  context->cb.aio_offset = lseek(context->cb.aio_fildes, 0, SEEK_END);
  context->cb.aio_nbytes = aio_return(&context->cb);
}