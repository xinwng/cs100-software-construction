#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, NumericalValues) {
	char* test_val[4]; 
	test_val[0] = "./c-echo"; 
	test_val[1] = "1"; 
	test_val[2] = "2";
	test_val[3] = "3"; 
	EXPECT_EQ("1 2 3", echo(4,test_val));
}	 

TEST(EchoTest, SpaceOutputsBlank) {
	char* test_val[1];
	test_val[0] = "./c-echo";
	test_val[1] = " ";
	EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, LongPhrase) {
	char* test_val[3];
	test_val[0] = "./c-echo";
	test_val[1] = "hello world";
	test_val[2] = "my name is xin";
	EXPECT_EQ("hello world my name is xin", echo(3, test_val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
