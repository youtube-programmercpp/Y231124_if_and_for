struct ymd {
	short          year     ; //�N�i16�r�b�g�j-32768�`32768
	unsigned short month : 4; //���i 4�r�b�g�j0�`15�A���̂���1�`12���g�p
	unsigned short day   : 5; //���i 5�r�b�g�j0�`31�A���̂���1�`31���g�p
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
	// a�`std::end(a)�͈̔͂� ymd { 2023, 12, 24 }��T��
	// ��v����� operator== ���p������
	const auto index = std::find(a, std::end(a), ymd{ 2023, 12, 24 }) - a;

	//<�Q�l>
	// a�`std::end(a)�͈̔͂� a ����בւ���
	// �召��r�̂��߂� operator< ���p������
	std::sort(a, std::end(a));
}
