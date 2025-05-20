//FormAI DATASET v1.0 Category: Data recovery tool ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 512

typedef struct __attribute__((__packed__)) {
    unsigned char filename[8];
    unsigned char ext[3];
    unsigned char attributes;
    unsigned char reserved[10];
    unsigned short create_time;
    unsigned short create_date;
    unsigned short access_date;
    unsigned short reserved2;
    unsigned short modified_time;
    unsigned short modified_date;
    unsigned short starting_cluster;
    unsigned int file_size;
}fileentry;

typedef struct {
    unsigned char name[8];
    unsigned char ext[3];
    unsigned int starting_cluster;
    unsigned int size;
} file;

unsigned short get_short(unsigned char *buf) {
    return (buf[1] << 8) | buf[0];
}

unsigned int get_int(unsigned char *buf) {
    return (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
}

void search_file(unsigned char *buf, char *fname, file *f) {
    int i, j;
    fileentry *fe = (fileentry*)buf;
    for(i=0; i<224; i++) {
        if(fe->filename[0] == 0x00) 
            return;
        if(fe->filename[0] != 0xE5) {
            if(strncmp(fe->filename, fname, 8) == 0 && strncmp(fe->ext, &fname[9], 3) == 0) {
                f->starting_cluster = fe->starting_cluster;
                f->size = fe->file_size;
                for(j=0;j<8;j++) 
                    f->name[j] = fe->filename[j];
                for(j=0;j<3;j++)
                    f->ext[j] = fe->ext[j];
                return;
            }
        }
        fe++;
    }
}

void read_sector(FILE *fp, unsigned int sector, unsigned char *buf) {
    fseek(fp, sector * 512, SEEK_SET);
    fread(buf, 1, 512, fp);
}

void read_cluster_chain(FILE *fp, unsigned int cluster, unsigned char *buf) {
    unsigned int sector;
    while(cluster < 0xFFF8) {
        sector = 31 + cluster - 2;
        read_sector(fp, sector, buf);
        buf += BLOCK_SIZE;
        cluster = get_short(buf);
    }
}

void save_file(file f, unsigned char *buf) {
    FILE *fp;
    char fname[13];
    int i;
    snprintf(fname, 13, "%s.%s", f.name, f.ext);
    fp = fopen(fname, "wb");
    if(fp) {
        fwrite(buf, 1, f.size, fp);
        fclose(fp);
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    unsigned char boot[BLOCK_SIZE];
    unsigned char fat1[BLOCK_SIZE * 9];
    unsigned char buf[BLOCK_SIZE * 16];
    file f;
    int i, j;

    if(argc != 3) {
        printf("\nUsage: %s <disk image> <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if(!fp) {
        fprintf(stderr, "\nError: could not open file %s\n", argv[1]);
        return 1;
    }

    /* Read boot sector */
    fread(boot, 1, BLOCK_SIZE, fp);

    /* Read FAT table */
    fseek(fp, BLOCK_SIZE, SEEK_SET);
    fread(fat1, 1, BLOCK_SIZE * 9, fp);

    /* Find file */
    search_file(&boot[0x2600], argv[2], &f);

    /* Read file */
    read_cluster_chain(fp, f.starting_cluster, buf);

    /* Save file */
    save_file(f, buf);

    fclose(fp);

    return 0;
}