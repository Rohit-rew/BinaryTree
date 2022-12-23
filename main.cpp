# include <iostream>

using namespace std;

class Node {
public :
    int data;
    Node* right;
    Node* left;
};

class BinaryTree {
    Node* root;

    void add(int val){
        Node* newNode = new Node();
        newNode->data = val;

        if(root == NULL){
            root = newNode;
        }else{

            if(val>root->data){
                Node* currentNode = root;
                while(currentNode->right->data){

                }
                root->right = newNode;
            }else{
                root->left = newNode;
            }
        }
    }

};

void main (){

}