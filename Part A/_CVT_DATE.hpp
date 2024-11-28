#ifndef _CVT_DATE
#define _CVT_DATE 1

#include <iostream>
using namespace std;

class cvtDate {
	private:
		int day, month, year;

	public:
		void setDay(int num){ day = num;}
		void setMonth(int num){ month = num;}
		void setYear(int num){ year = num;}

		int getDay() { return day;}
		int getMonth() { return month;}
		int getYear() { return year;}

		void convert(string s, bool *check) {
			size_t slash1 = s.find('/');
			size_t slash2 = s.find('/', slash1 + 1);

			if(slash1 == -1 || slash2 == -1) {
				cout << "Khong hop le!\n";
				*check = false;
				return;
			} else *check = true;

			day = stoi(s.substr(0, slash1));

			month = stoi(s.substr(slash1 + 1, slash2 - slash1));

			year = stoi(s.substr(slash2 + 1));
		}

		bool operator<(const cvtDate& other) const {
			if(year != other.year) {return year < other.year;}

			if(month != other.month) {return month < other.month;}

			if (day != other.day) {return day < other.day;}
		}

		bool operator==(const cvtDate& other) const {
			return year == other.year && month == other.month && day == other.day;
		}
};

#endif
