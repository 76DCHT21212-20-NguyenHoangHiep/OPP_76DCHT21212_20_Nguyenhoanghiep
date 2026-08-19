#include <iostream>
#include <string>
using namespace std;

#define MAX 100


struct NhanVien {
    string maNV;
    string tenNV;
    float luongCoBan;
    float heSo;
};

int main() {
    NhanVien dsNV[MAX];
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    return 0;
}
