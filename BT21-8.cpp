#include <iostream>
#include <string>

using namespace std;

// Khai báo lớp NhanVien
class NhanVien {
private:
    string hoten;
    string manv;
    string ngaysinh;
    string diachi;

public:
    // Phương thức nhập thông tin nhân viên
    void nhap() {
        cout << "Nhập mã nhân viên: ";
        getline(cin, manv);
        cout << "Nhập họ tên nhân viên: ";
        getline(cin, hoten);
        cout << "Nhập ngày sinh: ";
        getline(cin, ngaysinh);
        cout << "Nhập địa chỉ: ";
        getline(cin, diachi);
    }

    // Phương thức xuất thông tin nhân viên
    void xuat() {
        cout << "\n--- THÔNG TIN NHÂN VIÊN ---" << endl;
        cout << "Mã nhân viên: " << manv << endl;
        cout << "Họ tên: " << hoten << endl;
        cout << "Ngày sinh: " << ngaysinh << endl;
        cout << "Địa chỉ: " << diachi << endl;
    }
};

int main() {
    // Khai báo 1 đối tượng là Minh thuộc lớp NhanVien
    NhanVien Minh;

    cout << "NHẬP THÔNG TIN CHO MINH:\n";
    Minh.nhap();

    // Xuất thông tin của Minh
    Minh.xuat();

    return 0;
}
