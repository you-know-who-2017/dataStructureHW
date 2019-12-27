<!--
 * @Description: 
 * @Author: you-know-who-2017
 * @Github: https://github.com/you-know-who-2017
 * @Date: 2019-12-28 00:00:32
 * @LastEditors  : you-know-who-2017
 * @LastEditTime : 2019-12-28 00:00:32
 -->
## 顺序表

### 7-1 集合的并,交,差

以下是集合的类模板定义和主函数测试：

```java
template < typename T , int MaxSize>
class SeqSet {
T data [ MaxSize ];
int length; //集合中元素的个数
int Locate(T item); //按值查找，求集合中值为item的元素序号
void Insert(int i, T item); //在集合第i个位置插入值为item的元素
T Delete(int i); //删除集合的第i个元素
public:
SeqSet( ); //无参构造函数
SeqSet(T a[], int n); //有参构造函数
void PrintSeqSet(); //遍历集合，按序号依次输出各元素
void Union(SeqSet &set); //求并集
void Intersection(SeqSet &set); //求交集
void Difference(SeqSet &set); //求差集
};

int main(){
int a[10],i;
for (i=0; i<10; i++)

cin>>a[i];
int b[10];
for (i=0; i<10; i++)

cin>>b[i];
SeqSet < int,100 > s1(a,10),s2(b,10);
s1.Union(s2);
s1.PrintSeqSet();
SeqSet < int,100> s3(a,10),s4(b,10);

s3.Intersection(s4);
s3.PrintSeqSet();
SeqSet < int,100 > s5(a,10),s6(b,10);
s5.Difference(s6);
s5.PrintSeqSet();
return 0;
}
```

请完成集合类模板的各成员函数的定义。



## 7-2数组元素循环左移p位

```java
template < class T, int MaxSize> //类模板
class SeqList
{
T data[MaxSize]; //用于存放数据元素的数组
int length; //顺序表中元素的个数
public:
SeqList( ); //无参构造函数
void PrintSeqList(); //遍历顺序表，按序号依次输出各元素
void Insert(int i, T item); //在顺序表第i个位置插入值为item的元素
void LeftMove(int p) ; //将顺序表循环左移p位
void reverse(int b,int e); //将顺序表逆序
};
template < class T,int MaxSize>
SeqList< T,MaxSize>::SeqList(){ length=0; }
template < class T,int MaxSize>
void SeqList< T,MaxSize>::PrintSeqList(){
int i;
for (i=0; i<length-1; i++)
cout<<data[i]<<" ";
cout<<data[i]<<endl; }

int main(){
SeqList< int,1000> s1;
int n;
cin>>n;
for (int i=1; i<=n; i++)
s1.Insert(i,i);
int p;
cin>>p;
s1.LeftMove(p);
s1.PrintSeqList();
return 0;
}
```

