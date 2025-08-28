# 🤝 Contributing to Maze Generation

Thank you for your interest in contributing to the **Maze Generation** project! We welcome contributions from developers of all skill levels. This guide will help you get started.

---

## 📋 Table of Contents

- [🎯 Ways to Contribute](#-ways-to-contribute)
- [🚀 Getting Started](#-getting-started)
- [💻 Development Setup](#-development-setup)
- [📝 Code Style Guidelines](#-code-style-guidelines)
- [🧪 Testing Guidelines](#-testing-guidelines)
- [🐛 Bug Reports](#-bug-reports)
- [✨ Feature Requests](#-feature-requests)
- [📖 Documentation Updates](#-documentation-updates)
- [🔄 Pull Request Process](#-pull-request-process)
- [👥 Community Guidelines](#-community-guidelines)

---

## 🎯 Ways to Contribute

### 🐛 Bug Fixes
- Fix compilation issues
- Resolve algorithm bugs
- Improve memory management
- Enhance error handling

### ✨ New Features
- Additional maze generation algorithms (Kruskal's, Prim's, etc.)
- Different pathfinding methods (A*, Dijkstra's)
- Enhanced visualization options
- Performance optimizations

### 📚 Documentation
- Improve README clarity
- Add code comments
- Create tutorials or examples
- Update API documentation

### 🧪 Testing
- Add unit tests
- Create integration tests
- Performance benchmarking
- Cross-platform testing

---

## 🚀 Getting Started

### 1️⃣ Fork the Repository

1. Visit the [Maze Generation repository](https://github.com/H0NEYP0T-466/Maze_Generation)
2. Click the **"Fork"** button in the top-right corner
3. Clone your fork locally:

```bash
git clone https://github.com/YOUR-USERNAME/Maze_Generation.git
cd Maze_Generation
```

### 2️⃣ Set Up Remote

```bash
git remote add upstream https://github.com/H0NEYP0T-466/Maze_Generation.git
git remote -v  # Verify the remotes are set correctly
```

### 3️⃣ Stay Updated

```bash
git fetch upstream
git checkout main
git merge upstream/main
```

---

## 💻 Development Setup

### 🔧 Prerequisites

- **C++ Compiler**: GCC 7.0+ or Clang 5.0+ with C++17 support
- **Git**: Latest version
- **Text Editor/IDE**: VS Code, CLion, Vim, or your preferred editor

### 🛠️ Build Instructions

```bash
# Compile the project
g++ -std=c++17 -Wall -Wextra -O2 -o maze_generator maze_generator.cpp

# Run the executable
./maze_generator
```

### 🧹 Clean Build

```bash
# Remove compiled binaries
rm -f maze_generator *.o *.exe
```

---

## 📝 Code Style Guidelines

### 🎨 C++ Style Standards

**Naming Conventions:**
```cpp
// Classes: PascalCase
class MazeGenerator {};

// Functions and variables: camelCase
void generateMaze();
int mazeWidth;

// Constants: UPPER_SNAKE_CASE
const int MAX_SIZE = 100;

// Private members: camelCase with trailing underscore (optional)
private:
    int width_;
    int height_;
```

**Code Formatting:**
```cpp
// Use 4 spaces for indentation
if (condition) {
    doSomething();
} else {
    doSomethingElse();
}

// Braces on same line for functions and classes
class Maze {
public:
    void generate() {
        // Implementation
    }
};
```

**Comments:**
```cpp
// Use clear, descriptive comments
/**
 * Generates a maze using Depth-First Search algorithm
 * @param startX Starting X coordinate
 * @param startY Starting Y coordinate
 */
void dfsGenerate(int startX, int startY);

// Inline comments for complex logic
maze[x][y].visited = true;  // Mark current cell as visited
```

### 🔍 Code Quality

- **Keep functions small** (ideally < 50 lines)
- **Use meaningful variable names**
- **Avoid magic numbers** - use named constants
- **Handle edge cases** and error conditions
- **Follow RAII principles** for resource management

---

## 🧪 Testing Guidelines

### ✅ Manual Testing

Before submitting changes, ensure:

1. **Compilation Success**:
   ```bash
   g++ -std=c++17 -Wall -Wextra -Werror -o maze_generator maze_generator.cpp
   ```

2. **Basic Functionality**:
   ```bash
   ./maze_generator  # Should generate and solve a maze without errors
   ```

3. **Memory Safety**:
   ```bash
   # If valgrind is available
   valgrind --leak-check=full ./maze_generator
   ```

### 🧪 Test Cases to Verify

- **Small mazes** (2x2, 3x3)
- **Large mazes** (50x50, 100x100)
- **Edge cases** (1x1 maze)
- **Different start/exit positions**
- **Algorithm correctness** (path validity)

### 📊 Performance Testing

```bash
# Time the execution
time ./maze_generator

# For larger mazes, modify the main function temporarily
# Test with different dimensions and measure performance
```

---

## 🐛 Bug Reports

When reporting bugs, please include:

### 📝 Bug Report Template

```markdown
## 🐛 Bug Description
A clear description of what the bug is.

## 🔄 Steps to Reproduce
1. Compile with: `g++ -std=c++17 -o maze_generator maze_generator.cpp`
2. Run: `./maze_generator`
3. Observe: [Describe the issue]

## ✅ Expected Behavior
What you expected to happen.

## ❌ Actual Behavior  
What actually happened.

## 💻 Environment
- OS: [Ubuntu 20.04, Windows 10, macOS Big Sur]
- Compiler: [GCC 9.4.0, Clang 12.0.0]
- C++ Standard: [C++17]

## 📋 Additional Context
Any other relevant information, screenshots, or code snippets.
```

### 🏷️ Bug Labels
- `bug` - Something isn't working
- `critical` - Blocks core functionality
- `documentation` - Relates to docs
- `performance` - Performance issues

---

## ✨ Feature Requests

### 💡 Feature Request Template

```markdown
## ✨ Feature Summary
Brief description of the feature.

## 🎯 Problem Statement
What problem does this solve?

## 💭 Proposed Solution
Describe your ideal solution.

## 🔄 Alternative Solutions
Any alternative approaches considered.

## 📊 Impact Assessment
- Performance implications
- Complexity increase
- Breaking changes
```

### 🎨 Feature Categories
- **Algorithms**: New generation or solving methods
- **Visualization**: Display improvements
- **Performance**: Speed or memory optimizations
- **Usability**: User experience enhancements

---

## 📖 Documentation Updates

### 📚 Documentation Standards

- **Use clear, simple language**
- **Include code examples** where appropriate
- **Keep examples up-to-date** with current code
- **Use proper Markdown formatting**
- **Add emojis** for visual appeal (but don't overuse)

### 📝 Areas Needing Documentation

- Algorithm explanations
- Code architecture overview
- Build and deployment guides
- API reference documentation
- Performance characteristics

---

## 🔄 Pull Request Process

### 1️⃣ Create a Branch

```bash
git checkout -b feature/amazing-new-feature
# or
git checkout -b bugfix/fix-pathfinding-issue
```

### 2️⃣ Make Changes

- Follow the code style guidelines
- Test your changes thoroughly
- Update documentation if needed
- Add comments for complex logic

### 3️⃣ Commit Changes

```bash
git add .
git commit -m "feat: add Kruskal's maze generation algorithm

- Implement randomized Kruskal's algorithm
- Add union-find data structure  
- Update documentation with new algorithm option
- Include performance benchmarks"
```

**Commit Message Format:**
```
type(scope): description

[optional body]

[optional footer]
```

**Types:**
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting, etc.)
- `refactor`: Code refactoring
- `test`: Adding or updating tests
- `perf`: Performance improvements

### 4️⃣ Push and Create PR

```bash
git push origin feature/amazing-new-feature
```

Then create a Pull Request with:

- **Clear title** describing the change
- **Detailed description** of what was changed and why
- **Link to related issues** (if applicable)
- **Screenshots/examples** (if applicable)

### 5️⃣ PR Review Process

1. **Automated checks** will run (if configured)
2. **Code review** by maintainers
3. **Address feedback** and push updates
4. **Final approval** and merge

---

## 👥 Community Guidelines

### 🤝 Code of Conduct

- **Be respectful** and inclusive
- **Welcome newcomers** and help them learn
- **Provide constructive feedback**
- **Focus on the code**, not the person
- **Be patient** with questions and reviews

### 💬 Communication

- **GitHub Issues**: For bugs and feature requests
- **Pull Requests**: For code discussions
- **Discussions**: For general questions and ideas

### 🎯 Best Practices

- **Search existing issues** before creating new ones
- **One issue per problem** - don't mix multiple topics
- **Provide context** and examples
- **Follow up** on your contributions
- **Help review others' PRs**

---

## 🏆 Recognition

Contributors will be:
- **Listed in the README** acknowledgements section
- **Tagged in release notes** for significant contributions
- **Invited as collaborators** for consistent, quality contributions

---

## ❓ Questions?

If you have questions about contributing:

1. **Check existing documentation** and issues first
2. **Search closed issues** for similar questions  
3. **Create a new issue** with the `question` label
4. **Be specific** about what you need help with

---

**Thank you for contributing to Maze Generation! 🎉**

Your contributions help make this project better for everyone. We appreciate your time and effort in improving the codebase, documentation, and community.

---

<div align="center">

**Happy Coding! 🚀**

Made with ❤️ by the Maze Generation community

</div>