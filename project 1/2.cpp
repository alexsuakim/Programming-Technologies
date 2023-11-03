#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double e=2.72;

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is

// Function: sigmoid activation function
// Input: double x: the input of sigmoid activation function
// Ouput: the output of sigmoid activation function
double sigmoid(double x)
{
// ==========================

	double sigmoid_value = 1 / (1 + pow(e, -1 * x));
	return sigmoid_value;

// ==========================
}

// Function: tanh activate function
// Input: double x: the input of tanh activation function
// Ouput: double: the output of tanh activation function.
double tanh(double x)
{
  // ==========================

	double sigmoid_value = sigmoid(2 * x);
	double tanh_value = 2 * sigmoid_value - 1;
	return tanh_value;

  // ==========================
}

// Function: compute the next hidden value in an RNN cell
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: next hidden value in RNN cell
double ComputeH(double x, double h)
{
  // ==========================

	double h_value = tanh(0.5 * x - 2 * h);
	return h_value;

  // ==========================
}

// Function: compute the output value at current time step
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: current output value
double ComputeO(double x, double h)
{
  // ==========================

	double o_value = sigmoid(0.1 * x + 1.5 * h);
	return o_value;

  // ==========================

}

// Function: print the values stored in a 1D-array to screen
// Input: double xs[100]: the value of the sequence
//        int seq_len: the length of the sequence
void PrintSeqs(double xs[100], int seq_len)
{
  // ==========================

#define decimal_point(x) std::fixed << std::setprecision(10)<<(x)
	for (int i = 0; i < seq_len; i++){
		cout << decimal_point(xs[i]) << " ";
	}

  // ==========================
}

// Function: main function
int main()
{
  // ==========================

	//take input
	int T;
	double h_input, x_i, x_array[100], h_array[100], o_array[100];
	cin >> T >> h_input;
	for (int i = 0; i < T; i++){
		cin >> x_i;
		x_array[i] = x_i;
	}

	//compute
	h_array[0] = ComputeH(x_array[0], h_input);
	o_array[0] = ComputeO(x_array[0], h_input);
	for (int j = 1; j < T; j++){
		h_array[j] = ComputeH(x_array[j], h_array[j - 1]);
		o_array[j] = ComputeO(x_array[j], h_array[j - 1]);
	}

	//print output
	PrintSeqs(h_array, T);
	cout << endl;
	PrintSeqs(o_array, T);
	cout << endl;

  // ==========================

}

