#include "Graph.h"

Node* Node::cloneNode(Node* node,std::unordered_map < int, Node* > &newdata)
{ 
	Node* newnode = new Node(node->val);
	newdata[newnode->val] = newnode;

	if (!node->neighbors.size())
	{
		return newnode;
	}
	else
	{
		std::vector <Node*> newNeighbors;
		for (int i = 0; i < node->neighbors.size(); i++)
		{
			auto it = newdata.find(node->neighbors[i]->val);
			if (it == newdata.end())
			{
				newNeighbors.push_back(cloneNode(node->neighbors[i],newdata));
			}
			else
			{
				newNeighbors.push_back(newdata[node->neighbors[i]->val]);
			}
		}
		newnode->neighbors = newNeighbors;
		return newnode;
	}
};


int Node::findWater(int i, int j,std::vector<std::vector<int>> &grid,std::map<std::pair<int,int>,int> &curmap)
{
	curmap[{i, j}]++;
	int left = INT_MAX;
	int right = INT_MAX;
	int up = INT_MAX;
	int down = INT_MAX;

	if (i - 1 >= 0)
	{
		if (grid[i - 1][j] == 0)
		{
			grid[i][j] = 1;
			return grid[i][j];
		}
		else if (grid[i - 1][j] > 0)
		{
			auto it = curmap.find({i-1,j});
			if (it == curmap.end())
			{
				up = findWater(i - 1, j, grid, curmap);
			}
			else
			{
				up = grid[i - 1][j];
			}

		}
	}
	if (i + 1 < grid.size())
	{
		if (grid[i + 1][j] == 0)
		{
			grid[i][j] = 1;
			return grid[i][j];
		}
		else if (grid[i + 1][j] > 0 )
		{
			auto it = curmap.find({ i + 1,j });
			if (it == curmap.end())
			{
				down = findWater(i + 1, j, grid, curmap);
			}
			else
			{
				down = grid[i + 1][j];
			}
		}
	}
	if (j - 1 >= 0)
	{
		if (grid[i][j - 1] == 0)
		{
			grid[i][j] = 1;
			return grid[i][j];
		}
		else if (grid[i][j - 1] > 0)
		{
			auto it = curmap.find({ i ,j - 1 });
			if (it == curmap.end())
			{
				left = findWater(i , j - 1, grid, curmap);
			}
			else
			{
				left = grid[i][j - 1];
			}
		}
	}
	if (j + 1 < grid[0].size())
	{
		if (grid[i][j + 1] == 0)
		{
			grid[i][j] = 1;
			return grid[i][j];
		}
		else if (grid[i][j + 1] > 0 )
		{
			auto it = curmap.find({ i ,j + 1 });
			if (it == curmap.end())
			{
				right = findWater(i, j + 1, grid, curmap);
			}
			else
			{
				right = grid[i][j + 1];
			}
		}
	}

	grid[i][j] =  1 + std::min(std::min(left, right), std::min(up, down));

	return grid[i][j];
}

void Node::bfs(std::vector<std::vector<int>> &grid ,std::map <std::pair<int, int>, int> &mapped, std::deque<std::pair<int, int>> &layer, int dist, int size)
{
	while (layer.size())
	{
		for (int i = 0; i < size; i++)
		{
			int x = layer[i].first;
			int y = layer[i].second;

			if (x - 1 >= 0)
			{
				auto it = mapped.find({ x - 1, y });
				if (grid[x - 1][y] == INT_MAX && it == mapped.end())
				{
					grid[x - 1][y] = dist;
					mapped[{x - 1, y}]++;
					layer.push_back({ x - 1,y });
				}
			}
			if (x + 1 < grid.size())
			{
				auto it = mapped.find({ x + 1, y });
				if (grid[x + 1][y] == INT_MAX && it == mapped.end())
				{
					grid[x + 1][y] = dist;
					mapped[{x + 1, y}]++;
					layer.push_back({ x + 1,y });
				}
			}
			if (y - 1 >= 0)
			{
				auto it = mapped.find({ x , y - 1 });
				if (grid[x][y - 1] == INT_MAX && it == mapped.end())
				{
					grid[x][y - 1] = dist;
					mapped[{x, y - 1 }]++;
					layer.push_back({ x ,y - 1 });
				}
			}
			if (y + 1 < grid[0].size())
			{
				auto it = mapped.find({ x , y + 1 });
				if (grid[x][y + 1] == INT_MAX && it == mapped.end())
				{
					grid[x][y + 1] = dist;
					mapped[{x, y + 1 }]++;
					layer.push_back({ x ,y + 1 });
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			layer.pop_front();
		}
		dist++;
		size = layer.size();
		bfs(grid, mapped, layer, dist, size);
	}
	
}

void Node::islandsAndTreasure(std::vector<std::vector<int>>& grid)
{
	std::map <std::pair<int, int>, int> mapped;
	std::deque<std::pair<int, int>> layer;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] == 0)
			{
				// Water is found.
				layer.push_back({ i,j });
			}
		}
	}
	int size = layer.size();
	int dist = 1;
	bfs(grid, mapped, layer, dist, size);

}
void Node::bfs2(std::vector<std::vector<int>>& grid, std::map <std::pair<int, int>, int>& mapped, std::deque<std::pair<int, int>>& layer, int& dist, int size)
{
	while (layer.size())
	{
		for (int i = 0; i < size; i++)
		{
			int x = layer[i].first;
			int y = layer[i].second;

			if (x - 1 >= 0)
			{
				auto it = mapped.find({ x - 1, y });
				if (grid[x - 1][y] == 1 && it != mapped.end())
				{
					//grid[x - 1][y] = dist;
					mapped.erase({x-1,y});
					layer.push_back({ x - 1,y });
				}
			}
			if (x + 1 < grid.size())
			{
				auto it = mapped.find({ x + 1, y });
				if (grid[x + 1][y] == 1 && it != mapped.end())
				{
					//grid[x + 1][y] = dist;
					mapped.erase({ x + 1,y });
					layer.push_back({ x + 1,y });
				}
			}
			if (y - 1 >= 0)
			{
				auto it = mapped.find({ x , y - 1 });
				if (grid[x][y - 1] == 1 && it != mapped.end())
				{
					//grid[x][y - 1] = dist;
					mapped.erase({ x ,y - 1 });
					layer.push_back({ x ,y - 1 });
				}
			}
			if (y + 1 < grid[0].size())
			{
				auto it = mapped.find({ x , y + 1 });
				if (grid[x][y + 1] == 1 && it != mapped.end())
				{
					//grid[x][y + 1] = dist;
					mapped.erase({ x ,y + 1 });
					layer.push_back({ x ,y + 1 });
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			layer.pop_front();
		}
		dist++;
		size = layer.size();
		bfs2(grid, mapped, layer, dist, size);
	}

}

int Node::orangesRotting(std::vector<std::vector<int>>& grid)
{
	std::map <std::pair<int, int>, int> mapped;
	std::deque<std::pair<int, int>> layer;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] == 2)
			{
				// Water is found.
				layer.push_back({ i,j });
			}
			else if (grid[i][j] == 1)
			{
				mapped[{i, j}]++;
			}
		}
	}
	int size = layer.size();
	int dist = -1;
	bfs2(grid, mapped, layer, dist, size);

	if (mapped.size())
	{
		return -1;
	}
	else
	{
		return dist;
	}
}



void Node::bfsocean(std::deque<std::pair<int,int>> &q , std::map<std::pair<int,int>,int> &mapped,std::vector<std::vector<int>> &hgrid)
{
	while(!q.empty())
	{

		int i = q.front().first;
		int j = q.front().second;

		q.pop_front();

		if (i - 1 >= 0)
		{
			auto it = mapped.find({i-1,j});
			if (it == mapped.end())
			{
				if (hgrid[i - 1][j] > hgrid[i][j])
				{
					q.push_back({i-1,j});
					mapped[{i - 1, j}]++;
				}
			}
		}

		if (i + 1 < hgrid.size())
		{
			auto it = mapped.find({ i + 1,j });
			if (it == mapped.end())
			{
				if (hgrid[i + 1][j] > hgrid[i][j])
				{
					q.push_back({ i + 1,j });
					mapped[{i + 1, j}]++;
				}
			}
		}

		if (j - 1 >= 0)
		{
			auto it = mapped.find({ i ,j - 1 });
			if (it == mapped.end())
			{
				if (hgrid[i][j - 1] > hgrid[i][j])
				{
					q.push_back({ i,j - 1 });
					mapped[{i, j - 1}]++;
				}
			}
		}

		if (j + 1 < hgrid[0].size())
		{
			auto it = mapped.find({ i ,j + 1 });
			if (it == mapped.end())
			{
				if (hgrid[i ][j + 1] > hgrid[i][j])
				{
					q.push_back({ i,j + 1});
					mapped[{i , j + 1}]++;
				}
			}
		}
	}
}

std::vector<std::vector<int>> Node::pacificAtlantic(std::vector<std::vector<int>>& heights)
{
	std::map <std::pair<int, int>, int > mpacific;
	std::map <std::pair<int, int>, int > matlantic;
	std::deque <std::pair<int, int>> qpacific;
	std::deque <std::pair<int, int>> qatlantic;

	for (int i = 0; i < heights.size(); i++)
	{
		for(int j = 0; j < heights[0].size(); j++)
		{
			if (i == 0 || j == 0)
			{
				qpacific.push_back({i,j});
				mpacific[{i, j}]++;
			}
			if (i == heights.size() - 1 || j == heights[0].size() - 1)
			{
				qatlantic.push_back({i,j});
				matlantic[{i, j}]++;
			}
		}
	}

	bfsocean(qpacific, mpacific,heights);
	bfsocean(qatlantic, matlantic,heights);
	std::vector<std::vector<int>> result;
	for (auto it = mpacific.begin(); it != mpacific.end(); it++)
	{
		int x = it->first.first;
		int y = it->first.second;
		auto it2 = matlantic.find({x,y});
		if (it2 != matlantic.end())
		{
			result.push_back({x,y});
		}
	}

	return result;
}

bool Node::checkloop(int curpos, std::unordered_map<int,std::deque <int>>&mapped , std::unordered_map<int,int> &curpath)
{
	auto it = curpath.find(curpos);
	if (it != curpath.end())
	{
		return false;
	}
	else
	{
		
		if (mapped[curpos].size())
		{
			curpath[curpos]++;
			bool preq = false;

			while (mapped[curpos].size())
			{
				preq = checkloop(mapped[curpos][0], mapped, curpath);
				if (preq)
				{
					mapped[curpos].pop_front();
				}
				else
				{
					return false;
				}
			}
			curpath.erase(curpos);
			return true;
			
		}
		else
		{
			return true;
		}
	}
}

bool Node::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
	std::unordered_map <int,std::deque<int>> mapped;
	std::unordered_map <int, int> curpath;
	
	for (int i = 0; i < prerequisites.size(); i++)
	{
		mapped[prerequisites[i][0]].push_back(prerequisites[i][1]);
	}
	bool loopdetected = true;

	for (auto it = mapped.begin(); it != mapped.end(); it++)
	{
		loopdetected = checkloop(it->first, mapped, curpath);

		if (!loopdetected)
		{
			break;
		}
	}

	return loopdetected;
}

bool Node::checkloop2(int curpos, std::unordered_map<int, std::deque <int>>& mapped, std::unordered_map<int, int>& curpath,std::vector <int> &path,std::unordered_set <int> &old)
{
	auto it = curpath.find(curpos);
	if (it != curpath.end())
	{
		return false;
	}
	else
	{

		if (mapped[curpos].size())
		{
			curpath[curpos]++;
			bool preq = false;

			while (mapped[curpos].size())
			{
				preq = checkloop2(mapped[curpos][0], mapped, curpath,path,old);
				if (preq)
				{
					mapped[curpos].pop_front();
				}
				else
				{
					return false;
				}
			}
			curpath.erase(curpos);
			auto it = old.find(curpos);
			if (it == old.end())
			{
				old.insert(curpos);
				path.push_back(curpos);
			}

			return true;

		}
		else
		{
			auto it = old.find(curpos);
			if (it == old.end())
			{
				old.insert(curpos);
				path.push_back(curpos);
			}
			return true;
		}
	}
}

std::vector<int> Node::findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) 
{
	std::unordered_map <int, std::deque<int>> mapped;
	std::unordered_map <int, int> curpath;
	std::unordered_set <int> old;
	std::vector <int> path;
	path.clear();

	for (int k = 0; k < numCourses; k++)
	{
		mapped[k];
	}

	for (int i = 0; i < prerequisites.size(); i++)
	{
		mapped[prerequisites[i][0]].push_back(prerequisites[i][1]);
	}
	bool cancomplete = true;

	for (auto it = mapped.begin(); it != mapped.end(); it++)
	{
		cancomplete = checkloop2(it->first, mapped, curpath, path, old);

		if (!cancomplete)
		{
			path.clear();
			return path;
		}
	}

	return path;
	
}

bool Node::bfsvaltree(int prev,int cur,std::deque <int> &curpath , std::unordered_set <int> &visited , std::unordered_map <int,std::deque<int>> &childmap)
{
	auto it = visited.find(cur);
	if (it != visited.end())
	{
		return false;
	}
	else
	{
		curpath.push_back(cur);
		visited.insert(cur);
	}
	for (int i = 0; i < childmap[cur].size(); ++i)
	{
		if (childmap[cur][i] != prev)
		{
			if (!bfsvaltree(cur, childmap[cur][i], curpath, visited, childmap))
			{
				return false;
			}
		}
	}
	return true;
}

bool Node::validTree(int n, std::vector<std::vector<int>>& edges) 
{
	std::unordered_map <int, std::deque<int>> childmap;
	std::unordered_set <int> visited;
	std::deque <int> cur;
	
	for (int i = 0; i < n; ++i)
	{
		childmap[i];
	}

	for (int j = 0; j < edges.size(); ++j)
	{
		childmap[edges[j][0]].push_back(edges[j][1]);
		childmap[edges[j][1]].push_back(edges[j][0]);

	}

	auto it = childmap.begin();
	if (bfsvaltree(-1, it->first,cur, visited, childmap))
	{
		if (n == visited.size())
		{
			return true;
		}
	}

	return false;
}

void Node::dfsmapisland(int prev, int cur, std::unordered_set <int>& visited, std::unordered_map <int, std::deque<int>>& childmap)
{
	auto it = visited.find(cur);
	if (it != visited.end())
	{
		return;
	}
	else
	{
		visited.insert(cur);
	}
	for (int i = 0; i < childmap[cur].size(); ++i)
	{
		if (childmap[cur][i] != prev)
		{
			dfsmapisland(cur, childmap[cur][i], visited, childmap);
		}
	}
}

int Node::countComponents(int n, std::vector<std::vector<int>>& edges)
{
	std::unordered_map <int, std::deque<int>> childmap;
	std::unordered_set <int> visited;

	for (int i = 0; i < n; ++i)
	{
		childmap[i];
	}

	for (int j = 0; j < edges.size(); ++j)
	{
		childmap[edges[j][0]].push_back(edges[j][1]);
		childmap[edges[j][1]].push_back(edges[j][0]);

	}
	int count = 0;
	for (auto it = childmap.begin(); it != childmap.end(); ++it)
	{
		auto it2 = visited.find(it->first);
		if (it2 == visited.end())
		{
			dfsmapisland(-1, it->first, visited, childmap);
			++count;
		}
	}

	return count;
}

bool Node::dfsredcon(int prev, int cur, std::unordered_set <int>& curpath, std::unordered_set <int>& visited, std::unordered_map <int, std::deque<int>>& childmap)
{
	auto it = visited.find(cur);
	if (it != visited.end())
	{
		return false;
	}
	else
	{
		curpath.insert(cur);
		visited.insert(cur);
	}
	for (int i = 0; i < childmap[cur].size(); ++i)
	{
		if (childmap[cur][i] != prev)
		{
			if (!dfsredcon(cur, childmap[cur][i], curpath, visited, childmap))
			{
				return false;
			}
		}
	}
	curpath.erase(cur);
	return true;
}

std::vector<int> Node::findRedundantConnection(std::vector<std::vector<int>>& edges) 
{
	{
		std::unordered_map <int, std::deque<int>> childmap;
		std::unordered_set <int> visited;
		std::unordered_set <int> cur;

		for (int j = 0; j < edges.size(); ++j)
		{
			childmap[edges[j][0]].push_back(edges[j][1]);
			childmap[edges[j][1]].push_back(edges[j][0]);

		}

		auto it = childmap.begin();
		std::vector<int> result;
		if (!dfsredcon(-1, it->first, cur, visited, childmap))
		{
			for (const auto& i : edges)
			{
				auto ita = cur.find(i[0]);
				auto itb = cur.find(i[1]);

				if (ita != cur.end() && itb != cur.end())
				{
					result = {i[0],i[1]};
				}
			}
		}

		return result;
	}
}