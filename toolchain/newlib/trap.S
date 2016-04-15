.text

.global __syscall00, __syscall01, __syscall10, __syscall11

# void __syscall00(function)
__syscall00:
  pushl %ebp
  movl  %esp, %ebp
  movl -8(%ebp), %eax
  int $0x80
  leave
  ret $0x4

# void  __syscall01(function)
__syscall01:
  pushl %ebp
  movl  %esp, %ebp
  movl -8(%ebp), %eax
  int $0x80
  popl %eax
  movl %eax, -8(%ebp)
  leave
  ret $0x0

# void __syscall10(function, arg0)
__syscall10:
  pushl %ebp
  movl  %esp, %ebp
  movl -12(%ebp), %eax
  pushl -8(%ebp)
  int $0x80
  leave
  ret $0x8

# void __syscall11(function, arg0)
__syscall11:
  pushl %ebp
  movl  %esp, %ebp
  movl -12(%ebp), %eax
  pushl -8(%ebp)
  int $0x80
  popl %eax
  movl %eax, -8(%ebp)
  leave
  ret $0x4
