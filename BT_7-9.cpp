#include <iostream>
#include <cmath>

using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

    int UCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    // Hàm tạo không đối và có đối
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }

    PhanSo(int tu, int mau) {
        tuSo = tu;
        if (mau != 0) {
            mauSo = mau;
        } else {
            mauSo = 1;
        }
    }

    // Hàm hủy
    ~PhanSo() {}

    // Phương thức rút gọn chung
    void RutGon() {
        int ucln = UCLN(tuSo, mauSo);
        tuSo /= ucln;
        mauSo /= ucln;
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // --- CÁC PHƯƠNG THỨC THÔNG THƯỜNG (BÀI 1) ---
    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauSo;
            if (mauSo == 0) cout << "Mau so phai khac 0. Vui long nhap lai!\n";
        } while (mauSo == 0);
    }

    void Xuat() {
        if (mauSo == 1) cout << tuSo << endl;
        else if (tuSo == 0) cout << 0 << endl;
        else cout << tuSo << "/" << mauSo << endl;
    }

    PhanSo Cong(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps.mauSo + ps.tuSo * this->mauSo;
        kq.mauSo = this->mauSo * ps.mauSo;
        kq.RutGon();
        return kq;
    }

    PhanSo Tru(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps.mauSo - ps.tuSo * this->mauSo;
        kq.mauSo = this->mauSo * ps.mauSo;
        kq.RutGon();
        return kq;
    }

    PhanSo Nhan(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps.tuSo;
        kq.mauSo = this->mauSo * ps.mauSo;
        kq.RutGon();
        return kq;
    }

    PhanSo Chia(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps.mauSo;
        kq.mauSo = this->mauSo * ps.tuSo;
        kq.RutGon();
        return kq;
    }

    // --- NẠP CHỒNG TOÁN TỬ (BÀI 2) ---
    friend istream& operator >> (istream& in, PhanSo& ps) {
        cout << "Nhap tu so: ";
        in >> ps.tuSo;
        do {
            cout << "Nhap mau so (khac 0): ";
            in >> ps.mauSo;
            if (ps.mauSo == 0) cout << "Mau so phai khac 0. Vui long nhap lai!\n";
        } while (ps.mauSo == 0);
        return in;
    }

    friend ostream& operator << (ostream& out, const PhanSo& ps) {
        if (ps.mauSo == 1) out << ps.tuSo;
        else if (ps.tuSo == 0) out << 0;
        else out << ps.tuSo << "/" << ps.mauSo;
        return out;
    }

    PhanSo operator + (const PhanSo& ps) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps.mauSo + ps.tuSo * this->mauSo;
        kq.mauSo = this->mauSo * ps.mauSo;
        kq.RutGon();
        return kq;
    }

    PhanSo operator - (const PhanSo& ps) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps.mauSo - ps.tuSo * this->mauSo;
        kq.mauSo = this->mauSo * ps.mauSo;
        kq.RutGon();
        return kq;
    }

    PhanSo operator * (const PhanSo& ps) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps.tuSo;
        kq.mauSo = this->mauSo * ps.mauSo;
        kq.RutGon();
        return kq;
    }

    PhanSo operator / (const PhanSo& ps) {
        PhanSo kq;
        kq.tuSo = this->tuSo * ps.mauSo;
        kq.mauSo = this->mauSo * ps.tuSo;
        kq.RutGon();
        return kq;
    }
};

int main() {
    cout << "=== PHAN 1: SU DUNG PHUONG THUC THUONG ===" << endl;
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu 1:\n"; ps1.Nhap();
    cout << "Nhap phan so thu 2:\n"; ps2.Nhap();

    cout << "Cong: "; ps1.Cong(ps2).Xuat();
    cout << "Tru:  "; ps1.Tru(ps2).Xuat();
    cout << "Nhan: "; ps1.Nhan(ps2).Xuat();
    cout << "Chia: "; ps1.Chia(ps2).Xuat();

    cout << "\n=== PHAN 2: SU DUNG NAP CHONG TOAN TU ===" << endl;
    PhanSo ps3, ps4;
    cout << "Nhap phan so thu 3:\n"; cin >> ps3;
    cout << "Nhap phan so thu 4:\n"; cin >> ps4;

    cout << "Cong: " << ps3 << " + " << ps4 << " = " << (ps3 + ps4) << endl;
    cout << "Tru:  " << ps3 << " - " << ps4 << " = " << (ps3 - ps4) << endl;
    cout << "Nhan: " << ps3 << " * " << ps4 << " = " << (ps3 * ps4) << endl;
    cout << "Chia: " << ps3 << " / " << ps4 << " = " << (ps3 / ps4) << endl;

    return 0;
}
