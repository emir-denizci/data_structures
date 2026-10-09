#include <iostream>
using namespace std;

// 1. O(1) - Sabit Zaman (Constant Time)
// Veri boyutu 'n' ne kadar büyük olursa olsun, işlem her zaman tek bir adımda biter.
void sabitZaman(int n) {
    cout << "O(1) Calisti: " << (n * 2) << endl; 
    // Dongu yok, tek satir islem.
}

// 2. O(log n) - Logaritmik Zaman (Logarithmic Time)
// Sayac her adimda 2'ye bolundugu veya çarpildiği icin dongu n defa degil, log(n) defa doner.
void logaritmikZaman(int n) {
    int adimSayisi = 0;
    // n = 64 verildiginde dongu sadece 7 kez calisir.
    for (int i = n; i > 0; i /= 2) {
        adimSayisi++;
    }
    cout << "O(log n) Calisti. n=" << n << " icin adim sayisi: " << adimSayisi << endl;
}

// 3. O(n) - Lineer Zaman (Linear Time)
// Dongu tam 'n' defa calisir. Bir dizideki en kucuk elemani veya toplami bulmak O(n)'dir.
void lineerZaman(int n) {
    int toplam = 0;
    for (int i = 0; i < n; i++) { // n kadar doner
        toplam += i;
    }
    cout << "O(n) Calisti. Dongu " << n << " kere dondu." << endl;
}

// 4. O(n^2) - Karesel Zaman (Quadratic Time)
// Ic ice (nested) iki dongu de n kadar donerse n * n islem yapilir.
void kareselZaman(int n) {
    int islemSayisi = 0;
    for (int i = 0; i < n; i++) {         // Dis dongu n defa
        for (int j = 0; j < n; j++) {     // Ic dongu n defa
            islemSayisi++; 
        }
    }
    cout << "O(n^2) Calisti. n=" << n << " icin toplam islem: " << islemSayisi << endl;
}

// 5. O(n^2) - Bagimli Ic Ice Donguler
// Ic dongu dis dongudeki 'i' degerine gore doner. 
void bagimliKareselZaman(int n) {
    int islemSayisi = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) { // j < i sarti var
            islemSayisi++;
        }
    }
    // Islem sayisi 1 + 2 + 3 + ... + (n-1) = n*(n-1)/2 olur. En buyuk terim n^2 oldugu icin O(n^2) kabul edilir.
    cout << "O(n^2) (Bagimli) Calisti. n=" << n << " icin islem: " << islemSayisi << endl;
}

int main() {
    int n = 64; // Girdi boyutu

    cout << "--- Big-O Karmasiklik Örnekleri ---" << endl;
    sabitZaman(n);            // O(1)
    logaritmikZaman(n);       // O(log n)
    lineerZaman(n);           // O(n)
    kareselZaman(n);          // O(n^2)
    bagimliKareselZaman(n);   // O(n^2)

    return 0;
}