#ifndef _COMPARE_
#define _COMPARE_ 1

template<class A>
class Greater {
	public:
		bool operator()(const A& a,const A& b) {return a > b;}
};

template<class A>
class Less {
	public:
		bool operator()(const A& a,const A& b) {return a < b;}
};

#endif
