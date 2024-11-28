#ifndef _EDGE
#define _EDGE 1

template<class A>
class Edge {
	public:
		A w;
		int pos;
		
		Edge(A weight = 0, int to = -1): w(weight), pos(to) {}
};

#endif
