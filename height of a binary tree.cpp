/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
int height(Node* root) {
    // Write your code here.
    if(root->left==0 && root->right==0){
        return 0;
    }
    if(root->left==0){
        return height(root->right)+1;
    }
    if(root->right==0){
        return height(root->left)+1;
    }
    return max(height(root->left), height(root->right))+1;
}
