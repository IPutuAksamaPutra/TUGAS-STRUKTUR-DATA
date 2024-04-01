#include <iostream>
using namespace std;

class Node {
public:
    char id;
    Node* next;
    
    Node() {
        next = NULL; // Menggunakan operator penugasan (=) untuk menginisialisasi pointer next
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    
    LinkedList() {
        head = tail = NULL;
    }

    void insertToHead(char data) {
        Node* node = new Node();
        node->id = data;
        
        Node* tmp = head;
        head = node;
        node->next = tmp;
    }

    void insertToTail(char data) {
        Node* node = new Node();
        node->id = data;
        node->next = NULL; // Pastikan next dari node baru diatur menjadi NULL

        if (head == NULL) {
            // Jika linked list kosong, atur head dan tail menjadi node baru
            head = tail = node;
        } else {
            // Jika linked list tidak kosong, tambahkan node baru ke tail
            tail->next = node;
            tail = node;
        }
    }

    void printAll() {
        if (head == NULL) {
            cout << "Linked list is empty." << endl;
            return;
        }

        Node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->id << "->";
            tmp = tmp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteTail() {
        // Periksa jika linked list kosong
        if (head == NULL) {
            cout << "Linked list is empty. Nothing to delete." << endl;
            return;
        }
        
        // Periksa jika linked list hanya memiliki satu node
        if (head->next == NULL) {
            delete head;
            head = tail = NULL;
            cout << "Deleted the only node in the linked list." << endl;
            return;
        }
        
        // Temukan node sebelum tail
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        
        // Bebaskan memori tail
        delete tail;
        
        // Atur pointer tail ke node sebelum tail
        tail = temp;
        
        // Atur pointer next dari node sebelum tail menjadi NULL
        tail->next = NULL;
        
        cout << "Tail node deleted successfully." << endl;
    }
};

int main(int argc, char** argv) {
    
    LinkedList* link1 = new LinkedList();
    
    Node* node1 = new Node();
    node1->id = 'A';
    
    link1->head = node1;
    link1->tail = node1;
    
    cout << link1->head->id << endl;
    cout << node1 << endl;
    
    Node* node2 = new Node();
    node2->id = 'B';
    
    link1->tail->next = node2;
    link1->tail = node2;
    
    cout << link1->head->id << endl;
    cout << link1->tail->id << endl;
    
    Node* nodeX = new Node();
    nodeX->id = 'X';
    
    Node* tmp = link1->head;
    nodeX->next = tmp;
    
    cout << link1->head->id << endl;
    cout << link1->tail->id << endl;
    
    link1->insertToHead('Y');
    link1->insertToTail('C');
    
    cout << link1->head->id << endl;
    cout << link1->tail->id << endl;
    
    cout << "Linked list before deletion: ";
    link1->printAll();
    cout << endl;
    
    // Delete tail
    link1->deleteTail();
    
    cout << "Linked list after deletion: ";
    link1->printAll();
    cout << endl;

    return 0;
}

