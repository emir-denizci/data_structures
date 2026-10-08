#include <iostream>
using namespace std;

int main() {
    // 1. Temel Pointer Kullanımı
    int sayi = 123;
    int* ptr = &sayi; // ptr, sayi'nin bellek adresini tutar
    
    cout << "sayi'nin degeri: " << sayi << endl;
    cout << "sayi'nin bellek adresi: " << ptr << endl;
    cout << "Pointer'in isaret ettigi deger (*ptr): " << *ptr << endl;
    
    *ptr = 456; // Dereferencing ile degeri degistirme
    cout << "Dereferencing sonrasi sayi'nin yeni degeri: " << sayi << endl;
    cout << "-----------------------------------" << endl;

    // 2. Dinamik Dizi Olusturma (Dynamic Arrays)
    int boyut;
    cout << "Dinamik dizinin boyutunu girin: ";
    cin >> boyut;

    // 'new' ile calisma zamaninda bellekten alan ayiriyoruz
    int* dinamikDizi = new int[boyut];

    // Pointer aritmetigi ve dizi kullanimi
    for (int i = 0; i < boyut; i++) {
        *(dinamikDizi + i) = (i + 1) * 10; // dinamikDizi[i] = (i + 1) * 10 ile aynidir
    }

    cout << "Dinamik Dizinin Elemanlari:" << endl;
    for (int i = 0; i < boyut; i++) {
        // Dizinin adi ilk elemanin adresini isaret eder.
        cout << "Eleman " << (i+1) << ": " << dinamikDizi[i] 
             << " (Adres: " << (dinamikDizi + i) << ")" << endl;
    }

    // Isimiz bitince 'delete' ile ayirdigimiz dinamik bellegi sisteme iade ediyoruz
    delete[] dinamikDizi;
    
    return 0;
}