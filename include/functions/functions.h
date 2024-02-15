#include <iostream>
#include <stdexcept>
#include <random>
#include <string>

using namespace std;

namespace linkedList {

	template<typename T>
	struct Node {
		string lastName;
		string firstName;
		int course;
		float averageScore;
		Node* next;

		Node() : next(nullptr) {} // Конструктор по умолчанию

		Node(const Node& other) : lastName(other.lastName), firstName(other.firstName), course(other.course), averageScore(other.averageScore), next(nullptr) {} // Конструктор копирования

		Node(string lName, string fName, int crs, float score) : lastName(lName), firstName(fName), course(crs), averageScore(score), next(nullptr) {} // Конструктор, заполняющий список случайными значениями

		~Node() {} // Деструктор
	};

	template <typename T>
	class LinkedList {
	private:
		Node<T>* _head;

	public:
		LinkedList() : _head(nullptr) {}

		LinkedList(const LinkedList& other) {
			_head = nullptr;
			if (other._head != nullptr) {
				Node<T>* current = other._head->next;
				do {
					addStudent(new Node<T>(current->lastName, current->firstName, current->course, current->averageScore));
					current = current->next;
				} while (current != other._head->next);
			}
		}

		LinkedList(int numStudents) : _head(nullptr) {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<> scoreDistribution(2.0, 5.0);
			for (int i = 0; i < numStudents; ++i) {
				addStudent(new Node<T>("LastName" + std::to_string(i), "FirstName" + std::to_string(i), i % 5 + 1, scoreDistribution(gen)));
			}
		}

		~LinkedList() {
			while (_head != nullptr) {
				pop_head();
			}
		}

		LinkedList& operator=(const LinkedList& other) {
			if (this != &other) {
				LinkedList temp(other);
				std::swap(_head, temp._head);
			}
			return *this;
		}

		void addStudent(Node<T>* newStudent) {
			if (_head == nullptr) {
				_head = newStudent;
				_head->next = _head;
			}
			else {
				newStudent->next = _head->next;
				_head->next = newStudent;
				_head = newStudent;
			}
		}

		void push_tail(Node<T>* newStudent) {
			if (_head == nullptr) {
				_head = newStudent;
				_head->next = _head;
			}
			else {
				newStudent->next = _head->next;
				_head->next = newStudent;
				_head = newStudent;
			}
		}

		void push_tail(LinkedList& otherList) {
			if (otherList._head != nullptr) {
				Node<T>* current = otherList._head->next;
				do {
					push_tail(new Node<T>(current->lastName, current->firstName, current->course, current->averageScore));
					current = current->next;
				} while (current != otherList._head->next);
			}
		}

		void push_head(Node<T>* newStudent) {
			if (_head == nullptr) {
				_head = newStudent;
				_head->next = _head;
			}
			else {
				newStudent->next = _head->next;
				_head->next = newStudent;
			}
		}

		void push_head(LinkedList& otherList) {
			if (otherList._head != nullptr) {
				Node<T>* current = otherList._head->next;
				do {
					push_head(new Node<T>(current->lastName, current->firstName, current->course, current->averageScore));
					current = current->next;
				} while (current != otherList._head->next);
			}
		}

		void pop_head() {
			if (_head != nullptr) {
				if (_head->next == _head) {
					delete _head;
					_head = nullptr;
				}
				else {
					Node<T>* temp = _head->next;
					_head->next = temp->next;
					delete temp;
				}
			}
		}

		void pop_tail() {
			if (_head != nullptr) {
				if (_head->next == _head) {
					delete _head;
					_head = nullptr;
				}
				else {
					Node<T>* current = _head->next;
					while (current->next != _head) {
						current = current->next;
					}
					current->next = _head->next;
					delete _head;
					_head = current;
				}
			}
		}

		void delete_node(const string& lName, const string& fName, int crs) {
			if (_head != nullptr) {
				Node<T>* current = _head->next;
				Node<T>* prev = _head;
				while (current != _head) {
					if (current->lastName == lName && current->firstName == fName && current->course == crs) {
						prev->next = current->next;
						delete current;
						current = prev->next;
					}
					else {
						prev = current;
						current = prev->next;
					}
				}
			}
		}

		Node<T>* operator[](int index) const {
			if (index < 0 || _head == nullptr) return nullptr;

			Node<T>* current = _head->next;
			int count = 0;

			do {
				if (count == index) return current;
				++count;
				current = current->next;
			} while (current != _head->next);

			return nullptr;
		}

		Node<T>*& operator[](int index) {
			if (index < 0 || _head == nullptr)
				throw out_of_range("Index out of range");

			Node<T>* current = _head->next;
			int count = 0;

			do {
				if (count == index)
					return current;
				++count;
				current = current->next;
			} while (current != _head->next);

			throw out_of_range("Index out of range");
		}

		void removeFailingStudents() {
			Node<T>* current = _head->next;
			Node<T>* prev = _head;

			while (current != _head) {
				if (current->averageScore < 3.0) {
					prev->next = current->next;
					delete current;
					current = prev->next;
				}
				else {
					prev = current;
					current = prev->next;
				}
			}
		}
	};
	template<typename T>
	ostream& operator<<(ostream& os, const LinkedList<T>& list) {
		Node<T>* current = list[0];
		while (current != nullptr) {
			os << "Last Name: " << current->lastName << ", First Name: " << current->firstName << ", Course: " << current->course << ", Average Score: " << current->averageScore << endl;
			current = current->next;
			if (current == list[0]) break; 
		}
		return os;
}
}
