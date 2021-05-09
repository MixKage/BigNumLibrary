#include <iostream>
//#include <algorithm>
#include "bignum.h"
//#include "C:\Users\user\Documents\Программирование\C++\Library\BigNumLib\include\src\BigNumLib.h"
using namespace std;

int main()
{
	//Example 1
	/*bignum a;
	bignum c = "43";
	bignum b = "32";
	c = b = a;
	if (a == b)
		cout << true;
	else
		cout << false;*/
		//Example 2
		/*bignum a1 = "3g";
		if (!a1.isNum()){
			cout << "it is num!" << endl;}*/
			//Example 3
			/*bignum num1 = "32313131312331";
			bignum num2 = "43312312313123123";
			bignum answer = num1 + num2;
			cout << answer;*/
			//Example 4
		/*bignum notNum = "345536835782368538532528823828237853285343248784553245258623853643258435234438482842384238423543223485385324346823645624356432853832486524684532423784256823456524352652368237853245326823675234532494282345726358239658234632645823645364872384568236458237658365834656328956238956384756923865832764583624587324856395762876582365873645872364956984528364526834653268563286582365872364596238956923865823659236583268563289568239569238659368236587325682396592386592365923865923865823658239659238569238659238652839658268268365";
		bignum aNum="345536835782368538532528823828237853285343248784553245258623853643258435234438482842384238423543223485385324346823645624356432853832486524684532423784256823456524352652368237853245326823675234532494282345726358239658234632645823645364872384568236458237658365834656328956238956384756923865832764583624587324856395762876582365873645872364956984528364526834653268563286582365872364596238956923865823659236583268563289568239569238659368236587325682396592386592365923865923865823658239659238569238659238652839658268268365";
		if (notNum != aNum)
			cout << "!=" << endl;
		else
			cout << "==" << endl;*/
			//Example 5
			/*bignum NUM1 = "-322";
			bignum NUM2 = "-321";
			if (NUM1 >= NUM2)
				cout << "1" << endl;
			else
				cout << "0" << endl;*/
				//Example 6
				/*bignum Num_1;
				cout << Num_1 << endl;
				cin >> Num_1;
				cout << Num_1 << endl;*/
				//Example 7
				//Цикл фор
	/*while (true) {
		bignum num1;
		bignum num2 = "-44";
		cin >> num1;
		if (num1 > num1)
			cout << "HEY";
		else
			cout << "NO";
	}*/

	/*while (true) {
		bignum num1;
		bignum num2;
		char op;
		cout << "Enter the num1: ";
		cin >> num1; cin.ignore();
		cout << "Enter the operator: ";
		cin >> op; cin.ignore();
		cout << "Enter the num2: ";
		cin >> num2; cin.ignore();
		if(op=='+')
		{
			cout << num1 + num2 << endl;
		}
		else if(op=='-')
		{
			cout << num1 - num2 << endl;
		}
		else if(op=='<')
		{
			if (num1 < num2)
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
		else if(op=='>')
		{
			if (num1 > num2)
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
		else if(op=='=')
		{
			if(num1==num2)
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
		else
		{
			break;
		}

		/*try { auto num3 = num1 - num2; cout << "Answer: " << num1 << " - " << num2 << " = " << num3 << endl; }
		catch (const exception& e)
		{
			cerr << e.what() << endl;
		}*/
		//	}
	bignum a = 10;
	cout << a.getValueInt();
	bignum b = 9223372036854775807;
	cout << b.getValueInt();

	for(long long int i = 9223372036854775807; i>0 ;i--)
	{
		a = std::to_string(i);
		a.getValueInt();
		cout << "i: " << i << " - a: " << a << endl;
	}
	return 0;
}