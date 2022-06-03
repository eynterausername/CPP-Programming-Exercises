#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class TimeHMS {
	int hour, min, sec;

public:
	TimeHMS(int h, int m, int s) : hour(h), min(m), sec(s) {}
	TimeHMS(int d = 0) { convert(d); }
	~TimeHMS() {}

	void convert(int total) {
		hour = total / (60 * 60);
		total %= (60 * 60);
		min = total / 60;
		sec = total % 60;
	}
	int totalsec() {
		return hour * (60 * 60) + min * 60 + sec;
	}
	// (1) t3 = t1 + t2;
	TimeHMS operator+(TimeHMS t) {
		return TimeHMS((hour + t.hour) * 3600
			+ (min + t.min) * 60 + (sec + t.sec));
	}
	// (2) t3 = t1 - t2;
	TimeHMS operator-(TimeHMS t) {
		return TimeHMS((hour - t.hour) * 3600
			+ (min - t.min) * 60 + (sec - t.sec));
	}
	// (3) t1 == t2;
	bool operator==(TimeHMS t) {
		return totalsec() == t.totalsec();
	}

	// (4) ++t1; t1++;
	TimeHMS& operator++() {
		hour++;
		return *this;
	}
	TimeHMS& operator--() {
		hour--;
		return *this;
	}
	// (5) t1++; t1--;
	TimeHMS& operator++(int) {
		sec++;
		return *this;
	}
	TimeHMS& operator--(int) {
		sec--;
		return *this;
	}
	// (6) t1[0], t[1], t[2];
	int operator[](int id) {
		if (id == 0) return hour;
		else if (id == 1) return min;
		else if (id == 2) return sec;
		else return -1;
	}

	// (7) 초단위 변경
	operator int() {
		return totalsec();
	}
	// (8) 시단위 변경
	operator double() {
		return totalsec() / 3600.;
	}

	// (9) 정수 * 시간
	friend TimeHMS operator*(int times, TimeHMS t) {
		return TimeHMS(times * t.totalsec());
	}

	friend ostream& operator<<(ostream& os, const TimeHMS& t) {
		os << fixed << setfill('0') <<
			setw(2) << t.hour << ":" <<
			setw(2) << t.min << ":" <<
			setw(2) << t.sec << endl;
		return os;
	}
	friend istream& operator >> (istream& is, TimeHMS& t) {
		int total;
		is >> total;
		t.convert(total);
		return is;
	}
};
void main()
{
	TimeHMS	t1(10000), t2, t3(11, 22, 33), t4, t5, t6;

	cout << "t2: ";
	cin >> t2;

	cout << "t1      = " << t1;
	cout << "t2      = " << t2;
	cout << "t3      = " << t3;
	cout << "t1+t2   = " << t1 + t2;
	cout << "t1-t2   = " << t1 - t2;
	cout << "++t1    = " << ++t1;
	cout << "--t1    = " << --t1;
	cout << "t1++    = " << t1++;
	cout << "t1--    = " << t1--;

	cout << "t1[0~2] = " << t1[0] << " " << t1[1] << " " << t1[2] << endl;
	cout << "t2[sec] = " << (int)t2 << endl;
	cout << "t2[hour]= " << (double)t2 << endl;
	cout << "2*t2    = " << 2 * t2;
}