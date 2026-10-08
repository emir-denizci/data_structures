#include <iostream>
#include <string>
using namespace std;

// "Ogrenci" adinda bir sinif (Class) tanimliyoruz
class Ogrenci {
private:
    // Disaridan dogrudan erisimi engellenen (gizli) veri uyeleri (Black box mantigi)
    string isim;
    int id;

public:
    // Yapici Metot (Constructor): Nesne olusturuldugunda ilk durumlari atar
    Ogrenci(string ad, int numara) {
        isim = ad;
        id = numara;
    }

    // Sinifa ait davranis (Method): Ogrenci bilgilerini ekrana yazdirir
    void bilgileriGoster() {
        cout << "Ogrenci Adi: " << isim << endl;
        cout << "Ogrenci Numarasi: " << id << endl;
        cout << "----------------------" << endl;
    }
};

int main() {
    // Ogrenci sinifindan iki farkli nesne (object) uretiyoruz
    Ogrenci ogrenci1("Ahmet Yilmaz", 101);
    Ogrenci ogrenci2("Ayse Demir", 102);

    // Nesnelerin davranislarini (fonksiyonlarini) cagiriyoruz
    cout << "Sistemdeki Ogrenciler:" << endl;
    ogrenci1.bilgileriGoster();
    ogrenci2.bilgileriGoster();

    return 0;
}