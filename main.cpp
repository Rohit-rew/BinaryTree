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
    int length = 0;
    void push(Node* node){
        NodeOfStack* newNode = new NodeOfStack(node);
        if(head == NULL){
            head = newNode;
            length++;
        }else{
            newNode->next = head;
            head = newNode;
            length++;
        }
    }

    NodeOfStack* pop(){
        if(head == NULL){
            return NULL;
        }else{
            NodeOfStack* removedNode = head;
            head = head->next;
            length--;
            return removedNode;
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


void depthFirstTraversal(Node* root){
    if(root == NULL){
        return;
    }
    Stack* stack1 = new Stack();
    stack1->push(root);
    cout << "print starts for depth first traversal method" << endl;
    while(stack1->length > 0){
        const NodeOfStack* current = stack1->pop();
        cout << current->data->data <<endl ;
        if(current->data->right != NULL){
            stack1->push(current->data->right);
        }if(current->data->left != NULL){
            stack1->push(current->data->left);
        }
    }
    cout << "print ends for depth first traversal method" << endl;
}

//---------------------

class NodeOfQueue {
    public :
    Node* data;
    NodeOfQueue* next;
    NodeOfQueue(Node* node){
        data = node;
    }
};

class Queue{
    public :
    NodeOfQueue* head;
    int length = 0;
    
    void push(Node* node){
        NodeOfQueue* newNode = new NodeOfQueue(node);
        if(head==NULL){
            head = newNode;
            length++;
        }else{
            NodeOfQueue* currNode = head;
            while (currNode->next != NULL) {
                currNode = currNode->next;
            }
            currNode->next = newNode;
            length++;
        }
    }
    
    NodeOfQueue* pop(){
        if(head==NULL){
            return NULL;
        }else{
            NodeOfQueue* removedNode = head;
            head = head->next;
            length--;
            return removedNode;
        }
    }
    
    void print(){
        NodeOfQueue* currNode = head;
        cout << "queue print starts" <<endl;
        while (currNode->next !=NULL) {
            cout << currNode->data->data <<endl;
            currNode = currNode->next;
        }
        cout << currNode->data->data <<endl;
        cout << "queue print ends" << endl;
    }
};

void breadthFirstTraversal(Node* node){
    Queue* queue1 = new Queue();
    queue1->push(node);
    cout << "print for breadth first traversal starts" <<endl;
    while (queue1->length > 0) {
        NodeOfQueue* currentNode = queue1->pop();
        cout << currentNode->data->data <<endl;
        if(currentNode->data->left != NULL){
            queue1->push(currentNode->data->left);
        }if(currentNode->data->right != NULL){
            queue1->push(currentNode->data->right);
        }
    }
    cout << "print for breadth first traversal ends" <<endl;
}


void depthFirstTraversalByRecursion(Node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << endl;
    depthFirstTraversalByRecursion(root->left);
    depthFirstTraversalByRecursion(root->right);
}


int main (){

    Node* root = new Node(20);
    root->right = new Node(44);
    root->left = new Node(10);
    root->right->right = new Node(55);
    root->right->left = new Node(40);
    root->left->right = new Node(15);
    root->left->left = new Node(7);

//         20
//       /    \
//     10     44
//    /  \   /  \
//   7   15 40  55
    
    cout << "depth first traversal method using recursion starts" << endl;
    depthFirstTraversalByRecursion(root);
    cout << "depth first traversal method using recursion ends" << endl;
    depthFirstTraversal(root);
    breadthFirstTraversal(root);
}

