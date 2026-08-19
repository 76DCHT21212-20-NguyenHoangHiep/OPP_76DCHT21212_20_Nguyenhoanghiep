#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX 100

struct NhanVien {
    string maNV;
    string tenNV;
    float luongCoBan;
    float heSo;
};

void nhap(NhanVien dsNV[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";

        cout << "Ma NV: ";
        cin >> dsNV[i].maNV;

        cout << "Ten NV: ";
        cin.ignore();
        getline(cin, dsNV[i].tenNV);

        cout << "Luong co ban: ";
        cin >> dsNV[i].luongCoBan;

        cout << "He so: ";
        cin >> dsNV[i].heSo;
    }
}

float tinhLuongThucNhan(const NhanVien &nv) {
    return nv.luongCoBan * nv.heSo;
}

void xuat(NhanVien dsNV[], int n) {
    cout << "\n" << left
         << setw(10) << "Ma NV"
         << setw(25) << "Ten NV"
         << setw(12) << "Luong CB"
         << setw(8)  << "He so"
         << setw(15) << "Luong TN" << "\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        float luongTN = tinhLuongThucNhan(dsNV[i]);
        cout << left
             << setw(10) << dsNV[i].maNV
             << setw(25) << dsNV[i].tenNV
             << setw(12) << fixed << setprecision(2) << dsNV[i].luongCoBan
             << setw(8)  << dsNV[i].heSo
             << setw(15) << luongTN << "\n";
    }
}

int main() {
    NhanVien dsNV[MAX];
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    nhap(dsNV, n);
    xuat(dsNV, n);

    return 0;
}
