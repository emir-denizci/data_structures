#include <iostream>
using namespace std;

class MyVector {
    private:
    int* arr; // Verileri tutacağımız dinamik dizi (pointer)
    int capacity; // Dizinin hafızada ayırdığı toplam kapasite
    int current; // Dizide anlık olarak bulunan eleman sayısı (size)
    public:
    MyVector () { // Constructor: Başlangıçta 1 elemanlık yer ayırıyoruz
        capacity = 1;
        current = 0;
        arr = new int[capacity];
    }
    ~MyVector () { // Destructor: Obje yok olduğunda memory leak (bellek sızıntısı) olmaması için
        delete[] arr;
    }
    // Dizinin sonuna eleman ekleme fonksiyonu
    void push_back (int data) {
        // 1. Adım: Eğer dizi doluysa (current == capacity), kapasiteyi 2 katına çıkar.
        if (current == capacity) {
            capacity *= 2;
            int* temp = new int[capacity]; // Yeni kapasiteyle hafızada yer ayır
            // Eski dizideki elemanları yeni diziye taşı
            for (int i=0; i<current; i++) {
                temp[i] = arr[i];
            }
            delete[] arr; // Eski diziyi hafızadan sil
            arr = temp; // arr pointer'ını yeni diziye yönlendir
        }
        // 2. Adım: Yeni elemanı dizinin sonuna ekle ve current'ı 1 artır.
        arr[current] = data;
        current++;
    }
    void print () { // Dizideki elemanları ekrana yazdırma
        for (int i=0; i<current; i++) {
            cout << arr[i] << " ";
        }
        cout << "\nKapasite: " << capacity << " | Boyut: " << current << endl;
    }
};

int main () {
    MyVector vec;
    vec.push_back(10);
    vec.print();
    vec.push_back(20);
    vec.print();
    vec.push_back(30); // Kapasite aşımı burada gerçekleşiyor
    vec.print();
    return 0;
}