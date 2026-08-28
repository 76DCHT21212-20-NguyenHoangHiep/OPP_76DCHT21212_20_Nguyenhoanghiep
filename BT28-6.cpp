#include <iostream>
using namespace std;

class Matran {
private:
    int soHang, soCot;
    int data[100][100];

public:
    // Câu 1 & 2: Khai báo lớp và phương thức nhập, xuất
    void nhap() {
        cout << "Nhap so hang: ";
        cin >> soHang;
        cout << "Nhap so cot: ";
        cin >> soCot;
        cout << "Nhap cac phan tu cua ma tran:\n";
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << "A[" << i << "][" << j << "] = ";
                cin >> data[i][j];
            }
        }
    }

    void xuat() const {
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << data[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    // Câu 3: Khai báo hàm bạn (friend function) để cộng hai ma trận
    friend Matran congMaTran(const Matran &a, const Matran &b);
};

// Định nghĩa hàm bạn thực hiện cộng hai ma trận đồng cấp
Matran congMaTran(const Matran &a, const Matran &b) {
    Matran ketQua;
    ketQua.soHang = a.soHang;
    ketQua.soCot = a.soCot;
    for (int i = 0; i < a.soHang; i++) {
        for (int j = 0; j < a.soCot; j++) {
            ketQua.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return ketQua;
}

int main() {
    Matran A, B, C;
    
    cout << "--- NHAP MA TRAN A ---\n";
    A.nhap();
    
    cout << "\n--- NHAP MA TRAN B ---\n";
    B.nhap();
    
    cout << "\nMa tran A ban dau:\n";
    A.xuat();
    
    cout << "\nMa tran B ban dau:\n";
    B.xuat();
    
    C = congMaTran(A, B);
    cout << "\nMa tran ket qua (A + B):\n";
    C.xuat();
    
    return 0;
}
