#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ================= BÀI 6 =================
class SinhVienBai6 {
private:
    string hoTen;
    int namSinh;
    float diem[5];

public:
    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap diem 5 mon hoc:\n";
        for (int i = 0; i < 5; i++) {
            cout << "  Mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    void xuat() const {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << fixed << setprecision(2) << tinhDTB() << endl;
    }

    float tinhDTB() const {
        float tong = 0;
        for (int i = 0; i < 5; i++) {
            tong += diem[i];
        }
        return tong / 5.0f;
    }

    void kiemTraThiLai() const {
        bool coMonThiLai = false;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5.0f) {
                if (!coMonThiLai) {
                    cout << "- Sinh vien: " << hoTen << " (Nam sinh: " << namSinh << ")\n";
                    coMonThiLai = true;
                }
                cout << "  + Mon " << i + 1 << ": " << diem[i] << " (Phai thi lai)\n";
            }
        }
    }
};


// ================= BÀI 7 =================
class SinhVienBai7 {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap diem 4 mon hoc:\n";
        for (int i = 0; i < 4; i++) {
            cout << "  Mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    void xuat() const {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh << " | Diem TB: " << fixed << setprecision(2) << tinhDTB() << endl;
    }

    float tinhDTB() const {
        float tong = 0;
        for (int i = 0; i < 4; i++) {
            tong += diem[i];
        }
        return tong / 4.0f;
    }

    // Tieu chuan thi tot nghiep: DTB < 7 va khong co mon nao duoi 5
    bool thoaDienKieuThiTotNghiep() const {
        float dtb = tinhDTB();
        if (dtb >= 7.0f) return false;
        for (int i = 0; i < 4; i++) {
            if (diem[i] < 5.0f) {
                return false;
            }
        }
        return true;
    }
};


// ================= HÀM CHÍNH =================
int main() {
    int choice;
    do {
        cout << "\n================ MENU ================\n";
        cout << "1. Chay Bai 6 (5 mon, tim sinh vien thi lai diem < 5)\n";
        cout << "2. Chay Bai 7 (4 mon, tim sinh vien thi tot nghiep)\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "\n--- CHUONG TRINH BAI 6 ---\n";
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            vector<SinhVienBai6> ds(n);

            cout << "\nNhap thong tin sinh vien:\n";
            for (int i = 0; i < n; i++) {
                cout << "\nSinh vien thu " << i + 1 << ":\n";
                ds[i].nhap();
            }

            cout << "\n--- DANH SACH SINH VIEN PHAI THI LAI (Diem < 5) ---\n";
            bool found = false;
            for (int i = 0; i < n; i++) {
                // In ra chi tiet thi lai
                // (Co the kiem tra xem co sinh vien nao bi thi lai khong)
            }
            for (int i = 0; i < n; i++) {
                ds[i].kiemTraThiLai();
            }

        } else if (choice == 2) {
            int n;
            cout << "\n--- CHUONG TRINH BAI 7 ---\n";
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            vector<SinhVienBai7> ds(n);

            cout << "\nNhap thong tin sinh vien:\n";
            for (int i = 0; i < n; i++) {
                cout << "\nSinh vien thu " << i + 1 << ":\n";
                ds[i].nhap();
            }

            cout << "\n--- DANH SACH SINH VIEN PHAI THI TOT NGIEP (DTB < 7 va khong mon nao duoi 5) ---\n";
            bool coSV = false;
            for (int i = 0; i < n; i++) {
                if (ds[i].thoaDienKieuThiTotNghiep()) {
                    ds[i].xuat();
                    coSV = true;
                }
            }
            if (!coSV) {
                cout << "Khong co sinh vien nao thoa man.\n";
            }

        } else if (choice != 0) {
            cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }

    } while (choice != 0);

    cout << "\nTam biet!\n";
    return 0;
}
