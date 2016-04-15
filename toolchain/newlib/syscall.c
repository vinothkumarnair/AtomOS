#include <sys/syscall.h>

//int _exit(int);
DEFINE_SYSCALL_1(_exit, SYS_exit, int);
//int close(int file);
DEFINE_SYSCALL_1(close, SYS_close, int);
//int execve(char *name, char **argv, char **env);
DEFINE_SYSCALL_3(execve, SYS_execve, char *, char **, char **);
//int fork();
DEFINE_SYSCALL_0(fork, SYS_fork);
//int getpid();
DEFINE_SYSCALL_0(getpid, SYS_getpid);
//int read(int file, char *ptr, int len);
DEFINE_SYSCALL_3(read, SYS_read, int, char *, int);
//int write(int file, char *ptr, int len);
DEFINE_SYSCALL_3(write, SYS_write, int, char *, int);
//int lseek(int file, int ptr, int dir);
DEFINE_SYSCALL_3(lseek, SYS_lseek, int, int, int);
