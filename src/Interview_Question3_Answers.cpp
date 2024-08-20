#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool check_symmetry(TreeNode* left, TreeNode* right) {
    if (!left && !right) {
        return true;
    }
    if (!left || !right) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    }
    return check_symmetry(left->left, right->right) && check_symmetry(left->right, right->left);
}

bool is_symmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    return check_symmetry(root->left, root->right);
}

/*int main() {
    // Beispielbaum erstellen
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    //root->right->right->left = new TreeNode(3);

    // Symmetrie überprüfen
    bool symmetric = is_symmetric(root);

    // Ergebnis ausgeben
    if (symmetric) {
        std::cout << "Der Baum ist symmetrisch." << std::endl;
    } else {
        std::cout << "Der Baum ist nicht symmetrisch." << std::endl;
    }

    return 0;
}*/

// pseudo code

//FUNCTION is_symmetric(root):
//  IF root IS NULL:
//  RETURN TRUE
//
//  RETURN check_symmetry(root.left, root.right)
//
//FUNCTION check_symmetry(left, right):
//  IF left IS NULL AND right IS NULL:
//      RETURN TRUE
//  IF left IS NULL OR right IS NULL:
//      RETURN FALSE
//  IF left.val != right.val:
//      RETURN FALSE
//
//RETURN check_symmetry(left.left, right.right) AND check_symmetry(left.right, right.left)
