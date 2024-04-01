#include <iostream>
#include <string>
using namespace std;

class Queue {
	public:
	    int size;
	    int top;
	    string *items;
	
		Queue(int queueSize) {
		    size = queueSize;
		    top = -1;
		    items = new string[size];
		}
	
	
	    bool penuh() {
	        return top >= size - 1; // menggunakan bool untuk mengecek kondisi mengecek kondisi
	    }
	
	    bool kosong() {
	        return top == -1;
	    }
	
	    void enqueue() {
	        if (!penuh()) {
	            cout << "Masukkan Data: ";
	            cin >> items[top + 1]; 
	            top++; 
	            cout << "Data \"" << items[top] << "\" telah dimasukkan ke dalam Antrean.\n " << endl; 
	        } else {
	            cout << "ERROR: Antrean penuh." << endl;
	        }
	    }
	
	    void dequeue() {
	        if (!kosong()) {
	        	
	        	cout << "Data \"" << items[0] << "\" di-dequeue.\n" << endl;
	        	
	        	for(int i = 0; i < top; i++){
	        		items[i] = items[i + 1];
				}
				
	            top--;
	            
	        } else {
	            cout << "ERROR: Antrean kosong." << endl;
	        }
	    }
	
	    void tampil() {
	        if (!kosong()) {
	            cout << "Data dalam Queue: " << endl;
	            for (int i = top; i >= 0; i--) {
	                cout << items[i] << endl;
	            }
	        } else {
	            cout << "Data dalam queue: " << endl << "Tidak ada. \n\n" ;
	        }
	    }
};

int main() {
    int ukuranQueue;
    cout << "Masukkan ukuran queue: ";
    cin >> ukuranQueue;
    system ("cls");
    Queue queue(ukuranQueue); 

    int pilihan;

    do {
    	queue.tampil();
        cout << "\nMenu Utama\n1. Enqueue\n2. Dequeue\n3. Keluar\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
            	system ("cls");
                queue.enqueue();
                break;
            case 2:
            	system ("cls");
                queue.dequeue();
                break;
            case 3:
                cout << "Keluar dari program." << endl;
                break;
            default:
            	system("cls");
                cout << "Perintah tidak valid.\n" << endl;
                break;
        }
    } while (pilihan != 3);

    return 0;
}
