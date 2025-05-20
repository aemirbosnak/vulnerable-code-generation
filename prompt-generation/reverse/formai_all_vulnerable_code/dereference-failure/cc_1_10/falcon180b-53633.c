//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(){
    
    int fd;
    char *ptr;
    size_t page_size = sysconf(_SC_PAGE_SIZE);
    size_t mem_size = 0;
    size_t used_mem = 0;
    size_t free_mem = 0;
    size_t largest_free_block = 0;
    char filename[100];
    int i;
    
    printf("Enter the name of the process to monitor: ");
    scanf("%s", filename);
    
    fd = open("/proc/%s/maps", O_RDONLY);
    
    if(fd == -1){
        printf("Error opening file\n");
        exit(1);
    }
    
    mem_size = lseek(fd, 0, SEEK_END);
    
    if(mem_size == -1){
        printf("Error getting file size\n");
        close(fd);
        exit(1);
    }
    
    lseek(fd, 0, SEEK_SET);
    
    ptr = mmap(NULL, mem_size, PROT_READ, MAP_PRIVATE, fd, 0);
    
    if(ptr == MAP_FAILED){
        printf("Error mapping file\n");
        close(fd);
        exit(1);
    }
    
    close(fd);
    
    for(i=0; i<mem_size; i+=page_size){
        if(ptr[i] == 0){
            used_mem += page_size;
        }else{
            free_mem += page_size;
        }
    }
    
    largest_free_block = free_mem;
    
    while(largest_free_block > 0){
        if(ptr[largest_free_block-1] == 0){
            largest_free_block -= page_size;
        }else{
            break;
        }
    }
    
    printf("Total memory: %lu KB\n", mem_size/1024);
    printf("Used memory: %lu KB\n", used_mem/1024);
    printf("Free memory: %lu KB\n", free_mem/1024);
    printf("Largest free block: %lu KB\n", largest_free_block/1024);
    
    munmap(ptr, mem_size);
    close(fd);
    
    return 0;
}