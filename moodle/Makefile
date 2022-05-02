all:
	# tk solver.cpp t.tio

	cat solver.hpp | sed -e "/#ifdef PROF/,/#else/d" | sed -e "/#endif/d" | sed -e "/#define PROF/d" > student.hpp