//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void reverse(char *str, int start, int end) {
 char temp;
 for (; start < end; start++, end--) {
 temp = str[start];
 str[start] = str[end];
 str[end] = temp;
 }
}

int main(int argc, char *argv[]) {
 if (argc != 2) {
 printf("Usage: %s <filename>\n", argv[0]);
 exit(1);
 }

 int fd = open(argv[1], O_RDONLY);
 if (fd == -1) {
 perror("open");
 exit(1);
 }

 struct stat st;
 if (fstat(fd, &st) == -1) {
 perror("fstat");
 exit(1);
 }

 char *buf = malloc(st.st_size);
 if (buf == NULL) {
 perror("malloc");
 exit(1);
 }

 ssize_t bytes_read = read(fd, buf, st.st_size);
 if (bytes_read == -1) {
 perror("read");
 exit(1);
 }

 close(fd);

 // Reverse the string
 reverse(buf, 0, strlen(buf) - 1);

 printf("Original string: %s\n", buf);

 int len = strlen(argv[1]);
 // Reverse the filename and print it
 reverse(argv[1], 0, len - 1);
 printf("Reversed filename: %s\n", argv[1]);

 free(buf);
 return 0;
}