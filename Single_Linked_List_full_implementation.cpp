#include <iostream>

class sll {
    public:
    
    typedef long long ll;

    private:

    typedef struct node {
        ll data;
        node* next;
        node(ll x) {
            data = x;
            next = nullptr;
        }
    } Node;

    public:

    Node *head = nullptr;
    void append(ll x) {
        if (!head) {
            head = new Node(x);
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new Node(x);
        }
    }

    void insert(ll x) {
        if (!head) {
            head = new Node(x);
        }
        else {
            Node* temp = head;
            while (temp) {
                if (x < temp->next->data) {
                    Node *newNode = new Node(x);
                    newNode->next = temp->next;
                    temp->next = newNode;
                    break;
                }
                if (!temp->next) {
                    temp->next = new Node(x);
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void insertNode(Node*& sorted, Node* node) {
        if (!sorted || node->data < sorted->data) {
            node->next = sorted;
            sorted = node;
            return;
        }
        Node* current = sorted;
        while (current->next && current->next->data < node->data) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
    
    void sort() {
        Node* sorted = nullptr;
        Node* current = head;
        while (current) {
            Node* next = current->next;
            current->next = nullptr;
            insertNode(sorted, current);
            current = next;
        }
        head = sorted;
    }

    void remove() {
        if (!head) {
            return;
        }
        Node* temp = head;
        while (head) {
            if (head->next->next == nullptr) {
                delete head->next;
                head->next = nullptr;
                break;
            }

        }
    }

    void removeSpecific(ll x) {
        if (!head) {
            return;
        }
        Node* temp = head;
        while (temp) {
            if (temp->next->data == x) {
                Node* child = temp->next->next;
                delete temp->next; 
                temp->next = child;
                break;
            }
        }
    }

    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};


int main() {
    using namespace std;
    sll sl;
    sl.append(1); sl.print();
    sl.append(2); sl.print();
    sl.append(3); sl.print();
    sl.append(5); sl.print();
    sl.append(6); sl.print();
    sl.insert(4); sl.print();
    sl.insert(3); sl.print();
    sl.insert(2); sl.print();
    /*========================      testing sorting algorithm*/
    sl.append(6); sl.print();
    sl.append(5); sl.print();
    sl.append(4); sl.print();
    sl.append(3); sl.print();
    sl.append(2); sl.print();
    sl.sort(); sl.print();
