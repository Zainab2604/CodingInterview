#include <iostream>
#include <vector>
#include <queue>
//#include "googletest/googletest/include/gtest/gtest.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> level_order_traversal(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) {
        return result;
    }

    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        int levelSize = queue.size();
        std::vector<int> currentLevel;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = queue.front();
            queue.pop();
            currentLevel.push_back(node->val);

            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
        }

        result.push_back(currentLevel);
    }

    return result;
}

/*int main() {
    // Beispielbaum erstellen
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Level-Order Traversal ausführen
    std::vector<std::vector<int>> traversal = level_order_traversal(root);

    // Ergebnis ausgeben
    std::cout << "Level-Order Traversal:" << std::endl;
    for (const auto& level : traversal) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}*/


// pseudo code

//FUNCTION level_order_traversal(root):
//  IF root IS NULL:
//  RETURN []
//
//queue = new Queue()
//queue.enqueue(root)
//result = []
//
//WHILE NOT queue.isEmpty():
//        levelSize = queue.size()
//        currentLevel = []
//
//      FOR i FROM 0 TO levelSize - 1:
//          node = queue.dequeue()
//          currentLevel.append(node.val)
//
//      IF node.left IS NOT NULL:
//          queue.enqueue(node.left)
//      IF node.right IS NOT NULL:
//          queue.enqueue(node.right)
//
//      result.append(currentLevel)
//
//RETURN result


