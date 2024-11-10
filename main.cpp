#include <bits/stdc++.h>
#include "QLNS.cpp" 
using namespace std;

int main () {
    QLNS qlns;

    // Tao danh sach can bo  
    cout << "(?) Nhap danh sach can bo:";
    qlns.nhapDsCanBo();
    qlns.xuatDsCanBo();

    // Them 1 can bo bao danh sach
    int viTri;
    int ketQua;
    cout << "\n(?) Nhap vi tri muon them can bo (-1 de them vao cuoi ds): "; 
    cin >> viTri;
    ketQua = qlns.nhapCanBo(viTri);
    cout << (ketQua ? "(!) Them can bo moi thanh cong!\n" : "(x) Them can bo moi that bai, ma can bo khong hop le!\n");

    // In cac can bo co hsl >= 4.4
    SingleLinkList<CanBo> dsCanBo = qlns.getDsNhanVien();
    cout << "\n\n----- Danh sach can bo co he so luong > 4,4:\n";
    cout << setw(8) << "Ma NV" << setw(20) << "Ho ten" << setw(18) << "Phong ban" << setw(20) <<  "Chuc vu" << setw(15) << "Luong" << endl;
    for (SingleLinkList<CanBo>::iterator it = dsCanBo.begin(); it != dsCanBo.end(); it++) {
        CanBo canbo = *it;
        if (canbo.heSoLuong > 4.4)
            qlns.xuatCanBo(canbo);
    }

    // Tim va in danh sach theo chuc vu
    string timChucVu;
    cout << "\n\n(?) Nhap chuc vu muon tim kiem: "; 
    getline(cin, timChucVu); 
    cout << "----- Danh sach can bo co chuc vu " << timChucVu << ":\n";
    cout << setw(8) << "Ma NV" << setw(20) << "Ho ten" << setw(18) << "Phong ban" << setw(20) <<  "Chuc vu" << setw(15) << "Luong" << endl;
    for (SingleLinkList<CanBo>::iterator it = dsCanBo.begin(); it != dsCanBo.end(); it++) {
        CanBo canbo = *it;
        if (canbo.chucVu == timChucVu)
            qlns.xuatCanBo(canbo);
    }

    // Tim va in ds theo hsl va phong ban
    float timHsl;
    string timPhongBan;
    cout << "\n\n(?) Nhap he so luong can tim: "; 
    cin >> timHsl; 
    cin.ignore();  
    cout << "(?) Nhap phong ban can tim: "; 
    getline(cin, timPhongBan);
    cout << "\n----- Danh sach can bo co he so luong > " << timHsl << " && phong ban " << timPhongBan << ":\n";
    cout << setw(8) << "Ma NV" << setw(20) << "Ho ten" << setw(18) << "Phong ban" << setw(20) <<  "Chuc vu" << setw(15) << "Luong" << endl;
    for (SingleLinkList<CanBo>::iterator it = dsCanBo.begin(); it != dsCanBo.end(); it++) {
        CanBo canbo = *it;
        if (canbo.heSoLuong >= timHsl && canbo.phongBan == timPhongBan)
            qlns.xuatCanBo(canbo);
    }

    // Xap sep nhan vien theo ten
    qlns.sapXepNhanVienTheoTen();
    cout << "\n(!) Da xap sep danh sach theo ten:";
    qlns.xuatDsCanBo();

    return 0;
}

