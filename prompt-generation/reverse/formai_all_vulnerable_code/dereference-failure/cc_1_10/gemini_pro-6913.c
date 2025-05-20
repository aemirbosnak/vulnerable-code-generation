//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Minimalist Metadata Extractor for JPEG Files

// JPEG Marker Segment Constants
#define SOF0  0xC0 // Start of Frame (Baseline)
#define DQT   0xDB // Define Quantization Table
#define DRI   0xDD // Define Restart Interval
#define DHT   0xC4 // Define Huffman Table
#define SOS   0xDA // Start of Scan

// Huffman Table Type Constants
#define DC_TABLE  0 // DC coefficients
#define AC_TABLE  1 // AC coefficients

// JPEG Quantization Table
typedef uint8_t JpegQuantTable[64];

// JPEG Huffman Table
typedef struct {
    uint8_t  codeLength[16];    // Code length for each code
    uint16_t codeValue[256];   // Code value for each code
} JpegHuffmanTable;

// JPEG Scan Header
typedef struct {
    uint8_t  componentCount;    // Number of components in the scan
    struct {
        uint8_t  componentId;     // Component identifier
        uint8_t  dcTable;        // DC Huffman table index
        uint8_t  acTable;        // AC Huffman table index
    } component[4];             // Max 4 components
} JpegScanHeader;

// Function to extract JPEG metadata
int extract_jpeg_metadata(const uint8_t *jpeg_data, size_t jpeg_size) {
    uint32_t marker;
    int marker_size;
    int offset = 0;

    // Check for JPEG SOI marker
    if (jpeg_data[offset++] != 0xFF || jpeg_data[offset++] != 0xD8) {
        printf("Invalid JPEG file: missing SOI marker\n");
        return -1;
    }

    // Loop through JPEG markers
    while (offset < jpeg_size) {
        // Read marker segment
        marker = (jpeg_data[offset++] << 8) | jpeg_data[offset++];
        marker_size = (jpeg_data[offset++] << 8) | jpeg_data[offset++];

        // Process marker segment based on its type
        switch (marker) {
            case SOF0:
                printf("SOF0: Baseline JPEG, %dx%d pixels\n",
                    jpeg_data[offset + 7], jpeg_data[offset + 8]);
                offset += marker_size - 2;
                break;

            case DQT:
                printf("DQT: Quantization table\n");
                offset += marker_size - 2;
                break;

            case DRI:
                printf("DRI: Restart interval %d\n",
                    (jpeg_data[offset + 4] << 8) | jpeg_data[offset + 5]);
                offset += marker_size - 2;
                break;

            case DHT:
                {
                    uint8_t type = jpeg_data[offset++];
                    uint8_t tableId = jpeg_data[offset++];
                    if (type == DC_TABLE) {
                        printf("DHT: DC Huffman table #%d\n", tableId);
                    } else if (type == AC_TABLE) {
                        printf("DHT: AC Huffman table #%d\n", tableId);
                    } else {
                        printf("Unknown DHT type %d\n", type);
                    }
                    offset += marker_size - 4;
                }
                break;

            case SOS:
                {
                    JpegScanHeader *scanHeader = (JpegScanHeader *) &jpeg_data[offset];
                    printf("SOS: Start of scan\n");
                    printf("  Component count: %d\n", scanHeader->componentCount);
                    for (int i = 0; i < scanHeader->componentCount; i++) {
                        printf("  Component %d:\n", i + 1);
                        printf("    Component ID:     %d\n", scanHeader->component[i].componentId);
                        printf("    DC Huffman table: %d\n", scanHeader->component[i].dcTable);
                        printf("    AC Huffman table: %d\n", scanHeader->component[i].acTable);
                    }
                    offset += marker_size - 2;
                }
                break;

            default:
                printf("Unknown JPEG marker 0x%04X\n", marker);
                offset += marker_size - 2;
                break;
        }
    }

    return 0;
}

// Main function to test the metadata extractor
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <jpeg_file>\n", argv[0]);
        return 1;
    }

    // Read JPEG file
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    size_t jpeg_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint8_t *jpeg_data = malloc(jpeg_size);
    if (!jpeg_data) {
        printf("Error allocating memory for JPEG data\n");
        return 1;
    }
    if (fread(jpeg_data, 1, jpeg_size, fp) != jpeg_size) {
        printf("Error reading JPEG data\n");
        free(jpeg_data);
        fclose(fp);
        return 1;
    }
    fclose(fp);

    // Extract JPEG metadata
    int ret = extract_jpeg_metadata(jpeg_data, jpeg_size);
    free(jpeg_data);

    return ret;
}