            IFNDEF RAX
            .386
            ENDIF
_TEXT       SEGMENT
            IFDEF RAX
sub_cmp     PROC
            cmp rcx, rdx
            pushfq
            pop rax
            ret
sub_cmp     ENDP
            ELSE
_sub_cmp    PROC
            mov eax, dword ptr[esp+4];’l‚P
            mov ecx, dword ptr[esp+8];’l‚Q
            cmp eax, ecx
            pushfd
            pop eax
            ret
_sub_cmp    ENDP
            ENDIF
_TEXT       ENDS
            END
