#include <iostream>
#include <vector>
#include "binary_tree.h"

// 打印分隔线
static void printLine(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    BinaryTree bst;

    // ── 插入 ──────────────────────────────────
    printLine("插入节点");
    std::vector<int> values = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    for (int v : values) {
        bst.insert(v);
        std::cout << "插入: " << v << "\n";
    }
    std::cout << "节点总数: " << bst.size() << "\n";
    std::cout << "树的高度: " << bst.height() << "\n";

    // ── 遍历 ──────────────────────────────────
    printLine("中序遍历（升序）");
    bst.inorder([](int v) { std::cout << v << " "; });
    std::cout << "\n";

    printLine("前序遍历");
    bst.preorder([](int v) { std::cout << v << " "; });
    std::cout << "\n";

    printLine("后序遍历");
    bst.postorder([](int v) { std::cout << v << " "; });
    std::cout << "\n";

    // ── 查找 ──────────────────────────────────
    printLine("查找节点");
    for (int target : {40, 99}) {
        TreeNode* found = bst.search(target);
        std::cout << "查找 " << target << ": "
                  << (found ? "找到" : "未找到") << "\n";
    }

    // ── 删除 ──────────────────────────────────
    printLine("删除节点");

    // 删除叶节点
    std::cout << "删除叶节点 10\n";
    bst.remove(10);

    // 删除叶节点 25（20 的右孩子，无子节点）
    std::cout << "删除叶节点 25\n";
    bst.remove(25);

    // 删除有两个子节点的节点
    std::cout << "删除双子节点 30\n";
    bst.remove(30);

    std::cout << "删除后节点总数: " << bst.size() << "\n";
    std::cout << "删除后中序遍历: ";
    bst.inorder([](int v) { std::cout << v << " "; });
    std::cout << "\n";

    // ── 重复值插入 ─────────────────────────────
    printLine("重复值插入测试");
    int before = bst.size();
    bst.insert(50);  // 已存在，不应增加节点数
    std::cout << "再次插入 50 前节点数: " << before
              << "，插入后节点数: " << bst.size() << "\n";

    // ── 空树 ───────────────────────────────────
    printLine("空树测试");
    BinaryTree empty;
    std::cout << "空树 empty(): " << (empty.empty() ? "true" : "false") << "\n";
    std::cout << "空树 height(): " << empty.height() << "\n";
    std::cout << "空树 size():   " << empty.size() << "\n";
    std::cout << "空树 search(1): " << (empty.search(1) ? "找到" : "未找到") << "\n";

    return 0;
}
