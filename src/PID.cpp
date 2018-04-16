#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double p, double i, double d) {
	Kp = p;
	Ki = i;
	Kd = d;

	int_cte = 0;
	prev_cte = 0;
	p_error = i_error = d_error = 0;
}

void PID::UpdateError(double cte) {
	double diff_cte = cte - prev_cte;
	int_cte += cte;
	prev_cte = cte;
	p_error = -Kp * cte;
	i_error = -Ki * int_cte;
	d_error = -Kd * diff_cte;
}

double PID::TotalError() {
	double total = p_error + i_error + d_error;
	if (total > 1.0)
		return 1.0;
	if (total < -1.0)
		return -1.0;
	return total;
}
