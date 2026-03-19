# wang4

一个使用 C++ 实现的二叉搜索树（Binary Search Tree）项目，演示了 BST 的基本操作，包括插入、查找、删除和遍历。

## 项目结构

```
wang4/
├── binary_tree.h    # 二叉搜索树头文件（类声明）
├── binary_tree.cpp  # 二叉搜索树实现
├── main.cpp         # 演示程序入口
├── .gitignore       # Git 忽略规则
└── README.md        # 项目说明文档
```

## 构建与运行

```bash
g++ -std=c++17 -o bst main.cpp binary_tree.cpp
./bst
```

## GitHub Copilot 在本项目中的使用

本项目利用 GitHub Copilot 的多种能力来辅助开发。以下介绍 Copilot 的主要使用方式以及它是如何与项目联系起来的。

### 1. Copilot 代码补全（IDE 内）

在 VS Code 或其他支持 Copilot 的编辑器中编写代码时，Copilot 会根据上下文自动提供代码建议。例如：

- **编写函数实现**：在 `binary_tree.cpp` 中输入函数签名后，Copilot 可以根据头文件中的声明和注释自动补全递归实现（如 `insert_`、`search_`、`remove_` 等）。
- **编写注释和文档**：Copilot 能根据函数逻辑自动生成中文注释，与项目风格保持一致。
- **编写测试代码**：在 `main.cpp` 中编写测试用例时，Copilot 可以根据已有的测试模式自动补全类似的测试场景。

### 2. Copilot Chat（对话式辅助）

通过 Copilot Chat，可以直接向 Copilot 提问关于代码的问题：

- 解释代码逻辑（如 BST 的删除算法是如何工作的）
- 查找潜在的 bug 或性能问题
- 请求代码重构建议
- 生成新的功能代码（如新增一个层序遍历方法）

### 3. Copilot Coding Agent（自动化编码代理）

这是 Copilot 与本项目最紧密的联系方式。Copilot Coding Agent 可以被分配 GitHub Issue，然后自主完成以下工作：

- **理解 Issue 需求**：Agent 会阅读 Issue 描述，理解要实现的功能或要修复的问题。
- **探索代码库**：Agent 会浏览项目文件，了解现有代码结构、编码风格和约定。
- **自动编写代码**：根据需求在正确的文件中添加或修改代码。
- **创建 Pull Request**：Agent 会自动创建 PR 分支、提交代码、并更新 PR 描述来展示进度。
- **响应 Code Review**：当 PR 收到审查反馈时，Agent 可以根据反馈自动修改代码。

#### 工作流程

```
GitHub Issue → Copilot Coding Agent 接收任务
    → 探索代码库、理解上下文
    → 制定计划并创建 PR
    → 编写代码、运行测试
    → 提交更改、更新 PR
    → 响应审查反馈、迭代修改
```

#### 本项目的实际案例

本项目的二叉搜索树实现（PR #1）就是通过 Copilot Coding Agent 完成的。Agent：
1. 阅读了 Issue 中对 BST 功能的需求描述
2. 创建了 `binary_tree.h`（类声明）和 `binary_tree.cpp`（实现）
3. 编写了 `main.cpp` 演示程序，覆盖了插入、查找、删除、遍历等全部功能
4. 配置了 `.gitignore` 忽略编译产物

### 4. Copilot 代码审查（Pull Request Review）

在 Pull Request 中，可以请求 Copilot 进行代码审查：

- 自动检查代码质量和潜在问题
- 提供改进建议（如内存管理、边界条件处理）
- 评估代码风格是否与项目一致

### 总结

| Copilot 功能 | 使用场景 | 与项目的联系 |
|---|---|---|
| 代码补全 | 编写 C++ 代码时自动建议 | 加速 BST 算法实现 |
| Copilot Chat | 代码问答和调试 | 理解和改进 BST 逻辑 |
| Coding Agent | 自动化完成 Issue | 自主实现新功能和修复 |
| PR 代码审查 | Pull Request 审查 | 保证代码质量 |