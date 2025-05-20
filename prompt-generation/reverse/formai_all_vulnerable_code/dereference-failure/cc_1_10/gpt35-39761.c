//FormAI DATASET v1.0 Category: Data recovery tool ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 512

typedef struct ext2_dir_entry_2 {
    unsigned int inode;         // Inode number
    unsigned short rec_len;     // Directory entry length
    unsigned char name_len;     // Name length
    unsigned char file_type;    // File type
    char name[255];             // File name
} ext2_dir_entry_2;

typedef struct ext2_inode {
    unsigned short i_mode;      // File mode
    unsigned short i_uid;       // Owner UID
    unsigned int i_size;        // Size in bytes
    unsigned int i_atime;       // Access time
    unsigned int i_ctime;       // Creation time
    unsigned int i_mtime;       // Modification time
    unsigned int i_dtime;       // Deletion Time
    unsigned short i_gid;       // Group ID
    unsigned short i_links_count; // Links count
    unsigned int   i_blocks;    // Blocks count
    unsigned int   i_flags;     // File flags
    unsigned int   osd1;        // OS dependent 1
    unsigned int   i_block[15]; /* Pointers to blocks */
    unsigned int   i_generation;// File version (for NFS)
    unsigned int   i_file_acl;  // File ACL
    unsigned int   i_dir_acl;   // Directory ACL
    unsigned int   i_faddr;     // Fragment address
    unsigned char  i_osd2[12];  // OS dependent 2
} ext2_inode;

// Global Variables
FILE* file;                     // file pointer to image file
unsigned int block_size;        // size of block or sector in bytes
unsigned int inode_size;        // size of inode in bytes
unsigned int inode_table_block; // block number of inode table

// Function to get block number from inode
unsigned int get_block_num(unsigned int inode_num, unsigned int block_num) {
    unsigned int block;
    fseek(file, (inode_table_block*block_size) + (inode_num-1)*inode_size + 40 + (block_num*4), SEEK_SET);
    fread(&block, sizeof(unsigned int), 1, file);
    return block;
}

// Function to read data from blocks of a file given inode number 
void getData(unsigned int inode_num) {
    ext2_inode inode;
    fseek(file, (inode_table_block*block_size) + (inode_num-1)*inode_size, SEEK_SET);
    fread(&inode, sizeof(ext2_inode), 1, file);

    unsigned int i;
    for (i = 0; i < 12; i++) { // Direct blocks
        if (inode.i_block[i]) {
            char buffer[block_size];
            fseek(file, inode.i_block[i]*block_size, SEEK_SET);
            fread(&buffer, block_size, 1, file);
            printf("%s", buffer);
        }
    }

    if (inode.i_block[12]) { // Indirect blocks
        unsigned int* ind_block = malloc(block_size);
        fseek(file, inode.i_block[12]*block_size, SEEK_SET);
        fread(ind_block, block_size, 1, file);

        for (i = 0; i < block_size/4; i++) {
            if (ind_block[i]) {
                char buffer[block_size];
                fseek(file, ind_block[i]*block_size, SEEK_SET);
                fread(&buffer, block_size, 1, file);
                printf("%s", buffer);
            }
        }
        free(ind_block);
    }

    if (inode.i_block[13]) { // Double indirect blocks
        unsigned int* ind_block = malloc(block_size);
        fseek(file, inode.i_block[13]*block_size, SEEK_SET);
        fread(ind_block, block_size, 1, file);

        for (i = 0; i < block_size/4; i++) {
            if (ind_block[i]) {
                unsigned int* doubly_ind_block = malloc(block_size);
                fseek(file, ind_block[i]*block_size, SEEK_SET);
                fread(doubly_ind_block, block_size, 1, file);

                unsigned int j;
                for (j = 0; j < block_size/4; j++) {
                    if (doubly_ind_block[j]) {
                        char buffer[block_size];
                        fseek(file, doubly_ind_block[j]*block_size, SEEK_SET);
                        fread(&buffer, block_size, 1, file);
                        printf("%s", buffer);
                    }
                }
                free(doubly_ind_block);
            }
        }
        free(ind_block);
    }

    if (inode.i_block[14]) { // Triple indirect blocks
        unsigned int* ind_block = malloc(block_size);
        fseek(file, inode.i_block[14]*block_size, SEEK_SET);
        fread(ind_block, block_size, 1, file);

        for (i = 0; i < block_size/4; i++) {
            if (ind_block[i]) {
                unsigned int* doubly_ind_block = malloc(block_size);
                fseek(file, ind_block[i]*block_size, SEEK_SET);
                fread(doubly_ind_block, block_size, 1, file);

                unsigned int j;
                for (j = 0; j < block_size/4; j++) {
                    if (doubly_ind_block[j]) {
                        unsigned int* triply_ind_block = malloc(block_size);
                        fseek(file, doubly_ind_block[j]*block_size, SEEK_SET);
                        fread(triply_ind_block, block_size, 1, file);

                        unsigned int k;
                        for (k = 0; k < block_size/4; k++) {
                            if (triply_ind_block[k]) {
                                char buffer[block_size];
                                fseek(file, triply_ind_block[k]*block_size, SEEK_SET);
                                fread(&buffer, block_size, 1, file);
                                printf("%s", buffer);
                            }
                        }
                        free(triply_ind_block);
                    }
                }
                free(doubly_ind_block);
            }
        }
        free(ind_block);
    }
}

// main function
int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 0;
    }
    file = fopen(argv[1], "rb");
    if (!file) {
        printf("Unable to open %s\n", argv[1]);
        return 1;
    }

    fseek(file, 1024, SEEK_SET);
    fread(&block_size, sizeof(unsigned int), 1, file);
    inode_size = *(unsigned short*)((char*)&block_size + 24);
    fseek(file, 1024+32, SEEK_SET);
    fread(&inode_table_block, sizeof(unsigned int), 1, file);

    unsigned int inode_num = 12345; // change this to the desired inode number
    ext2_inode inode;
    fseek(file, (inode_table_block*block_size) + (inode_num-1)*inode_size, SEEK_SET);
    fread(&inode, sizeof(ext2_inode), 1, file);

    if (inode.i_mode & 0x4000) { // directory entry
        unsigned int block_num = 0; // change this to the desired block number
        unsigned int block = get_block_num(inode_num, block_num);
        unsigned int blockSize = block_size;
        fseek(file, block*blockSize, SEEK_SET);

        ext2_dir_entry_2* direntry = malloc(block_size);
        unsigned int rec_len = 0;
        while (rec_len < blockSize) {
            fread(direntry, block_size, 1, file);
            rec_len += direntry->rec_len;
            if (direntry->inode) {
                printf("%.*s\n", direntry->name_len, direntry->name);
            }
            fseek(file, block*blockSize + rec_len, SEEK_SET);
        }
        free(direntry);
    } else { // regular file
        getData(inode_num);
    }

    fclose(file);
    return 0;
}