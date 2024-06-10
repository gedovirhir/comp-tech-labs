#include <iostream>
#include <cmath>

#include "Interval.h"

using namespace std;

template<typename T>
void print_interval(const Interval<T>& I) {
	cout << "(" << I.getBot() << ", " << I.getTop() << ") ";
}

namespace lr2 {

	void main() {
		Interval<int> X(1, 2);

		Interval<int> res = 1 + 6 * X - 6 * (X ^ 2) + 2 * (X ^ 3);

		print_interval(res);
	}
}

namespace lr3 {
	
	template<typename T>
	Interval<T> func(Interval<T> X) {
		return 1 + 2 * X - ((X + 3) ^ 2);
	}

	const int N = 3;
	const int a = 1;
	const int b = 10;
	const int h = (b - a) / (N - 1);
	const float R = 1;

	void main() {
		int start = a;

		while (start <= b) {
			float l_start = start - R;
			l_start = l_start > a ? l_start : a;

			float l_end = start + R;
			l_end = l_end < b ? l_end : b;

			Interval<float> res = func(Interval<float>(l_start, l_end));

			printf("Start: %i ", start);
			print_interval(res);
			cout << endl;

			start += h;

		}
	}

}

namespace lr4 {
	const int V = 1;
	const double rad = 0.001;
	const int N = 10;

	auto get_i_el(int i) {
		return Interval<double>(
			sin(V + i) - rad,
			sin(V + i) + rad
		);
	}

	void fill_i_arr(Interval<double> i_lst[N]) {
		for (int i = 0; i < N; i++) {
			i_lst[i] = get_i_el(i);
		}
	}

	Interval<double> sum_i_arr(Interval<double> i_lst[N]) {
		Interval<double> sum_(0, 0);

		for (int i = 0; i < N; i++) {
			sum_ = sum_ + i_lst[i];
		}

		return sum_;
	}

	int compare(const void* a, const void* b) {
		const Interval<double>* ai = static_cast<const Interval<double>*>(a);
		const Interval<double>* bi = static_cast<const Interval<double>*>(b);

		if (ai->getBot() < bi->getBot()) {
			return -1;
		}
		else if (ai->getBot() > bi->getBot()) {
			return 1;
		}
		else {
			return 0;
		}

	}

	void sort_i_arr(Interval<double> i_lst[N]) {
		qsort(
			i_lst,
			N,
			sizeof(Interval<double>),
			compare
		);
	}

	void print_i_arr(Interval<double> i_lst[N]) {
		for (int i = 0; i < N; i++) {
			print_interval(i_lst[i]);
		}
		cout << endl;
	}

	void main() {
		Interval<double> i_lst[N];
		fill_i_arr(i_lst);
		print_i_arr(i_lst);

		Interval<double> sum_ = sum_i_arr(i_lst);
		print_interval(sum_);
		cout << endl;

		sort_i_arr(i_lst);
		print_i_arr(i_lst);
	}
}

int main() {
	lr4::main();
}