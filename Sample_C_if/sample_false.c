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

	// '\0' �� int �^�� 0�@�yC����̏ꍇ�z
	if ('\0')
		puts("A");
	else
		puts("B");

	// NULL�� 0 �� (void*)0 �yC����̏ꍇ�z
	if (NULL)
		puts("A");
	else
		puts("B");
}
