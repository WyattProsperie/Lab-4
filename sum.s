.section .text

.globl sum_array

sum_array:

    # RDI = address of array
    # RSI = number of integers

    movl $0, %eax          # sum = 0
    movq $0, %rcx          # i = 0

loop:

    cmpq %rsi, %rcx        # i >= count?
    jge done

    addl (%rdi,%rcx,4), %eax   # sum += array[i]

    incq %rcx              # i++
    jmp loop

done:

    ret


.section .note.GNU-stack,"",@progbits