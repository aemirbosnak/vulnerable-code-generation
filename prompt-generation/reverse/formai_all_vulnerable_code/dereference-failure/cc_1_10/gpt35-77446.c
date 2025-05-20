//FormAI DATASET v1.0 Category: Data recovery tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LOST_DATA_NODE {
    long long sector_index;
    int data_size;
    char* data;
};

void recover_data(const char* device_name, struct LOST_DATA_NODE** lost_data_list, int* lost_data_count) {
    // Open device and read its content
    FILE* device = fopen(device_name, "rb");
    if (!device) {
        printf("Error: Cannot open device %s\n", device_name);
        exit(1);
    }
    fseek(device, 0, SEEK_END);
    long long device_size = ftell(device);
    fseek(device, 0, SEEK_SET);
    char* device_content = malloc(device_size);
    fread(device_content, 1, device_size, device);
    fclose(device);
    
    // Scan device for lost data
    *lost_data_list = NULL;
    *lost_data_count = 0;
    long long sector_index = 0;
    while (sector_index + 16 < device_size) {
        if (device_content[sector_index] == 0xCA &&
            device_content[sector_index+1] == 0xFE &&
            device_content[sector_index+2] == 0xBA &&
            device_content[sector_index+3] == 0xBE &&
            device_content[sector_index+4] == 0xCA &&
            device_content[sector_index+5] == 0xFE &&
            device_content[sector_index+6] == 0xBA &&
            device_content[sector_index+7] == 0xBE) {
            
            // Found a lost data marker
            long long data_start = sector_index + 8;
            int data_size = (device_content[data_start] << 24) |
                            (device_content[data_start+1] << 16) |
                            (device_content[data_start+2] << 8) |
                            (device_content[data_start+3]);
            *lost_data_list = realloc(*lost_data_list, (*lost_data_count+1) * sizeof(struct LOST_DATA_NODE));
            struct LOST_DATA_NODE* lost_data_node = &((*lost_data_list)[*lost_data_count]);
            lost_data_node->sector_index = sector_index;
            lost_data_node->data_size = data_size;
            lost_data_node->data = malloc(data_size);
            memcpy(lost_data_node->data, &device_content[data_start+4], data_size);
            
            sector_index += 8 + data_size + 8;
            (*lost_data_count)++;
        } else {
            sector_index += 4096;
        }
    }
    
    // Clean up
    free(device_content);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <device_name>\n", argv[0]);
        return 1;
    }

    struct LOST_DATA_NODE* lost_data_list;
    int lost_data_count;
    
    recover_data(argv[1], &lost_data_list, &lost_data_count);
    
    if (lost_data_count == 0) {
        printf("No lost data found\n");
    } else {
        printf("%d lost data nodes found:\n", lost_data_count);
        for (int i = 0; i < lost_data_count; i++) {
            printf("[%lld] data_size=%d\n", lost_data_list[i].sector_index, lost_data_list[i].data_size);
        }
    }
    
    // Clean up
    for (int i = 0; i < lost_data_count; i++) {
        free(lost_data_list[i].data);
    }
    free(lost_data_list);
    
    return 0;
}