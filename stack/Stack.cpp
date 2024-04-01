#include <iostream>
using namespace std;

#define max 5
string data[max];
int top = 0;

bool isFull() {
    return (top >= max);
}

bool isEmpty() {
    return (top == 0);
}

void view() {
    if (!isEmpty()) {
        cout << "Data Tersimpan : " << endl;
        for (int a = 0; a < top; a++) {
            cout << a + 1 << ". " << data[a] << endl;
        }
    } else {
        cout << "Data Kosong" << endl;
    }
    if (isFull()) {
        cout << "Data Penuh" << endl;
    }
    cout << endl;
}

void push() {
    if (!isFull()) {
        cout << "Masukkan Data : ";
        cin >> data[top];
        top++;
    } else {
        cout << "Stack penuh, tidak bisa menambahkan data." << endl;
    }
}

void pop() {
    if (!isEmpty()) {
        top--;
    } else {
        cout << "Stack kosong, tidak ada data yang dapat dihapus." << endl;
    }
}

int main() {
    int pil;
    string isi;

    while (true) {
        system("cls");
        view();
        cout << "Menu Utama\n 1. Push\n 2. Pop\n 3. Keluar\n Pilih : ";
        cin >> pil;

        switch (pil) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
