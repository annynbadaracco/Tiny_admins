# suma.s  —  función suma(long a, long b) en AT&T syntax
# Convención System V AMD64 ABI:
#   %rdi = 1er argumento (a)
#   %rsi = 2do argumento (b)
#   %rax = valor de retorno

    .section .text
    .globl  suma       # exportar símbolo para el linker
    .type   suma, @function

suma:
    
    pushq   %rbp
    movq    %rsp, %rbp

    movq    %rdi, %rax   # rax = a  (1er argumento)
    addq    %rsi, %rax   # rax = a + b  (2do argumento)

    popq    %rbp
    ret                   # retorna; el caller lee %rax

    .size   suma, .-suma


# long convert_sum(float a, float b)
# Arguments: a in %xmm0, b in %xmm1
# Return:    Sum of converted longs in %rax

    .globl  convert_sum       # exportar símbolo para el linker
    .type   convert_sum, @function

convert_sum: 

    pushq   %rbp
    movq    %rsp, %rbp

    cvttss2si %xmm0, %rdi  # convert float a -> long in rdi
    cvttss2si %xmm1, %rsi  # convert float b -> long in rsi
    call suma              # suma(rdi, rsi)

    popq    %rbp
    ret

    .size   convert_sum, .-convert_sum
    
    .section .note.GNU-stack,"",@progbits
