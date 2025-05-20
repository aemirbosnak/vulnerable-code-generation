//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/mman.h>
#include <string.h>

#define MAX_PATH 1024

struct metadata_item {
  char *name;
  uint8_t *data;
  size_t size;
};

struct metadata_extractor {
  int fd;
  struct stat stat;
  void *mmap_addr;
  Elf64_Ehdr *ehdr;
  Elf64_Shdr *shdr;
  char *strtab;
  struct metadata_item *items;
  size_t num_items;
};

int extract_metadata(struct metadata_extractor *extractor, char *path) {
  int ret;
  struct metadata_item *item;

  extractor->fd = open(path, O_RDONLY);
  if (extractor->fd < 0) {
    return -1;
  }

  ret = fstat(extractor->fd, &extractor->stat);
  if (ret < 0) {
    return -1;
  }

  extractor->mmap_addr = mmap(NULL, extractor->stat.st_size, PROT_READ, MAP_PRIVATE, extractor->fd, 0);
  if (extractor->mmap_addr == MAP_FAILED) {
    return -1;
  }

  extractor->ehdr = (Elf64_Ehdr *)extractor->mmap_addr;
  if (extractor->ehdr->e_ident[EI_MAG0] != ELFMAG0 || extractor->ehdr->e_ident[EI_MAG1] != ELFMAG1 || extractor->ehdr->e_ident[EI_MAG2] != ELFMAG2 || extractor->ehdr->e_ident[EI_MAG3] != ELFMAG3) {
    return -1;
  }

  extractor->shdr = (Elf64_Shdr *)(extractor->mmap_addr + extractor->ehdr->e_shoff);
  extractor->strtab = (char *)(extractor->mmap_addr + extractor->shdr[extractor->ehdr->e_shstrndx].sh_offset);

  extractor->items = malloc(sizeof(struct metadata_item) * extractor->ehdr->e_shnum);
  if (extractor->items == NULL) {
    return -1;
  }

  for (size_t i = 0; i < extractor->ehdr->e_shnum; i++) {
    item = &extractor->items[i];
    item->name = extractor->strtab + extractor->shdr[i].sh_name;
    item->data = extractor->mmap_addr + extractor->shdr[i].sh_offset;
    item->size = extractor->shdr[i].sh_size;
  }

  extractor->num_items = extractor->ehdr->e_shnum;

  return 0;
}

void print_metadata(struct metadata_extractor *extractor) {
  for (size_t i = 0; i < extractor->num_items; i++) {
    printf("%s: ", extractor->items[i].name);
    for (size_t j = 0; j < extractor->items[i].size; j++) {
      printf("%02x", extractor->items[i].data[j]);
    }
    printf("\n");
  }
}

void free_metadata(struct metadata_extractor *extractor) {
  if (extractor->mmap_addr != MAP_FAILED) {
    munmap(extractor->mmap_addr, extractor->stat.st_size);
  }
  if (extractor->fd >= 0) {
    close(extractor->fd);
  }
  if (extractor->items != NULL) {
    free(extractor->items);
  }
}

int main(int argc, char **argv) {
  struct metadata_extractor extractor;
  int ret;

  if (argc < 2) {
    printf("Usage: %s <file>\n", argv[0]);
    return 1;
  }

  ret = extract_metadata(&extractor, argv[1]);
  if (ret < 0) {
    printf("Error extracting metadata: %s\n", strerror(-ret));
    return 1;
  }

  print_metadata(&extractor);

  free_metadata(&extractor);

  return 0;
}