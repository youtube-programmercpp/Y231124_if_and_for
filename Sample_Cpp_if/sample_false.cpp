#include <stdio.h>
void sample_false()
{
	//���l�� 0 �ł���΋U�ifalse�j
	if (0)
		puts("A");
	else
		puts("B");

	// double �^�ł�����
	if (.0)
		puts("A");
	else
		puts("B");

	// char �^�ł�����
	if (*"")
		puts("A");
	else
		puts("B");

	// '\0' �� char �^�� 0�@�yC++�̏ꍇ�z
	if ('\0')
		puts("A");
	else
		puts("B");

	// nullptr �͋U�ƂȂ� �yC++�̏ꍇ�z
	if (nullptr)
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
	int C::* p = nullptr; //nullptr�� 0 �Ƃ��Ă��܂��� &C::d �Ƌ�ʂ����Ȃ��Ȃ�B����āA�����ł� p �̓����l�͔� 0 �ƂȂ�
	if (p)
		puts("A");
	else
		puts("B");
	auto q = &C::e;
	if (q)
		puts("A");
	else
		puts("B");
}
