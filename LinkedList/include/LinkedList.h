#ifndef __LinkedList_H_
#define __LinkedList_H_

#include <iostream>

namespace Type {
	template<typename T>
	class LinkedList;

	template<typename U>
	class Node {
	private:
		U m_Value;
		std::shared_ptr<Node<U>> m_Next;
	public:
		Node(U value) : m_Value{ value }, m_Next{ nullptr } {};

		friend class LinkedList<U>;
	};

	template<typename T>
	class LinkedList {
	public:
		LinkedList() : m_Head{ nullptr }, m_Tail{ nullptr } {};
		LinkedList(const std::initializer_list<T>& list) {
			for (auto& value : list) {
				insertAtTail(value);
			}
		}

		void insertAtHead(T value) {
			if (m_Head == nullptr) {
				m_Head = std::make_shared<Node<T>>(value);
				m_Tail = m_Head;
				return;
			}
			auto temp = std::make_shared<Node<T>>(value);
			temp->m_Next = m_Head;
			m_Head = temp;
		}

		void insertAtTail(T value) {
			if (m_Tail == nullptr) {
				insertAtHead(value);
				return;
			}
			auto temp = std::make_shared<Node<T>>(value);
			m_Tail->m_Next = temp;
			m_Tail = temp;
		}

		void insertAtIndex(unsigned int index, T value) {
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

			auto newNode = std::make_shared<Node<T>>(value);
			newNode->m_Next = temp->m_Next;
			temp->m_Next = newNode;
		}

		void deleteHead() {
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

		void deleteTail() {
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

		void deleteIndex(unsigned int index) {
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
			else if (index == length() - 1) {
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

		void display() const {
			auto temp = m_Head;
			while (temp) {
				std::cout << temp->m_Value << "->";
				temp = temp->m_Next;
			}
			std::cout << "NULL\n";
		}

		unsigned int length() const {
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
	private:
		std::shared_ptr<Node<T>> m_Head;
		std::shared_ptr<Node<T>> m_Tail;
	};
}
#endif