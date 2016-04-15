#ifndef _SYSCALL_H
#define _SYSCALL_H

#include <stdint.h>
#include <string.h>

/********************************************************************
                        SYSCALL FUNCTIONS
********************************************************************/

#define SYS_exit        1
#define SYS_fork        2
#define SYS_read        3
#define SYS_write       4
#define SYS_open        5
#define SYS_close       6
#define SYS_wait4       7
#define SYS_creat       8
#define SYS_link        9
#define SYS_unlink      10
#define SYS_execv       11
#define SYS_chdir       12
#define SYS_mknod       14
#define SYS_chmod       15
#define SYS_chown       16
#define SYS_lseek       19
#define SYS_getpid      20
#define SYS_isatty      21
#define SYS_fstat       22
#define SYS_time        23
#define SYS_ARG         24
#define SYS_stat        38
#define SYS_pipe        42
#define SYS_execve      59
#define SYS_truncate    129
#define SYS_ftruncate   130
#define SYS_argc        172
#define SYS_argnlen     173
#define SYS_argn        174
#define SYS_utime       201
#define SYS_wait        202

/********************************************************************
                        HELPER FUNCTIONS
********************************************************************/
#define DECLARE_SYSCALL_0(fn)                int fn()
#define DECLARE_SYSCALL_1(fn,p1)             int fn(p1)
#define DECLARE_SYSCALL_2(fn,p1,p2)          int fn(p1,p2)
#define DECLARE_SYSCALL_3(fn,p1,p2,p3)       int fn(p1,p2,p3)

#define DEFINE_SYSCALL_0(fn, num) \ 
    int fn() \ 
    { \ 
        int a; \ 
        asm volatile("int $0x80" : "=a" (a) : "0" (num)); \ 
        return a; \ 
    }

#define DEFINE_SYSCALL_1(fn, num, P1) \ 
    int fn(P1 p1) \ 
    { \ 
        int a; \ 
        asm volatile("int $0x80" : "=a" (a) : "0" (num), "b" ((int)p1)); \ 
        return a; \ 
    }

#define DEFINE_SYSCALL_2(fn, num, P1, P2) \ 
    int fn(P1 p1, P2 p2) \ 
    { \ 
        int a; \ 
        asm volatile("int $0x80" : "=a" (a) : "0" (num), "b" ((int)p1), "c" ((int)p2)); \ 
        return a; \ 
    }

#define DEFINE_SYSCALL_3(fn, num, P1, P2, P3) \ 
    int fn(P1 p1, P2 p2, P3 p3) \ 
    { \ 
        int a; \ 
        asm volatile("int $0x80" : "=a" (a) : "0" (num), "b" ((int)p1), "c" ((int)p2), "d" ((int)p3)); \ 
        return a; \ 
    }

/********************************************************************
                        DECLARATION
********************************************************************/
DECLARE_SYSCALL_1(_exit, int);
DECLARE_SYSCALL_1(close, int);
DECLARE_SYSCALL_3(execve, char *, char **, char **);
DECLARE_SYSCALL_0(fork);
DECLARE_SYSCALL_0(getpid);
DECLARE_SYSCALL_3(read, int, char *, int);
DECLARE_SYSCALL_3(write, int, char *, int);
DECLARE_SYSCALL_3(lseek, int, int, int);

#endif