#ifndef __LinkedList_H_
#define __LinkedList_H_

#include <iostream>

namespace Type {
	class Node {
	private:
		int m_Value;
		std::shared_ptr<Node> m_Next;
	public:
		Node(int value) : m_Value{ value }, m_Next{ nullptr } {};

		friend class LinkedList;
	};

	class LinkedList {
	private:
		std::shared_ptr<Node> m_Head;
		std::shared_ptr<Node> m_Tail;
	public:
		LinkedList() : m_Head{ nullptr }, m_Tail{ nullptr } {};
		LinkedList(const std::initializer_list<int>&);

		void display() const;
		int length() const;
		void insertAtHead(int value);
		void insertAtTail(int value);
		void insertAtIndex(int index, int value);
		void deleteHead();
		void deleteTail();
		void deleteIndex(int index);
	};
}
#endif