//FormAI DATASET v1.0 Category: File Synchronizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <sys/inotify.h>

#define MAX_EVENTS 1024 /* Maximum number of events to process */
#define EVENT_SIZE  ( sizeof (struct inotify_event) ) /* Size of one event */
#define BUF_LEN     ( MAX_EVENTS * ( EVENT_SIZE + NAME_MAX + 1 ) ) /* Buffer to store the data of events */

int main( int argc, char **argv )
{
    int length, i = 0, wd;
    int fd;
    char buffer[BUF_LEN];
    char src_dir[PATH_MAX], dest_dir[PATH_MAX], temp_dir[PATH_MAX];
    struct inotify_event *event;
    int offset = 0;
    char *direction;
    
    if(argc < 3) {
        printf("Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        return -1;
    }

    strcpy(src_dir, argv[1]);
    strcpy(dest_dir, argv[2]);
    strcpy(temp_dir, dest_dir);

    fd = inotify_init();

    if ( fd < 0 ) {
        perror( "inotify_init" );
    }

    wd = inotify_add_watch( fd, src_dir, IN_CLOSE_WRITE | IN_CREATE | IN_DELETE );

    if ( wd == -1 ) {
        printf( "Could not watch directory %s\n", src_dir );
    } else {
        printf( "Watching source directory: %s\n", src_dir );
    }

    while (1) {
        i = 0;
        length = read( fd, buffer, BUF_LEN );

        if ( length < 0 ) {
            perror( "read" );
        }

        while ( i < length ) {
            event = ( struct inotify_event * ) &buffer[ i ];
            if ( event->len ) {
                direction = (event->mask & IN_ISDIR) ? strcat(temp_dir, event->name) : dest_dir;
                printf("Copying file: %s/%s to %s/%s\n", src_dir, event->name, direction, event->name);
                char command[256];
                snprintf(command, sizeof(command), "cp %s/%s %s/%s", src_dir, event->name, direction, event->name);
                system(command);
                offset += event->len + EVENT_SIZE;
            }
            i += EVENT_SIZE + event->len;
        }
    }

    ( void ) inotify_rm_watch( fd, wd );
    ( void ) close( fd );

    return 0;
}