#include "../include/LinkedList.h"
using Type::LinkedList;

LinkedList::LinkedList(const std::initializer_list<int>& list) {
	for (auto& value : list) {
		insertAtTail(value);
	}
}

void LinkedList::display() const {
	auto temp = m_Head;
	while (temp) {
		std::cout << temp->m_Value << "->";
		temp = temp->m_Next;
	}
	std::cout << "NULL\n";
}

int LinkedList::length() const {
	if (!m_Head) {
		return 0;
	}
	auto temp = m_Head;
	auto size = 1;

	while (temp->m_Next) {
		temp = temp->m_Next;
		size++;
	}

	return size;
}

void LinkedList::insertAtHead(int value) {
	if (m_Head == nullptr) {
		m_Head = std::make_shared<Node>(value);
		m_Tail = m_Head;
		return;
	}
	auto temp = std::make_shared<Node>(value);
	temp->m_Next = m_Head;
	m_Head = temp;
}

void LinkedList::insertAtTail(int value) {
	if (m_Tail == nullptr) {
		insertAtHead(value);
		return;
	}
	auto temp = std::make_shared<Node>(value);
	m_Tail->m_Next = temp;
	m_Tail = temp;
}

void LinkedList::insertAtIndex(int index, int value) {
	if (index < 0 || index > length()) {
		std::cout << "Invalid Index\n";
		return;
	}
	else if (index == 0) {
		insertAtHead(value);
		return;
	}
	else if (index == length()) {
		insertAtTail(value);
		return;
	}

	auto temp = m_Head;

	while (index - 1 > 0) {
		temp = temp->m_Next;
		index--;
	}

	auto newNode = std::make_shared<Node>(value);
	newNode->m_Next = temp->m_Next;
	temp->m_Next = newNode;
}

void LinkedList::deleteHead() {
	if (!m_Head) {
		std::cout << "Can't delete head of an empty list\n";
		return;
	}
	else if (m_Head == m_Tail) {
		m_Head = nullptr;
		m_Tail = nullptr;
		return;
	}
	m_Head = m_Head->m_Next;
}

void LinkedList::deleteTail() {
	if (!m_Tail) {
		std::cout << "Can't delete tail of an empty list\n";
		return;
	}
	else if (m_Head == m_Tail) {
		m_Head = nullptr;
		m_Tail = nullptr;
		return;
	}
	auto temp = m_Head;

	while (temp && temp->m_Next != m_Tail) {
		temp = temp->m_Next;
	}

	m_Tail = temp;
	m_Tail->m_Next = nullptr;
}

void LinkedList::deleteIndex(int index) {
	if (!m_Head) {
		return;
	}
	else if (index < 0 || index >= length()) {
		std::cout << "Invalid Index\n";
		return;
	}
	else if (index == 0) {
		deleteHead();
		return;
	}
	else if (index == length()-1) {
		deleteTail();
		return;
	}

	auto temp = m_Head;

	while (index - 1 > 0) {
		temp = temp->m_Next;
		index--;
	}

	temp->m_Next = temp->m_Next->m_Next;
}