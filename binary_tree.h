#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <functional>

// 二叉搜索树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 二叉搜索树 (Binary Search Tree)
class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    // 插入节点
    void insert(int val);

    // 查找节点，找到返回指向该节点的指针，否则返回 nullptr
    TreeNode* search(int val) const;

    // 删除节点
    void remove(int val);

    // 中序遍历（左-根-右），结果为升序序列
    void inorder(std::function<void(int)> visit) const;

    // 前序遍历（根-左-右）
    void preorder(std::function<void(int)> visit) const;

    // 后序遍历（左-右-根）
    void postorder(std::function<void(int)> visit) const;

    // 树的高度；空树返回 0
    int height() const;

    // 节点总数
    int size() const;

    // 判断树是否为空
    bool empty() const;

private:
    TreeNode* root_;

    // 递归辅助函数
    TreeNode* insert_(TreeNode* node, int val);
    TreeNode* search_(TreeNode* node, int val) const;
    TreeNode* remove_(TreeNode* node, int val);
    TreeNode* minNode_(TreeNode* node) const;
    void destroy_(TreeNode* node);
    void inorder_(TreeNode* node, std::function<void(int)>& visit) const;
    void preorder_(TreeNode* node, std::function<void(int)>& visit) const;
    void postorder_(TreeNode* node, std::function<void(int)>& visit) const;
    int height_(TreeNode* node) const;
    int size_(TreeNode* node) const;
};

#endif // BINARY_TREE_H
