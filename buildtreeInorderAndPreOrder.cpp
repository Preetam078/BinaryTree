#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;

    }
};

int search(int inOrder[], int start, int end, int curr){
    for( int i =start; i<=end; i++){
        if(inOrder[i] == curr){
            return i;
        }
    }
    return -1;
}

Node* buildtree(int preOrder[], int inOrder[], int start, int end){
    static int idx = 0;

    if(start > end){
        return NULL;
    }

    int curr = preOrder[idx];
    idx++;
    Node* node = new Node(curr);

    if(start = end){
        return node;
    }
    int pos = search(inOrder, start, end, curr);
    node->left = buildtree(preOrder, inOrder, start, pos-1);
    node->right = buildtree(preOrder, inOrder, pos+1, end);

    return node;
}


void inorder(Node* node){

    if(node == NULL){
        return;
    }

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}



int main(){

    int preOrder[] = {1,2,4,3,5};
    int inOrder[] = {4,2,1,5,3};

    Node*root = buildtree(preOrder, inOrder,0,4);
    inorder(root);

    return 0;
}