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
}
