#pragma once

#include "Graph.h"
#include <algorithm>
#include <queue>


//class Heap
//{
//public:
//	std::vector <int> data;
//	int K;
//
//	Heap(int _k, std::vector<int>& _data)
//	{
//		K = _k;
//		heapCreate(_data);
//	}
//
//	void heapCreate(std::vector <int>& _data)
//	{
//		for (size_t i = 0; i < _data.size(); ++i)
//		{
//			this->add(_data[i]);
//		}
//	}
//
//	void swapPlaces(int& parent, int& child)
//	{
//		// Swaping value
//		int p = this->data[parent];
//		this->data[parent] = this->data[child];
//		this->data[child] = p;
//
//		// Swapping indexes
//		p = parent;
//		parent = child;
//		child = p;
//		return;
//
//	}
//
//	int getChildIndexA(int pindex)
//	{
//		return (pindex * 2) + 1;
//	};
//	int getChildIndexB(int pindex)
//	{
//		return (pindex * 2) + 2;
//	}
//
//	int getParentIndex(int childindex)
//	{
//		return std::floor((childindex - 1) / 2);
//	}
//
//	int add(int val)
//	{
//		if (!this->data.size())
//		{
//			this->data.push_back(val);
//		}
//		else
//		{
//			int cur = this->data.size();
//			this->data.push_back(val);
//		
//
//			while (true)
//			{
//				// two conditions to end the loop.
//				// 1 - the position of element is fixed and no further fixing required.
//				// 2 - the element reaches at the root of the tree.
//				if (cur == 0)
//				{
//					// condition 1
//					break;
//				}
//				else
//				{
//					int p = getParentIndex(cur);
//					if (this->data[p] >= this->data[cur])
//					{
//						// condition 2
//						break;
//					}
//					else
//					{
//						swapPlaces(p,cur);
//						continue;
//					}
//				}
//			}
//			
//		}
//		if (this->data.size() >= this->K)
//		{
//			return this->data[this->K - 1];
//		}
//		else
//		{
//			return -1;
//		}
//	}
//
//};

enum class Theap
{
	Min , Max
};

class Heap
{
public:
	Theap type;
	int size;
	std::vector <int> data;	

	Heap(Theap type,int k , std::vector <int> _data);

	void swapElem(int &id1 , int &id2);
	int insertElem(int elem);
	int popElem();
	int getRoot();
	int getChildA(int cur);
	int getChildB(int cur);
	int getParent(int cur);

};

int lastStoneWeight(std::vector <int>& stones);
std::vector<std::vector<int>> kClosestPoints(std::vector<std::vector<int>>& points, int k);