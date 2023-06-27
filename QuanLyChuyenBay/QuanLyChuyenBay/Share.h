#pragma once

void exit() {
	char x = _getch();
	while (x != 27) {
		if (x != -32) {
			cout << "Nhan ESC de quay lai." << endl;
		}
		x = _getch();
	}
}

template <class T>
void loadFile(int n, T* array, string fileText) {
	ofstream ofs(fileText, ios::out);
	for (int i = 0; i < n; i++) {
		array[i].ghiDuLieu(ofs);
	}
	ofs.close();
}
template <class T>
void layDS(int& n, T* array, string fileText) {
	ifstream ifs(fileText);
	while (!ifs.eof()) {
		array[n].docDuLieu(n, ifs);
	}
	ifs.close();
}
template <class T>
bool isEmpty(int n, T a) {
	return (n == 0);
}
template<class T>
void deleteElement(int& n, T* array, int vitri) {
	if (n <= 0) return;
	else {
		if (vitri >= 0 && vitri < n) {
			for (int i = vitri; i < n - 1; i++) {
				array[i] = array[i + 1];
			}
		}
		n--;
	}
}

bool checkExistByIDObject(string maChuyenBay, int nHH, ChuyenBay* hangHoa) {
	for (int i = 0; i < nHH; i++) {
		if (hangHoa[i].getmaChuyenBay() == maChuyenBay) {
			return false;
		}
	}
	return true;
}

float singlePriceByID(string _maChuyenBay) {
	float donGia = 0;
	ChuyenBay chuyenBay[100];
	int nHH = 0;
	layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
	for (int i = 0; i < nHH; i++) {
		if (chuyenBay[i].getmaChuyenBay() == _maChuyenBay) {
			return chuyenBay[i].getGiaVe();
		}
	}
	return donGia;
}

int quantityShowingByID(string _maChuyenBay) {
	int soLuong = 0;
	ChuyenBay chuyenBay[100];
	int nHH = 0;
	layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
	for (int i = 0; i < nHH; i++) {
		if (chuyenBay[i].getmaChuyenBay() == _maChuyenBay) {
			return chuyenBay[i].getSoLuongHienThi();
		}
	}
	return soLuong;
}
void editQuantityShowing(string _maChuyenBay, int soLuong) {
	ChuyenBay chuyenBay[100];
	int nHH = 0;
	layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
	for (int i = 0; i < nHH; i++) {
		if (chuyenBay[i].getmaChuyenBay() == _maChuyenBay) {
			chuyenBay[i].setSoLuongHienThi(chuyenBay[i].getSoLuongHienThi() - soLuong);
			loadFile<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
		}
	}
}
int quantitySavingByID(string _maChuyenBay) {
	int soLuong = 0;
	ChuyenBay chuyenBay[100];
	int nHH = 0;
	layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
	for (int i = 0; i < nHH; i++) {
		if (chuyenBay[i].getmaChuyenBay() == _maChuyenBay) {
			return chuyenBay[i].getsoLuongConLai();
		}
	}
	return soLuong;
}
bool editQuantitySaving(int nHH, ChuyenBay* chuyenBay, string maChuyenBay, int soLuong) {
	for (int i = 0; i < nHH; i++) {
		if (chuyenBay[i].getmaChuyenBay() == maChuyenBay) {
			chuyenBay[i].setsoLuongConLai(soLuong);
			loadFile<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
			return true;
		}
	}
	return false;
}

//t = 1: Main Menu
//t = 2: Manage Menu
//t = 3: Sub Manage Menu
void focusChoose(int currentChoose, int k, int t) {
	string mess;
	switch (t)
	{
	case 1:
	{
		switch (currentChoose)
		{
		case 1: mess = "Hien thi thong tin chuyen bay";
			break;
		case 2: mess = "Tim kiem thong tin chuyen bay";
			break;
		case 3: mess = "        Dat chuyen bay       ";
			break;
		case 4: mess = "           Quan ly           ";
			break;
		default:
			mess = "           Thoat             ";
			break;
		}
		break;
	}
	case 2:
	{
		switch (currentChoose)
		{
		case 1: mess = "         Xu ly dat ve        ";
			break;
		case 2: mess = "      Quan ly chuyen bay     ";
			break;
		default:
			mess = "          Thoat              ";
			break;
		}
		break;
	}
	default:
		switch (currentChoose)
		{
		case 1: mess = "       Them chuyen bay       ";
			break;
		case 2: mess = "       Xoa chuyen bay        ";
			break;
		case 3: mess = "Cap nhat so luong chuyen bay ";
			break;
		default:
			mess = "           Thoat             ";
			break;
		}
		break;
	}
	cout << setw(22) << "*";
	if (currentChoose == k) {
		SetColor(9, 0);
	}
	cout << setw(27) << mess;
	SetColor(0, 11);
	cout << "*" << endl;
}
void showMainMenu(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 11);
	cout << setw(57) << right << "|----------> MENU CHINH <---------|\n\n\n";

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;

	for (int i = 1; i <= 5; i++) {
		focusChoose(i, k, 1);
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}
void showManageMenu(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 11);
	cout << setw(58) << right << "|----------> MENU QUAN LY <---------|\n\n\n";

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;

	for (int i = 1; i <= 3; i++) {
		focusChoose(i, k, 2);
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}
void showSubManageMenu(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 11);
	cout << setw(60) << right << "|----------> MENU CON QUAN LY <---------|\n\n\n";

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;

	for (int i = 1; i <= 4; i++) {
		focusChoose(i, k, 3);
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}
void showWarning(int k, string mess) {
	system("cls");
	cout << "\n\n";
	cout << setw(21) << "" << setfill('-') << setw(32) << "-" << setfill(' ') << endl;
	cout << setw(22) << "|" << setw(22) << "Them chuyen bay?" << setw(9) << "|" << endl;
	cout << setw(22) << "|" << setw(31) << "|" << endl;
	cout << setw(22) << "|" << setw(31) << "|" << endl;

	cout << setw(22) << "|" << setw(5) << "";
	if (k == 1) {
		SetColor(11, 0);
	}
	cout << "YES";
	SetColor(0, 11);
	cout << setw(15) << "";
	if (k == 2) {
		SetColor(11, 0);
	}
	cout << "NO";
	SetColor(0, 11);
	cout << setw(6) << "|" << endl;

	cout << setw(22) << "|" << setw(31) << "|" << endl;
	cout << setw(21) << "" << setfill('-') << setw(32) << "-" << setfill(' ') << endl;
}

void showObject() {
	int nHH = 0;
	ChuyenBay chuyenBay[50];
	layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
	system("cls");
	SetColor(0, 11);
	cout << setw(23) << "" << setfill('*') << setw(34) << "*" << setfill(' ') << endl;
	cout << setw(57) << "*                                *" << endl;

	cout << setw(57) << "*      DANH SACH CHUYEN BAY      *" << endl;

	cout << setw(57) << "*                                *" << endl;
	cout << setw(23) << "" << setfill('*') << setw(34) << "*" << setfill(' ') << endl << endl;
	if (!isEmpty(nHH, chuyenBay)) {
		cout << setw(15) << left << "Ma chuyen bay";
		cout << setw(18) << left << "So hieu";
		cout << setw(9) << left << "Gia ban";
		cout << setw(13) << left << "Noi den";
		cout << setw(16) << left << "Ngay khoi hanh";
		cout << setw(8) << left << "So ve" << endl;
		cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
		for (int i = 0; i < nHH; i++) {
			chuyenBay[i].hienThi();
		}
		cout << "\nNhan ESC de quay lai menu chinh.\n" << endl;
	}
	else {
		cout << setw(63) << "\nKhong co chuyen bay nao!. Nhan ESC de quay lai.\n" << endl;
	}
}

bool searchChuyenBay(string chuyenBayName) {
	bool check = false;
	int nHH = 0;
	ChuyenBay chuyenBay[50];
	layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
	cout << setw(23) << "" << setfill('*') << setw(34) << "*" << setfill(' ') << endl;
	cout << setw(57) << "*                                *" << endl;

	cout << setw(57) << "*       DANH SACH TIM DUOC       *" << endl;

	cout << setw(57) << "*                                *" << endl;
	cout << setw(23) << "" << setfill('*') << setw(34) << "*" << setfill(' ') << endl << endl;
	if (!isEmpty(nHH, chuyenBay)) {
		cout << setw(15) << left << "Ma chuyen bay";
		cout << setw(18) << left << "So hieu";
		cout << setw(9) << left << "Gia ban";
		cout << setw(13) << left << "Noi den";
		cout << setw(16) << left << "Ngay khoi hanh";
		cout << setw(8) << left << "So ve" << endl;
		cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
		for (int i = 0; i < nHH; i++) {
			if (chuyenBay[i].getsoHieu() == chuyenBayName) {
				chuyenBay[i].hienThi();
				check = true;
			}
		}
		if (check)
			cout << "\nNhan ESC de quay lai menu chinh.\n";
		else
			cout << "\nKhong co chuyen bay nay. Nhan ESC de quay lai.\n";
	}
	else {
		cout << setw(63) << "\nKhong co chuyen bay nao!. Nhan ESC de quay lai.\n";
	}
	return check;
}

int currentNumber(string fileText) {
	ifstream ifs(fileText);
	int stt = 0;
	string key;
	while (!ifs.eof()) {
		getline(ifs, key);
		if (key == "") {
			stt++;
		}
	}
	ifs.close();
	if (stt > 1) return stt - 1;
	return 0;
}
bool regisOrder1(int& n, string* maChuyenBay, int* soLuong) {
	bool regis = true;
	while (regis) {
		system("cls");
		ChuyenBay chuyenBay[100];
		int nHH = 0;
		layDS<ChuyenBay>(nHH, chuyenBay, "ChuyenBay.txt");
		cout << setw(59) << right << "|----------> NHAP CHUYEN BAY <---------|\n\n\n";
		cout << setw(21) << "" << setfill('*') << setw(32) << "*" << setfill(' ') << endl;
		string mH;
		cout << setw(32) << "Ma chuyen bay: ";
		getline(cin, mH);
		while (mH == "" || checkExistByIDObject(mH, nHH, chuyenBay)) {
			if (mH == "")	cout << setw(42) << "(Khong duoc bo trong.)\n\n" << setw(32) << "Ma chuyen bay: ";
			else cout << setw(48) << "(Khong ton tai ma chuyen bay nay.)\n\n" << setw(32) << "Ma chuyen bay: ";
			getline(cin, mH);
		}
		maChuyenBay[n] = mH;
		int sL;
		cout << setw(32) << "Nhap so luong: ";
		cin >> sL;
		if (quantityShowingByID(mH) != 0) {
			while (sL == 0 || sL > quantityShowingByID(mH)) {
				if (sL == 0)
					cout << setw(32) << "(It nhat 1.)\n\n" << setw(32) << "Nhap so luong: ";
				else
					cout << setw(41) << "(Luong ve nay chi con " << quantityShowingByID(mH) << " ve)\n\n" << setw(32) << "Nhap so luong: ";
				cin >> sL;
			}
			soLuong[n] = sL;
			cin.ignore();
			n++;
		}
		else {
			cout << "Ma chuyen bay nay da het ve, quay lai menu chinh" << endl;
			return false;
		}

		char choose = 0;
		int k = 1;
		string warningMess = "Them chuyen bay?";
		showWarning(k, warningMess);
		while (choose != 27)
		{
			choose = _getch();
			if (choose != -32) {
				showWarning(k, warningMess);
				switch (choose)
				{
				case 77:
					k++;
					if (k == 3) {
						k = 1;
					}
					showWarning(k, warningMess);
					break;
				case 75:
					k--;
					if (k == 0) {
						k = 2;
					}
					showWarning(k, warningMess);
					break;
				case 13:
					switch (k)
					{
					case 1:
						choose = 27;
						regis = true;
						break;
					default:
						choose = 27;
						regis = false;
						break;
					}
					break;
				default:
					break;
				}
			}
		}
	}
	return true;
}
bool regisOrder2(string& tenKH, string& diachiKH, string& soCMND, string& ngayDat) {
	system("cls");
	cout << setw(59) << right << "|----------> NHAP THONG TIN <---------|\n\n\n";
	cout << setw(21) << "" << setfill('*') << setw(32) << "*" << setfill(' ') << endl;
	cout << setw(39) << "Ten khach hang: ";
	getline(cin, tenKH);
	while (tenKH == "") {
		cout << setw(42) << "(Khong duoc bo trong.)\n\n" << setw(39) << "Ten khach hang: ";
		getline(cin, tenKH);
	}
	cout << setw(39) << "Dia chi: ";
	getline(cin, diachiKH);
	while (diachiKH == "") {
		cout << setw(42) << "(Khong duoc bo trong.)\n\n" << setw(39) << "Dia chi: ";
		getline(cin, diachiKH);
	}
	cout << setw(39) << "So CMND: ";
	getline(cin, soCMND);
	while (soCMND == "") {
		cout << setw(42) << "(Khong duoc bo trong.)\n\n" << setw(39) << "So CMND: ";
		getline(cin, soCMND);
	}
	cout << setw(39) << "Ngay dat (year/month/day): ";
	getline(cin, ngayDat);
	while (ngayDat == "") {
		cout << setw(42) << "(Khong duoc bo trong.)\n\n" << setw(39) << "Ngay dat (year/month/day): ";
		getline(cin, ngayDat);
	}
	return true;
}
bool addOrder(int n, string* maChuyenBay, int* soLuong, string tenKH, string diachiKH, string soCMND, string ngayDat) {
	ofstream ofs("DatVe.txt", ios::app);
	ofs << "So thu tu: " << currentNumber("DatVe.txt") + 1 << endl;
	for (int i = 0; i < n; i++) {
		ofs << "Ma hang: " << maChuyenBay[i] << ", so luong: " << soLuong[i] << endl;
		editQuantityShowing(maChuyenBay[i], soLuong[i]);
	}
	ofs << "Ten khach hang: " << tenKH << endl;
	ofs << "Dia chi: " << diachiKH << endl;
	ofs << "So CMND: " << soCMND << endl;
	ofs << "Ngay dat hang: " << ngayDat << endl << endl;
	ofs.close();
	return true;
}

void showLogin(string& _userName, string& _passWord, string mess) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 12);
	cout << setw(63) << mess << endl;
	SetColor(0, 14);
	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << setw(22) << "*" << setw(30) << "*" << endl;
	cout << setw(22) << "*";
	SetColor(0, 11);
	cout << "      DANG NHAP HE THONG     ";
	SetColor(0, 14);
	cout << "*" << endl;
	cout << setw(22) << "*" << setw(30) << "*" << endl;
	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	SetColor(0, 3);

	string userName;
	cout << setw(33) << "User: ";
	SetColor(0, 7);
	cin >> userName;
	_userName = userName;
	SetColor(0, 3);
	string passWord;
	cout << setw(37) << "Password: ";
	SetColor(0, 7);

	string pass = "\0";
	char kytu = 0;
	int i = 0;
	while (kytu != '\r') {
		kytu = _getch();
		if ((kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z') || (kytu >= '0' && kytu <= '9')) {
			pass += kytu;
			i++;
			cout << "*";
		}
		if (kytu == '\b' && i >= 1) {
			cout << "\b \b";
			i--;
		}
	}
	cout << endl;
	_passWord = pass;
}
bool checkAccount(string userName, string passWord, int nAD, Admin* admin) {
	for (int i = 0; i < nAD; i++) {
		if (admin[i].getUser() == userName && admin[i].getPass() == passWord) {
			return true;
			break;
		}
	}
	return false;
}

bool updateObject(int nHH, ChuyenBay* chuyenBay, int n, string* maChuyenBay, int* soLuong) {
	for (int i = 0; i < n; i++) {
		editQuantitySaving(nHH, chuyenBay, maChuyenBay[i], quantitySavingByID(maChuyenBay[i]) - soLuong[i]);
	}
	return true;
}
bool deleteOrder(int& nDH, DonDatVe* donDatVe, int soThuTu) {
	for (int i = 0; i < nDH; i++) {
		if (donDatVe[i].getSTT() == soThuTu) {
			deleteElement<DonDatVe>(nDH, donDatVe, i);
			loadFile<DonDatVe>(nDH, donDatVe, "DatVe.txt");
			return true;
		}
	}
	return false;
}
bool handlingOrder(int& nDH, DonDatVe* donDatVe, int& nHH, ChuyenBay* chuyenBay, int& dem) {
	while (nDH != 0) {
		int i = 0;
		updateObject(nHH, chuyenBay, donDatVe[i].getN(), donDatVe[i].getmaChuyenBay(), donDatVe[i].getSoLuong());
		deleteOrder(nDH, donDatVe, donDatVe[i].getSTT());
		dem++;
	}
	return true;
}

void regisObject(int& nHH, ChuyenBay* chuyenBay, string& maChuyenBay, string& soHieu, float& giaVe, string& noiDen, string& ngayKhoiHanh, int& soLuong) {
	system("cls");
	cout << setw(59) << right << "|----------> NHAP THONG TIN <---------|\n\n\n";
	cout << setw(21) << "" << setfill('*') << setw(32) << "*" << setfill(' ') << endl;
	cout << setw(32) << "Ma chuyen bay: ";
	cin >> maChuyenBay;
	while (!checkExistByIDObject(maChuyenBay, nHH, chuyenBay)) {
		cout << setw(42) << "(Chuyen bay da ton tai.)\n\n" << setw(32) << "Ma hang: ";
		cin >> maChuyenBay;
	}
	cin.ignore();
	cout << setw(32) << "So hieu: ";
	getline(cin, soHieu);

	cout << setw(32) << "Gia ban: ";
	cin >> giaVe;
	cin.ignore();

	cout << setw(32) << "Noi den: ";
	getline(cin, noiDen);
	cout << setw(32) << "Ngay khoi hanh: ";
	cin >> ngayKhoiHanh;
	cout << setw(32) << "So luong: ";
	cin >> soLuong;
	cin.ignore();
}
bool addObject(string& maChuyenBay, string& soHieu, float& giaVe, string& noiDen, string& ngayKhoiHanh, int& soLuongHienThi) {
	ofstream ofs("ChuyenBay.txt", ios::app);
	ofs << "Ma chuyen bay: " << maChuyenBay << endl;
	ofs << "So hieu: " << soHieu << endl;
	ofs << "Gia ban: " << giaVe << endl;
	ofs << "Noi den: " << noiDen << endl;
	ofs << "Ngay khoi hanh: " << ngayKhoiHanh << endl;
	ofs << "So luong hien thi: " << soLuongHienThi << endl;
	ofs << "So luong ton kho: " << soLuongHienThi << endl << endl;
	ofs.close();
	return true;
}

bool deleteObject(int& nHH, ChuyenBay* chuyenBay, string maChuyenBay) {
	for (int i = 0; i < nHH; i++) {
		if (chuyenBay[i].getmaChuyenBay() == maChuyenBay) {
			deleteElement<ChuyenBay>(nHH, chuyenBay, i);
			return true;
		}
	}
	return false;
}

bool updateQuantityObject(int nHH, ChuyenBay* chuyenBay, string maChuyenBay, int soLuong) {
	for (int i = 0; i < nHH; i++) {
		if (chuyenBay[i].getmaChuyenBay() == maChuyenBay) {
			chuyenBay[i].setsoLuongConLai(soLuong);
			chuyenBay[i].setSoLuongHienThi(soLuong);
		}
	}
	return true;
}
