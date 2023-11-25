struct ymd {
	short          year     ; //年（16ビット）-32768～32768
	unsigned short month : 4; //月（ 4ビット）0～15、そのうち1～12を使用
	unsigned short day   : 5; //日（ 5ビット）0～31、そのうち1～31を使用
};
int ymd_to_int(struct ymd value)
{
	return value.day | (value.month << 5) | (value.year << 9);
}
// 左 > 右  ... 正
// 左 < 右  ... 負
// 左 = 右  ... 0
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
	// a 内で ymd { 2023, 12, 24 }を探す
	const struct ymd key = { 2023, 12, 24 };
	unsigned number = sizeof a / sizeof * a;
	const ptrdiff_t index = (struct ymd*)/*_Check_return_ _ACRTIMP void* __cdecl */_lfind
	( /*_In_                               const void * key    */&key
	, /*_In_reads_bytes_(*number * width)  const void * base   */a
	, /*_Inout_                            unsigned   * number */&number
	, /*_In_                               unsigned     width  */sizeof *a
	, /*_In_ _CoreCrtNonSecureSearchSortCompareFunction compare*/ymd_compare
	) - a;

	//<参考>
	// a 内を並べ替える
	qsort
	( /*base   */a
	, /*number */sizeof a / sizeof *a
	, /*width  */sizeof *a
	, /*compare*/ymd_compare
	);
}
