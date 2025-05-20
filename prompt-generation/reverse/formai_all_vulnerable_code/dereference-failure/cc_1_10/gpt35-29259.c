//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
   // Print out a welcome message
   printf("Welcome to the Ephemeral System Administration Example Program!\n");

   // Generate a unique filename to use for the ephemeral file
   char *filename = strdup("/tmp/ephemeral_XXXXXX");
   if (mkstemp(filename) < 0) {
      perror("Failed to create ephemeral file");
      exit(EXIT_FAILURE);
   }
   printf("Generated a unique filename for the ephemeral file: %s\n", filename);

   // Write some dummy data to the ephemeral file
   int fd = open(filename, O_WRONLY);
   if (fd < 0) {
      perror("Failed to open ephemeral file for writing");
      exit(EXIT_FAILURE);
   }
   char *data = "This is some dummy data for the ephemeral file.";
   size_t data_len = strlen(data);
   if (write(fd, data, data_len) < 0) {
      perror("Failed to write to ephemeral file");
      exit(EXIT_FAILURE);
   }
   printf("Wrote %ld bytes of data to the ephemeral file.\n", data_len);

   // Wait for 10 seconds to simulate some activity
   printf("Waiting for 10 seconds to simulate some activity...\n");
   sleep(10);

   // Read back the data from the ephemeral file and print it out
   char buf[data_len + 1];
   if (lseek(fd, 0, SEEK_SET) < 0) {
      perror("Failed to seek to start of file");
      exit(EXIT_FAILURE);
   }
   if (read(fd, buf, data_len) < 0) {
      perror("Failed to read from ephemeral file");
      exit(EXIT_FAILURE);
   }
   printf("Read back %ld bytes of data from the ephemeral file: %s\n", data_len, buf);

   // Close and remove the ephemeral file
   if (close(fd) < 0) {
      perror("Failed to close ephemeral file");
      exit(EXIT_FAILURE);
   }
   if (unlink(filename) < 0) {
      perror("Failed to remove ephemeral file");
      exit(EXIT_FAILURE);
   }
   printf("Closed and removed the ephemeral file: %s\n", filename);

   // Print out a goodbye message
   printf("Thank you for using the Ephemeral System Administration Example Program!\n");
   exit(EXIT_SUCCESS);
}