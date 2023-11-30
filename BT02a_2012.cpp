#include <iostream>
using namespace std;

// L?p ??ng v?t c? b?n
class DongVat {
public:
    virtual void tiengKeu() { cout << "Âm thanh không xác ??nh c?a ??ng v?t" << endl; }
};

// L?p chó k? th?a t? ??ng v?t
class Cho : public DongVat {
public:
    void tiengKeu() override { cout << "Gâu gâu!" << endl; }
};

// L?p mèo k? th?a t? ??ng v?t
class Meo : public DongVat {
public:
    void tiengKeu() override { cout << "Meo meo!" << endl; }
};

int main() {
    DongVat* dv;

    // S? d?ng ?a hình ?? g?i hàm ti?ng kêu
    Cho cho;
    Meo meo;

    dv = &cho;
    dv->tiengKeu(); // In ra: Gâu gâu!

    dv = &meo;
    dv->tiengKeu(); // In ra: Meo meo!

    return 0;
}
