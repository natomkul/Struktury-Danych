#include "SinglyLinked.h"


SinglyLinked::SinglyLinked():head(NULL){
	size = 0;
}

SinglyLinked::~SinglyLinked(){
	SNode* v = get_head();
	while (v != NULL) {
		deleteFront();
		v = get_head();
	}
}

SNode* SinglyLinked::get_head(){
	return head;
}

void SinglyLinked::display() {
	SNode* v = get_head();
	while (v != NULL) {
		cout << v ->data << " -> ";
		v = v ->next;
	}
	cout << "END";
	
}

void SinglyLinked::addAt(int index, int value){
	SNode* v = new SNode(); //dodawany węzeł
	v->data = value;
	if (index == 0) {
		addFront(value);
	}
	if (index < 0 || index > size) {
		cout<<"brak indeksu nr "<<index<<endl;
	}
	else {
		SNode* old = new SNode();	//węzeł "transportowy"
		old->data = value;
		old->next = head;
		for (int i = 0; i < index; i++) {
			old = old->next;
		}
		v->next = old->next;
		old->next = v;
		size++;
	}
}

void SinglyLinked::addFront(int value) {
	SNode* v = new SNode();
	v ->data = value;
	v ->next = head;
	head = v;
	size++;
}

void SinglyLinked::addBack(int value) {
	addAt(size, value);
}

void SinglyLinked::deleteAt(int index){
	if (index < 0 || index > size) {
		cout << "brak indeksu nr " << index << endl;
	}
	if (index == 0) {
		deleteFront();
	}
	else {
		SNode* temp = new SNode();
		SNode* old = new SNode();	//węzeł "transportowy"
		old->next = head;
		for (int i = 0; i < index; i++) {
			old = old->next;
		}
		temp = old->next;
		old->next = temp->next;
		delete temp;
		size--;
	}

}

void SinglyLinked::deleteFront(){
	SNode* old = get_head();
	if (old==NULL) {
		return;
	}
	else{
		head = old->next;
		delete old;
		size--;

	}
}

void SinglyLinked::deleteBack() {
	deleteAt(size-1);
}

int main() {
	SinglyLinked* lista = new SinglyLinked();
	lista->addFront(6);
	lista->addFront(8);
	lista->addFront(7);
	lista->addFront(9);
	lista->deleteBack();
	lista->display();
}
