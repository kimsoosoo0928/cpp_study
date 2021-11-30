#include <iostream>
// iostream 이라는 헤더파일을 include 
// iostream : 표준 입축력에 필요한 것들을 포함

int main()
// main 함수는 프로그램이 실행될 때 가장 먼저 실행되는 함수
{
	std::cout << "Hello, World!!!" << std::endl;
	// std : C++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 이름 공간.
	// 같은 이름이라도, 소속된 이름 공간이 다르면 다른것으로 취급
	// std::cout : std 라는 이름 공간에 정의되어 있는 cout를 의미
	return 0;
}


namespace header1 {
	int foo();
	void bar();
}
namespace header1 {
	int foo();
	void bar();
}

// header1 라는 이름 공간에 살고 있는 foo와 header2 라는 이름 공간에 살고 있는 foo

#include "header1.h"

namespace header1 {
	int fuc() {
		foo(); // 알아서 header1::foo()가 실행된다. 
	}
}

#include "header1.h"
#include "header2.h"

namespace header1 {
	int func() {
		foo(); // 알아서 header1::foo()가 실행된다.
		header2::foo(); // header2::foo()가 실행된다.
	}
}

#include "header1.h"
#include "header2.h"

int func() {
	header1::foo(); // header1 이란 이름 공간에 있는 foo를 호출
}

#include "header1.h"
#include "header2.h"
 
using header1::foo;
int main() {
	foo(); // header1에 있는 함수를 호출
}

#include "header1.h"
#include "header2.h"

using namespace header1; // header1 이름 공간안에 정의된 모든 것들을 header1:: 없이 사용
int main() {
	foo(); // header1 에 있는 함수를 호출
	bar(); // header1 에 있는 함수를 호출
}

#include "header1.h"
#include "header2.h"

using namespace header1;

int main() {
	header2::foo(); // 명시적 사용
	foo();
}

// std 를 붙이기 귀찮은 경우
#include <iostream>
using namespace std;

int main() {
	cout << "Hello, World" << endl;
	return 0;
}



