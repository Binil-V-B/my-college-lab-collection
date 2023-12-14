;Program to perform linear search in masm

data segment
list dw 1234h,4567h,3343h,9809h
key dw 9809h
msg1 db "Found$"
msg2 db "Not Found$"
data ends

macro print msg
lea dx,msg
mov ah,09h
int 21h
endm

code segment
assume cs:code,ds:data
start: mov ax,data
        mov ds,ax
        mov si,offset list
        mov dx,key
        mov cx,0004h
    above: mov ax,[si]
        cmp ax,dx
        je below
        inc si
        inc si
        loop above
        print msg2
        jmp stop
    below:
        pirnt msg1
    stop:
        mov dh,4ch
        int 21h
         