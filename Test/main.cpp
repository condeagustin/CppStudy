
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <cmath> 
#include <typeinfo>
#include <memory>
#include <functional>
#include <array>
#include <map>
#include <optional>
#include <future>
#include <tuple>

using namespace std;

struct Person {
    string name;
    int age;

    public:
    const Person *getPerson() const{
        return new Person {"Gloria", 41};
    }

    Person(string name, int age) : name(name), age(age) 
    {

    }

    Person()
    {

    }
};

void reverseString(char inputString[]) {
    
    int length = strlen(inputString);
    std::cout << length << endl;
   
    for(int i=0, j= length-1; i < j; i++, j--) {
        
        char temp = inputString[i];
        inputString[i] = inputString[j];
        inputString[j] = temp;
    }
}

int substraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = functocall(x, y); //or
  //g = (*functocall)(x,y);
  return g;
}

float operationLambda(int x, int y, std::function<float(int,int)> powerOf) {

    return powerOf(x, y);
} 

int* getPointer () {
    //static int n = 5;
    int *n = new int[10];
    return n;
}

void changePerson(const Person * const person) {
    //person->name = "Gioo";
    //person = new Person;
    string name = person->name;
    //person->name = "Gloria";
    std::cout << "Person name " << name << endl; 
}

void printNumber(const int &n) {
    cout << "The number is " << n << endl;
    
}

template <class T>
class Functor 
{
    public:
    void operator () (const T& element) const
    {
        cout << "element is " << element << endl;
    }
};

void doTest1() {
    //string sentence ="Now is the winter of our discontent made glorious summer by this son of York";
    char sentence[] ="Agustin es GameCoder";
   
    std::cout << sentence << endl;
    reverseString(sentence);
    std::cout << sentence << endl;
    
    
    int array1[] = {10, 20, 31, 40};
    int * p = array1;
    
    cout << "array1 in p is" << *p++ << endl;
    
    //p = array1 + 1;
    *p += 2;

    std::cout << "array1[1] is " << array1[1] << endl;
    
    cout << "sizeof array1: " << sizeof(array1) << endl;
    
    vector<int> numbers {5, 4, 3, 2, 1};
    int amountOfEvenNumbers = 0;
    
    //this is valid for iterators too
    //std::for_each(array1, array1 + 4, [&amountOfEvenNumbers](const int& element)->void {
    std::for_each(std::begin(array1), std::end(array1), [&amountOfEvenNumbers](const int& element)->void {
        cout << "The element is " << element << endl;

        if(element % 2 == 0)
        {
            amountOfEvenNumbers++;
        }
    });

    //using a Functor
    std::for_each(std::begin(array1), std::end(array1), Functor<int>());

    cout << "amount of even numbers: " << amountOfEvenNumbers << endl;
    int myVar1 = 0;
    int myVar2 = 1;
    auto powerOf = [myVar1, &myVar2](int a, int b)->float {
        
        myVar2++;
        if(b == 0)
        {
            return 1;
        }

        int exponent = std::abs(b);

        int result = 1;
        for(int i = 0; i < exponent; i++)
        {
            result *= a;
        }
        
        if(b < 1)
        {
            return 1.0f/result;
        }
        
        return result;
    };

   

    std::function<float(int, int)> powerOfFunc = [myVar1, &myVar2](int a, int b)->float {
        
        myVar2++;
        if(b == 0)
        {
            return 1;
        }

        int exponent = std::abs(b);

        int result = 1;
        for(int i = 0; i < exponent; i++)
        {
            result *= a;
        }
        
        if(b < 1)
        {
            return 1.0f/result;
        }
        
        return result;
    };

    

    double x = 0;
    cout << "type of decltype is " << typeid(decltype ((x)) ).name() << endl;

    cout << "type of powerOf is " << typeid(powerOfFunc).name() << endl;

    cout << "BEFORE: myVar1=" << myVar1 << ", myVar2=" << myVar2 << endl;
    cout << "2^-2 = " << operationLambda(2, -2, powerOfFunc) << endl;
    cout << "2^-2 = " << powerOf(2, -2) << endl;
    cout << "AFTER: myVar1=" << myVar1 << ", myVar2=" << myVar2 << endl;
    
    int (*minus)(int, int) = substraction;
    
    int res = operation(10, 2, minus);
    std::cout << "substraction result: " << res <<endl;
    
    std::cout << "CHAR_BIT(number of bits in a byte): " << CHAR_BIT << endl;
    std::cout << "sizeof short " << sizeof(short) << endl;
    std::cout << "sizeof int " << sizeof(int) << endl;
    std::cout << "sizeof long " << sizeof(long) << endl;
    std::cout << "sizeof float " << sizeof(float) << endl;
    std::cout << "sizeof double " << sizeof(double) << endl;
    std::cout << "sizeof string " << sizeof(string) << endl;
    std::cout << "sizeof Person " << sizeof(Person) << endl;
    

    Person* person = new Person {"Agus", 32};
    std::cout << "sizeof Person instance  " << sizeof(person) << endl;
    
    int *dynArray = new int[10];
    dynArray[0] = 4;
    delete[] dynArray;
    std::cout << "dynArray[0]: " << dynArray[0] << endl;
    
    int *pointer1 = getPointer();
    pointer1[0] = 10;
    std::cout << *pointer1 << endl;
    delete[] pointer1;
    
    int year;
    string str1 = "1234";
    stringstream(str1) >> year;
    
    std::cout << year<< endl;
    
    Person person1;
    Person *person1ptr = &person1;
    
    person1ptr->name = "Agustin";
    person1ptr->age = 33;
    
    changePerson(person1ptr);
    
    std::cout << person1ptr->name << " is " << (*person1ptr).age << " old" << endl;
    
}

void doTest2() {
    int a = 6;
    int b = a;
    int &ref = a;
    int *pointer = &a;

    Person person;
    person.name = "Agustin";
    person.age = 33;

    Person &refP = person;
    refP.age = 21;

    cout << person.age << endl;

    //b = 7;
    ref = 7;
    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;
    cout << "pointer: " << pointer << endl;
}

struct Human
{
    string ownerName;
};

class Animal {

    private:
        bool hasWings;
    public:
        string name;
        mutable int numberOfLegs;
        Human human;
        
        Animal(string name) : name(name){
             human.ownerName = "Agustin";  
        }

        //
        Animal() : Animal("default") {
            human.ownerName = "Agustin";   
        }

        Animal(Animal&& animal) {
            cout << "Move constructor was called" << endl;
            name = animal.name;
            animal.name = "emptyAnimal";
            
        }

        Animal(const Animal& animal)
        {
            cout << "Copy constructor was called" << endl;
            name = animal.name;
        }

        Animal& operator=(Animal&& animal)
        {
            cout << "Move assign operator called" << endl;
            name = animal.name;
            animal.name = "emptyAnimal";
            return *this;
        }
        
        Animal& operator=(const Animal& animal)
        {
            cout << "Copy assign operator was called" << endl;
            name = animal.name;
            return *this;
        }

        ~Animal() {
            cout << "Destroying Animal " << name << endl;
        }

        Human& getHuman()
        {
            return human;
        }

        virtual void eat() const {
            cout << "Animal " << name <<  " eats" << endl;
        }

        void sleep() &
        {
            cout << "from sleep() &: Animal " << name << " sleeps" << endl;
        }

        void sleep() &&
        {
            cout << "from sleep() &&: Animal " << name << " sleeps" << endl;
        }
};

class Mammal : public Animal {

    public:
        Mammal(string name) : Animal(name) {

        }
        ~Mammal() {
            cout << "Destroying Mammal " << name << endl;
        }

        virtual void eat() const override{
            
            Animal::eat();
            cout << "Mammal " << name <<  " eats" << endl;
        }
};

class Dog : public Mammal {
    public:

        Dog(string name) : Mammal(name) {

        }

        ~Dog() {
            cout << "Destroying Dog " << name << endl;
        }

        void sleep()
        {
            cout << "Dog " << name << " sleeps" << endl;
        }
};

class Survey {
    public:
        void doSurvey(Animal *animal) {
            cout << "Animal type" << endl;
        }

        void doSurvey(Mammal *animal) {
            cout << "Mammal type" << endl;
        }   

        void doSurvey(Dog *animal) {
            cout << "Dog type" << endl;
        }

        
};

template <typename T>
class Thing {
    
    private:
        T someProperty;
        int otherProperty;

    public: 
        Thing(T someProperty, int otherProperty) : otherProperty(otherProperty) {
            this->someProperty = someProperty;
        }

        Thing() {

        }

        auto getSomeProperty() -> decltype((someProperty)) //double parentheses mean by reference, single parentheses mean by value
        {
            return someProperty;
        }

        int getOtherProperty()
        {
            return otherProperty;
        }
};

template<class T>
auto mul(T a, T b) -> decltype(a*b){
    return a*b;
}

//this returns an rvalue reference
int&& testValue(int a) {
    return 17;
}

class Shape {

    public:
    virtual int calcArea() = 0;
    
    void printName() {
        cout << "Shape name" << endl;
    }
};

int Shape::calcArea() {
    return -1;
}
class Square : public Shape {

    public:
        int side;

        int calcArea() {
            return side * side;
        }
};

Animal returnSameArg(Animal pAnimal)
{
    return pAnimal;
}

void doTest3() {

    short x = 255;
    x <<= 1;
    cout << "x is " << x << endl;

    
    Square square;
    square.printName();
    
    Thing<int> thing(5, 2);

    cout << "BEFORE thing other property is " << thing.getOtherProperty() << endl;
    //auto& other = thing.getOtherProperty();
    cout << "AFTER thing other property is " << thing.getOtherProperty() << endl;

    cout << "BEFORE thing some property is " << thing.getSomeProperty() << endl;
    auto& some = thing.getSomeProperty();
    some = 9;
    cout << "AFTER thing some property is " << thing.getSomeProperty() << endl;

    
    int result = mul<int>(8, 4);
    cout << "mul result: " << result << endl;
   

    Mammal *animal1 = new Mammal("mammal1");
    Dog *animal2 = new Dog("dog2");
    animal2->sleep();
    Survey *survey = new Survey;
    survey->doSurvey(animal1);
    survey->doSurvey(animal2);

    Animal *animal3 = new Dog("dog3");
    animal3->sleep();
    animal3->eat();
    Animal *animal4 = new Mammal("mammal4");
    animal1->eat();
    animal4->eat();
    survey->doSurvey(animal3);
    survey->doSurvey(animal4);

    

    //pointer to a class member
    cout << "animal name is " << animal1->name << endl;

    string Animal::* ptrName = &Animal::name;
    animal1->*ptrName = "AnimalX";

    cout << "animal name is " << animal1->name << endl;

    delete animal1;
    delete animal2;

    //Does not call Dog destructor because animal3 is of type Animal (even if it is a Dog instance)
    delete animal3;

    delete animal4;
    delete survey;

    cout << "animal name is " << animal1->name << endl;

    if(animal1)
    {
        cout << "animal1 is " << animal1 << endl;
    }

    std::array<int, 4> stdArray = {2, 1, 3, 4};
    
}

Animal createAnimal() {
   
    //In this case RVO (return value optimization) is NOT performed, so the move or copy constructor is called
    Animal animal = Animal();
    return animal;

    //if we are going to return some attribute from a temporary is more efficient to return the result of a
    //move operation
    //return std::move(Animal());

    //In this case RVO is performed so there is no need for copy or move operations
    //return Animal{};
}

void changeInt(int& myInt)
{
    myInt = 1;
}

struct BitfieldTest
{
   int a : 3;
};



void doTest5()
{
    
    cout << "size of struct BitfieldTest " << sizeof(BitfieldTest) << endl;
    
/*    Animal animal5("animal5");
    Animal animal6 = animal5;

    //std::move also calls the move constructor
    Animal animal8 = std::move(animal5);
*/
    //by calling a function that does not return a reference and the compiler does not perform RVO, the move constructor is called
    Animal animal7 = createAnimal();
    
    Animal a;

    a.sleep();

    Animal().eat();

    const Animal b = Animal("b");
    //b.name = "b";
    b.numberOfLegs = 5;

    const Animal* c = &b;
    Animal* d = const_cast<Animal*>(c);
    d->name = "d";
    cout << "b.name : " << b.name << endl;
    changeInt(b.numberOfLegs);

    int Animal::* ptrNoL = &Animal::numberOfLegs;
    //b.*ptrNoL = 6; //error, you cannot assign to a variable that is const
    b.numberOfLegs = 6;
    int x = 4;
    const int* y = &x;
    int* z = const_cast<int*>(&x);
    *z = 6;

    cout << "x: " << x << ", z: " << *z << endl;

    float x1 = 34.5f;
    int x2 = static_cast<int>(x1);
    bool x3 = static_cast<bool>(0);
    
    cout << "x1: " << x1 << ", x2: " << x2 << ", x3: " << x3 << endl;

    cout << "size of char " << sizeof(char) << endl;
    cout << "size of uchar " << sizeof(unsigned char) << endl;
    cout << "size of int " << sizeof(int) << endl;
    cout << "size of uint " << sizeof(unsigned int) << endl;
    cout << "size of bool " << sizeof(bool) << endl;

    Animal *animal9 = new Animal("AnimalZ");
    unique_ptr<Animal> upAnimal (animal9);

    upAnimal = std::make_unique<Animal>("AnimalY");
    
    upAnimal->eat();
    //or...
    Animal* anim = upAnimal.get();
    
    anim->eat();
       
    unique_ptr<Animal> upAnimal1(new Animal("AnimalW"));
    
    shared_ptr<Animal> spAnimal(new Animal("animal1"));
    cout << "use count: " << spAnimal.use_count() << endl;
    shared_ptr<Animal> spAnimal1 = spAnimal;
    cout << "use count: " << spAnimal1.use_count() << endl;
    (*spAnimal).eat();
    spAnimal1->eat();
}

void passRef(Person person) {
    person.name = "Gio";
}

void doTest4() {

    Person person;

    const Person *personA = person.getPerson();
    
    //personA->name = "Gloria";
    cout << "personA name is " << personA->name << endl;
    delete personA;

    Person person1 {"Person1", 42};
    Person person3 = Person("Person3", 32);

    cout << "Reference test" << endl;
    Person &refP1 = person1;
    cout << person1.name << " " << person1.age <<  endl;
    refP1 = person3;
    
    //refP1.name = "Person Y";
    cout << person1.name << " " << person1.age <<  endl;

    cout << person3.name << endl;
    Person person2{"AndresX", 34};
    passRef(person2);
    cout << "person2 name is " << person2.name << endl;

    vector<int> v = {10, 12, 6, 4};

    for(const int& elem: v) {
        
    }

    int myArr[4];
    myArr[2] = 56;

    const int a = 1;
    static_assert(a != 0, "Fatal error, the variable is zero");

    cout << myArr[2] << endl;
}

class Example {
    Example() = default;
    const void doSome() const;

    int operator +(int x);
    operator bool();
};

const void Example::doSome() const
{

}

int Example::operator+(int x) 
{
    return x + 1;
}

Example::operator bool()
{
    return true;
}

class Base { 
    public:
    int length;
    unique_ptr<int> aPointer;

    virtual void dummy() {
        cout << "Base dummy" << endl;
    }

    Base() = default;

    explicit Base(unique_ptr<int> aPointer) : aPointer(std::move(aPointer))
    {

    }

    //conversion constructor. The rule of thumb os to make them explicit to avoid hard to find bugs!
    Base(double payment) {
        cout << "inside Base payment constructor" << endl;
    }

    Base(string name) 
    {

    }

    virtual Base& operator + (const Base& base)
    {   
        //Base newBase;
        //newBase.length = this->length + base.length;
        this->length += base.length;
        return *this;
    }

    void setLength(int pLength)
    {
        length = pLength;
    }

    //this is a conversion function
    virtual operator bool() 
    {
        cout << "bool conversion function called" << endl;
        return false;
    }

};
class Derived : public Base { 
    int a; 

    public:
    virtual void dummy () override {
        
        cout << "Derived dummy" << endl;  
    }

    
};
class OtherDerived: public Derived { 
    
    
    public:
    void dummy() override{
        
        cout << "OtherDerived dummy" << endl;  
    }

   
};

struct AddX 
{
    int x;
    AddX(int x) : x(x) {}

    //this is a functor (function object)
    int operator () (int y)
    {
        return x + y;
    }

    //this is a functor (function object)
    int operator () (int y, int z)
    {
        return y + z;
    }
};

//constant expression that is evaluated at compile time
constexpr int square(int x) 
{
   
    return x * x;
}

int& goo()
{
    int l = 1;
    return l;
}

void testConvConstructor(Base base)
{

}

void testConvFunction(bool pValue)
{

}

void foo(Base& base) 
{
    cout << "foo with lvalue" << endl;
}

void foo(Base&& base)
{
    cout << "foo with rvalue" << endl;
}

template<typename T, typename Arg>
unique_ptr<T> factory(Arg&& arg)
{
    return unique_ptr<T>(new T(std::forward<Arg>(arg)));
}

//template aliases
using Xtring = std::string;

template<typename T>
using Patacon = std::vector<T>;

template<typename S>
void testUniversalReference(S&& s)
{
    cout << "Universal reference? " << is_same<int&, decltype(s)>::value <<  endl;
}

template<typename S>
void testArrayTemplate(S& s)
{
    cout << "Are the same? " << is_same<const int(&)[3], decltype(s)>::value <<  endl;
    //if we remove the & from the parameter of this function (pass it by value), an array will be deduced as a pointer
    //cout << "Are the same? " << is_same<const int*, decltype(s)>::value <<  endl;
}

unique_ptr<int> createUniquePtr(int param)
{
    unique_ptr<int> ptr = make_unique<int>(param);
    return ptr;
}

void f1(unique_ptr<Base> ptr)
{

}

template<typename PtrType>
void testNull(PtrType ptrType)
{
    f1(ptrType);
}

template<typename T>
void testTemplateReference(T& param)
{
    cout << "Reference: Type of T " << typeid(param).name() << endl;
    //static_assert(is_same<const int&, decltype(param)>::value, "are not the same");
}

template<typename T>
void testTemplatePointer(T* param)
{
    cout << "Pointer: Type of T " << typeid(param).name() << endl;
    //static_assert(is_same<const int&, decltype(param)>::value, "are not the same");
}


template<typename T>
void testTemplateUR(T&& param)
{
    cout << "Universal Reference: Type of T " << typeid(param).name() << endl;
    //static_assert(is_same<const int&, decltype(param)>::value, "are not the same");
}

template<typename T>
void testTemplateValue(T param)
{
    cout << "Value: Type of T " << typeid(param).name() << endl;
    //static_assert(is_same<int, decltype(param)>::value, "are not the same");
}

void printArgs(int& a, bool&& b)
{
    cout << "1. printArgs" << endl;
}

void printArgs(int&& a, bool &b, string c)
{
    cout << "2. printArgs" << endl;
}

template<typename... Args>
void testVariadic(Args&&... args)
{
    printArgs(forward<Args>(args)...);
}

int asyncSum(int x, int y)
{
    cout << "calculating sum..." << endl;
    return x + y;
}


void doTest6()
{
    const int aVar = 0;
    const int* aVarPointer = &aVar;
    
    //type deduced is const int&
    testTemplateReference(aVar);
    //type deduced is const int*
    testTemplateReference(aVarPointer);
    //this does not compile because an rvalue cannot bind to a T&, it binds to a const T&
    //testTemplateReference(10);


    //this does not compile because the lvalue int aVar does not match with T*
    //testTemplatePointer(aVar);
    //type deduced is const int*
    testTemplatePointer(aVarPointer);
    //this does not compile because the rvalue 10 does not match with T*
    //testTemplatePointer(10);

    //type deduced is int. by being only T, it removes constness, volatileness and referenceness!
    testTemplateValue(aVar);
    //type deduced is const int*. For pointers, the type deduced never removes anything
    testTemplateValue(aVarPointer);
    testTemplateValue(10);

    BitfieldTest bitFieldTest;
    bitFieldTest.a = 8;

    cout << "Bitfield test a: " <<  bitFieldTest.a << endl;

    int arg1 = 2;
    bool arg2 = true;
    string arg3 = "hello";
    testVariadic(2, arg2, arg3);

    //the function passed could also be a lambda
    std::future<int> fut = std::async(std::launch::async, asyncSum, 1, 2);
    cout << "checking sum..." << endl;
    int futResult = fut.get();
    cout << "sum is: " << futResult << endl;

    const std::vector<int> intVector1 {1, 2, 3};
    //this will not compile cause intVector1 is const
    //intVector1.push_back(1);

    //this compiles because f1 is being called directly, there is no type deduction
    f1(0);
    f1(NULL);

    //this does not compile because the function template deduces type of 0 and NULL as int / integral type and f1 is expecting a unique_ptr<Base>
    //testNull(0);
    //testNull(NULL);
    
    testNull(nullptr);

    int ur = 24;
    //the type deduction here will be int&
    testUniversalReference(ur);
    testUniversalReference(30);
    
    //this will not compile because there is no type deduction when explicitly specifying the type <int>.
    //S&& is replaced explicitly to int&& which is an rvalue
    //testUniversalReference<int>(ur);

    const int myArray[] = {1, 2, 3};
    testArrayTemplate(myArray);

    int w = 0;
    int z = 1;
    int* const pw = &w;
    *pw = 2;

    const int theAnswer = 42;
    const int& refTheAnswer = theAnswer;
    
    //auto will deduce the const and * only if it is initialized as a pointer!
    auto pTheAnswer = &theAnswer;
    
    static_assert(is_same<const int*, decltype(pTheAnswer)>::value, "NOT the same");

    cout << "about to move unique_ptr" << endl;
    unique_ptr<Animal> uniAni = make_unique<Animal>();
    //does not call the move constructor of Animal, only the move constructor of unique_ptr
    unique_ptr<Animal> uniAni2 = std::move(uniAni);
    cout << "unique_ptr moved" << endl;

    unique_ptr<int> intPointer = make_unique<int>(20);

    Base newBase(make_unique<int>(20));
    Base otherBase = Base(std::move(intPointer));

    unique_ptr<int[]> intArrPtr = make_unique<int[]>(5);
    intArrPtr[0] = 1;

    shared_ptr<int> otherPtr = createUniquePtr(10);
    cout << "unique_ptr: " << *otherPtr << endl;

    shared_ptr<Derived> der = make_shared<Derived>();
    cout << "ref count der before move: " << der.use_count() << endl;
    shared_ptr<Base> bas = der;
    cout << "ref count bas before move: " << bas.use_count() << endl;

    //moving a shared_ptr is faster than copying it because no atomic ref count operations are done
    shared_ptr<Base> bas1 = std::move(bas);

    if(bas == nullptr)
    {
        cout << "bas is null" << endl;
    }

    cout << "ref count der after move: " << der.use_count() << endl;
    cout << "ref count bas after move: " << bas.use_count() << endl;
    cout << "ref count bas1 after move: " << bas1.use_count() << endl;

    int pat1 = 0;
    Patacon<decltype(pat1)> pat;
    Xtring h = "sdf";    
    Base b12;
    foo(b12);
    //calls the conversion constructor
    testConvConstructor(44.5);
    
    //calls the conversion constructor
    Base base30 = 13.4;

    std::array<int, square(2)> arrayY;

    const int n = 3;
    constexpr const int *np = &n;

    //this is valid because goo() is an lvalue
    goo() = 42;

    //if np is not constexpr the following line will not compile: "expression did not evaluate to a constant"
    int arrayX[*np];

    Base* base1 = new OtherDerived();
    base1->dummy();
    delete base1;

    Base base2;
    base2.length = 4;
    Base base3;
    base3.length = 5;
    //Base base4 = base3 + base2;
    base3 + base2;
    //cout << "base4 length: " << base4.length << endl;
    cout << "base3 length: " << base3.length << endl;
    cout << "base2 length: " << base2.length << endl;

    Base* base5 = new Base();

    unique_ptr<Base> ubase5(base5);

    vector<unique_ptr<Base>> list;
    //in order to guarantee that the ownership of base5 is only one, we have to move it instead oc copying it
    list.push_back(std::move(ubase5));

    const Base b1;
    Base* b2 = const_cast<Base*>(&b1);
    b2->setLength(3);
    //b1.setLength(3); //this does not compile because b1 is const and there is no reference qualifier const overload
    //for setLength()
    //b1.length = 3; //this compiles if length is mutable
    cout << "b1.length " << b1.length << endl;
    cout << "b2->length " << b2->length << endl;
    //Base* base2 = new Base();
    //I cannot cast a based to a derived or vice versa, if base does not have one virtual method as minimum
    //Derived* derived1 = dynamic_cast<Derived*>(base1);

    vector<int> in = {1, 2, 3};
    vector<int> out(in.size());
    AddX add1 = AddX(1);
    
    //here the overloading of () with 1 parameter is invoked. Instead of add1 this lambda works too [](int x){ return x + 1;}
    std::transform(in.begin(), in.end(), out.begin(), add1);
    for(auto element : out)
    {
        cout << "out element is " << element << endl;
    }
    //here the overloading of () with 2 parameters is invoked
    std:transform(in.begin(), in.end(), out.begin(), out.begin(), add1);

    for(auto it = out.begin(); it != out.end(); it++)
    {
        cout << "out element is " << *it << endl;
    }

    Base *base = new Base();
    testConvFunction(*base);

   
    auto comparatorFn = [](string a, string b) {
        
        return a > b;
    };
    //construct a map with a comparator function
    map<string, int, std::function<bool(string, string)>> map1(comparatorFn);

    map1["xyz"] = 4;
    map1["gio"] = 2;
    map1["agustin"] = 1;
    map1["gloria"] = 3;

    for(auto& pair : map1) 
    {
       cout << pair.first << " = " << pair.second << endl;
    }

    //get comparator function
    auto compFn = map1.key_comp();
    cout << typeid(compFn).name() << endl;
    
    if(compFn("1", "-1"))
    {
        cout << "true" << endl;
    } 
    else 
    {
        cout << "false" << endl;
    }
    
    map<string, int> map2 (map1.begin(), map1.end());
    for (auto it = map2.begin(); it != map2.end(); it++)
    {
        cout << it->first << " = " << it->second << endl;
    }

    Animal anim1;
    factory<Animal>(Animal{});

    std::vector<bool> features = {false, true, true};
    auto feature1 = features[0];

    std::vector<int> numbers = {1, 2, 3};
    auto number = numbers[0];
    cout << "Type of feature: " << typeid(feature1).name() << endl;
    cout << "Type of number: " << typeid(number).name() << endl;
    
    
}

template<typename A>
decltype(auto) sum(A a, A b) 
{
    return (a + b);
}

//an auto return type is possible in C++ 14
auto multiplyByOne (int i = 0)
{
    return i * 1;
}
void testCpp14()
{

    int x = 0;    
    int countCycles = 0;
    int countInvokes = 0;
    int *pCountCycles = &countCycles;
    //std::optional<string> myOpt = "Hello";
    //only for lambdas a parameter can be of type auto, but it cannot be defaulted to a value unless the type is explicit
    //the initializing expression is evaluated when lambda is created, NOT when is invoked
    //the capture variables mantain state inside the lambda, like an attribute of an object
    //x in the initializer is totally different than the x declared above
    //mutable lets us modify any parameter passed by value or any initializer variable like x
    auto generator = [x = multiplyByOne(0), &countInvokes1 = countInvokes, pCountCycles] (auto data) mutable -> auto
    {
        countInvokes1++;

        //because pCountCycles is a pointer, the lambda does not need to be mutable to modify the content of such pointer
        if(x == data.size())
        {
            (*pCountCycles)++;

            //if the lambda was not mutable, there would be a compiler error when trying to modify x
            x = 0;
        }
        return data[x++];
    };

    std::vector<string> data = {"agus", "gloria", "kevin"};
    cout << generator(data) << endl;
    cout << generator(data) << endl;
    cout << generator(data) << endl;
    cout << generator(data) << endl;
    cout << "number of cycles: "<< *pCountCycles << endl;
    cout << "number of invokes: " << countInvokes << endl;
    
    auto up = std::make_unique<int>(13);
    *up = 10;
    int a = 0;
    int* b = &a;

    auto lambda1 = [b, &up] () {
        
        //raw pointers can be modified with just passing them by value in the capture
        *b = 10;
        
        //this has to be passed as reference or else this will not compile
        *up = 21;

    };
    
    cout << "up:" << *up << endl;
    lambda1();
    cout << "up:" << *up << endl;

    int res = [](int a)
    {
        return a * a;
    }(2);

    //in C++ 14 you can put auto as the return type for a lambda and for a function
    decltype(auto) result = []() -> auto&&
    {
        //int f = 5;
        return 5;
    }();

    static_assert(is_same<int&&, decltype(result)>::value, "Not the same");

    //decltype(auto) captures not only the type but also the reference, constness and volatileness
    const int d = 0;
    decltype(auto) d1 = d; //const int

    const int&& e = 0;
    decltype(auto) e1 = std::move(e); //const int&&

    static_assert(is_same<const int&&, decltype(e1)>::value, "not the same e");

    string f = "h";
    string& f1 = f;
    decltype(auto) f2 = f1;
    volatile int special = 20;
    decltype(auto) special1 = special;

    static_assert(std::is_same<volatile int, decltype(special1)>::value, "not the same int");
    static_assert(std::is_same<string&, decltype(f2)>::value, "not the same string");

    cout << sum(1, 4) << endl;

}

class Node 
{
public:
    string name;
    std::array<int, 2> point;
};

void testCpp17()
{
    auto person = std::make_tuple(34, "Gioooo", false, "JavaScript");
    const auto [age, name, isSingle, languageSkill] = person;

    //Node is an aggregate class: the members are public, no user defined constructors, no virtual functions
    Node node = {"TheNode", {8, 5}};
    auto [nodeName, point] = node;
    cout << nodeName << endl;
    cout << point[0] << ", " << point[1] << endl;
}

namespace Weapons {
    class Weapon
    {
    
    public:
    
        //any attribute that is not copyable will make the compiler to NOT generate the default copy constructor
        //because unique_ptr is not copyable (only movable), the compiler will not generate an implicit copy constructor for Weapon class
        //in order for this to work you will have to define copy constructor
        //unique_ptr<int> intPtr;
    
        virtual void fire()
        {
            cout << "Firing Weapon" << endl;
        }
    
        Weapon() 
        {
            cout << "Weapon constructor" << endl;
        }
    
        Weapon(const Weapon& weapon) {
            cout << "Weapon Copy Constructor" << endl;
        }

        ~Weapon()
        {
            cout << "Weapon destructor" << endl;
        }
    
    };
    
    class Pistol : public Weapon
    {
    
    public:

        virtual void fire() override
        {
            cout << "Firing Pistol" << endl;
        }
    };

    namespace Version1 
    {
        void printVersion()
        {
            cout << "Version is 1" << endl;
        }
    }

    inline namespace Version2 
    {
        void printVersion()
        {
            cout << "Version is 2" << endl;
        }

        void test()
        {

        }
    }
}

template <typename T>
struct UniqueResult
{
    using scalar = unique_ptr<T>;
};

template <typename T>
//we have to put typename here because UniqueResult<T> is dependend on T
typename UniqueResult<T>::scalar createUnique()
{
    return unique_ptr<T>(new T());
}

class Building
{
public:
    
    Building()
    {
        cout << "Building constructor" << endl;
    }

    constexpr Building(int x)
    {

    }
    void print()
    {
        cout << "Building print" << endl;
    }

    void print(int x)
    {
        cout << "Building print: " << x << endl;
    }

    virtual ~Building()
    {
        cout << "Destructing building " << endl;
    }
};

class House : public Building
{
public:
   
    void print(int x)
    {
        cout << "House print:" << x << endl;
        
    }
    ~House()
    {
        cout << "Destructing House" << endl;
    }
};

void testDef()
{
    cout << "1" << endl;
   
}

void testDef(int a = 0)
{
    cout << "2" << endl;
}

template<typename T>
T compare(T x, T y)
{
    return x>y? x : y;
}

int& testStatic2()
{
    static int x = 3;
    return x;
}

int testStatic1()
{
    //this will mantain state because is static
    static int i = 5;
    return ++i;
}

int* testStatic3()
{
    static int i = 4;
    //(*(&i))++;
    return &i;
}

void doTest7()
{

    *testStatic3() = 5;
    cout << *testStatic3() << endl;


    testStatic2() = 8;
    cout << testStatic2() << endl; //prints 8

    //this will not compile because T would be float and int, that is ambiguous
    //compare(4.5, 2);
    cout << testStatic1();
    cout << testStatic1();
    cout << testStatic1() << endl;


    Weapons::Version1::printVersion();
    Weapons::test();

    using namespace Weapons;

    //this will call the Weapon copy constructor
    Weapon weapon = Pistol();
    //this will invoke Weapon::fire() because weapon is a plain object (not a pointer nor a reference) this is known as slicing
    weapon.fire();
    
    Weapon& other = Pistol();
    //this will invoke Pistol::fire() because other is a reference
    other.fire();

    //this will invoke Pistol::fire() becasue otherW is a pointer
    unique_ptr<Weapon> otherW = make_unique<Pistol>();
    otherW->fire();

   
    char hex[] = "\x61\x62";
    wchar_t longHex[] = L"\x0061";
    char binary[] = {0b1100001, 0b1100010};
    char octal[] = "\141\142";

    int intBinary = 0b01100001;
    
    /*
    \x is a escape sequence for hex digits. Each hex digit occupies 4 bits. That is why we can only store 
    2 hex digits in a char (char is 1 byte). \ is the escape sequence for octals

    wchar_t is 2 bytes so we can put 4 hex digits inside a wchar_t
    */
    cout << "hex: " << hex[0] << endl;
    cout << "longHex: " << longHex[0] << endl;
    cout << "longHex cast to char: " << static_cast<char>(longHex[0]) << endl;
    cout << "binary: " << binary[0] << endl;
    cout << "octal: " << octal[0] << endl;
    cout << "intBinary: " << intBinary << endl;

    int i = 5;
    int* p = &i;
    int* z = &*p;

    int a = 4;
    a = ++a + a++;
    cout << "a is " << a << endl;

    int b = 5;

    b = b + ++b + ++b;

    cout << "b is " << b << endl;

    int var1 = 6, var2 = 4, var3 = 7, q;
    //it will assign q with the last variable
    q = (var3, var2, var1);
    cout << "q: " << q << endl;

    int n = 9;

    int result = 0;
    for(int i = 0; i <= n; i++)
    {
        result += pow(2, i);
    }


    //sumatory of 2^x where (0 <= x <= n); plus 1 is always equal to 2^(n+1)  
    cout << "result :" << result + 1<< endl;
    cout << "2^(n+1): " << pow(2, n+1) << endl;

    class Empty{
        int abc;
        char a1;
    };

    cout << "size of Empty: " << sizeof(Empty) << endl;

    //this will not compile because it is ambiguous. If the invocation is never made, it compiles both overloadings
    //of testDef function
    //testDef();

    //the parent class destructor must be virtual if we want to be able to invoke child destructor by deleting
    //it through a parent variable
    Building* building = new House();
    delete building;
    
    {
        /*
        - When executing House(), the Building constructor is invoked
        - When assigning House() to build1, the copy constructor of Building is called
        - The Building destructor is called when House() gets destroyed
        - The Building destructor is called again when build1 (which is copy) gets destroyed
        */
        Building build1 = House();
    }

    //A derived class inherits the exact same (no overriding) functions from the father ONLY if 
    //the derived class has not defined the functions with same names as the father's
    House house;
    house.print('a');
    //this will not compile because the derived class defined function with same name as parent ("print") but with 
    //an argument. In order for this to compile: 1. all print functions in House must be deleted or 2. define the
    //print() function without arguments in House class as well
    //house.print();

    //this will not compile because Building has a user defined destructor and build1 is a constexpr 
    //constexpr Building build1(10);

    Building build2(20);

    constexpr int matrix[2][3] = {1, 2, 3, 4, 5};
    //this matrix has exactly the same data as previous one
    //constexpr int matrix[2][3] = { {1,2,3}, {4,5} };
    /*
    1 2 3
    4 5 0
    */
    static_assert(matrix[0][0] == 1, "not same");
    static_assert(matrix[0][1] == 2, "not same");
    static_assert(matrix[0][2] == 3, "not same");
    static_assert(matrix[1][0] == 4, "not same");
    static_assert(matrix[1][1] == 5, "not same");
    static_assert(matrix[1][2] == 0, "not same");
   
    constexpr int rows = 2;
    constexpr int columns = 3;
    constexpr int size = rows * columns;
    int arrayFromMatrix[size];

    static_assert(0 % 3 == 0, "invalid");
    static_assert(1 % 3 == 1, "invalid");
    static_assert(2 % 3 == 2, "invalid");
    static_assert(3 % 3 == 0, "invalid");

    //fill an unidimensional array from a matrix
    for(int i = 0; i < size; i++)
    {

        int column = i % columns;
        int row = i / columns;
        arrayFromMatrix[i] = matrix[row][column];
    }
    
    //given a row and a column from the matrix, calculate the equivalent index in the unidimensional array
    //a constexpr lambda is a feature of c++ 17. 
    constexpr auto calculateIndex = [columns, rows](int row, int column)
    {   
        return (row*columns) + column*(rows-1);
    };

    //If we only put constexpr between ) and { of a lambda this static assert will not compile (unless the 
    //operations inside the lambda are only with the parameters, not the capture variables)
    //If we only put constexpr before the auto of lambda this static assert will compile
    static_assert( calculateIndex(0, 0) == 0, "not same");
    

    cout << "0,0: " << arrayFromMatrix[calculateIndex(0,0)] << endl;
    cout << "0,1: " << arrayFromMatrix[calculateIndex(0,1)] << endl;
    cout << "0,2: " << arrayFromMatrix[calculateIndex(0,2)] << endl;
    cout << "1,0: " << arrayFromMatrix[calculateIndex(1,0)] << endl;
    cout << "1,1: " << arrayFromMatrix[calculateIndex(1,1)] << endl;
    cout << "1,2: " << arrayFromMatrix[calculateIndex(1,2)] << endl;
    
    
    int myArr1[] = {1, 2, 3};
    
    int *pArr1 = myArr1;
    cout << "*pArr1: " << *pArr1 << endl; 
}



int main() {
        
    //doTest1();
    //doTest2();
    //doTest3();
    //doTest4();
    //doTest5();
    //doTest6();
    doTest7();
    //testCpp14();
    //testCpp17();
    system("pause");
    
    return 0;
}