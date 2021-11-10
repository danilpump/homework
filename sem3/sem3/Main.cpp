#include "tbitfield.h"

int main()
{
	int N = 20;
	TBitField bitField(N);
	cout << "TbitField tests:" << "\n" << endl;

	cout << "bitField.GetLength(). Expected: " << N << " , Actual: " << bitField.GetLength() << "\n" << endl;

	TBitField bitField2(bitField);
	cout << "bitField2 == bitField. Expected: " << true << " , Actual: " << (bitField2 == bitField) << "\n" << endl;

	for (int i = 0; i < N / 2; i++) 
	{
		bitField.SetBit(i * 2);
		bitField.ClrBit(i * 2 + 1);
	}
	cout << "bitField2 == bitField. Expected: " << false << " , Actual: " << (bitField2 == bitField) << "\n" << endl;

	cout << "bitField.GetBit(). Expected: " << 1010 << " , Actual: "
		 << bitField.GetBit(0) << bitField.GetBit(1) << bitField.GetBit(16) << bitField.GetBit(17) << "\n" << endl;

	int N2 = 40;
	TBitField bitField3(N2);
	bitField3 = bitField;
	cout << "bitField3 == bitField. Expected: " << true << " , Actual: " << (bitField3 == bitField) << "\n" << endl;

	int N3 = 10;
	TBitField bitField4(N3);
	for (int i = 0; i < N3; i++)
	{
		bitField4.SetBit(i);
	}
	cout << "bitField4 | bitField." << endl
	 	 << "Expected: 11111111111010101010" << endl
	 	 << "Actual:   " << (bitField4 | bitField) << "\n" << endl;

	cout << "bitField4 & bitField." << endl
		 << "Expected: 10101010100000000000" << endl
		 << "Actual:   " << (bitField4 & bitField) << "\n" << endl;

	cout << "~bitField." << endl
		 << "Expected: 01010101010101010101" << endl
	 	 << "Actual:   " << (~bitField) << "\n\n";

	cout << "cin test (enter a bitfield 4 chars long):\n" << "Expected:" << endl;
	TBitField bitField5(4);
	cin >> bitField5;

	cout << "Actual:\n" << bitField5 << endl;
}