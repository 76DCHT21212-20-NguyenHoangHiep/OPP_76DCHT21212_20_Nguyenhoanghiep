#include <iostream>
#include <vector>
#include <string>

using namespace std;

class nhanvien {
private:
    string hoten;
    string manv;
    string ngaysinh;
    string diachi;
public:
    void nhap() {
        cout << "nhap ma nhan vien: ";
        getline(cin, manv);

        cout << "nhap ho ten: ";
        getline(cin, hoten);

        cout << "nhap ngay sinh: ";
        getline(cin, ngaysinh);

        cout << "nhap dia chi: ";
        getline(cin, diachi);
    }

    void xuat() {
        cout << "ma nhan vien: " << manv << endl;
        cout << "ho ten: " << hoten << endl;
        cout << "ngay sinh: " << ngaysinh << endl;
        cout << "dia chi: " << diachi << endl;
    }
};

int main() {
    int n = 10;

//cach 1
    cout << "cach 1: mang tinh \n";
    nhanvien dsnv1[10];

    for (int i = 0; i < n; i++) {
        cout << "nhap thong tin nhan vien " << i + 1 << "\n";
        dsnv1[i].nhap();
    }

    for (int i = 0; i < n; i++) {
        cout << "xuat thong tin nhan vien " << i + 1 << "\n";
        dsnv1[i].xuat();
    }
//cach 2
    cout << "cach 2: mang dong \n";
    nhanvien *dsnv2;
    dsnv2 = new nhanvien[n]; 

    for (int i = 0; i < n; i++) {
        cout << "nhap thong tin nhan vien" << i + 1 << "\n";
        dsnv2[i].nhap();
    }

    for (int i = 0; i < n; i++) {
        cout << "xuat thong tin nhan vien " << i + 1 << "\n";
        dsnv2[i].xuat();
    }

    delete[] dsnv2;
//cach 3 
    cout << "cach 3: vector \n";
    vector<nhanvien> dsnv3;
    for (int i = 0; i < n; i++) {
        nhanvien nv;
        cout << "nhap thong tin nhan vien" << i + 1 << "\n";
        nv.nhap();
        dsnv3.push_back(nv);
    }
    for (int i = 0; i < (int)dsnv3.size(); i++) {
        cout << "xuat thong tin nhan vien" << i + 1 << "\n";
        dsnv3[i].xuat();
    }
    return 0;
}
