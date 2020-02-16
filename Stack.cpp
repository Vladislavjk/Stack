template <typename T>
class Stack {
	template <typename T>
	class Node {
	public:
		T data;
		Node<T>* pNext;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node<T>* head;
	int size;
public:
	Stack();
	~Stack();
	void pop();
	void push(T data);
	int GetSize();
	void clear();
	bool empty();
	T top();
};

template <typename T>
Stack<T>::Stack() {
	head = nullptr;
	size = 0;
}

template <typename T>
Stack<T>::~Stack() {
	clear();
}

template<typename T>
void Stack<T>::pop() {   // pop_front
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void Stack<T>::push(T data) {  // push_front
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
int Stack<T>::GetSize() {
	return size;
}

template<typename T>
void Stack<T>::clear() {
	while (size) {
		pop();
	}
}

template<typename T>
bool Stack<T>::empty() {
	if (size == 0) return 1;
	else return 0;
}

template<typename T>
T Stack<T>::top() {
	return head->data;
}