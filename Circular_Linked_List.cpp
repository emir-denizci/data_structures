#include <iostream>
using namespace std;

// Dugum (Node) Sinifi
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head; // Dairesel listelerde baslangic noktasini tutan referans (cursor)

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Dairesel listeye eleman ekleme
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) { // Eger liste bossa
            head = newNode;
            head->next = head; // Dairesel yapiyi kurmak icin kendi kendini gosterir
        } else {
            Node* current = head;
            
            // Son elemani bulana kadar ilerle (son elemanin next'i tekrar head'i gosterir)
            while (current->next != head) {
                current = current->next;
            }
            
            current->next = newNode; // Eski son elemani yeni elemana bagla
            newNode->next = head;    // Yeni elemanin okunu tekrar en basa (head) bagla ki cember bozulmasin
        }
    }

    // Dairesel listeyi ekrana yazdirma
    // Cember yapisi oldugu icin standart while kullanilamaz, do-while dongusu kullanilir
    void display() {
        if (head == NULL) {
            cout << "Dairesel Bagli Liste bos." << endl;
            return;
        }

        Node* current = head;
        cout << "Dairesel Liste: ";
        
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head); // Tekrar basa donene kadar yazdir
        
        cout << "(Head)" << endl;
    }
};

int main() {
    CircularLinkedList clist;
    
    clist.insert(100);
    clist.insert(200);
    clist.insert(300);
    
    // Cikti: Dairesel Liste: 100 -> 200 -> 300 -> (Head)
    clist.display();

    return 0;
}