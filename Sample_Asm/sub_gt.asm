            IFNDEF RAX
            .386
            ENDIF
_TEXT       SEGMENT
            IFDEF RAX
sub_gt      PROC
            cmp ecx, edx
            jg  $return_true
            mov eax, 0
            ret
$return_true:
            mov eax, 1
            ret
sub_gt      ENDP
            ELSE
_sub_gt     PROC
            mov eax, dword ptr[esp+4];’l‚P
            mov ecx, dword ptr[esp+8];’l‚Q
            cmp eax, ecx
            jg  $return_true
            mov eax, 0
            ret
$return_true:
            mov eax, 1
            ret
_sub_gt     ENDP
            ENDIF
_TEXT       ENDS
            END
