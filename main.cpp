# include <iostream>

using namespace std;

class Node {
public :
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
    };
};

class NodeOfStack {
    public:
    Node* data;
    NodeOfStack* next;

    NodeOfStack(Node* node){
        data = node;
    }
};

class Stack{
public :
    NodeOfStack* head;

    void push(Node* node){
        NodeOfStack* newNode = new NodeOfStack(node);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){
        if(head == NULL){
            return;
        }else{
            head = head->next;
        }
    }

    void printStack(){

        NodeOfStack* currNode = head;
        cout << "stack data print starts" <<endl;
        while (currNode->next != NULL)
        {
            cout << currNode->data->data <<endl;
            currNode = currNode->next;
        }
        cout << currNode->data->data <<endl;
        cout << "stack data print ends" <<endl;
        return;
        
    }

};

void printAll(Node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << endl;
    printAll(root->right);
    printAll(root->left);
}


void printByIteration(Node* root){
    if(root == NULL) return;
}

int main (){

    Node* root = new Node(20);
    root->right = new Node(44);
    root->left = new Node(10);
    root->right->right = new Node(55);
    root->right->left = new Node(40);
    root->left->right = new Node(15);
    root->left->left = new Node(7);
    cout << "hello" <<endl;
    // printAll(root);

    // cout << "iteration method : " <<endl;

    // printByIteration(root);
//         20
//       /    \
//     10     44
//    /  \   /  \
//   7   15 40  55

Stack* stack1 = new Stack();

    stack1->push(root);
    stack1->push(root->right);
    stack1->push(root->left);

    stack1->printStack();

}   