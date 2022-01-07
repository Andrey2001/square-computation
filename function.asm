section .data
  const1 dq 3.0
  const2 dq 0.5
  const3 dq 4.0
    
; f1 = 3 / ((x - 1) ^ 2 + 1)
; f2 = sqrt (x + 0.5)
; f3 = e ^ (-x)

section .text
global f1
f1:
    push ebp
    mov ebp, esp
    finit
    
    fld qword[const1]
    fld qword[ebp + 8]
    fld1
    fsubp
    fld ST0
    fmulp
    fld1
    faddp
    fdivp
    
    leave 
    ret
    
global f2
f2:
    push ebp
    mov ebp, esp
    finit
    
    fld qword[ebp + 8]
    fld qword[const2]
    faddp
    fsqrt
    
    leave
    ret
    
global f3
f3:
    push ebp
    mov ebp, esp
    finit 
    
    fld qword[ebp + 8]
    fchs   ; -x
    fldl2e ; log2(e)
    fmulp  ; -x*log2(e)
    fld qword[const3]
    fdivp  ; -x*log2(e) / 4.0
    f2xm1  ; ST0 = 2 ^ ST0 - 1, -1 < ST0 < 1
    fld1
    faddp  ; e ^ (-x / 4.0)
    fld ST0
    fmulp
    fld ST0
    fmulp
    
    leave
    ret
