//
// Created by Zainab Mohamed Basheer on 18.08.24.
//

#include <Interview_Question3_Answers.cpp>
#include <gtest/gtest.h>

// Test 1: Symmetrischer Baum
TEST(SymmetricTreeTest, SymmetricTree) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    EXPECT_TRUE(is_symmetric(root));
}

// Test 2: Nicht symmetrischer Baum
TEST(SymmetricTreeTest, AsymmetricTree) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5); // Unterschied hier

    EXPECT_FALSE(is_symmetric(root));
}

// Test 3: Symmetrischer Baum mit einem Knoten
TEST(SymmetricTreeTest, SingleNodeTree) {
    TreeNode* singleNodeRoot = new TreeNode(1);
    EXPECT_TRUE(is_symmetric(singleNodeRoot));
}

// Test 4: Leerer Baum
TEST(SymmetricTreeTest, EmptyTree) {
    TreeNode* emptyRoot = nullptr;
    EXPECT_TRUE(is_symmetric(emptyRoot));
}


