struct ymd {
	short          year     ; //年（16ビット）-32768～32768
	unsigned short month : 4; //月（ 4ビット）0～15、そのうち1～12を使用
	unsigned short day   : 5; //日（ 5ビット）0～31、そのうち1～31を使用
public:
	bool operator==(const ymd& rhs) const noexcept
	{
		return day   == rhs.day  
		&&     month == rhs.month
		&&     year  == rhs.year 
		;
	}
	bool operator<(const ymd& rhs) const noexcept
	{
		return to_int() < rhs.to_int();
	}
private:
	int to_int() const noexcept
	{
		return day | (month << 5) | (year << 9);
	}
};
#include <algorithm>
void sample_conditions_2()
{
	ymd a[] =
	{ {2023, 11, 24} //a[0]
	, {2022, 11, 24} //a[1]
	, {2023, 12, 24} //a[2]
	, {2023, 11, 25} //a[3]
	};
	// a～std::end(a)の範囲で ymd { 2023, 12, 24 }を探す
	// 一致判定に operator== が用いられる
	const auto index = std::find(a, std::end(a), ymd{ 2023, 12, 24 }) - a;

	//<参考>
	// a～std::end(a)の範囲で a を並べ替える
	// 大小比較のために operator< が用いられる
	std::sort(a, std::end(a));
}
