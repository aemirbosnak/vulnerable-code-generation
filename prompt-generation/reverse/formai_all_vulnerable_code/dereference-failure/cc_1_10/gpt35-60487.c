//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

/* Define metadata field sizes */
#define MAX_TITLE_LEN 128
#define MAX_ARTIST_LEN 64
#define MAX_ALBUM_LEN 64
#define MAX_YEAR_LEN 4

/* Define metadata structure */
typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char year[MAX_YEAR_LEN];
} metadata_t;

/* Define function to extract metadata asynchronously */
void extract_metadata_async(char *filename)
{
    /* Open file for reading */
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: could not open file '%s'.\n", filename);
        return;
    }

    /* Get file size */
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        fprintf(stderr, "Error: could not get file size for '%s'.\n", filename);
        close(fd);
        return;
    }

    /* Memory-map file */
    char *file_data = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_data == MAP_FAILED) {
        fprintf(stderr, "Error: could not memory-map file '%s'.\n", filename);
        close(fd);
        return;
    }

    /* Close file */
    close(fd);

    /* Define metadata structure and flags */
    metadata_t metadata;
    bool title_flag = false;
    bool artist_flag = false;
    bool album_flag = false;
    bool year_flag = false;
    int title_len = 0;
    int artist_len = 0;
    int album_len = 0;
    int year_len = 0;

    /* Extract metadata */
    for (int i = 0; i < sb.st_size; i++) {
        /* Check for end of line */
        if (file_data[i] == '\n') {
            /* Check for metadata field */
            if (strncmp(&file_data[i+1], "TITLE=", 6) == 0) {
                /* Extract title */
                strncpy(metadata.title, &file_data[i+7], title_len);
                metadata.title[title_len] = '\0';
                title_flag = true;
            }
            else if (strncmp(&file_data[i+1], "ARTIST=", 7) == 0) {
                /* Extract artist */
                strncpy(metadata.artist, &file_data[i+8], artist_len);
                metadata.artist[artist_len] = '\0';
                artist_flag = true;
            }
            else if (strncmp(&file_data[i+1], "ALBUM=", 6) == 0) {
                /* Extract album */
                strncpy(metadata.album, &file_data[i+7], album_len);
                metadata.album[album_len] = '\0';
                album_flag = true;
            }
            else if (strncmp(&file_data[i+1], "YEAR=", 5) == 0) {
                /* Extract year */
                strncpy(metadata.year, &file_data[i+6], year_len);
                metadata.year[year_len] = '\0';
                year_flag = true;
            }

            /* Reset flags and lengths */
            title_flag = false;
            artist_flag = false;
            album_flag = false;
            year_flag = false;
            title_len = 0;
            artist_len = 0;
            album_len = 0;
            year_len = 0;
        }
        else {
            /* Check for metadata field */
            if (strncmp(&file_data[i], "TITLE=", 6) == 0) {
                /* Set flag and increment length */
                title_flag = true;
                title_len++;
            }
            else if (strncmp(&file_data[i], "ARTIST=", 7) == 0) {
                /* Set flag and increment length */
                artist_flag = true;
                artist_len++;
            }
            else if (strncmp(&file_data[i], "ALBUM=", 6) == 0) {
                /* Set flag and increment length */
                album_flag = true;
                album_len++;
            }
            else if (strncmp(&file_data[i], "YEAR=", 5) == 0) {
                /* Set flag and increment length */
                year_flag = true;
                year_len++;
            }
            /* Increment length if flag set */
            if (title_flag) title_len++;
            if (artist_flag) artist_len++;
            if (album_flag) album_len++;
            if (year_flag) year_len++;
        }
    }

    /* Unmap file */
    munmap(file_data, sb.st_size);

    /* Print metadata */
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %s\n", metadata.year);
}

int main(int argc, char **argv)
{
    /* Check for filename argument */
    if (argc < 2) {
        fprintf(stderr, "Error: no filename specified.\n");
        return 1;
    }

    /* Extract metadata asynchronously */
    extract_metadata_async(argv[1]);

    return 0;
}