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



Node* LCA(Node* node, int n1, int n2){

    if(node == NULL){
        return NULL;
    }

    if(node->data == n1 || node->data == n2){
        return node;
    }

    Node* left = LCA(node->left, n1, n2);
    Node* right = LCA(node->right, n1,n2);


    if(left!= NULL && right!= NULL){
        return node;
    }

    if(left == NULL && right == NULL) {
        return NULL;
    }

    if(left != NULL){
        return left;
    }
    return right;
}

int findDist(Node* node, int k, int dist){
    if(node == NULL){
        return -1;
    }
    if(node->data == k){
        return dist;
    }

    int left = findDist(node->left, k, dist+1);
    if(left != -1){
        return left;
    }
    return findDist(node->right, k, dist+1);
}


int distancebtwNode(Node* node, int n1 , int n2){
    Node* lca  = LCA(node, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1+d2;
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);


    cout<<distancebtwNode(root, 40, 10)<<endl;

    return 0;
}