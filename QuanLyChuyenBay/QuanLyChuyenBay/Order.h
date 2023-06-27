#pragma once

class DonDatVe {
private:
	int soThuTu;
	int n;
	string* maChuyenBay;
	int* soLuong;
	float tongTien;
	string tenKhachHang, diaChiKH, soCMND, ngayDatVe;
public:
	DonDatVe() {}
	DonDatVe(int soThuTu, int n, string* maChuyenBay, int* soLuong, float tongTien, string tenKH, string diaChiKH, string soCMND, string ngayDatVe) {
		this->soThuTu = soThuTu;
		this->n = n;
		this->maChuyenBay = maChuyenBay;
		this->soLuong = soLuong;
		this->tongTien = tongTien;
		this->tenKhachHang = tenKH;
		this->diaChiKH = diaChiKH;
		this->soCMND = soCMND;
		this->ngayDatVe = ngayDatVe;
	}
	~DonDatVe() {}

	int getSTT() {
		return this->soThuTu;
	}
	void setSTT(int stt) {
		this->soThuTu = stt;
	}
	int getN() {
		return this->n;
	}
	void setN(int n) {
		this->n = n;
	}
	string* getmaChuyenBay() {
		return this->maChuyenBay;
	}
	int* getSoLuong() {
		return this->soLuong;
	}
	void setSoLuong(int* soLuong) {
		this->soLuong = soLuong;
	}
	float getTongTien() {
		return this->tongTien;
	}
	void setTongTien(float tongTien) {
		this->tongTien = tongTien;
	}
	void getmaChuyenBay(string* maChuyenBay) {
		this->maChuyenBay = maChuyenBay;
	}

	string getTenKH() {
		return this->tenKhachHang;
	}
	void setTenKH(string tenKH) {
		this->tenKhachHang = tenKH;
	}
	string getDiaChiKH() {
		return this->diaChiKH;
	}
	void setDiaChiKH(string diaChiKH) {
		this->diaChiKH = diaChiKH;
	}
	string getSDT() {
		return this->soCMND;
	}
	void setSDT(string soCMND) {
		this->soCMND = soCMND;
	}
	string getNgayDat() {
		return this->ngayDatVe;
	}
	void setNgayDat(string ngayDat) {
		this->ngayDatVe = ngayDat;
	}

	void docDuLieu(int& nDH, ifstream& ifs) {
		string soThuTu;
		getline(ifs, soThuTu);
		if (soThuTu == "") {
			return;
		}
		else {
			this->soThuTu = stringSangINT(catChuoi(soThuTu, 11));
			this->maChuyenBay = new string[20];
			this->soLuong = new int[20];
			this->n = 0;

			while (true) {
				string _maChuyenBay;
				getline(ifs, _maChuyenBay);
				if (_maChuyenBay.find("Ma chuyen bay: ") == 0) {
					this->maChuyenBay[this->n] = _maChuyenBay.substr(9, _maChuyenBay.find(",") - 9);
					this->soLuong[this->n] = stringSangINT(_maChuyenBay.substr(_maChuyenBay.find(",") + 12, _maChuyenBay.length() - _maChuyenBay.find(",") + 12));
					this->n++;
				}
				else {
					//Tong tien
					this->tongTien = stringSangFLOAT(catChuoi(_maChuyenBay, 11));
					break;
				}
			}
			string tenKH;
			getline(ifs, tenKH);
			this->tenKhachHang = catChuoi(tenKH, 16);

			string diaChi;
			getline(ifs, diaChi);
			this->diaChiKH = catChuoi(diaChi, 9);

			string soCMND;
			getline(ifs, soCMND);
			this->soCMND = catChuoi(soCMND, 9);

			string ngayDat;
			getline(ifs, ngayDat);
			this->ngayDatVe = catChuoi(ngayDat, 14);

			string key;
			getline(ifs, key);
			if (key == "") nDH++;
		}
	}
	void ghiDuLieu(ofstream& ofs) {
		ofs << "So thu tu: " << this->soThuTu << endl;
		for (int i = 0; i < this->n; i++) {
			ofs << "Ma hang: " << this->maChuyenBay[i] << ", so luong: " << this->soLuong[i] << endl;
		}
		ofs << "Tong tien: " << this->tongTien << endl;
		ofs << "Ten khach hang: " << this->tenKhachHang << endl;
		ofs << "Dia chi: " << this->diaChiKH << endl;
		ofs << "So CMND: " << this->soCMND << endl;
		ofs << "Ngay dat hang: " << this->ngayDatVe << endl << endl;
	}

};