class Singleton {
private:
    static Singleton* instance;

    // Constructor private
    Singleton() {}

public:
    // Ph??ng th?c tr? v? th? hi?n duy nh?t c?a l?p
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Kh?i t?o con tr? instance
Singleton* Singleton::instance = nullptr;