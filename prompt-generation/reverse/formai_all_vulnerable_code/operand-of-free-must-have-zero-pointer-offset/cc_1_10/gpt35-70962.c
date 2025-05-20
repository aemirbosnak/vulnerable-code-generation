//FormAI DATASET v1.0 Category: Memory management ; Style: Cryptic
#define SPLT 'e'-'a'
#define SEC 1000
#define MEM_SIZE 10000

int main() {
    long int mem_addr_start = (long int)(malloc(MEM_SIZE)) + SPLT*SEC;
    if (mem_addr_start == 0) {
        return 1;
    }
    memset((void*)mem_addr_start, 0, MEM_SIZE);
    int *p1 = (int*)(mem_addr_start + SEC);
    *p1 = 500;
    short *p2 = (short*)(mem_addr_start + SEC*2);
    *p2 = 20;
    char *p3 = (char*)(mem_addr_start + SEC*3);
    *p3 = 'a';

    int *p4 = (int*)(mem_addr_start + SEC*6);
    *p4 = 999;

    int *p5 = (int*)(mem_addr_start + SEC*7);
    *p5 = 1000;

    free((void*)(mem_addr_start + SEC*2));
    free((void*)(mem_addr_start + SEC*7));

    char *p6 = (char*)(mem_addr_start + SEC*8);
    *p6 = 'z';

    int *p7 = (int*)(mem_addr_start + SEC*9);
    *p7 = 1500;

    short *p8 = (short*)(mem_addr_start + SEC*12);
    *p8 = 30;

    char *p9 = (char*)(mem_addr_start + SEC*13);
    *p9 = 'b';

    free((void*)p2);
    free((void*)p8);

    char *p10 = (char*)(mem_addr_start + SEC*14);
    *p10 = 'd';

    // Print the values stored at each memory address
    printf("Value at mem_addr_start + SEC: %d\n", *p1);
    printf("Value at mem_addr_start + SEC*2: %d\n", *p2);
    printf("Value at mem_addr_start + SEC*3: %c\n", *p3);
    printf("Value at mem_addr_start + SEC*6: %d\n", *p4);
    printf("Value at mem_addr_start + SEC*7: %d\n", *p5);
    printf("Value at mem_addr_start + SEC*8: %c\n", *p6);
    printf("Value at mem_addr_start + SEC*9: %d\n", *p7);
    printf("Value at mem_addr_start + SEC*12: %d\n", *p8);
    printf("Value at mem_addr_start + SEC*13: %c\n", *p9);
    printf("Value at mem_addr_start + SEC*14: %c\n", *p10);

    free((void*)mem_addr_start);
    return 0;
}