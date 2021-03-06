
int source();
void sink(...) {};

class StructLikeClass {
public:
	StructLikeClass() {} // Constructor
	StructLikeClass(int _v) : v(_v) {} // ConversionConstructor

	int v;
};

void test_structlikeclass()
{
	{
		StructLikeClass s1(1);
		StructLikeClass s2 = 1;
		StructLikeClass s3(s1);
		StructLikeClass s4;
		s4 = 1;

		sink(s1);
		sink(s2);
		sink(s3);
		sink(s4);
	}

	{
		StructLikeClass s1(source());
		StructLikeClass s2 = source();
		StructLikeClass s3(s1);
		StructLikeClass s4;
		s4 = source();

		sink(s1); // tainted
		sink(s2); // tainted
		sink(s3); // tainted
		sink(s4); // tainted
	}

	{
		StructLikeClass s1;
		StructLikeClass s2 = s1;
		StructLikeClass s3(s1);
		StructLikeClass s4;
		s4 = s1;

		sink(s1);
		sink(s2);
		sink(s3);
		sink(s4);
	}

	{
		StructLikeClass s1 = StructLikeClass(source());
		StructLikeClass s2;
		StructLikeClass s3;
		s2 = StructLikeClass(source());

		sink(s1); // tainted
		sink(s2); // tainted
		sink(s3 = source()); // tainted
	}
}
