#include <iostream>
#include <vector>
#include <string>
using namespace std;

// L?p c? s? cho m�y l?c
class MayLocNuoc {
protected:
    float donGiaThue; // ??n gi� thu�
    float chiPhiSuDung;  // Chi ph� nhi�n li?u ho?c h�a ch?t
    float thoiGianHoatDong; // Th?i gian ho?t ??ng

public:
    MayLocNuoc(float gia, float chiPhi) : donGiaThue(gia), chiPhiSuDung(chiPhi), thoiGianHoatDong(0) {}

    virtual ~MayLocNuoc() {}

    virtual float tinhCongSuat() const = 0; // H�m ?o pure virtual, c?n ???c ??nh ngh?a ? c�c l?p con
    virtual float tinhTongChiPhi() const = 0; // H�m ?o pure virtual, c?n ???c ??nh ngh?a ? c�c l?p con

    void datThoiGianHoatDong(float thoiGian) {
        thoiGianHoatDong = thoiGian;
    }
};

// L?p con MayLocLyTam k? th?a t? MayLocNuoc
class MayLocLyTam : public MayLocNuoc {
private:
    float luongXangTieuThu; // L??ng x?ng s? d?ng (l�t/gi?)

public:
    MayLocLyTam(float gia, float xang) : MayLocNuoc(gia, 0), luongXangTieuThu(xang) {}

    // ??nh ngh?a h�m ?o t? l?p c? s?
    float tinhCongSuat() const override {
        return donGiaThue * thoiGianHoatDong;
    }

    float tinhTongChiPhi() const override {
        return (donGiaThue + chiPhiSuDung) * thoiGianHoatDong;
    }
};

// L?p con MayLocXucTac k? th?a t? MayLocNuoc
class MayLocXucTac : public MayLocNuoc {
private:
    float luongHoaChat; // L??ng h�a ch?t s? d?ng (kg/gi?)

public:
    MayLocXucTac(float gia, float hoaChat) : MayLocNuoc(gia, hoaChat), luongHoaChat(hoaChat) {}

    // ??nh ngh?a h�m ?o t? l?p c? s?
    float tinhCongSuat() const override {
        return donGiaThue * thoiGianHoatDong * (luongHoaChat / 100);
    }

    float tinhTongChiPhi() const override {
        return (donGiaThue + chiPhiSuDung) * thoiGianHoatDong;
    }
};

// L?p qu?n l� c�c m�y l?c
class QuanLyMayLocNuoc {
private:
    vector<MayLocNuoc*> danhSachMayLoc; // Danh s�ch m�y l?c

public:
    ~QuanLyMayLocNuoc() {
        // Gi?i ph�ng b? nh? khi ??i t??ng QuanLyMayLocNuoc b? h?y
        for (MayLocNuoc* mayLoc : danhSachMayLoc) {
            delete mayLoc;
        }
    }

    void themMayLoc(MayLocNuoc* mayLoc) {
        danhSachMayLoc.push_back(mayLoc);
    }

    float tinhTongCongSuat() const {
        float tongCongSuat = 0;
        for (const MayLocNuoc* mayLoc : danhSachMayLoc) {
            tongCongSuat += mayLoc->tinhCongSuat();
        }
        return tongCongSuat;
    }

    float tinhTongChiPhi() const {
        float tongChiPhi = 0;
        for (const MayLocNuoc* mayLoc : danhSachMayLoc) {
            tongChiPhi += mayLoc->tinhTongChiPhi();
        }
        return tongChiPhi;
    }
};

int main() {
    QuanLyMayLocNuoc quanLy;

    // Th�m c�c m�y l?c v�o danh s�ch
    MayLocLyTam* mayLocLyTam = new MayLocLyTam(50000, 5);
    mayLocLyTam->datThoiGianHoatDong(2);
    quanLy.themMayLoc(mayLocLyTam);

    MayLocXucTac* mayLocXucTac = new MayLocXucTac(80000, 2);
    mayLocXucTac->datThoiGianHoatDong(3);
    quanLy.themMayLoc(mayLocXucTac);

    // T�nh to�n v� xu?t k?t qu?
    cout << "Tong Cong Suat: " << quanLy.tinhTongCongSuat() << " m3" << endl;
    cout << "Tong Chi Phi: " << quanLy.tinhTongChiPhi() << " VND" << endl;

    return 0;
}