;program to evaluate A^2+(A-B) in masm; A AND B are 16 bit numbers

Data segment
    A dw 3333h
    B dw 1032h
    Result dw 2 dup(?)
Data ends 
 Code segment
 Assume cs:code,ds:data
Start:mov ax,data
          Mov ds,ax
          Mov ax,A 
          Mul ax       ;A^2
          Mov bx,ax
          Mov di,dx 
      
          Mov ax,A
          Sub ax,B    ;(A-B)
          Mov si,ax

         Mov ax,bx 
         Add ax,si       ;A^2+(A-B)
         Mov es,ax 

        Mov ah,4ch
       Int 21h
       Code ends 
       end starts