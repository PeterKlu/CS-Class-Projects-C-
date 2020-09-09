#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

// add at the beginning of the linked chain
Node* add(Node* head, const int& newEntry) {
	Node* cur = new Node();
	cur->data = newEntry;
	cur->next = head;
	head = cur;
	cur = NULL;
	return head;
}

void display(Node* head) {
	Node* cur = head;
	while (cur->next != NULL) {
		cout << cur->data << "->";
		cur = cur->next;
	}
	cout << cur->data;
}

/*TODO: Q3. merge two sorted linked lists and
* return it as a new list
*/
Node* mergeTwoList(Node* n1, Node* n2) {
	if (n1 == NULL)
        return n2;
    if (n2 == NULL)
        return n1;

    if (n1->data < n2->data) {
        n1->next = mergeTwoList(n1->next, n2);
        return n1;
    }
    else {
        n2->next = mergeTwoList(n2->next, n1);
        return n2;
  }
}


/*TODO: Q4. Reverse a singly linked list
*/
Node* reverseList(Node* head) {
    Node *prev = NULL, *cur = head, *next = head->next;

    if (next->next != NULL)
        prev = next->next;

    head->next = NULL;

    while (prev->next != NULL) {
        next->next = cur;
        cur = next;
        next = prev;
        prev = prev->next;
    }

    next->next = cur;
    head = prev;
    prev->next = next;

    return head;
}


/*TODO: Q5. Remove all elements from a linked list
* of integers that have value val.
*/
Node* removeElements(Node* head, int val) {
    Node* cur = head, *prev = NULL;

    while (cur->data != val) {
        prev = cur;
        cur = cur->next;
    }

    if (cur->data == val) {
        if (prev)
            prev->next = cur->next;
        else
            head = cur->next;
    }


    return head;
}

int main() {
/*TODO: Test Case for each of the three functions
*/
    // Question 3
    Node* n1 = new Node, *n2 = new Node;

    n1 = add(n1, 4);
    n1 = add(n1, 2);
    n1 = add(n1, 1);
    n2 = add(n2, 4);
    n2 = add(n2, 3);
    n2 = add(n2, 1);
    mergeTwoList(n1, n2);
    display(n1);

    cout << endl;

    //Question 4
    Node* head = new Node;

    head = add(head, 5);
    head = add(head, 4);
    head = add(head, 3);
    head = add(head, 2);
    head = add(head, 1);
    head = reverseList(head);
    display(head);

    cout << endl;

    //Question 5
    Node* n3 = new Node;
    const int VAL = 6;

    n3 = add(n3, 6);
    n3 = add(n3, 5);
    n3 = add(n3, 4);
    n3 = add(n3, 3);
    n3 = add(n3, 6);
    n3 = add(n3, 2);
    n3 = add(n3, 1);
    n3 = removeElements(n3, VAL);
    n3 = removeElements(n3, VAL);
    display(n3);

    return 0;

}
