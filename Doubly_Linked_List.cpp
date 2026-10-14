#include <iostream>
using namespace std;

// Cift Yonlu Dugum Sinifi
class DNode {
public:
    int data;
    DNode* next;     // Ileri ok
    DNode* previous; // Geri ok

    DNode(int value) {
        data = value;
        next = NULL;
        previous = NULL;
    }
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail; // Son elemani hafizada tutmak islemleri hizlandirir

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Listenin sonuna eleman ekleme
    void insertEnd(int value) {
        DNode* newNode = new DNode(value);
        
        if (tail == NULL) { // Liste bossa
            head = newNode;
            tail = newNode;
        } else {
            newNode->previous = tail; // Yeni dugumun gerisi, eski sonu gosterir
            tail->next = newNode;     // Eski sonun ilerisi, yeni dugumu gosterir
            tail = newNode;           // Kuyrugu (tail) yeni dugume tasi
        }
    }

    // Sondan eleman silme islemi (O(1) karmasikligi)
    // Tek yonlu listelerin aksine bastan aramamiza gerek kalmaz.
    void deleteTail() {
        if (tail != NULL) {
            if (tail->previous != NULL) { // Listede birden fazla eleman varsa
                tail = tail->previous; // Kuyrugu bir geriye cek
                delete tail->next;     // Eski son elemani sil
                tail->next = NULL;     // Yeni sonun ileri bagini kopar
            } else { // Sadece tek bir eleman kaldiysa
                delete tail;
                head = NULL;
                tail = NULL;
            }
        }
    }

    void displayForward() {
        DNode* current = head;
        cout << "Ileri Dogru: ";
        while (current != NULL) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dlist;
    dlist.insertEnd(5);
    dlist.insertEnd(15);
    dlist.insertEnd(25);
    
    dlist.displayForward(); // 5 <-> 15 <-> 25 <-> NULL
    
    // Sondaki 25 elemanini hizlica siler
    dlist.deleteTail();
    cout << "Kuyruk silindikten sonra: ";
    dlist.displayForward(); // 5 <-> 15 <-> NULL
    
    return 0;
}