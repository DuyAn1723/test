#include <iostream>
using namespace std;

// Lớp trừu tượng
class Hinh {
public:
    // Hàm ảo thuần ảo (pure virtual function)
    virtual void ve() = 0;
};

// Lớp hình tròn kế thừa từ lớp Hinh
class HinhTron : public Hinh {
public:
    void ve() override { cout << "Vẽ hình tròn" << endl; }
};

// Lớp hình vuông kế thừa từ lớp Hinh
class HinhVuong : public Hinh {
public:
    void ve() override { cout << "Vẽ hình vuông" << endl; }
};

int main() {
    Hinh* hinh; // Khai báo con trỏ của lớp cơ sở
    HinhTron ht;
    HinhVuong hv;

    hinh = &ht;
    hinh->ve(); // In ra: Vẽ hình tròn

    hinh = &hv;
    hinh->ve(); // In ra: Vẽ hình vuông

    return 0;
}

