#include <iostream>
using namespace std;

class clsCalculator
{
private:

	float _LastNumber = 0;
	string _LastOperation = "Clear";
	float _PreviousResult = 0;
	float _Result = 0;

	bool _IsZero(int Number)
	{
		return Number == 0; 
	}

public:
	void Clear()
	{
		_LastOperation = "Clear";
		_LastNumber = 0;
		_PreviousResult = _Result;
		_Result = 0;
	}

	void Add(float N)
	{
		_LastNumber = N;
		_PreviousResult = _Result;
		_LastOperation = "Adding";
		_Result += N;
	}

	void Subtract(float N)
	{
		_LastNumber = N;
		_PreviousResult = _Result;
		_LastOperation = "Subtracting";
		_Result -= N;
	}

	void Multiply(float N)
	{
		_LastNumber = N;
		_PreviousResult = _Result;
		_LastOperation = "Multiplying";
		_Result *= N;
	}

	void Divide(float N)
	{
		if (_IsZero(N))
		{
			N = 1;
		}

		_LastNumber = N;
		_PreviousResult = _Result;
		_LastOperation = "Dividing";
		_Result /= N;
	}

	void CancelLastOperation()
	{
		_LastOperation = "Cancel Last Operation";
		_Result = _PreviousResult;
	}

	void PrintResult()
	{
		cout << "Result after " << _LastOperation << " " << _LastNumber <<
			" is: " << _Result << endl;
	}

	float Result()
	{
		return _Result;
	}
};

int main()
{
	clsCalculator Calc;

	Calc.Clear();

	Calc.Add(30);
	Calc.PrintResult();

	Calc.Subtract(10);
	Calc.PrintResult();

	Calc.Multiply(100);
	Calc.PrintResult();

	Calc.Divide(10);
	Calc.PrintResult();

	Calc.CancelLastOperation();
	Calc.PrintResult();

	return 0;
}
