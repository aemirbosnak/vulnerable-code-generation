//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <errno.h>

#define SYS_GET_SYSMAP    410

/* We will examine the running kernel itself */
#define KERNEL_IMAGE   "/proc/kcore"

/*
 * Not every architecture uses the same e_entry offset in the ELF header,
 * adjust this as needed.
 */
#define ELF_HDR_OFF    0x100

/*
 * The sys_get_sysmap syscall needs to be called first in order to
 * know where the sysmap is.
 */
static unsigned long get_sysmap_start(void)
{
        unsigned long start, end;
        int ret;

        ret = syscall(SYS_GET_SYSMAP, &start, &end);
        if (ret < 0) {
                perror("syscall(SYS_GET_SYSMAP)");
                exit(1);
        }

        return start;
}

int main(int argc, char **argv)
{
        unsigned long kcore_fd, kernel_image, elf_hdr_addr, entry_off, entry;
        struct stat st;

        /* Map the file /proc/kcore into memory */
        kcore_fd = open(KERNEL_IMAGE, O_RDONLY);
        if (kcore_fd < 0) {
                perror("open");
                exit(1);
        }

        stat(KERNEL_IMAGE, &st);

        kernel_image = mmap(0, st.st_size,
                            PROT_READ, MAP_PRIVATE, kcore_fd, 0);
        if (kernel_image == MAP_FAILED) {
                perror("mmap");
                exit(1);
        }

        /* We now have the kernel image mapped in memory. */

        /*
         * The sysmap kernel module contains the address of the kernel
         * entry point.  Get this address.
         */
        elf_hdr_addr = kernel_image + ELF_HDR_OFF;

        /* Read offset of entry point from ELF header */
        entry_off = *(unsigned long *)(elf_hdr_addr + 24);

        /* The sysmap address is the address of the kernel image plus */
        /* the entry point offset.                                */
        entry = kernel_image + entry_off;

        /*
         * Now 'entry' holds the kernel entry point address.
         * We can do whatever we want with it.  Here we just print
         * it out.
         */
        printf("Kernel entry point: 0x%016lx\n", entry);

        /*
         * All done.  Unmap the kernel image and close the file.
         */
        munmap((void *)kernel_image, st.st_size);
        close(kcore_fd);

        return 0;
}