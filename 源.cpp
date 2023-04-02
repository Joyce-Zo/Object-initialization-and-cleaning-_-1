#include<iostream>
using namespace std;

// 构造函数与析构函数 - 初始化和销毁
//class person
//{
//public:
//	person()
//	{
//		cout << "person_构造函数的调用" << endl;
//	}
//
//	~person()
//	{
//		cout << "person_析构函数的调用" << endl;
//	}
//};
//
//void test1()
//{
//	person p; // 栈上的数据，test1执行完毕后，释放这个对象
//}
//int main()
//{
//	//test1();
//
//	person p;
//	return 0;
//}

// 分类与调用
//class person
//{
//public:
//	// 有无参构造
//	person()
//	{
//		cout << "person_无参构造函数的调用" << endl;
//	}
//	person(int a)
//	{
//		age = a;
//		cout << "person_有参构造函数的调用" << endl;
//	}
//	
//	// 拷贝构造
//	person(const person& p) // 不可修改原构造函数，所以加const
//	{
//		age = p.age;
//		cout << "person_拷贝构造函数的调用" << endl;
//	}
//
//	~person()
//	{
//		cout << "person_析构函数的调用" << endl;
//	}
//
//	int age = 21;
//};
//
//// 调用
//void test1()	
//{
	 //括号法
	//person p1;	 // 无参构造函数 的调用 名称后不加括号
	//person p2(5);  // 有参构造函数 的调用
	//person p3(p2); // 拷贝构造函数 的调用

	//cout << p2.age << endl;
	//cout << p3.age << endl; // p2的age也传给p3，所以结果相同

	// 注意：
	//person p1();
	//
	//void func();

	// 显式法
	//person p1; // 无参
	//person p2 = person(5); // 有参
	//person p3 = person(p2);// 拷贝

	//person(5); // 匿名对象，当前行执行完，其立即倍被系统销毁
	//cout << "444" << endl;

	//person(p3);


	// 隐式转换法
//	person p4 = 10;  // 等价于person p4 = person(10); 有参构造
//	person p5 = p4;  // 拷贝构造
//}
//int main()
//{
//	test1();
//	return 0;
//}

// 拷贝构造函数的调用时机
//class person
//{
//public:
//	person()
//	{
//		cout << "person默认构造函数调用" << endl;
//	}
//	person(int age)
//	{
//		m_age = age;
//		cout << "person有参构造函数调用" << endl;
//	}
//	person(const person& p)
//	{
//		m_age = p.m_age;
//		cout << "person拷贝构造函数调用" << endl;
//	}
//
//	~person()
//	{
//		cout << "person析构函数调用" << endl;
//	}
//
//	int m_age;
//};

// 1.使用一个已经创建完毕的对象来初始化一个新对象
//void test01()
//{
//	person p1(50);
//	person p2(p1);
//	
//	cout << "p2的年龄为:" << p2.m_age << endl;
//}
//
//// 2.值传递方式给函数参数传参
//void func(person p)
//{
//	;
//}
//void test02()
//{
//	person p; // 默认构造函数
//	func(p); // 拷贝构造函数
//}
//
//// 3.值的方式返回局部对象
//person func2()
//{
//	person p1; // 默认构造函数
//	cout << &p1 << endl;
//	return p1; // 返回 值
//}
//void test03()
//{
//	person p2 = func2();// 接收后，成为拷贝构造函数
//	cout << &p2 << endl;
//}
//int main()
//{
//	//test01();
//	//test02();
//	test03();
//
//	return 0;
//}

// 构造函数调用规则
//class person
//{
//public:
//	/*person()
//	{
//		cout << "person默认构造函数调用" << endl;
//	}*/
//	/*person(int age)
//	{
//		m_age = age;
//		cout << "person有参构造函数调用" << endl;
//	}*/
//	person(const person& p)
//	{
//		m_age = p.m_age;
//		cout << "person拷贝构造函数调用" << endl;
//	}
//
//	~person()
//	{
//		cout << "person析构函数调用" << endl;
//	}
//
//	int m_age;
//};

////void test01()
////{
////	person p1;
////	p1.m_age = 10;
////
////	person p2(p1);
////	cout << p2.m_age << endl;	
////}
//void test02()
//{
//	person p1(22);
//	person p2(p1);
//	cout << p2.m_age << endl;
//}
//void test03()
//{
//	person p1; // 默认构造函数
//	person p2(10); // 有参构造函数
//}

//int main()
//{
//	test01();
//	test03();
//	return 0;
//}

// 深拷贝与浅拷贝问题
class person
{
public:
	person()
	{
		cout << "person默认构造函数调用" << endl;
	}
	person(int age, int height)
	{
		m_age = age;
		m_height = new int(height);
		cout << "person有参构造函数调用" << endl;
	}
	person(const person& p)
	{
		m_age = p.m_age;
		//m_height = p.m_height; //编译器默认实现，即浅拷贝
		m_height = new int(*p.m_height);
		cout << "person拷贝构造函数调用" << endl;
	}

	~person()
	{
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "person析构函数调用" << endl;
	}

	int m_age;
	int* m_height;
};

void test01()
{
	person p1(22,179);
	cout << "年龄为" << p1.m_age << "身高为" << *p1.m_height << endl;

	person p2(p1);
	cout << "年龄为" << p2.m_age << "身高为" << *p2.m_height << endl;
}

int main()
{
	test01();

	return 0;
}