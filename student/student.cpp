#include <iostream>
#include <conio.h>
using namespace std;

class Student
{
private:
	string ht;
	float dk1, dk2, dtb;
public:
	Student(string ht = "n", float dk1 = 0, float dk2 = 0);
	void diemtb()
	{
		dtb = (dk1 + 2 * dk2) / 3;
	}
	void nhap();
	void xuat();
	friend int operator > (Student s1, Student s2);
};

Student::Student(string ht1, float dk11, float dk21)
{
	ht = ht1;
	dk1 = dk11;
	dk2 = dk21;
	diemtb();
}

void Student::nhap()
{
	cout << "\nNhap ho ten: "; cin >> ht;
	cout << "Nhap diem ki 1: "; cin >> dk1;
	cout << "Nhap diem ki 2: "; cin >> dk2;
	diemtb();
}

void Student::xuat()
{
	cout << "\nHo ten: " << ht << ", diem ki 1: " << dk1
		<< ", diem ki 2: " << dk2 << ", diem trung binh: " << dtb;
}

int operator> (Student s1, Student s2)
{
	return (s1.dtb > s2.dtb);
}

int main()
{
	int i, j, n = 5;
	Student* s = new Student[n];
	for (i = 0; i < n; i++)
		s[i].nhap();
	cout << "\nHien thi danh sach vua nhap: ";
	for (i = 0; i < n; i++)
		s[i].xuat();

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (!(s[i] > s[j]))
			{
				Student s1 = s[i];
				s[i] = s[j];
				s[j] = s1;
			}
	cout << "\n\nDanh sach sau khi sap xep: ";
	for (i = 0; i < n; i++)
		s[i].xuat();

	return 0;
}