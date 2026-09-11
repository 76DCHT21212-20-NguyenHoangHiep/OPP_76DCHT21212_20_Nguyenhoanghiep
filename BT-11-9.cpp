#include <iostream>

using namespace std;

class SoPhuc {
private:
    double thuc;
    double ao;

public:
    // Hàm tạo không đối
    SoPhuc() {
        thuc = 0;
        ao = 0;
    }

    // Hàm tạo có đối
    SoPhuc(double t, double a) {
        thuc = t;
        ao = a;
    }

    // Hàm hủy
    ~SoPhuc() {
        // Destructor
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& is, SoPhuc& sp) {
        cout << "Nhap phan thuc: ";
        is >> sp.thuc;
        cout << "Nhap phan ao: ";
        is >> sp.ao;
        return is;
    }

    // Toán tử xuất << dưới dạng a+bi
    friend ostream& operator<<(ostream& os, const SoPhuc& sp) {
        os << sp.thuc;
        if (sp.ao >= 0) {
            os << " + " << sp.ao << "i";
        } else {
            os << " - " << -sp.ao << "i";
        }
        return os;
    }

    // Toán tử cộng +
    SoPhuc operator+(const SoPhuc& sp) const {
        return SoPhuc(thuc + sp.thuc, ao + sp.ao);
    }

    // Toán tử trừ -
    SoPhuc operator-(const SoPhuc& sp) const {
        return SoPhuc(thuc - sp.thuc, ao - sp.ao);
    }

    // Toán tử nhân *
    SoPhuc operator*(const SoPhuc& sp) const {
        return SoPhuc(thuc * sp.thuc - ao * sp.ao, thuc * sp.ao + ao * sp.thuc);
    }

    // Toán tử chia /
    SoPhuc operator/(const SoPhuc& sp) const {
        double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
        if (mau == 0) {
            cout << "Loi: Khong the chia cho so phuc 0!\n";
            return SoPhuc(0, 0);
        }
        double t = (thuc * sp.thuc + ao * sp.ao) / mau;
        double a = (ao * sp.thuc - thuc * sp.ao) / mau;
        return SoPhuc(t, a);
    }
};

int main() {
    SoPhuc sp1, sp2;

    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;

    cout << "\nNhap so phuc thu hai:\n";
    cin >> sp2;

    cout << "\n--- KET QUA ---\n";
    cout << "So phuc 1: " << sp1 << endl;
    cout << "So phuc 2: " << sp2 << endl;

    SoPhuc tong = sp1 + sp2;
    SoPhuc hieu = sp1 - sp2;
    SoPhuc tich = sp1 * sp2;
    SoPhuc thuong = sp1 / sp2;

    cout << "Tong (sp1 + sp2) = " << tong << endl;
    cout << "Hieu (sp1 - sp2) = " << hieu << endl;
    cout << "Tich (sp1 * sp2) = " << tich << endl;
    cout << "Thuong (sp1 / sp2) = " << thuong << endl;

    return 0;
}
