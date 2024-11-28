#ifndef _PRODUCT
#define _PORDUCT 1

#include <iomanip>
#include <string>
#include "_CVT_DATE.hpp"

string convertName(string s) {
	string string_new;

	for(int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') continue;

		if (s[i] >= 'A' && s[i] <= 'Z') {
			string_new += s[i] + 32;
		}
		else string_new += s[i];
	}

	return string_new;
}

class Product {
	private:
		string id,
				name, lowName,
				entryDate, expDate;

		cvtDate cvt_entryDate,
				cvt_expDate;

		int amount;
		double price;

	public:

		void setName (string s) {name = s;}
		void setAmount (int a) {amount = a;}
		void setPrice (double p) {price = p;}

		string getName () const {return name;}
		string getId ()  const {return id;}
		int getAmount () const {return amount;}
		double getPrice () const {return price;}
		string getEntryDate_string () const { return entryDate;}
		string getExpDate_string () const {return expDate;}

		cvtDate getEntryDate () const {return cvt_entryDate;}
		cvtDate getExpDate () const {return cvt_expDate;}

  		friend istream& operator>>(istream& in, Product& product) {
			cout << "Nhap id san pham (Duy nhat!)(*): ";
				in >> product.id;

			in.ignore();
			cout << "Nhap ten san pham(*): ";
			getline(in, product.name);
			product.lowName = convertName(product.name);

			cout << "Nhap so luong san pham: ";
			in >> product.amount;

			do {
				cout << "Nhap gia san pham: ";
				in >> product.price;

				if (product.price < 0) cout << "Gia san pham khong hop le!";
			} while (product.price < 0);

			in.ignore();
			bool check = false;
			do {
				cout << "Nhap ngay nhap kho (dd/mm/yyyy)(*): ";
//				getline(in, product.entryDate);
				in >> product.entryDate;

				product.cvt_entryDate.convert(product.entryDate, &check);

			} while (!check);

			do {
				cout << "Nhap han su dung (dd/mm/yyyy)(*): ";
				in >> product.expDate;

				product.cvt_expDate.convert(product.expDate, &check);

			} while (!check);

			return in;
		}

		friend ostream& operator<<(ostream& out, Product& product) {
			cout << "ID san pham: ";
			out << product.id << endl;

			cout <<"Ten san pham: ";
			out << product.name << endl;

			cout << "So luong: ";
			out << product.amount << endl;

			cout << fixed << setprecision(2);
			cout << "Gia san pham: ";
			out << product.price << endl;

			cout << "Ngay nhap kho: ";
			out << product.entryDate << endl;

			cout << "Han su dung: ";
			out << product.expDate << endl;

			return out;
		}


		bool operator<(const Product& other) const {return amount < other.amount;}
		bool operator>(const Product& other) const {return amount > other.amount;}
		bool operator==(const Product& other) const {return id == other.id;}
};

#endif
