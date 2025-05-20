//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAGIC_NUMBER 0xDEADBEEF

void* alloc_mem(size_t size) {
  void* mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if(mem == MAP_FAILED) {
    perror("mmap");
    exit(EXIT_FAILURE);
  }
  return mem;
}

void free_mem(void* mem) {
  munmap(mem, strlen(mem));
}

int main() {
  // allocate some memory
  void* mem = alloc_mem(1024);
  if(mem == NULL) {
    perror("alloc_mem");
    return 1;
  }

  // write some data to the memory
  char* p = mem;
  for(int i = 0; i < 1024; i++) {
    *p++ = i % 2 ? 'A' : 'B';
  }

  // create a new process
  pid_t pid = fork();
  if(pid < 0) {
    perror("fork");
    return 1;
  }
  if(pid == 0) {
    // child process
    // mmap the memory as read-only
    void* mem2 = mmap(NULL, 1024, PROT_READ, MAP_PRIVATE, -1, 0);
    if(mem2 == MAP_FAILED) {
      perror("mmap");
      exit(EXIT_FAILURE);
    }
    // write some data to the memory
    char* p2 = mem2;
    for(int i = 0; i < 1024; i++) {
      *p2++ = 'C';
    }
    // exit the child process
    exit(EXIT_SUCCESS);
  } else {
    // parent process
    // wait for the child process to finish
    wait(NULL);
    // print the contents of the memory
    char* p = mem;
    for(int i = 0; i < 1024; i++) {
      printf("%c", *p++);
    }
    printf("\n");
  }

  // free the memory
  free_mem(mem);

  return 0;
}