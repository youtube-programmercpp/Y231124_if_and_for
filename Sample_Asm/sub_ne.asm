            IFNDEF RAX
            .386
            ENDIF
_TEXT       SEGMENT
            IFDEF RAX
sub_ne      PROC
            cmp ecx, edx
            jne $return_true
            mov eax, 0
            ret
$return_true:
            mov eax, 1
            ret
sub_ne      ENDP
            ELSE
_sub_ne     PROC
            mov eax, dword ptr[esp+4];’l‚P
            mov ecx, dword ptr[esp+8];’l‚Q
            cmp eax, ecx
            jne $return_true
            mov eax, 0
            ret
$return_true:
            mov eax, 1
            ret
_sub_ne     ENDP
            ENDIF
_TEXT       ENDS
            END
