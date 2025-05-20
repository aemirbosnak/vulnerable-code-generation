//FormAI DATASET v1.0 Category: File Backup System ; Style: Romeo and Juliet
/* Oh backup, my backup, wherefore art thou backup?
Deny thy disks and refuse thy paths;
Or, if thou wilt not, be but sworn my backup
And I'll no longer be without my backups.
'Tis but thy name that is my enemy;
Thou art thyself, though not my backup.
What's backup? It is nor disk, nor path,
Nor any other part belonging to a file.
O, be some other name! What's in a name?
That which we call backup by any other name would backup just as sweet.
So Romeo would, were he not Romeo call'd,
Retain that dear perfection which he owes
Without that title. Backup, doff thy name,
And for that name which is no part of thee,
Take all myself. */
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <source file> <destination file> \n", argv[0]);
        return 1;
    }

    char source_path[BUFFER_SIZE], destination_path[BUFFER_SIZE];

    strcpy(source_path, argv[1]);
    strcpy(destination_path, argv[2]);

    FILE *source_file, *destination_file;

    if((source_file = fopen(source_path, "r")) == NULL) {
        printf("Could not open the source file %s\n", source_path);
        return 1;
    }

    if((destination_file = fopen(destination_path, "w")) == NULL) {
        printf("Could not create the destination file %s\n", destination_path);
        return 1;
    }

    char buffer[BUFFER_SIZE];

    while(fread(buffer, BUFFER_SIZE, 1, source_file)) {
        fwrite(buffer, sizeof(buffer), 1, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    printf("Backup successful!\n");

    return 0;
}