
#include <iostream>

 
struct Node{
	int val;
	struct Node* next;

	Node(int val){
		this->val = val;
		this->next = nullptr;
	}

	Node(int val, struct Node* next){
		this->val = val;
		this->next = next;
	}
};

typedef struct Node Node;


class LinkedList{
public:
	LinkedList(){
		mHead = nullptr;
		mSize = 0;
	}

	LinkedList(Node* head){
		mHead = head;
		mSize = 0;
		while(head != nullptr){
			mSize++;
			head = head->next;
		}
	}

	~LinkedList(){
		while(mHead != nullptr){
			Node* next = mHead->next;
			delete mHead;
			mHead = next;
		}
	}

	void printList(){
		Node* curr = mHead;
		while(curr != nullptr){
			std::cout << curr->val << " ";
			curr = curr->next;
		}
		std::cout << std::endl;
	}

	void insertHead(Node* node){
		if( node == nullptr )
			return;

		node->next = mHead;
		mHead = node;
	}

	void insertTail(Node* node){
		if( node == nullptr )
			return;

		if( mHead == nullptr ){
			mHead = node;
			return;
		}

		Node* curr = mHead;
		while( curr->next != nullptr ){
			curr = curr->next;
		}
		curr->next = node;
	}

private:
	Node* mHead;
	int mSize;
};



int main(){
	Node* head = new Node(1);
	LinkedList list(head);
	list.insertHead(new Node(2));
	list.printList();
	list.insertTail(new Node(3));
	list.printList();
}





