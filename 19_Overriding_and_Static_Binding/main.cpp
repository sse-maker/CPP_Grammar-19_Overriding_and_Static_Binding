//
//  main.cpp
//  19_Overriding_and_Static_Binding
//
//  Created by 세광 on 2021/07/06.
//

// override: 우선하다
// 바인딩: 모호한 포인터를 어떤 특정한 타입을 가리키는 포인터로 결정하는 것 (프로그램의 어떤 기본 단위가 가질 수 있는 구성요소의 구체적인 값, 성격을 확정하는 것)

#include <iostream>

using namespace std;

class Base {
public:
    int a = 10;
    void Print() { cout << "From Base" << endl; }
};

class Derived : public Base {
public:
    int a = 20;
    void Print() { cout << "From Derived" << endl; }
};
// a가 덮어씌워진 것이 아님

class Derived2 : public Base {
    
};

int main() {
    // 오버라이딩
    Base b;
    Derived d;

    cout << b.a << endl;
    cout << d.a << endl;
    cout << d.Derived::a << endl;
    cout << d.Base::a << endl;

    d.Print();
    d.Base::Print();
    d.Derived::Print();
    
    // 정적 바인딩
    // C++에서는 타입이 달라도 예외적으로 부모 class의 포인터가 자식을 가리킬 수 있음
    Base *k = new Derived();
    k->Print();
    k = new Derived2();
    k->Print(); // 정적 바인딩
}
