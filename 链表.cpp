#include<iostream>
using namespace std;
class Link
{
public:
	struct node {
		int data;
		node* nextl;
	};
private:
	node* head= nullptr;
	int siz=0;
public:
	void Link_inh(int a) {
		node* p = new node();
		p->data = a;
		p->nextl = head;
		head=p;
		siz++;
	}
	void Link_inb(int a) {
		if (head == nullptr) {
			Link_inh(a);
			return;
		}
		node* p = new node();
		node* cir = head;
		while (cir->nextl != nullptr) {
			cir = cir->nextl;
		}
		cir->nextl = p;
		p->data = a;
		p->nextl = nullptr;
		siz++;
	}
	void Link_ini(int a, int pos) {
		if (pos <= siz) {
			if (siz==0&&pos==0&&head == nullptr) {
				Link_inh(a);
				return;
			}
			if (pos == 0) {
				Link_inh(a);
				return;
			}
			node* p = new node();
			node* cir_i = head;
			for (int i = 1;i <= pos;i++) {
				cir_i = cir_i->nextl;
			}
			node* t = cir_i->nextl;
			cir_i->nextl = p;
			p->data = a;
			p->nextl = t;
			siz++;
		}
		else {
			cout << -1;
		}
	}
	void Link_pop(int pos) {
		if (siz == 0) {
			return;
		}
		if (pos >= 1 && pos <= siz) {
			node* cir = head;
			if (pos == 1) {
				node* temp = head;
				head = head->nextl;
				delete temp;
				siz--;
				return;
			}
			for (int i = 1;i < pos-1;i++) {
				cir = cir->nextl;
			}
			node *temp=cir->nextl;
			cir->nextl = cir->nextl->nextl;
			delete temp;
			siz--;
		}
		else {
			cout << -1;
		}
	}
	~Link() {
		node* cir = head;
		if (head == nullptr) {
			return;
		}
		while (cir!=nullptr) {
			node* temp = cir;
			cir = cir->nextl;
			delete temp;
		}
	}
};
int main() {
		return 0;
	}
