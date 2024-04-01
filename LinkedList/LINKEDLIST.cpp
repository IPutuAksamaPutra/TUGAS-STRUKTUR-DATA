#include <iostream>
using namespace std;

class Node{
	public:
		char id;
		Node *next;
		
		Node(){
			next == NULL;
		}
};
class LinkedList{
	public:
		Node *head;
		Node*tail;
		
		LinkedList(){
			head = tail = NULL;
		}
		void insertToHead(char data){
			Node *node = new Node();
			node->id = data;
			
			if(head==NULL){
				head = tail =NULL;
			}else{
				Node *tmp = head;
				head = node;
				head->next = tmp;
			}
			Node *tmp = head;
			head = node;
			node->next= tmp;
		
		}
		void insertToTail(char data){
			
			Node *node = new Node();
			node->id = data;
			
			if(head==NULL){
				head = tail =node;
			}else{
				tail->next = node;
				tail = node;
			}
		
		}
		void printALL(){
			if (head!=NULL){
				Node *tmp = head;
				do {
					cout << tmp->id << "->";
					tmp = tmp->next;
				}while (tmp!=NULL);
			}
		}
		void insertNodeAfter(char *data, char after){
			
			if(tail->id == data{
				insertToTail(data);
			}else if(head==NULL){
				cout << "ERROR LINKEDLIST EMPTY " <<endlL;
			}else if(tail->id==data){
				insertToTail(data);
			}else {
				Node *node = new Node();
				node->id = data;
				
				Node *tmp = head;
				while (tmp->id!=after && tmp! = NULL){
					tmp = tmp->next;
				}
				
				if(tmp==NULL){
						cout << "After node is not found " << endl;
				}else{
					node->next = tmp->next;
					tmp->next = node;
				}
			}
			
					
			}
};		
int main(int argc, char** argv) {
	
	LinkedList *link1 = new LinkedList();
	
	Node *node1 = new Node();
	node1->id = 'A';
	
	link1->head = node1;
	link1->tail = node1;
	
	cout << link1->head->id << endl;
	cout << node1<< endl;
	
	Node *node2 = new Node();
	node2->id = 'B';
	
	link1->tail->next = node2;
	link1->tail = node2;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id <<endl;
	
	Node *nodeX = new Node();
	nodeX->id = 'X';
	
	Node *tmp = link1->head;
	nodeX->next = tmp;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	link1->insertToHead('Y');
	link1->insertToTail('C');
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	link1->insertNodeAfter('Z','C');
	link1->printALL();
	return (0);
}
