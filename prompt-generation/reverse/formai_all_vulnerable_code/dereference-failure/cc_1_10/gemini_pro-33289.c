//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/user.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid_t pid = atoi(argv[1]);

    if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) < 0) {
        perror("ptrace(PTRACE_ATTACH)");
        return EXIT_FAILURE;
    }

    struct user_regs_struct regs;

    if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) < 0) {
        perror("ptrace(PTRACE_GETREGS)");
        return EXIT_FAILURE;
    }

    printf("Registers:\n");
    printf("    RIP: %llx\n", regs.rip);
    printf("    RSP: %llx\n", regs.rsp);
    printf("    RBP: %llx\n", regs.rbp);
    printf("    RAX: %llx\n", regs.rax);
    printf("    RBX: %llx\n", regs.rbx);
    printf("    RCX: %llx\n", regs.rcx);
    printf("    RDX: %llx\n", regs.rdx);
    printf("    RSI: %llx\n", regs.rsi);
    printf("    RDI: %llx\n", regs.rdi);
    printf("    R8: %llx\n", regs.r8);
    printf("    R9: %llx\n", regs.r9);
    printf("    R10: %llx\n", regs.r10);
    printf("    R11: %llx\n", regs.r11);
    printf("    R12: %llx\n", regs.r12);
    printf("    R13: %llx\n", regs.r13);
    printf("    R14: %llx\n", regs.r14);
    printf("    R15: %llx\n", regs.r15);

    if (ptrace(PTRACE_DETACH, pid, NULL, NULL) < 0) {
        perror("ptrace(PTRACE_DETACH)");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}