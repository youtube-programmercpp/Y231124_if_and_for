struct ymd {
	short          year     ; //�N�i16�r�b�g�j-32768�`32768
	unsigned short month : 4; //���i 4�r�b�g�j0�`15�A���̂���1�`12���g�p
	unsigned short day   : 5; //���i 5�r�b�g�j0�`31�A���̂���1�`31���g�p
};
int ymd_to_int(struct ymd value)
{
	return value.day | (value.month << 5) | (value.year << 9);
}
// �� > �E  ... ��
// �� < �E  ... ��
// �� = �E  ... 0
int ymd_compare(const struct ymd* lhs, const struct ymd* rhs)
{
	return ymd_to_int(*lhs) - ymd_to_int(*rhs);
}
#include <search.h>
void sample_conditions_2()
{
	struct ymd a[] =
	{ {2023, 11, 24} //a[0]
	, {2022, 11, 24} //a[1]
	, {2023, 12, 24} //a[2]
	, {2023, 11, 25} //a[3]
	};
	// a ���� ymd { 2023, 12, 24 }��T��
	const struct ymd key = { 2023, 12, 24 };
	unsigned number = sizeof a / sizeof * a;
	const ptrdiff_t index = (struct ymd*)/*_Check_return_ _ACRTIMP void* __cdecl */_lfind
	( /*_In_                               const void * key    */&key
	, /*_In_reads_bytes_(*number * width)  const void * base   */a
	, /*_Inout_                            unsigned   * number */&number
	, /*_In_                               unsigned     width  */sizeof *a
	, /*_In_ _CoreCrtNonSecureSearchSortCompareFunction compare*/ymd_compare
	) - a;

	//<�Q�l>
	// a ������בւ���
	qsort
	( /*base   */a
	, /*number */sizeof a / sizeof *a
	, /*width  */sizeof *a
	, /*compare*/ymd_compare
	);
}
