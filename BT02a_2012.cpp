#include <iostream>
using namespace std;

// L?p ??ng v?t c? b?n
class DongVat {
public:
    virtual void tiengKeu() { cout << "�m thanh kh�ng x�c ??nh c?a ??ng v?t" << endl; }
};

// L?p ch� k? th?a t? ??ng v?t
class Cho : public DongVat {
public:
    void tiengKeu() override { cout << "G�u g�u!" << endl; }
};

// L?p m�o k? th?a t? ??ng v?t
class Meo : public DongVat {
public:
    void tiengKeu() override { cout << "Meo meo!" << endl; }
};

int main() {
    DongVat* dv;

    // S? d?ng ?a h�nh ?? g?i h�m ti?ng k�u
    Cho cho;
    Meo meo;

    dv = &cho;
    dv->tiengKeu(); // In ra: G�u g�u!

    dv = &meo;
    dv->tiengKeu(); // In ra: Meo meo!

    return 0;
}
