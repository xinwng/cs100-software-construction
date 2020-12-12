#include "header/div.hpp"
#include "header/add.hpp"
#include "header/base.hpp"
#include "header/iterator.hpp"
#include "header/mult.hpp"
#include "header/op.hpp"
#include "header/pow.hpp"
#include "header/rand.hpp"
#include "header/sub.hpp"
#include "header/visitor.hpp"

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	Base *b1 = new Op(1);
	Base *b2 = new Op(2);
	Base *b3 = new Op(3);
	Base *b5 = new Op(5);

	Base *a8 = new Add(b3, b5);
	cout << "Result: " << a8->stringify() << " = " << a8->evaluate() << endl;
	cout << "Expected: "
		 << "3 + 5"
		 << " = "
		 << "8" << endl;

	Base *s1 = new Sub(b3, b2);
	cout << "Result: " << s1->stringify() << " = " << s1->evaluate() << endl;
	cout << "Expected: "
		 << "3 - 2"
		 << " = "
		 << "1" << endl;

	Base *m15 = new Mult(a8, s1);
	cout << "Result: " << m15->stringify() << " = " << m15->evaluate() << endl;
	cout << "Expected: "
		 << "8 * 1"
		 << " = "
		 << "8" << endl;

	Base *p9 = new Pow(b3, m15);
	cout << "Result: " << p9->stringify() << " = " << p9->evaluate() << endl;
	cout << "Expected: "
		 << "3 ** 8"
		 << " = "
		 << "6561" << endl;

	Base *d5 = new Div(p9, b1);
	cout << "Result: " << d5->stringify() << " = " << d5->evaluate() << endl;
	cout << "Expected: "
		 << "5 / 1"
		 << " = "
		 << "5" << endl;
	
	Add *dummy = new Add(d5, new Op(5));
	CountVisitor *cvisit = new CountVisitor;
	PreorderIterator *porder = new PreorderIterator(dummy);

	porder->first();
	while (!porder->is_done())
	{
		porder->current()->accept(cvisit);
		porder->next();
	}

	printf("Number of + : %i\n", cvisit->add_count());
	printf("Number of - : %i\n", cvisit->sub_count());
	printf("Number of * : %i\n", cvisit->mult_count());
	printf("Number of / : %i\n", cvisit->div_count());
	printf("Number of pows : %i\n", cvisit->pow_count());
	printf("Number of operands : %i\n", cvisit->op_count());
	printf("Number of rands : %i\n", cvisit->rand_count());

	cout << d5->stringify() << " = " << d5->evaluate() << endl;

	return 0;
};
