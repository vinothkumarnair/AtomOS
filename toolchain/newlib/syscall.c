#include <sys/syscall.h>

void
_exit(void)
{
    __syscall00(SYS_exit);
}

int
fork(void)
{
    return __syscall01(SYS_fork);
}

int
getpid(void)
{
    return __syscall01(SYS_getpid);
}

int
close(int file)
{
    return __syscall11(SYS_close, file);
}


