#include "pch.h" //TODO
#include<iostream>
using namespace std;

class Check { //constructor
	int val;
public:
	Check() : val(0) {} //allocating 0 to val
	void setValue(int newVal) {
		this->val = newVal;
	}
	int getVal() {
		return this->val;
	}
};
//TF --> test fixture
struct TF : public testing::Test { //google test
	Check* c1;
	void SetUp() {
		cout << "SETUP" << endl;
		c1 = new Check();
	}
	void TearDown() {
		cout << "TEARDOWN" << endl;
		delete c1;
	}
};


TEST_F(TF, SubTestName) {
	
	//Arrange
	// Check* c1 = new Check();
	
  //Act
  c1->setValue(100);

  //Assert --> fatal
  ASSERT_EQ(c1->getVal(),200);

}


TEST_F(TF, SubTestName_1) {
	
  //Act
  c1->setValue(500);
  //Expect --> non fatal
  EXPECT_EQ(c1->getVal(),500);

}