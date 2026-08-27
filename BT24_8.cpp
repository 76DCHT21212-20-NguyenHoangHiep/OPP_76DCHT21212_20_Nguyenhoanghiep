#include <iostream>
#include <string>
#include <iomanip> // Thư viện hỗ trợ căn chỉnh lề, in theo cột

using namespace std;

class NhanVien {
private:
    int maNV;
    string hoTen;
    double luong;

public:
    // 1. Constructor không đối (Default constructor)
    NhanVien() {
        maNV = 0;
        hoTen = "";
        luong = 0.0;
    }

    // 2. Constructor có đối (Parameterized constructor)
    NhanVien(int ma, string ten, double l) {
        maNV = ma;
        hoTen = ten;
        luong = l;
    }

    // Phương thức xuất thông tin một nhân viên theo dòng (dạng cột)
    void xuat() const {
        cout << left << setw(10) << maNV 
             << setw(25) << hoTen 
             << setw(15) << fixed << setprecision(0) << luong << endl;
    }

    // Cho phép hàm bên ngoài hoặc con trỏ truy xuất (nếu cần)
    friend void nhapDanhSach(NhanVien ds[], int n);
    friend void nhapDanhSachBangConTro(NhanVien *ptr, int n);
};

// --- CÁCH 2: Nhập thông qua hàm truyền mảng, dùng Constructor có đối ---
void nhapDanhSach(NhanVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        int ma;
        string ten;
        double luong;
        
        cout << "\nNhập thông tin nhân viên thứ " << i + 1 << ":\n";
        cout << "Mã NV: ";
        cin >> ma;
        cin.ignore(); // Xóa bộ nhớ đệm
        cout << "Họ tên: ";
        getline(cin, ten);
        cout << "Lương: ";
        cin >> luong;

        // Sử dụng Constructor có đối để khởi tạo đối tượng và đưa vào mảng
        ds[i] = NhanVien(ma, ten, luong);
    }
}

// --- CÁCH 3: Nhập sử dụng con trỏ, dùng Constructor có đối ---
void nhapDanhSachBangConTro(NhanVien *ptr, int n) {
    for (int i = 0; i < n; i++) {
        int ma;
        string ten;
        double luong;
        
        cout << "\nNhập thông tin nhân viên thứ " << i + 1 << " (Dùng con trỏ):\n";
        cout << "Mã NV: ";
        cin >> ma;
        cin.ignore();
        cout << "Họ tên: ";
        getline(cin, ten);
        cout << "Lương: ";
        cin >> luong;

        // Sử dụng Constructor có đối thông qua con trỏ (ptr + i)
        *(ptr + i) = NhanVien(ma, ten, luong);
    }
}

// Hàm xuất toàn bộ danh sách nhân viên theo dạng cột chuyên nghiệp
void xuatDanhSach(NhanVien ds[], int n) {
    cout << "\n\n==================== DANH SÁCH NHÂN VIÊN ====================\n";
    // In tiêu đề cột
    cout << left << setw(10) << "Mã NV" 
         << setw(25) << "Họ Tên" 
         << setw(15) << "Lương" << endl;
    cout << "-------------------------------------------------------------\n";
    
    // In dữ liệu từng nhân viên
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
    cout << "=============================================================\n";
}

int main() {
    int n;
    cout << "Nhập số lượng nhân viên (n): ";
    cin >> n;

    // Khởi tạo mảng động hoặc mảng tĩnh (ở đây dùng mảng tĩnh tối đa 100 hoặc cấp phát tùy ý)
    NhanVien ds[100]; 

    // Bạn có thể chọn 1 trong 2 cách nhập dưới đây:
    
    cout << "\n--- CHỌN CÁCH NHẬP ---\n";
    cout << "1. Nhập bằng hàm thông thường (Cách 2)\n";
    cout << "2. Nhập bằng con trỏ (Cách 3)\n";
    int chon;
    cout << "Lựa chọn của bạn: ";
    cin >> chon;

    if (chon == 1) {
        nhapDanhSach(ds, n); // Gọi Cách 2
    } else {
        nhapDanhSachBangConTro(ds, n); // Gọi Cách 3
    }

    // Xuất dữ liệu nhân viên theo cột
    xuatDanhSach(ds, n);

    return 0;
}
