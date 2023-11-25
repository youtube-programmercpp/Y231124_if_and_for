# Sample_Asm
<https://youtu.be/Ts6q5dBh2BI>
## CMP����
SUB���߁i�����Z�j�Ɨގ����Ă��邪���Z�̌��ʂ̓t���O�݂̂ɔ��f�����B

### ZF (zero flag)
| ���Z���� | ZF�̒l | CMP���߂Ƃ̑g�ݍ��킹 |
|:---:|:---:|---|
|0|ZF=1|�����Z�̌��ʂ��O�Ƃ������ƂŁA�l�͓�����|
|��0|ZF=0|�����Z�̌��ʂ���O�Ƃ������ƂŁA�l�͓������Ȃ�|

## �������򖽗�

| �A�Z���u������<br>�\�[�X�t�@�C�� |  ���Z�q  | ���� | �Ӗ� |
|:--------:|:--------:|:---:|---|
|sub_eq.asm| ==       | je  |�l1�ƒl2����������΃W�����v|
|sub_ne.asm| !=       | jne |�l1�ƒl2���������Ȃ���΃W�����v|
|sub_ge.asm| >=       | jge |�l1���l2�ȏ�ł���΃W�����v|
|sub_gt.asm| >        | jg  |�l1���l2���傫����΃W�����v|
|sub_le.asm| \<=      | jle |�l1���l2�ȉ��ł���΃W�����v|
|sub_lt.asm| <        | jl  |�l1���l2�����ł���΃W�����v|

## �����A�Z���u��
### IFDEF, ELSE, ENDIF
�ȉ��̂悤�ɂ���x64�p�R�[�h��x86�p�̃R�[�h�����.asm�t�@�C���ɏ������Ƃ��ł���B
```masm
IFDEF RAX
;x64�p�̃R�[�h
ELSE
;x86�p�̃R�[�h
ENDIF
```
### IFNDEF ENDIF
x86��p�̃R�[�h���L�q����ۂ� IFNDEF RAX�ȂǂƏ�����B
```masm
IFNDEF RAX
;x86�p�̃R�[�h
ENDIF
```

