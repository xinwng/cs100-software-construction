#ifndef __COUNT_VISITOR_HPP__
#define __COUNT_VISITOR_HPP__

class Base;

class CountVisitor{
    private:
        int ops;
        int rands;
        int mults;
        int divs;
        int add;
        int sub;
        int pow;

    public:
        CountVisitor()
        {
            this->ops = 0;
            this->rands = 0;
            this->mults = 0;
            this->divs = 0;
            this->add = 0;
            this->sub = 0;
            this->pow = 0;
        }

        void visit_op(Base *temp)
        {
            (this->ops)++;
        }

        int op_count()
        {
            return this->ops;
        }

        void visit_rand(Base *temp)
        {
            (this->rands)++;
        }

        int rand_count()
        {
            return this->rands;
        }

        void visit_mult(Base *temp)
        {
            (this->mults)++;
        }

        int mult_count()
        {
            return this->mults;
        }

        void visit_div(Base *temp)
        {
            (this->divs)++;
        }

        int div_count()
        {
            return this->divs;
        }

        void visit_add(Base *temp)
        {
            (this->add)++;
        }

        int add_count()
        {
            return this->add;
        }

        void visit_sub(Base *temp)
        {
            (this->sub)++;
        }

        int sub_count()
        {
            return this->sub;
        }

        void visit_pow(Base *temp)
        {
            (this->pow)++;
        }

        int pow_count()
        {
            return this->pow;
        }
};

#endif //__COUNT_VISITOR_HPP__
