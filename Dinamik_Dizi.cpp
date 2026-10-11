#include <iostream>
using namespace std;

// Array-Based List (Dinamik Dizi) Sinifi
class ArrayList {
private:
    int* data;      // Bellekteki diziyi isaret eden pointer
    int capacity;   // Dizinin fiziksel kapasitesi
    int size;       // Dizideki mevcut gecerli eleman sayisi

    // Dizi doldugunda calisacak olan dinamik boyutlandirma fonksiyonu
    void resize() {
        int newCapacity = capacity * 2;             // Kapasiteyi 2 katina cikar
        int* newData = new int[newCapacity];        // Yeni kapasiteyle bellekte yer ayir
        
        // Eski dizideki verileri yeni diziye kopyala (O(n) maliyeti burada olusur)
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        delete[] data;      // Eski dizinin bellegini serbest birak
        data = newData;     // Pointer'i yeni diziye bagla
        capacity = newCapacity;
        
        cout << "[Sistem] Kapasite artirildi. Yeni kapasite: " << capacity << endl;
    }

public:
    // Yapici metot (Constructor): Baslangic degerlerini atar
    ArrayList() {
        capacity = 2;              // Baslangicta fiziksel kapasite 2
        size = 0;                  // Baslangicta eleman yok (mantiksal boyut 0)
        data = new int[capacity];  // 2 elemanlik alan ayir
    }

    // Yikici metot (Destructor): Sinifla isimiz bitince bellegi temizler
    ~ArrayList() {
        delete[] data;
    }

    // Listenin sonuna eleman ekleme (Amortized O(1))
    void add(int value) {
        // Eger gecerli eleman sayisi kapasiteye ulastiysa, genislet
        if (size == capacity) {
            resize();
        }
        data[size] = value;
        size++; // Mantiksal boyutu artir
    }

    // Belirli bir indekse eleman ekleme (Araya ekleme O(n))
    void insert(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Gecersiz indeks!" << endl;
            return;
        }
        if (size == capacity) {
            resize();
        }
        
        // Aradaki boslugu acmak icin elemanlari saga kaydir (Shifting)
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    // Dizinin icerigini, boyutunu ve kapasitesini ekrana yazdirma
    void printList() {
        cout << "Liste: [ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "] (Size: " << size << ", Capacity: " << capacity << ")" << endl;
    }
};

int main() {
    ArrayList myList;

    // Baslangicta kapasite 2 oldugu icin ucuncu eleman eklendiginde resize calisacaktir.
    myList.add(10);
    myList.add(20);
    myList.printList();
    
    myList.add(30); // Burada dizi tam dolu oldugu icin arka planda kapasite 4'e cikacak
    myList.printList();
    
    // 1. indekse 15 sayisini ekleyelim (Kaydirma islemi yapilacak)
    cout << "1. indekse 15 ekleniyor..." << endl;
    myList.insert(1, 15);
    myList.printList();

    return 0;
}