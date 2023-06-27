#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;
void SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}
string catChuoi(string s, int vitri) {
	return s.substr(vitri, s.length() - vitri);
}
float stringSangFLOAT(string s) {
	float ketQuaNguyen = 0;
	float ketQuaThapPhan = 0;
	int muNguyen = 0;
	int muThapPhan = -1;
	int kiemTra = s.find(".");
	if (kiemTra != -1) {
		for (int i = s.find(".") - 1; i >= 0; i--) {
			ketQuaNguyen += (s[i] - 48) * pow(10, muNguyen);
			muNguyen++;
		}
		for (int i = s.find(".") + 1; i < s.length(); i++) {
			ketQuaThapPhan += (s[i] - 48) * pow(10, muThapPhan);
			muThapPhan--;
		}
	}
	else {
		for (int i = s.length() - 1; i >= 0; i--) {
			ketQuaNguyen += (s[i] - 48) * pow(10, muNguyen);
			muNguyen++;
		}
	}
	return ketQuaNguyen + ketQuaThapPhan;
}
int stringSangINT(string s) {
	int ketQua = 0;
	int mu = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		ketQua += (s[i] - 48) * pow(10, mu);
		mu++;
	}
	return ketQua;
}
#include "Admin.h"
#include "Object.h"
#include "Order.h"
#include "Share.h"

int main() {
	char chooseMM = 0;
	int kMM = 1;
	showMainMenu(kMM);
	while (chooseMM != 27)
	{
		chooseMM = _getch();
		if (chooseMM != -32) {
			showMainMenu(kMM);
			//Switch Main Menu
			switch (chooseMM)
			{
				//Key Down
			case 80:
				kMM++;
				if (kMM == 6) {
					kMM = 1;
				}
				showMainMenu(kMM);
				break;
				//Key Up
			case 72:
				kMM--;
				if (kMM == 0) {
					kMM = 5;
				}
				showMainMenu(kMM);
				break;
				//Key Enter
			case 13:
				//Switch Choose Of Main Menu
				switch (kMM)
				{
				case 1:
				{
					showObject();
					exit();
					showMainMenu(kMM);
					break;
				}
				case 2:
				{
					system("cls");
					SetColor(0, 11);
					string chuyenBayName;
					cout << "Nhap so hieu chuyen bay can tim: ";
					getline(cin, chuyenBayName);
					searchChuyenBay(chuyenBayName);
					exit();
					showMainMenu(kMM);
					break;
				}
				case 3:
				{
					int n = 0;
					string* maChuyenBay = new string[20];
					string tenKH, diachiKH, soCMND, ngayDat;
					int* soLuong = new int[20];
					SetColor(0, 11);
					if (regisOrder1(n, maChuyenBay, soLuong)) {
						if (regisOrder2(tenKH, diachiKH, soCMND, ngayDat)) {
							addOrder(n, maChuyenBay, soLuong, tenKH, diachiKH, soCMND, ngayDat) ? cout << "\nDon dat ve cho xu ly. Nhan ESC de quay lai.\n" : cout << "\nDat hang khong thanh cong. Nhan ESC de quay lai.\n";
						}
					}
					exit();
					showMainMenu(kMM);
					break;
				}
				case 4:
				{
					Admin admin[100];
					int nAD = 0;
					layDS<Admin>(nAD, admin, "Admin.txt");
					string userName = "", passWord = "", mess = "";
					for (int i = 3; i >= 0; i--) {
						showLogin(userName, passWord, mess);
						if (checkAccount(userName, passWord, nAD, admin)) {
							char chooseMaM = 0;
							int kMaM = 1;
							showManageMenu(kMaM);
							while (chooseMaM != 27)
							{
								chooseMaM = _getch();
								if (chooseMaM != -32) {
									showManageMenu(kMaM);
									//Switch Manager Menu
									switch (chooseMaM)
									{
										//Key Down
									case 80:
										kMaM++;
										if (kMaM == 4) {
											kMaM = 1;
										}
										showManageMenu(kMaM);
										break;
										//Key Up
									case 72:
										kMaM--;
										if (kMaM == 0) {
											kMaM = 3;
										}
										showManageMenu(kMaM);
										break;
										//Key Enter
									case 13:
										switch (kMaM)
										{
										case 1:
										{
											int dem = 0;
											DonDatVe donDatVe[100];
											int nDH = 0;
											layDS<DonDatVe>(nDH, donDatVe, "DatVe.txt");
											ChuyenBay chuyenBay[100];
											int nHH = 0;
											layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
											SetColor(0, 11);
											if (handlingOrder(nDH, donDatVe, nHH, chuyenBay, dem)) {
												cout << "Xu ly thanh cong " << dem << " don dat ve. Nhan ESC de quay lai.\n" << endl;
											}
											break;
										}
										case 2:
										{
											char chooseSMaM = 0;
											int kSMaM = 1;
											showSubManageMenu(kSMaM);
											while (chooseSMaM != 27)
											{
												chooseSMaM = _getch();
												if (chooseSMaM != -32) {
													showSubManageMenu(kSMaM);
													//Switch Sub Manage Menu
													switch (chooseSMaM)
													{
														//Key Down
													case 80:
														kSMaM++;
														if (kSMaM == 5) {
															kSMaM = 1;
														}
														showSubManageMenu(kSMaM);
														break;
														//Key Up
													case 72:
														kSMaM--;
														if (kSMaM == 0) {
															kSMaM = 4;
														}
														showSubManageMenu(kSMaM);
														break;
														//Key Enter
													case 13:
														switch (kSMaM)
														{
														case 1:
														{
															ChuyenBay chuyenBay[100];
															int nHH = 0;
															string maChuyenBay, soHieu, noiDen, ngayKhoiHanh;
															float giaVe;
															int soLuong;
															layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
															SetColor(0, 11);
															regisObject(nHH, chuyenBay, maChuyenBay, soHieu, giaVe, noiDen, ngayKhoiHanh, soLuong);
															if (addObject(maChuyenBay, soHieu, giaVe, noiDen, ngayKhoiHanh, soLuong)) {
																cout << "\nThem chuyen bay thanh cong. Nhan ESC de quay lai.\n" << endl;
															}
															break;
														}
														case 2:
														{
															ChuyenBay chuyenBay[100];
															int nHH = 0;
															layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
															string maChuyenBay;
															SetColor(0, 11);
															cout << "Nhap ma chuyen bay can xoa: ";
															cin >> maChuyenBay;
															if (!checkExistByIDObject(maChuyenBay, nHH, chuyenBay)) {
																if (deleteObject(nHH, chuyenBay, maChuyenBay)) {
																	loadFile<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
																	cout << "\nXoa chuyen bay thanh cong. Nhan ESC de quay lai.\n";
																}
															}
															else cout << "\nKhong co chuyen bay nay. Nhan ESC de quay lai.\n";
															SetColor(0, 7);
															break;
														}
														case 3:
														{
															ChuyenBay chuyenBay[100];
															int nHH = 0;
															layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
															string maChuyenBay;
															SetColor(0, 11);
															cout << "\nNhap ma chuyen bay can thay doi so luong: ";
															cin >> maChuyenBay;
															if (!checkExistByIDObject(maChuyenBay, nHH, chuyenBay)) {
																int soLuong;
																cout << "\nNhap so luong ve can thay doi: ";
																cin >> soLuong;
																if (updateQuantityObject(nHH, chuyenBay, maChuyenBay, soLuong)) {
																	loadFile<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
																	cout << "\nCap nhat so luong thanh cong. Nhan ESC de quay lai.\n";
																}
															}
															else cout << "\nKhong co ma chuyen bay nay. Nhan ESC de quay lai.\n";
															SetColor(0, 7);
															break;
														}
														default:
															chooseSMaM = 27;
															showMainMenu(kSMaM);
															break;
														}
														break;
													default:
														break;
													}
													//End Switch Sub Manage Menu
												}
											}
											showManageMenu(kMaM);
											break;
										}
										default:
											chooseMaM = 27;
											showMainMenu(kMM);
											break;
										}
										break;
									default:
										break;
									}
									//End Switch Manager Menu
								}
							}
							break;
						}
						else {
							if (i > 1) {
								mess = "";
								mess += "Sai ten dang nhap hoac mat khau!. Con ";
								mess += (i - 1) + 48;
								mess += " lan dang nhap";
							}
							else {
								break;
							}
						}
					}
					showMainMenu(kMM);
					break;
				}
				default:
					exit(0);
					break;
				}
				//End Switch Choose Of Main Menu
				break;
			default:
				exit(0);
				break;
			}
			//End Switch Main Menu
		}
	}

	return 0;
}