#ifndef _GRAPH
#define _GRAPH 1

#include "../PriorityQueue/_VECTOR.hpp"
#include "../PriorityQueue/_PRIORITY_QUEUE.hpp"
#include "_EDGE.hpp"
#include "_CMP_EDGE.hpp"

#include <iostream>

template<class A>
class Graph {
	private:
		int vertices;
		Vector<Vector<Edge<A>>> adj;
	public:
		Graph(int ver): vertices(ver), adj(ver) {};
		
		void addEdge(int from, int to, A weight) {
			adj[from].push_back(Edge<A>(weight, to));
			adj[to].push_back(Edge<A>(weight, from));
		}
		
		void prim (int begin) {
			Vector<bool> visited(vertices, false);
			Priority_Queue<Edge<A>, cmp_edge<A>> pq;
			A min_weight = 0;
			
			visited[begin] = true;
			for(int i = 0; i < adj[begin].size(); i++) pq.push(adj[begin][i]);

			while(!pq.empty()) {
				Edge<A> e = pq.top();

				pq.pop();
				
				int check_pos = e.pos;
				if(visited[check_pos]) continue;
				
				visited[check_pos] = true;
				min_weight += e.w;

				if (e.pos != -1) {
                    std::cout << "Edge: " << begin << " - " << e.pos
                              << " | Weight: " << e.w << "\n";
                }
				
				for(int i = 0; i < adj[check_pos].size(); i++){
					int v = adj[check_pos][i].pos;
					
					if(!visited[v]) {
						pq.push(adj[check_pos][i]);
					}
				}
			}
			
			std::cout << "Min weight: " << min_weight;
		}
		
		void print() {
			for(int i = 0; i < adj.size(); i++) {
				for(int j = 0; j <adj[i].size(); j++) {
					std::cout <<adj[i][j].pos << i << adj[i][j].w << " ";
				}
				std::cout<<std::endl;
			}
		}
};

#endif
