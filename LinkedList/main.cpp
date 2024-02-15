#include "./include/LinkedList.h"
using Type::LinkedList;

int main() {
	LinkedList<int> l1{ 1,2,3,4,5 };
	l1.insertAtHead(0);
	l1.insertAtTail(6);
	l1.display();
}