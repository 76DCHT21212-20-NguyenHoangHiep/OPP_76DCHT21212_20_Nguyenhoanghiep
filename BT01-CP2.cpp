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

void xuat(NhanVien dsNV[], int n) {
    cout << "\n" << left
         << setw(10) << "Ma NV"
         << setw(25) << "Ten NV"
         << setw(15) << "Luong CB"
         << setw(10) << "He so" << "\n";
    cout << "---------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left
             << setw(10) << dsNV[i].maNV
             << setw(25) << dsNV[i].tenNV
             << setw(15) << fixed << setprecision(2) << dsNV[i].luongCoBan
             << setw(10) << dsNV[i].heSo << "\n";
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
