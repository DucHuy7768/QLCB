#pragma once
class ChuyenBay {
private:
	string maChuyenBay, soHieu, noiDen;
	float giaVe;
	string ngayKhoiHanh;
	int soLuongHienThi;
	int soLuongConLai;
public:
	ChuyenBay() {}
	ChuyenBay(string maChuyenBay, string soHieu, float giaVe, string noiDen, string ngayKhoiHanh, int soLuongHienThi, int soLuongConLai) {
		this->maChuyenBay = maChuyenBay;
		this->soHieu = soHieu;
		this->giaVe = giaVe;
		this->noiDen = noiDen;
		this->ngayKhoiHanh = ngayKhoiHanh;
		this->soLuongHienThi = soLuongHienThi;
		this->soLuongConLai = soLuongConLai;
	}
	~ChuyenBay() {}

	string getmaChuyenBay() {
		return this->maChuyenBay;
	}
	void setmaChuyenBay(string mH) {
		this->maChuyenBay = mH;
	}
	string getsoHieu() {
		return this->soHieu;
	}
	void setsoHieu(string tH) {
		this->soHieu = tH;
	}

	float getGiaVe() {
		return this->giaVe;
	}
	void setGiaVe(float giaVe) {
		this->giaVe = giaVe;
	}

	string getNoiDen() {
		return this->noiDen;
	}
	void setNoiDen(string noiDen) {
		this->noiDen = noiDen;
	}
	string getngayDi() {
		return this->ngayKhoiHanh;
	}
	void setngayDi(string ngayDi) {
		this->ngayKhoiHanh = ngayDi;
	}
	int getSoLuongHienThi() {
		return this->soLuongHienThi;
	}
	void setSoLuongHienThi(int soLuongHienThi) {
		this->soLuongHienThi = soLuongHienThi;
	}
	int getsoLuongConLai() {
		return this->soLuongConLai;
	}
	void setsoLuongConLai(int soLuongConLai) {
		this->soLuongConLai = soLuongConLai;
	}
	void docDuLieu(int& nHH, ifstream& ifs) {
		string _maChuyenBay;
		getline(ifs, _maChuyenBay);
		if (_maChuyenBay == "") {
			return;
		}
		else {
			this->maChuyenBay = catChuoi(_maChuyenBay, 15);

			string _soHieu;
			getline(ifs, _soHieu);
			this->soHieu = catChuoi(_soHieu, 9);

			string _giaVe;
			getline(ifs, _giaVe);
			this->giaVe = stringSangFLOAT(catChuoi(_giaVe, 9));

			string _noiDen;
			getline(ifs, _noiDen);
			this->noiDen = catChuoi(_noiDen, 9);

			string _ngayDi;
			getline(ifs, _ngayDi);
			this->ngayKhoiHanh = catChuoi(_ngayDi, 16);

			string _sLHienThi;
			getline(ifs, _sLHienThi);
			this->soLuongHienThi = stringSangINT(catChuoi(_sLHienThi, 19));

			string _sLConLai;
			getline(ifs, _sLConLai);
			this->soLuongConLai = stringSangINT(catChuoi(_sLConLai, 18));

			string key;
			getline(ifs, key);
			if (key == "") nHH++;
		}
	}
	void ghiDuLieu(ofstream& ofs) {
		ofs << "Ma chuyen bay: " << this->maChuyenBay << endl;
		ofs << "So hieu: " << this->soHieu << endl;
		ofs << "Gia ban: " << this->giaVe << endl;
		ofs << "Noi den: " << this->noiDen << endl;
		ofs << "Ngay khoi hanh: " << this->ngayKhoiHanh << endl;
		ofs << "So luong hien thi: " << this->soLuongHienThi << endl;
		ofs << "So luong con lai: " << this->soLuongConLai << endl << endl;
	}
	void hienThi() {
		cout << setw(15) << left << this->maChuyenBay;
		cout << setw(18) << left << this->soHieu;
		cout << setw(9) << left << this->giaVe;
		cout << setw(13) << left << this->noiDen;
		cout << setw(16) << left << this->ngayKhoiHanh;
		cout << setw(4) << right << this->soLuongHienThi << endl;
		cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
	}
};