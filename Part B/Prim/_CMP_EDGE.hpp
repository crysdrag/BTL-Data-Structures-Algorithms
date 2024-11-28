#ifndef _CMP_EDGE
#define _CMP_EDGE 1
#include "_EDGE.hpp"

template<class A>
class cmp_edge {
	public:
		bool operator()(const Edge<A>& a, const Edge<A>& b){return a.w < b.w;}
};

#endif
