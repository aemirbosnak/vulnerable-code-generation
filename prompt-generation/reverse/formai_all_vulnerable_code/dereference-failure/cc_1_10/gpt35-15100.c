//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv) {
   if (argc < 2) {
      printf("Usage: %s <filename>\n", argv[0]);
      return 1;
   }

   int fd = open(argv[1], O_RDONLY);
   if (fd < 0) {
      printf("Error: could not open file %s (%s)\n", argv[1], strerror(errno));
      return 1;
   }

   // Let's get the file size to allocate memory
   struct stat st;
   if (fstat(fd, &st) < 0) {
      printf("Error: could not get status of file %s (%s)\n", argv[1], strerror(errno));
      close(fd);
      return 1;
   }
   size_t size = st.st_size;

   // Read the file into memory
   char *buffer = (char *) malloc(size);
   if (buffer == NULL) {
      printf("Error: could not allocate memory (%s)\n", strerror(errno));
      close(fd);
      return 1;
   }
   ssize_t n = read(fd, buffer, size);
   if (n < 0 || n != (ssize_t) size) {
      printf("Error: could not read file %s (%s)\n", argv[1], strerror(errno));
      close(fd);
      free(buffer);
      return 1;
   }

   // Now, let's extract some metadata from the file
   printf("Filename: %s\n", argv[1]);
   printf("File size: %lu bytes\n", size);
   printf("First 10 bytes: '");
   for (size_t i = 0; i < 10; i++) {
      printf("%02x ", (int) buffer[i]);
   }
   printf("'\n");

   // Cleanup
   close(fd);
   free(buffer);
   return 0;
}