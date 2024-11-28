#ifndef _LIST_OF_PRODUCT
#define _LIST_OF_PRODUCT 1

#include <list>
#include "_PRODUCT.hpp"

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

					if(inp == 'y' || inp == 'Y') {
						it = list_product.erase(it);
						cout << "San pham duoc xoa thanh cong!\n";
					}

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
		void flex_sort(int inp, char c) {
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
			flex_sort(3, c);
			
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
			flex_sort(4, c);
			
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
			flex_sort(1, c);
			
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
			flex_sort(2, c);
			
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

#endif
