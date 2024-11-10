#include<bits/stdc++.h>
#include "SingleLinkList.cpp"
using namespace std;

struct CanBo {
    int ma;
    string hoTen;
    string phongBan;
    string chucVu;
    float heSoLuong;
};

class QLNS {
private:
    int soCanBo;
    SingleLinkList<CanBo> dsCanBo;

public:
    QLNS();
    QLNS(int soCanBo, SingleLinkList<CanBo> dsCanBo); 
    int getSoNhanVien();
	SingleLinkList<CanBo> getDsNhanVien();
	// Input/Output
	int nhapCanBo(int viTri = -1);
	void xuatCanBo(CanBo canBo); 
	void nhapDsCanBo();
	void xuatDsCanBo();
	//Function
	long tinhLuong(CanBo nv);
	void sapXepNhanVienTheoTen();
};
	QLNS::QLNS(){
		this->soCanBo = 0;
	}
	QLNS::QLNS(int soCanBo, SingleLinkList<CanBo> dsCanBo){
		this->soCanBo = soCanBo;
		this->dsCanBo.assign(dsCanBo);
	}
	QLNS::getSoNhanVien(){
		return soCanBo;
	} 
	SingleLinkList<CanBo> QLNS::getDsNhanVien(){
		return dsCanBo;
	}
    int QLNS::nhapCanBo(int viTri) {
        CanBo canBo;
        cout << "\nNhap ma can bo: "; cin >> canBo.ma; cin.ignore();
        if (canBo.ma <= 0) {
            return 0;
        }
        cout << "Nhap ho ten: "; getline(cin, canBo.hoTen);
        cout << "Nhap phong ban: "; getline(cin, canBo.phongBan);
        cout << "Nhap chuc vu: "; getline(cin, canBo.chucVu);
        cout << "Nhap he so luong: "; cin >> canBo.heSoLuong; cin.ignore();

        if (viTri < 0) {
            dsCanBo.push_back(canBo);
            soCanBo++;
        } else {
            dsCanBo.insert(viTri, canBo);
            soCanBo++;
        }
        return 1;
    }

    void QLNS::xuatCanBo(CanBo canBo) {
        cout << setw(8) << canBo.ma << setw(20) << canBo.hoTen << setw(18) << canBo.phongBan
             << setw(20) << canBo.chucVu << setw(15) << tinhLuong(canBo) << endl;
    }

    void QLNS::nhapDsCanBo() {
        int result;
        while (true) {
            result = nhapCanBo();
            if (result == 0) break;
        }
    }

    void QLNS::xuatDsCanBo() {
        cout << "\n------------------------------- DANH SACH CAN BO --------------------------------\n";
        cout << setw(8) << "Ma NV" << setw(20) << "Ho ten" << setw(18) << "Phong ban" << setw(20) 
             << "Chuc vu" << setw(15) << "Luong" << endl;
        cout << "---------------------------------------------------------------------------------\n";
        for (const CanBo &canBo : dsCanBo) {
            xuatCanBo(canBo);
        }
        cout << "---------------------------------------------------------------------------------\n";
        cout << "(!) Danh sach co " << soCanBo << " can bo.\n";
    }

    long QLNS::tinhLuong(CanBo nv) {
        return 1350000 * nv.heSoLuong;
    }

    void QLNS::sapXepNhanVienTheoTen() {
        for (SingleLinkList<CanBo>::iterator it = dsCanBo.begin(); it != dsCanBo.end(); it++) {
            for (SingleLinkList<CanBo>::iterator it2 = it; it2 != dsCanBo.end(); it2++) {
                int pos = (*it).hoTen.find_last_of(" ");
                string ten1 = (*it).hoTen.substr(pos + 1);
                pos = (*it2).hoTen.find_last_of(" ");
                string ten2 = (*it2).hoTen.substr(pos + 1);
                if (ten2 < ten1) {
                    iter_swap(it, it2);
                }
            }
        }
    }






