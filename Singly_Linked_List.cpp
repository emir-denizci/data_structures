#include <iostream>
using namespace std;

// Dugum (Node) Sinifi
class Node {
public:
    int data;       // Dugumun tuttugu veri
    Node* next;     // Bir sonraki dugumun adresi

    // Constructor: Yeni bir dugum yaratildiginda calisir
    Node(int value) {
        data = value;
        next = NULL; // Ilk basta hicbir yeri gostermez
    }
};

// Tek Yonlu Bagli Liste Sinifi
class SinglyLinkedList {
private:
    Node* head; // Listenin ilk elemanini tutan gosterici

public:
    SinglyLinkedList() {
        head = NULL; // Baslangicta liste bostur
    }

    // Listenin basina eleman ekleme
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value); // Bellekte yeni yer ayir
        newNode->next = head;            // Yeni dugumun okunu eski baslangica yonlendir
        head = newNode;                  // Yeni dugumu artik listenin basi yap
    }

    // Listenin sonuna eleman ekleme (Tail pointer olmadigi durum)
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {              // Eger liste bossa
            head = newNode;              // Eklenen eleman ayni zamanda head olur
        } else {
            Node* current = head;
            // Son elemani (next'i NULL olan) bulana kadar ilerle
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode; // Son elemanin okunu yeni elemana bagla
        }
    }

    // Listeyi ekrana yazdirma (Traversing)
    void display() {
        Node* current = head;
        cout << "Liste: ";
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next; // Bir sonraki dugume atla (link hopping)
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    
    // Cikti: Liste: 20 -> 10 -> 30 -> NULL olacaktir
    list.display();

    return 0;
}