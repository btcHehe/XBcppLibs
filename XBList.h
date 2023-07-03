#pragma once
#include <iostream>
#include <memory>

namespace xb
{
	template<typename T>
	class Node
	{
	public:
		T value;
		std::shared_ptr<Node<T>> nextNode;
		std::shared_ptr<Node<T>> prvNode;

		Node(const T& value) : value(value), nextNode(nullptr), prvNode(nullptr) {}
	};

	template<typename T>
	class XBList
	{
	private:
		std::shared_ptr<Node<T>> _head;
		std::shared_ptr<Node<T>> _tail;

	public:

		XBList() : _head(nullptr), _tail(nullptr) {}

		void push_front(const T& value)
		{
			std::shared_ptr<Node<T>> newElement = std::make_shared<Node<T>>(value);

			if (!_head)
			{
				_head = newElement;
				_tail = _head;
			}
			else
			{
				newElement->nextNode = _head;
				newElement->prvNode = nullptr;
				_head = newElement;
			}

		}
		void push_back(const T& value)
		{
			std::shared_ptr<Node<T>> newElement = std::make_shared<Node<T>>(value);

			if (!_tail)
			{
				_tail = newElement;
				_head = _tail;
			}
			else
			{
				_tail->nextNode = newElement;
				newElement->prvNode = _tail;
				_tail = newElement;
			}
		}
		bool check_exist(const T& value)
		{
			std::shared_ptr<Node<T>> iterator = _head;
			while (iterator != nullptr)
			{
				if (iterator->value == value)
					return true;
				iterator = iterator->nextNode;
			}
			return false;
		}
		void print_forward() const
		{
			std::shared_ptr<Node<T>> iterator = _head;

			while (iterator != nullptr)
			{
				std::cout << iterator->value << " ";
				iterator = iterator->nextNode;
			}
		}
		void print_backward() const
		{
			std::shared_ptr<Node<T>> iterator = _tail;

			while (iterator != nullptr)
			{
				std::cout << iterator->value << " ";
				iterator = iterator->prvNode;
			}
		}
		void rm_elem(const T& value)
		{
			if (!_head)
				return;

			if (_head == _tail)
			{
				if (_head->value == value)
				{
					_head.reset();
					_tail.reset();
				}
				else
				{
					std::cout << "RemoveCertainElement message: value to remove not found! \n";
					return;
				}
			}
			else if (_head->value == value)
			{
				_head = _head->nextNode;
				_head->prvNode.reset();
			}
			else if (_tail->value == value)
			{
				_tail = _tail->prvNode;
				_tail->nextNode.reset();
			}
			else
			{
				std::shared_ptr<Node<T>> current = _head;

				while (current->value != value)
				{
					current = current->nextNode;
					if (current == nullptr)
						return;
				}
				current->nextNode->prvNode = current->prvNode;
				current->prvNode->nextNode = current->nextNode;
				current.reset();
			}
		}
		void rm_first()
		{
			if (_head)
			{
				if (_head->nextNode)
				{
					_head = _head->nextNode;
					_head->prvNode.reset();
				}
				else
				{
					_tail.reset();
					_head.reset();
				}

			}
			else
			{
				std::cout << "RemoveFirst message: Error! First element does not exist!";
			}
		}
		void rm_last()
		{
			if (_tail)
			{
				if (_tail->prvNode)
				{
					_tail = _tail->prvNode;
					_tail->nextNode.reset();
				}
				else
				{
					_tail.reset();
					_head.reset();
				}
			}
			else
			{
				std::cout << "RemoveLast message: Error! Last element does not exist!";
			}
		}
		void clear()
		{
			std::shared_ptr<Node<T>> current = _head;
			std::shared_ptr<Node<T>> erasePtr = nullptr;

			_head = nullptr;
			_tail = nullptr;
			while (current != nullptr)
			{
				erasePtr = current;
				erasePtr.reset();
				current = current->nextNode;
			}

		}
		void reverse()
		{
			std::shared_ptr<Node<T>> reverseHelpPtr = nullptr;
			std::shared_ptr<Node<T>> current = _head;
			while (current != nullptr)
			{
				reverseHelpPtr = current->nextNode;
				current->nextNode = current->prvNode;
				current->prvNode = reverseHelpPtr;
			}
			reverseHelpPtr = _head;
			_head = _tail;
			_tail = reverseHelpPtr;
		}
		void modify_at(const int pos, const T& value)
		{
			if (!_head || GetLength() <= pos || pos < 0)
			{
				std::cout << " getValueAtPosition message: Error! Position out of range or empty list!";
				return;
			}


			int iterator = 0;
			std::shared_ptr<Node<T>> current = _head;

			while (iterator != pos && current != nullptr)
			{
				current = current->nextNode;
				iterator++;
			}
			if (current != nullptr)
				current->value = value;
			else
			{
				std::cout << " getValueAtPosition message: Error! Position out of range or empty list!";

			}

		}
		int length()
		{
			int length = 0;
			std::shared_ptr<Node<T>> iterator = _head;
			while (iterator != nullptr)
			{
				length++;
				iterator = iterator->nextNode;
			}
			return length;

		}
		bool empty()
		{
			int length = 0;
			std::shared_ptr<Node<T>> iterator = _head;
			while (iterator != nullptr)
			{
				length++;
				iterator = iterator->nextNode;
			}
			if (length == 0)
				return true;
			return false;
		}
		T at(int pos)
		{
			int iterator = 0;
			std::shared_ptr<Node<T>> current = _head;

			while (iterator != pos && current != nullptr)
			{
				current = current->nextNode;
				iterator++;
			}
			if (current != nullptr)
				return current->value;
			else
			{
				std::cout << " getValueAtPosition message: Error! Position out of range or empty list!";
				return -1;
			}
		}

	};
}