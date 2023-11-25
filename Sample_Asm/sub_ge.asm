            IFNDEF RAX
            .386
            ENDIF
_TEXT       SEGMENT
            IFDEF RAX
sub_ge      PROC
            cmp ecx, edx
            jge $return_true
            mov eax, 0
            ret
$return_true:
            mov eax, 1
            ret
sub_ge      ENDP
            ELSE
_sub_ge     PROC
            mov eax, dword ptr[esp+4];’l‚P
            mov ecx, dword ptr[esp+8];’l‚Q
            cmp eax, ecx
            jge $return_true
            mov eax, 0
            ret
$return_true:
            mov eax, 1
            ret
_sub_ge     ENDP
            ENDIF
_TEXT       ENDS
            END
