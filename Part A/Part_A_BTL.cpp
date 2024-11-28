#include <iostream>
#include <string>
#include <list>
#include <iomanip>
using namespace std;


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
		
		
		bool operator<(const Product& other) const {return price < other.price;}
		bool operator>(const Product& other) const {return price > other.price;}
		bool operator==(const Product& other) const {return id == other.id;}
};


class List_of_Product {
	private:
		list<Product> list_product;

	public:
		
		bool empty() {
			if (list_product.empty()) {
				cout << "Danh sach trong!\n";
				cin.ignore(); cin.get();
				return false;
			} else return true;
		}
		
		void newProduct () {
			Product product;

			bool existedId;

			do {
				cin >> product;
			
				existedId = false;
				for (auto& prd : list_product) {
					if (prd == product) {
						existedId = true;
						cout << "=======================================\n";
						cout << "ID da ton tai! Vui long tao ID khac!\n";
						cout << "=======================================\n";
	 				}
				}
			} while (existedId);
			
			list_product.push_back(product);
		}
		
		void showList () {
			for(auto prd : list_product) {
				cout << prd << endl;
			}
		}
		
		void delProduct (string id1) {
			bool check = false;
			
			for(auto it = list_product.begin(); it != list_product.end(); ++it) {
				if (it->getId() == id1) {
					check= true;
					char inp;
					
					cout << "Ban chac chan muon xoa san pham nay(Y or N) ? ";
					cin >> inp;
					
					if(inp == 'y' || inp == 'Y') it = list_product.erase(it);
					
					cout << "San pham duoc xoa thanh cong!\n";
					cin.ignore(); cin.get();
					return;
				}
			}
			
			if (!check) cout << "San pham khong ton tai!\n";
			cin.ignore(); cin.get();
		}
		
		void updProduct (string id1) {
			bool check = false;

			for (auto& prd : list_product) {
				if (prd.getId() == id1) {
					check = true;
					int act;

					cout << "===============================================\n"
							"=  1. Ten san pham                            =\n"
							"=  2. So luong san pham                       =\n"
							"=  3. Gia san pham                            =\n"
							"=  4. Khac                                    =\n"
							"===============================================\n"
							"Nhap lua chon: "; cin >> act;

					switch (act) {
						case 1:{
							cin.ignore();
							string name_new;
							cout << "Nhap ten moi: ";
							getline(cin, name_new);
							prd.setName(name_new);

							cout << "Cap nhat thanh cong!\n";
							cin.get();
							break;
						}
						case 2: {
							int amount_new;
							cout << "Nhap so luong moi: ";
							cin >> amount_new;
							prd.setAmount(amount_new);

							cout << "Cap nhat thanh cong!\n";
							cin.ignore(); cin.get();
							break;
						}
						case 3: {
							double price_new;
							cout << "Nhap gia moi: ";
							cin >> price_new;
							prd.setPrice(price_new);

							cout << "Cap nhat thanh cong!\n";
							cin.ignore(); cin.get();
							break;
						}
						case 4: {
							cout << "Voi nhung du lieu khong muon cap nhat: Enter cho Ten, nhap -1 cho So luong, Gia ca.\n";
							string name_new;
							int amount_new;
							double price_new;

							cout << "Ten san pham moi: ";
							cin.ignore(); getline(cin, name_new);
							if (name_new.length() != 0) prd.setName(name_new);

							cout << "So luong san pham: "; cin >> amount_new;
							if (amount_new >= 0) prd.setAmount(amount_new);

							cout << "Gia san pham: "; cin >> price_new;
							if (price_new > 0) prd.setPrice(price_new);

							cout << "Cap nhat thanh cong!\n";
							cin.ignore(); cin.get();

							break;
						}
						default: {
							cout << "Lua chon khong hop le!\n";
							break;
						}
					}
					
					return;
				}
			}
			
			if (!check) {
				cout << "San pham khong ton tai!\n";
				cin.ignore(); cin.get();
			}
		
		}
		
		//compare and sort
		void flex_sort(char c, int inp) {
	        switch (inp) {
	        case 1:
	            list_product.sort([](const Product& a, const Product& b) {
	                return a < b;
	            });
	            break;
	        case 2:
	            list_product.sort([](const Product& a, const Product& b) {
	                return a.getPrice() < b.getPrice();
	            });
	            break;
	        case 3:
	            list_product.sort([](const Product& a, const Product& b) {
	                return a.getEntryDate() < b.getEntryDate();
	            });
	            break;
	        case 4:
	            list_product.sort([](const Product& a, const Product& b) {
	                return a.getExpDate() < b.getExpDate();
	            });
	            break;
	        default:
	            cout << "Lua chon khong hop le!\n";
	            return;
	        }
	        
	        if(c == '>') list_product.reverse();
	        
	        cout << "Sap xep hoan tat!\n";
	    }
		//end compare and sort
		
		//find/search by information
		void find_by_Id (string id1) {
			bool check = false;
			for (auto& prd : list_product) {
				if (prd.getId() == id1) {
					cout << prd;
					check = true;
				}
			}
			
			if(!check) cout << "Khong co mat hang nay!\n";
		}
		
		void find_by_Name (string name1) {
			bool check = false;
			for(auto& prd : list_product) {
				if (prd.getName() == name1) {
					cout << prd << endl;
					check = true;
				}
			}
			
			if (!check) cout << "Khong co mat hang nay!\n";
		}
		
		void search_by_entryDate (string entry) {
			bool check = false;
			
			for (auto& prd : list_product) {
				if(prd.getEntryDate_string() == entry) {
					cout << prd << endl;
					check = true;
				}
			}

			if (!check) cout << "Khong co san pham nhap kho vao ngay nay!\n";
		}
		
		void search_by_expDate (string exp) {
			bool check = true;

			for (auto& prd : list_product) {
				if(prd.getExpDate_string() == exp) {
					cout << prd << endl;
					check = true;
				}
			}

			if (!check) cout << "Khong co san pham het han vao ngay nay!\n";
		}
		
		void search_by_priceRange (double price1, double price2) {
			bool check = false;
			
			for (auto& prd : list_product) {
				double price = prd.getPrice();
				if (price >= price1 && price <= price2) {
					cout << prd << endl;
					check = true;
				}
			}
			
			if (!check) cout << "Khong co san pham trong tam gia!\n";
		}
		
		//search by min/max
		void search_by_flexEntry (char c) {
			flex_sort(c, 3);
	        if (!list_product.empty()) {
	            cvtDate time = list_product.front().getEntryDate();
	            for (auto& prd : list_product) {
	            	if (prd.getEntryDate() == time) {
	            		cout << prd << endl;
					}
				}
	        } else {
	            cout << "Danh sach san pham trong!\n";
        	}
		}
		
		void search_by_flexExp (char c) {
			flex_sort(c, 4);
	        if (!list_product.empty()) {
	            cvtDate time = list_product.front().getExpDate();
	            for (auto& prd : list_product) {
	            	if (prd.getExpDate() == time) {
	            		cout << prd << endl;
					}
				}
	        } else {
	            cout << "Danh sach san pham trong!\n";
        	}
		}
		
		void search_by_flexAmount (char c) {
			flex_sort(c, 1);
	        if (!list_product.empty()) {
	            int a = list_product.front().getAmount();
	            for (auto& prd : list_product) {
	            	if (prd.getAmount() == a) {
	            		cout << prd << endl;
					}
				}
	        } else {
	            cout << "Danh sach san pham trong!\n";
        	}
		}
		
		void search_by_flexPrice (char c) {
			flex_sort(c, 2);
	        if (!list_product.empty()) {
	            double p = list_product.front().getPrice();
	            for (auto& prd : list_product) {
	            	if (prd.getPrice() == p) {
	            		cout << prd << endl;
					}
				}
	        } else {
	            cout << "Danh sach san pham trong!\n";
        	}
		}
		
};

class Application {
	private:
		List_of_Product List_PRD;
		
	public:
		void Menu () {
			cout << "===============================================\n"
					"=  DANH SACH QUAN LY KHO SAN PHAM             =\n"
					"===============================================\n"
					"=                                             =\n"
					"=  1. Them san pham                           =\n"
					"=  2. Xoa san pham                            =\n"
					"=  3. Cap nhat san pham                       =\n"
					"=  4. Hien thi sanh sach san pham             =\n"
					"=  5. Tim kiem                                =\n"
					"=  6. Sap xep danh sach san pham              =\n"
					"=  7. Thoat                                   =\n"
					"===============================================\n";
					
			cout << "Nhap lua chon cua ban: ";

		}

		void addProduct() {
			int inp;
			cout << "Neu muon ngung cap nhat bam -1: ";
			cin >> inp;
			
			while (inp != -1) {
				List_PRD.newProduct();
				cout << "Ban co muon tiep tuc them san pham? (-1 de thoat): ";
				cin >> inp;
			}
		}
		
		void deleteProduct () {
			string inp;
			cout << "Nhap ID san pham can xoa: "; cin >> inp;
			
			List_PRD.delProduct(inp);
		}
		
		void updateProduct () {
			string inp;
			cout << "Nhap ID san pham can cap nhat: "; cin >> inp;
			
			List_PRD.updProduct(inp);
		}
		
		void showListProduct() {
			List_PRD.showList();
		}
		
		void Run () {
			int inp;
			
			do {
				Menu();

				cin >> inp;
				switch(inp) {
					case 1: {
						addProduct();
						break;
					}

					case 2: {
						if (List_PRD.empty()) cout << "khong trong\n";
						deleteProduct();
						break;
					}

					case 3: {
						if (List_PRD.empty()) updateProduct();
						break;
					}

					case 4: {
						if (List_PRD.empty()) showListProduct();
						break;
					}
					
					case 5: {
						if (List_PRD.empty()) {
							int child_act;
							cout << "===============================================\n"
									"=                                             =\n"
									"=  1. Tim theo thuoc tinh                     =\n"
									"=  2. Tim theo min/max                        =\n"
									"===============================================\n";
							cout << "Nhap lua chon cua ban: "; cin >> child_act;
							
							switch(child_act) {
								case 1: {
									int child_act1;
									cout << "===============================================\n"
											"=                                             =\n"
											"=  1. Tim theo id                             =\n"
											"=  2. Tim theo ten                            =\n"
											"=  3. Tim theo ngay nhap kho                  =\n"
											"=  4. Tim theo ngay het han                   =\n"
											"=  5. Tim theo khoang gia                     =\n"
											"=  6. Thoat ve menu chinh                     =\n"
											"===============================================\n";
									cout << "Nhap lua chon cua ban: "; cin >> child_act1;
									
									switch (child_act1) {
										case 1: {
											string id1;
											cout << "Nhap ID san pham can tim: "; cin >> id1;
											List_PRD.find_by_Id(id1);
											cin.ignore(); cin.get();
											break;
										}
										
										case 2: {
		   									string name1;
											cout << "Nhap ten san pham can tim: ";
											cin.ignore();
											getline(cin, name1);
											List_PRD.find_by_Name(name1);
											cin.get();
											break;
										}
										
										case 3: {
											string entry;
											cout << "Nhap ngay nhap kho: "; cin >> entry;
											List_PRD.search_by_entryDate(entry);
											cin.ignore(); cin.get();
											break;
										}
										
										case 4: {
											string exp;
											cout << "Nhap ngay het han: "; cin >> exp;
											List_PRD.search_by_expDate(exp);
											cin.ignore(); cin.get();
											break;
										}
										
										case 5: {
											int max, min;
											cout << "Nhap khoang gia (min max): "; cin >> min >> max;
											List_PRD.search_by_priceRange(min, max);
											cin.ignore(); cin.get();
											break;
										}
										
										default: {
											break;
										}
									}
									break;
								}
								
								case 2: {
									int child_act2;
									cout << "===============================================\n"
											"=  Nhap '<' cho min/xa va '>' cho max/gan      =\n"
											"=  1. So luong min/max                        =\n"
											"=  2. Gia min/max                             =\n"
											"=  3. Ngay nhap kho gan/xa nhat               =\n"
											"=  4. Ngay het han gan/xa nhat                =\n"
											"=  5. Thoat ve menu chinh                     =\n"
											"===============================================\n";
									cout << "Nhap lua chon cua ban: "; cin >> child_act2;
									if (child_act2 == 5) break;

									char c;
									cout << "Min/xa nhat hoac max/gan nhat ('<' or '>'): "; cin >> c;
									
									switch (child_act2) {
										case 1: {
											List_PRD.search_by_flexAmount(c);
											cin.ignore(); cin.get();
											break;
										}
										
										case 2: {
											List_PRD.search_by_flexPrice(c);
											cin.ignore(); cin.get();
											break;
										}
										
										case 3: {
											List_PRD.search_by_flexEntry(c);
											cin.ignore(); cin.get();
											break;
										}
										
										case 4: {
											List_PRD.search_by_flexExp(c);
											cin.ignore(); cin.get();
											break;
										}
										
										default: {
											break;
										}
									}
									break;
								}
							}
							
						}

						break;
					}

					case 6: {
						if (List_PRD.empty()) {
							int child_act;
							char c;
							
							cout << "===============================================\n"
									"=  Nhap '<' cho tang dan va '>' cho giam dan  =\n"
									"=  1. Theo so luong                           =\n"
									"=  2. Theo gia                                =\n"
									"=  3. Theo ngay nhap kho                      =\n"
									"=  4. Theo ngay het han                       =\n"
									"=  5. Thoat ve menu chinh                     =\n"
									"===============================================\n";
							cout << "Nhap lua chon cua ban: "; cin >> child_act;
							if (child_act == 5) break;
							
							cout << "Tang dan hoac giam dan ('<' or '>': "; cin >> c;

							List_PRD.flex_sort(child_act, c);

							cin.ignore(); cin.get();
						}
						break;
					}

					case 7: {
						cout << "Chuong trinh ket thuc!\n";
						break;
					}

					default: {
						cout << "Chuc nang nay khong duoc ho tro!\n";
						cin.ignore(); cin.get();
						break;
					}
				}
			} while (inp != 7);
		}
		
};


main () {
	Application app;
	app.Run();
}

