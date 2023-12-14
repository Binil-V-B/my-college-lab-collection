;program to evaluate the expression (AB)/(A+B) in masm where A and B are 16 bit numbers.

data segment
n1 dw 1111h
n2 dw 2222h
pro dw 2 dup(?)
sum dw ?
quotient dw ?
remainder dw ?
data ends

code segment
assume cs:code,ds:data
start:  mov ax,data
        mov ds,ax

        mov ax,n1
        mov bx,n2
        add ax,bx
        mov [sum],ax

        mov ax,n1
        mul bx
        mov [pro],ax
        mov [pro],dx

        mov bx,[sum]
        div bx
        mov [quotient],ax
        mov [remainder],dx

        mov ah,4ch
        int 21h
        code ends
        end start



