#include <Interview_Question_1_Answers.cpp>
#include "gtest/gtest.h"

// Test 1: Standardbaum
TEST(LevelOrderTraversalTest, StandardTree) {
TreeNode* root = new TreeNode(3);
root->left = new TreeNode(9);
root->right = new TreeNode(20);
root->right->left = new TreeNode(15);
root->right->right = new TreeNode(7);

std::vector<std::vector<int>> expected = {
        {3},
        {9, 20},
        {15, 7}
};

EXPECT_EQ(level_order_traversal(root), expected);
}

// Test 2: Leerer Baum
TEST(LevelOrderTraversalTest, EmptyTree) {
TreeNode* emptyRoot = nullptr;
std::vector<std::vector<int>> expected = {};

EXPECT_EQ(level_order_traversal(emptyRoot), expected);
}

// Test 3: Baum mit nur einem Knoten
TEST(LevelOrderTraversalTest, SingleNodeTree) {
TreeNode* singleNodeRoot = new TreeNode(1);
std::vector<std::vector<int>> expected = {{1}};

EXPECT_EQ(level_order_traversal(singleNodeRoot), expected);
}
