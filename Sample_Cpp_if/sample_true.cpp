#include <stdio.h>
void sample_true()
{
	//���l�� 0 �ȊO �ł���ΐ^�itrue�j
	if (12345)
		puts("A");
	else
		puts("B");

	// double �^�ł�����
	if (3 / 2.)
		puts("A");
	else
		puts("B");

	// char �^�ł�����
	if (*"X")
		puts("A");
	else
		puts("B");

	//�|�C���^�ł������i0�Ԓn�͗L���ȃA�h���X�ł͂Ȃ����̂Ƃ��Ă���j
	//������
	if ("")
		puts("A");
	else
		puts("B");
	//�֐��A�h���X
	if (sample_true)
		puts("A");
	else
		puts("B");


	//�����o�ϐ��̑��΃A�h���X
	//�����o�֐��̃A�h���X
	struct C {
		int d;
		void e()
		{
		}
	};
	if (&C::d) //���΃A�h���X�Ƃ��Ă� 0 �ƂȂ邪��nullptr�A�܂�^�ƂȂ�
		puts("A");
	else
		puts("B");
	if (&C::e)
		puts("A");
	else
		puts("B");

	//���Z�q�̃I�[�o�[���[�h
	struct X {
		int a;
		int b;
		explicit operator bool() const noexcept
		{
			return a || b;
		}
	};
	if (X{ 0, 1 })
		puts("A");
	else
		puts("B");

	//�Â��X�^�C��
	struct Y {
		int a;
		int b;
		operator const void* () const /*noexcept*/
		{
			return a || b ? this : NULL;
		}
	};
	if (Y{ 2, 3 })
		puts("A");
	else
		puts("B");
}
