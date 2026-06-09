#include "Heap.h"

Heap::Heap(Theap _type, int k, std::vector <int> _data)
{
	this->size = k;
	this->type = _type;

	for (int i = 0; i < _data.size(); i++)
	{
		this->insertElem(_data[i]);
	}
	
}

int Heap::insertElem(int elem)
{
	this->data.push_back(elem);
	int id = this->data.size() - 1;

	while (true)
	{
		int p = this->getParent(id);
		// There are two conditions to stop sorting 
		// 1. ELement reaches the root position.
		// 2. Element cant be moved further up.

		if (p < 0)
		{
			break;
		}

		if (this->type == Theap::Min)
		{
			if (this->data[id] >= this->data[p])
			{
				break;
			}
			else
			{
				swapElem(p,id);
			}
		}
		else
		{
			if (this->data[id] <= this->data[p])
			{
				break;
			}
			else
			{
				swapElem(p, id);
			}
		}
	}

	if (this->data.size() > this->size)
	{
		this->popElem();
	}
	return this->data[0];
}

void Heap::swapElem(int &id1, int &id2)
{
	int tempval = this->data[id1];
	int tempid = id1;

	this->data[id1] = this->data[id2];
	this->data[id2] = tempval;

	id1 = id2;
	id2 = tempid;

}

int Heap::popElem()
{
	int cur = 0;
	int ret = this->data[0];
	int bound = this->data.size() - 1;


	while (true)
	{
		int ca = getChildA(cur);
		int cb = getChildB(cur);

		if (bound < ca && bound < cb)
		{
			break;
		}
		else if (bound < ca)
		{
			this->swapElem(cur, cb);
			break;
		}
		else if (bound < cb)
		{
			this->swapElem(cur, ca);
			break;
		}	

		if (this->type == Theap::Max)
		{
			int cmax = (this->data[ca] > this->data[cb])? ca : cb;
			this->swapElem(cur,cmax);

		}
		else
		{
			int cmin = (this->data[ca] < this->data[cb]) ? ca : cb;
			this->swapElem(cur, cmin);
		}
	}
	this->data.erase(this->data.begin() + cur);
	return ret;

}

int Heap::getRoot()
{
	return this->data[0];
}
int Heap::getChildA(int cur)
{
	return (cur * 2) + 1;
}
int Heap::getChildB(int cur)
{
	return (cur * 2) + 2;
}
int Heap::getParent(int cur)
{
	return std::ceil(cur/2.0) - 1;
}


int lastStoneWeight(std::vector <int> &stones)
{
	std::make_heap(stones.begin(), stones.end());

	while (true)
	{
		if (!stones.size())
		{
			return 0;
		}
		else if (stones.size() == 1)
		{
			return stones[0];
		}
		else
		{
			std::pop_heap(stones.begin(),stones.end());
			int stoneA = stones[stones.size() - 1];
			stones.pop_back();

			std::pop_heap(stones.begin(), stones.end());
			int stoneB = stones[stones.size() - 1];
			stones.pop_back();

			int remstone = std::abs(stoneA - stoneB);

			if (remstone)
			{
				stones.push_back(remstone);
				std::push_heap(stones.begin(), stones.end());
			}
		}
	}
}

std::vector<std::vector<int>> kClosestPoints(std::vector<std::vector<int>>& points, int k)
{
	// Make a Hashmap to store point with corresponding distance.
	// Make min heap.
	// return first k elements based on distance.

	std::multimap <float, int>ptable;
	std::priority_queue <float, std::vector <float>, std::greater <float>> distq;

	// create point map to distance , and create a priority queue based on distance .
	for (int i = 0; i < points.size(); i++)
	{
		float distance = std::sqrt((points[i][0]* points[i][0]) + (points[i][1] * points[i][1]));
		ptable.insert({distance,i});
		distq.push(distance);
	}

	std::vector <std::vector<int>> result;
	while(true)
	{
		auto it = ptable.begin();

		while (it != ptable.end() && it->first == distq.top())
		{
			std::vector <int> temp = points[it->second];
			result.push_back(temp);
			if (result.size() == k)
			{
				return result;
			}
			it++;
		}

		ptable.erase(distq.top());
		distq.pop();
	}

}