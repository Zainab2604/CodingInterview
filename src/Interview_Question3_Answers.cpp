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
