//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: safe
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#define PAGE_SIZE getpagesize()
#define PAGE_MASK (PAGE_SIZE - 1)

static volatile uint64_t start = 0, stop = 0;

static void inline rdtscp(uint64_t *tsc) {
  uint32_t eax, ebx, ecx, edx;
  asm volatile("rdtscp" : "=a"(eax), "=d"(edx), "=c"(ecx), "=b"(ebx) :
               : "memory");
  *tsc = (((uint64_t)edx << 32) | eax);
}

static void inline start_tsc() { rdtscp(&start); }
static void inline stop_tsc() { rdtscp(&stop); }
static inline uint64_t get_tsc() { return stop - start; }

static void *alloc_pages(size_t npages) {
  void *ptr = mmap(NULL, npages * PAGE_SIZE, PROT_READ | PROT_WRITE,
                   MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
  if (ptr == MAP_FAILED) {
    perror("mmap");
    exit(EXIT_FAILURE);
  }
  return ptr;
}

static void free_pages(void *ptr, size_t npages) {
  if (munmap(ptr, npages * PAGE_SIZE)) {
    perror("munmap");
    exit(EXIT_FAILURE);
  }
}

static void touch_pages(void *ptr, size_t npages) {
  uint64_t t_sum = 0;
  for (size_t i = 0; i < npages; i++) {
    start_tsc();
    *((uint64_t *)((uintptr_t)ptr + i * PAGE_SIZE)) = i;
    stop_tsc();
    t_sum += get_tsc();
  }
  printf("Touching %lu pages took %lu cycles (avg %lu cycles per page)\n", npages,
         t_sum, t_sum / npages);
}

static void access_pages_seq(void *ptr, size_t npages) {
  uint64_t t_sum = 0;
  for (size_t i = 0; i < npages; i++) {
    start_tsc();
    *((uint64_t *)((uintptr_t)ptr + i * PAGE_SIZE));
    stop_tsc();
    t_sum += get_tsc();
  }
  printf("Accessing %lu pages sequentially took %lu cycles (avg %lu cycles per page)\n",
         npages, t_sum, t_sum / npages);
}

static void access_pages_random(void *ptr, size_t npages) {
  uint64_t t_sum = 0;
  for (size_t i = 0; i < npages; i++) {
    size_t index = rand() % npages;
    start_tsc();
    *((uint64_t *)((uintptr_t)ptr + index * PAGE_SIZE));
    stop_tsc();
    t_sum += get_tsc();
  }
  printf("Accessing %lu pages randomly took %lu cycles (avg %lu cycles per page)\n",
         npages, t_sum, t_sum / npages);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <num pages> <seed>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  size_t npages = strtoul(argv[1], NULL, 10);
  srand(strtoul(argv[2], NULL, 10));

  void *ptr = alloc_pages(npages);
  printf("Allocated %lu pages at %p\n", npages, ptr);

  touch_pages(ptr, npages);
  access_pages_seq(ptr, npages);
  access_pages_random(ptr, npages);

  free_pages(ptr, npages);
  return 0;
}