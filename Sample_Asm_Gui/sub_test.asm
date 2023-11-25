            IFNDEF RAX
            .386
            ENDIF
_TEXT       SEGMENT
            IFDEF RAX
sub_test    PROC
            test rcx, rdx
            pushfq
            pop  rax
            ret
sub_test    ENDP
            ELSE
_sub_test   PROC
            mov  eax, dword ptr[esp+4];’l‚P
            mov  ecx, dword ptr[esp+8];’l‚Q
            test eax, ecx
            pushfd
            pop  eax
            ret
_sub_test   ENDP
            ENDIF
_TEXT       ENDS
            END
