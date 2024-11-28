#ifndef _APPLICATION
#define _APPLICATION 1

#include "_LIST_OF_PRODUCT.hpp"

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

		void Run () {
			int inp;

			do {
				Menu();

				cin >> inp;
				switch(inp) {
					case 1: { // add product
						int inp;
						cout << "Neu muon ngung cap nhat bam -1: ";
						cin >> inp;

						while (inp != -1) {
							List_PRD.newProduct();
							cout << "Ban co muon tiep tuc them san pham? (-1 de thoat): ";
							cin >> inp;
						}
						break;
					}

					case 2: { // delete product
						if (List_PRD.empty()) {
							string inp;
							cout << "Nhap ID san pham can xoa: "; cin >> inp;

							List_PRD.delProduct(inp);
						}
						break;
					}

					case 3: { // update product
						if (List_PRD.empty()) {
							string inp;
							cout << "Nhap ID san pham can cap nhat: "; cin >> inp;

							List_PRD.updProduct(inp);
						}
						break;
					}

					case 4: { // show list
						if (List_PRD.empty()) List_PRD.showList();
						break;
					}

					case 5: { // find product
						if (List_PRD.empty()) {
							int child_act;
							cout << "===============================================\n"
									"=                                             =\n"
									"=  1. Tim theo thuoc tinh                     =\n"
									"=  2. Tim theo min/max                        =\n"
									"===============================================\n";
							cout << "Nhap lua chon cua ban: "; cin >> child_act;

							switch(child_act) {
								case 1: { // fine by attributes
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
										
										case 6: {
											break;
										}

										default: {
											cout << "Lua chon khong hop le!\n";
											break;
										}
									}
									break;
								}

								case 2: { // find by min/max
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
											cout << "Lua chon khong hop le!\n";
											break;
										}
									}
									break;
								}
							}

						}

						break;
					}

					case 6: { // sort list
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
	   
							do {
								cout << "Tang dan hoac giam dan ('<' or '>': "; cin >> c;
								if(c != '<' && c != '>') {
									cin.ignore(1000, '\n');
									cout << "Lua chon khong hop le!\n";
								}
							} while (c != '>' && c != '<');

							List_PRD.flex_sort(child_act, c);

							cin.ignore(); cin.get();
						}
						break;
					}

					case 7: { // end process
						cout << "Chuong trinh ket thuc!\n";
						break;
					}

					default: { // invalid input
						cout << "Chuc nang nay khong duoc ho tro!\n";
						cin.ignore(); cin.get();
						break;
					}
				}
			} while (inp != 7);
		}

};

#endif
