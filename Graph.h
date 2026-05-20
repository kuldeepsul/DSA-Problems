#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <map>
#include <deque>

class Node
{
public:
	int val;
	std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
	
    Node* cloneNode(Node* node, std::unordered_map < int, Node* >& newdata);
    static void islandsAndTreasure(std::vector<std::vector<int>> &grid);
    static int findWater(int i, int j, std::vector<std::vector<int>>& grid, std::map<std::pair<int, int>, int>& curmap);
    static void modifydistance(int i, int j, std::vector<std::vector<int>>& grid, int curdistance);
    static void bfs(std::vector<std::vector<int>>& grid, std::map <std::pair<int, int>, int>& mapped, std::deque<std::pair<int, int>>& layer, int dist, int size);
    static int orangesRotting(std::vector<std::vector<int>>& grid);
    static void bfs2(std::vector<std::vector<int>>& grid, std::map <std::pair<int, int>, int>& mapped, std::deque<std::pair<int, int>>& layer, int& dist, int size);

    static void bfsocean(std::deque<std::pair<int, int>>& q, std::map<std::pair<int, int>, int>& mapped, std::vector<std::vector<int>>& hgrid);
    static std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights);
    static bool checkloop(int curpos, std::unordered_map<int, std::deque<int>>& mapped, std::unordered_map<int, int>& curpath);
    static bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);

    static bool checkloop2(int curpos, std::unordered_map<int, std::deque <int>>& mapped, std::unordered_map<int, int>& curpath, std::vector <int>& path, std::unordered_set <int>& old);
    static std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites);

    static bool bfsvaltree(int prev,int cur, std::deque <int>& curpath, std::unordered_set <int>& visited, std::unordered_map <int, std::deque<int>>& childmap);
    static bool validTree(int n, std::vector<std::vector<int>>& edges);

    static void dfsmapisland(int prev, int cur, std::unordered_set <int>& visited, std::unordered_map <int, std::deque<int>>& childmap);
    static int countComponents(int n, std::vector<std::vector<int>>& edges);

    static bool dfsredcon(int prev, int cur, std::unordered_set <int>& curpath, std::unordered_set <int>& visited, std::unordered_map <int, std::deque<int>>& childmap);
    static std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges);

    static bool dfsreplace(int i, int j, std::map<std::pair<int, int>, int>& visited, std::vector<std::vector<char>>& board,bool& isSorrounded, std::vector<std::pair<int, int>>& curisland);
    static void solve(std::vector<std::vector<char>>& board);
};