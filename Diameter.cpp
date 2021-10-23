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

int calDiameter(Node*node, int* height){
    if(node == NULL){
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ld = calDiameter(node->left, &lh);
    int rd = calDiameter(node->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;


    return max(currDiameter, max(ld,rd));

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

    cout<<calDiameter(root, &height)<<endl;

    return 0;
}