            IFNDEF RAX
            .386
            ENDIF
_TEXT       SEGMENT
            IFDEF RAX
sub_eq      PROC
            cmp ecx, edx
            je  $return_true
            mov eax, 0
            ret
$return_true:
            mov eax, 1
            ret
sub_eq      ENDP
            ELSE
_sub_eq     PROC
            mov eax, dword ptr[esp+4];�l�P
            mov ecx, dword ptr[esp+8];�l�Q
            cmp eax, ecx
            je  $return_true
            mov eax, 0
            ret
$return_true:
            mov eax, 1
            ret
_sub_eq     ENDP
            ENDIF













_TEXT       ENDS
            END
