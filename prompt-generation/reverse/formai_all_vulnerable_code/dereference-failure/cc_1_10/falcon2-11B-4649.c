//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char* filename;
    char* watermark;
    int watermark_len;
} WatermarkingData;

void write_watermark(WatermarkingData* data) {
    FILE* file = fopen(data->filename, "rb+");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s for writing\n", data->filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* content = (char*)malloc(file_size);
    if (content == NULL) {
        fprintf(stderr, "Failed to allocate memory for file content\n");
        fclose(file);
        return;
    }

    fread(content, 1, file_size, file);

    char* watermark_start = strstr(content, data->watermark);
    if (watermark_start == NULL) {
        fprintf(stderr, "Watermark not found in the file\n");
        free(content);
        fclose(file);
        return;
    }

    int watermark_len = strlen(data->watermark);

    if (watermark_start > content || watermark_start + watermark_len > content + file_size) {
        fprintf(stderr, "Watermark not found in the correct position in the file\n");
        free(content);
        fclose(file);
        return;
    }

    int watermark_offset = watermark_start - content;

    if (watermark_offset < 0 || watermark_offset >= MAX_FILE_SIZE) {
        fprintf(stderr, "Watermark offset is out of bounds in the file\n");
        free(content);
        fclose(file);
        return;
    }

    char* watermark_content = (char*)malloc(watermark_len);
    if (watermark_content == NULL) {
        fprintf(stderr, "Failed to allocate memory for watermark content\n");
        free(content);
        fclose(file);
        return;
    }

    strncpy(watermark_content, data->watermark, watermark_len);

    char* modified_content = (char*)malloc(file_size + watermark_len);
    if (modified_content == NULL) {
        fprintf(stderr, "Failed to allocate memory for modified content\n");
        free(content);
        free(watermark_content);
        fclose(file);
        return;
    }

    memmove(modified_content, content, watermark_offset);
    memmove(modified_content + watermark_offset, watermark_content, watermark_len);
    memmove(modified_content + watermark_offset + watermark_len, content + watermark_offset + watermark_len, file_size - watermark_offset - watermark_len);

    fseek(file, 0, SEEK_SET);
    fwrite(modified_content, 1, file_size, file);
    fclose(file);
    free(content);
    free(watermark_content);
}

int main() {
    WatermarkingData data = {
       .filename = "output.txt",
       .watermark = "This is a watermark",
       .watermark_len = strlen("This is a watermark")
    };

    write_watermark(&data);

    return 0;
}