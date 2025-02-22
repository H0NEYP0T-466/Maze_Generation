#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include <queue>
#include <tuple>

struct Cell {
    bool visited = false;
    bool top_wall = true;
    bool bottom_wall = true;
    bool left_wall = true;
    bool right_wall = true;
};

class Maze {
public:
    Maze(int width, int height)
        : width(width), height(height), maze(width, std::vector<Cell>(height)) {
        std::srand(std::time(nullptr));
    }

    void generate(int startX, int startY) {
        dfsGenerate(startX, startY); // Generate the maze using DFS
    }

    void setStartAndExit() {
        startX = 0;
        startY = 0;
        exitX = width - 1;
        exitY = height - 1;

        maze[startX][startY].left_wall = false;  // Open the left wall of the start
        maze[exitX][exitY].right_wall = false;  // Open the right wall of the exit
    }

    void display(const std::vector<std::tuple<int, int>>& path = {}) const {
        for (int y = 0; y < height; y++) {
            // Print the top walls
            for (int x = 0; x < width; x++) {
                std::cout << (maze[x][y].top_wall ? "+---" : "+   ");
            }
            std::cout << "+" << std::endl;

            // Print the left walls and cells
            for (int x = 0; x < width; x++) {
                bool isPath = std::find(path.begin(), path.end(), std::make_tuple(x, y)) != path.end();
                if (x == startX && y == startY) {
                    std::cout << "| S ";  // Start point
                } else if (x == exitX && y == exitY) {
                    std::cout << "( E ";  // Exit point
                } else if (isPath) {
                    std::cout << (maze[x][y].left_wall ? "|  *" : "   *");
                } else {
                    std::cout << (maze[x][y].left_wall ? "|   " : "    ");
                }
            }
            std::cout << "|" << std::endl;
        }

        // Print the bottom walls
        for (int x = 0; x < width; x++) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
    }

    std::vector<std::tuple<int, int>> bfsSolve() {
        std::vector<std::vector<bool>> visited(width, std::vector<bool>(height, false));
        std::queue<std::tuple<int, int>> q;
        std::vector<std::vector<std::tuple<int, int>>> parent(width, std::vector<std::tuple<int, int>>(height, {-1, -1}));

        q.push({startX, startY});
        visited[startX][startY] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == exitX && y == exitY) {
                return constructPath(parent);
            }

            // Check all four directions
            std::vector<std::tuple<int, int, char>> directions = {
                {0, -1, 'T'}, {0, 1, 'B'}, {-1, 0, 'L'}, {1, 0, 'R'}
            };
            for (auto& [dx, dy, wall] : directions) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && nx < width && ny >= 0 && ny < height && !visited[nx][ny]) {
                    if ((wall == 'L' && !maze[x][y].left_wall) ||
                        (wall == 'R' && !maze[x][y].right_wall) ||
                        (wall == 'T' && !maze[x][y].top_wall) ||
                        (wall == 'B' && !maze[x][y].bottom_wall)) {
                        visited[nx][ny] = true;
                        parent[nx][ny] = {x, y};
                        q.push({nx, ny});
                    }
                }
            }
        }

        return {};  // Return empty path if no solution exists
    }

private:
    int width, height;
    int startX, startY, exitX, exitY;
    std::vector<std::vector<Cell>> maze;

    void dfsGenerate(int x, int y) {
        maze[x][y].visited = true;

        std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(directions.begin(), directions.end(), g);

        for (auto& [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;

            if (nx >= 0 && nx < width && ny >= 0 && ny < height && !maze[nx][ny].visited) {
                if (dx == -1) {
                    maze[x][y].left_wall = false;
                    maze[nx][ny].right_wall = false;
                } else if (dx == 1) {
                    maze[x][y].right_wall = false;
                    maze[nx][ny].left_wall = false;
                } else if (dy == -1) {
                    maze[x][y].top_wall = false;
                    maze[nx][ny].bottom_wall = false;
                } else if (dy == 1) {
                    maze[x][y].bottom_wall = false;
                    maze[nx][ny].top_wall = false;
                }

                dfsGenerate(nx, ny);
            }
        }
    }

    std::vector<std::tuple<int, int>> constructPath(const std::vector<std::vector<std::tuple<int, int>>>& parent) {
        std::vector<std::tuple<int, int>> path;
        int x = exitX, y = exitY;

        while (x != startX || y != startY) {
            path.push_back({x, y});
            auto [px, py] = parent[x][y];
            x = px;
            y = py;
        }
        path.push_back({startX, startY});
        std::reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    int width = 5;
    int height = 5;
    Maze maze(width, height);
    maze.generate(0, 0);  // Generate the maze using DFS
    maze.setStartAndExit();  // Set start at (0, 0) and exit at (width-1, height-1)

    std::cout << "Generated Maze:\n";
    maze.display();

    std::cout << "\nSolving with BFS:\n";
    auto path = maze.bfsSolve();  // Solve using BFS

    if (!path.empty()) {
        maze.display(path);  // Display the maze with the solution path
    } else {
        std::cout << "No path found using BFS." << std::endl;
    }

    return 0;
}
