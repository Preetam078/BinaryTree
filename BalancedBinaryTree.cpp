#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

bool BalancedTree(Node* node, int* height){

    if(node == NULL){
        return true;
    }

    int lh = 0, rh = 0;
    if(BalancedTree(node->left, &lh) == false){
      return false;
    }
     if(BalancedTree(node->right, &rh) == false){
      return false;
    }

    *height = max(rh, lh) + 1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else
      return false;
 return false;

}

int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    int height = 0;

    if(BalancedTree(root, &height) == true){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"unbalanced"<<endl;
    }

    return 0;
}