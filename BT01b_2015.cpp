class A {
public:
    A() { a = new int[3]; for (int i = 0; i < 3; i++) a[i] = i + 1; }
    ~A() { delete[] a; }
private:
    int* a;
};

void init(A& a) {
    A* b = new A(); // T?o m?t ??i t??ng A m?i
    a = *b; // Gán ??i t??ng m?i vào tham chi?u a
    delete b; // Xóa ??i t??ng m?i sau khi ?ã gán vào a
}

int main() {
    A obj;
    init(obj);
    return 0;
}